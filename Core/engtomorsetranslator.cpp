#include "engtomorsetranslator.h"

#include <QDebug>

#include "englishcharcoder.h"
#include "numbercoder.h"
#include "symbolcoder.h"

EngToMorseTranslator::EngToMorseTranslator(QObject *parent) : AbstractTranslator(parent)
{
    EnglishCharCoder engChCoder;
    NumberCoder numCoder;
    SymbolCoder symCoder;

    QHash<QChar, QString>::ConstIterator it = engChCoder.codes().cbegin();
    for(; it != engChCoder.codes().cend(); ++it)
        m_codes.insert(it.key(), it.value());

    it = numCoder.codes().cbegin();
    for(; it != numCoder.codes().cend(); ++it)
        m_codes.insert(it.key(), it.value());

    it = symCoder.codes().cbegin();
    for(; it != symCoder.codes().cend(); ++it)
        m_codes.insert(it.key(), it.value());
}

QString EngToMorseTranslator::translate(const QString& text)
{
    QString result;
    QString::ConstIterator it = text.cbegin();

    for(; it != text.cend(); ++it)
    {
        QChar ch = (*it).toLower();

        if(ch == ' ')
            result.append("  ");

        else
        {
            QString code = m_codes.value(ch);
            if(code.isEmpty())
            {
                if(!result.isEmpty())
                    result.remove(result.length()-1, 1);
            }

            else
            {
                result.append(code);
                if(it+1 != text.cend())
                    if(*(it+1) != ' ')
                        result.append(' ');
            }
        }
    }

    return result;
}
