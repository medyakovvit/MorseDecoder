#ifndef ENGLISHCHARCODER_H
#define ENGLISHCHARCODER_H

#include <QHash>

class EnglishCharCoder
{
public:
    EnglishCharCoder();
    QHash<QChar, QString> codes() {return m_codes;}

protected:
    QHash<QChar, QString> m_codes;
};

#endif // ENGLISHCHARCODER_H