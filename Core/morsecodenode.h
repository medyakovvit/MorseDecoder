#ifndef MORSECODENODE_H
#define MORSECODENODE_H

#include <QChar>

// Present item in Morse Code Tree

class MorseCodeNode
{
public:
    MorseCodeNode(QChar s='\0');

    QChar symbol(){return m_symbol;}
    void setSymbol(QChar ch);

    MorseCodeNode* left(){return p_left;}
    void setLeft(MorseCodeNode* node);

    MorseCodeNode* right(){return p_right;}
    void setRight(MorseCodeNode* node);

protected:
    QChar m_symbol;
    MorseCodeNode *p_left;      // dot
    MorseCodeNode *p_right;     // dash
};

#endif // MORSECODENODE_H
