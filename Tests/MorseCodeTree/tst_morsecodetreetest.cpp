#include <QString>
#include <QtTest>
#include <QChar>

#include <queue>
#include <morsecodetree.h>


class MorseCodeTreeTest : public QObject
{
    Q_OBJECT

public:
    MorseCodeTreeTest();
    QString printLevelOrder(MorseCodeNode* root);

private Q_SLOTS:
    void testCase1();
};

MorseCodeTreeTest::MorseCodeTreeTest()
{
}

QString MorseCodeTreeTest::printLevelOrder(MorseCodeNode *root)
{
    QString str;
    if(!root)
        return QString();
    std::queue<MorseCodeNode*> currentLevel, nextLevel;
    currentLevel.push(root);
    while (!currentLevel.empty())
    {
        MorseCodeNode *currNode = currentLevel.front();
        currentLevel.pop();
        if (currNode)
        {
            QChar ch = currNode->symbol();

            if(ch != '\0')
                str.append(currNode->symbol());
            nextLevel.push(currNode->left());
            nextLevel.push(currNode->right());
        }
        if (currentLevel.empty())
            swap(currentLevel, nextLevel);
    }
    return str;
}

void MorseCodeTreeTest::testCase1()
{
    MorseCodeTree tree;
    tree.addNode('2', "..");
    tree.addNode('3', ".-");
    tree.addNode('0', ".");
    tree.addNode('1', "-");
    tree.addNode('4', "-.");
    tree.addNode('5', "--");

    QCOMPARE(printLevelOrder(tree.root()), QString("012345"));
    QChar ch = tree.find("--");
    QVERIFY(ch == '5');
}

QTEST_APPLESS_MAIN(MorseCodeTreeTest)

#include "tst_morsecodetreetest.moc"
