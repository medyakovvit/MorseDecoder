#include <QString>
#include <QtTest>

#include <abstracttranslator.h>
#include <morsetoenglishtranslator.h>
#include <englishcharcoder.h>
#include <symbolcoder.h>
#include <numbercoder.h>

class HashTable_MorseToEnglishTranslator : public AbstractTranslator {
    Q_OBJECT
public:
    HashTable_MorseToEnglishTranslator(QObject *parent = 0);

    // AbstractTranslator interface
public:
    QString translate(const QString &text);

protected:
    QHash<QString, QChar> m_codes;
};

class Hash_Tree_BenchmarkTest : public QObject
{
    Q_OBJECT

public:
    Hash_Tree_BenchmarkTest();

private Q_SLOTS:
    void morseTreeText();
    void hashText();
    void morseTreeBigText();
    void hashBigText();

protected:
    MorseToEnglishTranslator treeTranslator;
    HashTable_MorseToEnglishTranslator hashTranslator;
    QString bigText;
};

const QString text("Pack my box with five dozen liquor jugs "
                   "0123456789 "
                   ".,?\'!/()&;:=+-_\"$@");

Hash_Tree_BenchmarkTest::Hash_Tree_BenchmarkTest()
{
    bigText = text;
    for(int i=0; i<100; i++)
        bigText += (" " + text);
}

void Hash_Tree_BenchmarkTest::morseTreeText()
{
    QBENCHMARK {treeTranslator.translate(text);
               }
}

void Hash_Tree_BenchmarkTest::hashText()
{
    QBENCHMARK {hashTranslator.translate(text);
               }
}

void Hash_Tree_BenchmarkTest::morseTreeBigText()
{
    QBENCHMARK {treeTranslator.translate(bigText);
               }
}

void Hash_Tree_BenchmarkTest::hashBigText()
{
    QBENCHMARK {hashTranslator.translate(bigText);
               }
}



HashTable_MorseToEnglishTranslator::HashTable_MorseToEnglishTranslator(QObject *parent) : AbstractTranslator(parent)
{
    EnglishCharCoder engCharCoder;
    SymbolCoder symbCoder;
    NumberCoder numCoder;

    QHash<QChar,QString>::ConstIterator it = engCharCoder.codes().cbegin();
    for(;it != engCharCoder.codes().cend(); ++it)
        m_codes.insert(it.value(), it.key());

    it = symbCoder.codes().cbegin();
    for(;it != symbCoder.codes().cend(); ++it)
        m_codes.insert(it.value(), it.key());

    it = numCoder.codes().cbegin();
    for(;it != numCoder.codes().cend(); ++it)
        m_codes.insert(it.value(), it.key());
}

QString HashTable_MorseToEnglishTranslator::translate(const QString &text)
{
    QStringList results;
    QStringList strings = text.split("  ");

    foreach (QString word, strings)
    {
        QString res;
        QStringList paths = word.split(' ');
        foreach (QString path, paths) {
            res.append(m_codes.value(path));
        }
        results << res;
    }
    return results.join(' ');
}

QTEST_APPLESS_MAIN(Hash_Tree_BenchmarkTest)

#include "tst_hash_tree_benchmarktest.moc"
