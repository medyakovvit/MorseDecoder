#ifndef TRANSLATORFACTORY_H
#define TRANSLATORFACTORY_H

#include "core_global.h"

#include <abstracttranslator.h>

/*!
  \class TranslatorFactory
  \brief Creates translator with the appropriate type
*/
class CORESHARED_EXPORT TranslatorFactory
{
public:
    TranslatorFactory();

    AbstractTranslator* createTranslator(QString type);
};

#endif // TRANSLATORFACTORY_H
