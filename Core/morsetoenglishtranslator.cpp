#include "morsetoenglishtranslator.h"

#include "englishcharcoder.h"
#include "symbolcoder.h"
#include "numbercoder.h"

MorseToEnglishTranslator::MorseToEnglishTranslator(QObject *parent) : AbstractTranslator(parent)
{
    EnglishCharCoder engCharCoder;
    SymbolCoder symbCoder;
    NumberCoder numCoder;

    QHash<QChar,QString>::ConstIterator it = engCharCoder.codes().cbegin();
    for(;it != engCharCoder.codes().cend(); ++it)
        m_codes.addNode(it.key(), it.value());

    it = symbCoder.codes().cbegin();
    for(;it != symbCoder.codes().cend(); ++it)
        m_codes.addNode(it.key(), it.value());

    it = numCoder.codes().cbegin();
    for(;it != numCoder.codes().cend(); ++it)
        m_codes.addNode(it.key(), it.value());
}

QString MorseToEnglishTranslator::translate(const QString &text)
{
    QStringList results;
    QStringList strings = text.split("  ");

    foreach (QString word, strings)
    {
        QString res;
        QStringList paths = word.split(' ');
        foreach (QString path, paths) {
            res.append(m_codes.find(path));
        }
        results << res;
    }
    return results.join(' ');
}
