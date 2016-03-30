#include "morsecodetree.h"

MorseCodeTree::MorseCodeTree() :
    p_root(0)
{

}

MorseCodeTree::~MorseCodeTree()
{
    deleteTree(p_root);
}

void MorseCodeTree::addNode(const QChar &symbol, const QString &path)
{
    if(!p_root)
        p_root = new MorseCodeNode();

    MorseCodeNode *node = p_root;

    for(int i=0; i<path.length(); i++)
    {
        if(path.at(i) == '.')
        {
            if(!node->left())
            {
                node->setLeft(new MorseCodeNode());
            }
            node = node->left();
        }

        else if(path.at(i) == '-')
        {
            if(!node->right())
            {
                node->setRight(new MorseCodeNode());
            }
            node = node->right();
        }
    }

    node->setSymbol(symbol);
}

QChar MorseCodeTree::find(const QString &path) const
{
    if(!p_root)
        return QChar();

    MorseCodeNode *node = p_root;

    for(int i=0; i<path.length(); i++)
    {
        if(path.at(i) == '.')
            node = node->left();

        else if(path.at(i) == '-')
            node = node->right();

        if(!node)
            break;
    }

    if(node)
        return node->symbol();

    else
        return QChar();
}

void MorseCodeTree::deleteTree(MorseCodeNode *node)
{
    if(!node)
        return;

    if(node->left())
        deleteTree(node->left());

    if(node->right())
        deleteTree(node->right());

    if (node)
    {
        delete node;
        node = 0;
    }
}
