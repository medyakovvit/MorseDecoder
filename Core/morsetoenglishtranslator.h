#ifndef MORSETOENGLISHTRANSLATOR_H
#define MORSETOENGLISHTRANSLATOR_H

#include <QObject>

#include "abstracttranslator.h"
#include "morsecodetree.h"

/* Translate Morse code to English text. Class uses
Morse code tree to hold symbols and codes. Morse code tree is
binary tree, where root node has symbol '\0'. Morse code considered
like path in the tree. Each node has pointers to left(dot) and right(dash)*/

class CORESHARED_EXPORT MorseToEnglishTranslator : public AbstractTranslator
{
    Q_OBJECT
public:
    MorseToEnglishTranslator(QObject *parent = 0);

    // AbstractTranslator interface
public:
    QString translate(const QString &text);

protected:
    MorseCodeTree m_codes;
};

#endif // MORSETOENGLISHTRANSLATOR_H
