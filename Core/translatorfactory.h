#ifndef TRANSLATORFACTORY_H
#define TRANSLATORFACTORY_H

#include "core_global.h"

#include <abstracttranslator.h>

class CORESHARED_EXPORT TranslatorFactory
{
public:
    TranslatorFactory();

    AbstractTranslator* createTranslator(QString type);
};

#endif // TRANSLATORFACTORY_H
