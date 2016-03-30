#ifndef SYMBOLCODER_H
#define SYMBOLCODER_H

#include <QHash>

/* Holds codes for punctuation symbols */

class SymbolCoder
{
public:
    SymbolCoder();

    QHash<QChar, QString> codes() {return m_codes;}

protected:
    QHash<QChar, QString> m_codes;
};

#endif // SYMBOLCODER_H
