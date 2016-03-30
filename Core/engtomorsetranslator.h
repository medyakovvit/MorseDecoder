#ifndef ENGTOMORSETRANSLATOR_H
#define ENGTOMORSETRANSLATOR_H

#include <QObject>
#include <QHash>

#include "abstracttranslator.h"

/* Translate english text to Morse code. Class uses
hashtable to hold symbols(Key) and codes(Value)*/

class CORESHARED_EXPORT EngToMorseTranslator : public AbstractTranslator
{
    Q_OBJECT
public:
    EngToMorseTranslator(QObject *parent=0);

    // AbstractTranslator interface
public:
    QString translate(const QString &text);

protected:
    QHash<QChar, QString> m_codes;
};

#endif // ENGTOMORSETRANSLATOR_H
