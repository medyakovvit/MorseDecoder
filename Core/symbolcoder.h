#ifndef SYMBOLCODER_H
#define SYMBOLCODER_H

#include "core_global.h"

#include <QHash>

/*!
 * \class SymbolCoder
 * \brief Holds codes for punctuation symbols
*/

class CORESHARED_EXPORT SymbolCoder
{
public:
    SymbolCoder();

    QHash<QChar, QString> codes() {return m_codes;}

protected:
    QHash<QChar, QString> m_codes;
};

#endif // SYMBOLCODER_H
