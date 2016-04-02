#ifndef MORSECODETREE_H
#define MORSECODETREE_H

#include "core_global.h"

#include <QString>

#include "morsecodenode.h"

/*!
 * \class MorseCodeTree
 * \brief Present binary tree to search symbol
*/

class CORESHARED_EXPORT MorseCodeTree
{
public:
    MorseCodeTree();
    ~MorseCodeTree();
    MorseCodeNode* root(){return p_root;}

    void addNode(const QChar& symbol, const QString& path);

    /*!
     * Search symbol with \a path in tree
     * @param String representing path in tree
     * @return Symbol
    */
    QChar find(const QString& path)const;

protected:
    void deleteTree(MorseCodeNode *node);

protected:
    MorseCodeNode* p_root;
};

#endif // MORSECODETREE_H
