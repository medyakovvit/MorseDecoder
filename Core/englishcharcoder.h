#ifndef ENGLISHCHARCODER_H
#define ENGLISHCHARCODER_H

#include "core_global.h"

#include <QHash>

/*! \class EnglishCharCoder
 * \brief Holds codes for english letters
*/

class CORESHARED_EXPORT EnglishCharCoder
{
public:
    EnglishCharCoder();
    QHash<QChar, QString> codes() {return m_codes;}

protected:
    QHash<QChar, QString> m_codes;
};

#endif // ENGLISHCHARCODER_H
