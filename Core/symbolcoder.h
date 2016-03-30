#ifndef SYMBOLCODER_H
#define SYMBOLCODER_H

#include <QHash>


class SymbolCoder
{
public:
    SymbolCoder();

    QHash<QChar, QString> codes() {return m_codes;}

protected:
    QHash<QChar, QString> m_codes;
};

#endif // SYMBOLCODER_H