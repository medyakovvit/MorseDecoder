#ifndef MORSECODETREE_H
#define MORSECODETREE_H

#include "core_global.h"

#include <QString>

#include "morsecodenode.h"

class CORESHARED_EXPORT MorseCodeTree
{
public:
    MorseCodeTree();
    ~MorseCodeTree();
    MorseCodeNode* root(){return p_root;}

    void addNode(const QChar& symbol, const QString& path);
    QChar find(const QString& path)const;

protected:
    void deleteTree(MorseCodeNode *node);

protected:
    MorseCodeNode* p_root;
};

#endif // MORSECODETREE_H
