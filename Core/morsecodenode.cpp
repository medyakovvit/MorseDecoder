#include "morsecodenode.h"

#include <QDebug>

MorseCodeNode::MorseCodeNode(QChar s) :
    m_symbol(s), p_left(0), p_right(0)
{

}

void MorseCodeNode::setSymbol(QChar ch)
{
    if(m_symbol == ch)
        return;

    m_symbol = ch;
}

void MorseCodeNode::setLeft(MorseCodeNode *node)
{
    if(p_left == node)
        return;

    p_left = node;
}

void MorseCodeNode::setRight(MorseCodeNode *node)
{
    if(p_right == node)
        return;

    p_right = node;
}
