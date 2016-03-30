#include "translatorfactory.h"

#include "morsetoenglishtranslator.h"
#include "engtomorsetranslator.h"

TranslatorFactory::TranslatorFactory()
{

}

AbstractTranslator *TranslatorFactory::createTranslator(QString type)
{
    if(type == "Morse")
        return new MorseToEnglishTranslator();

    else if(type == "English")
        return new EngToMorseTranslator();

    else
        return 0;
}
