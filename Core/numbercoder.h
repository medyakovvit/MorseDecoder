#ifndef NUMBERCODER_H
#define NUMBERCODER_H

#include "core_global.h"

#include <QHash>

/*! \class NumberCoder
 * \brief Holds codes for numbers
*/

class CORESHARED_EXPORT NumberCoder
{
public:
    NumberCoder();
    QHash<QChar, QString> codes() {return m_codes;}

protected:
    QHash<QChar, QString> m_codes;
};

#endif // NUMBERCODER_H
