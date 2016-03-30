#include <QString>
#include <QtTest>

#include <QDebug>

#include "../Core/numbercoder.h"

class NumberCoderTest : public QObject
{
    Q_OBJECT

public:
    NumberCoderTest();

private Q_SLOTS:
    void checkCodes();
};

NumberCoderTest::NumberCoderTest()
{
}

void NumberCoderTest::checkCodes()
{
    NumberCoder coder;
    QHash<QChar, QString> expected;
    expected.insert('0', "-----");
    expected.insert('1', ".----");
    expected.insert('2', "..---");
    expected.insert('3', "...--");
    expected.insert('4', "....-");
    expected.insert('5', ".....");
    expected.insert('6', "-....");
    expected.insert('7', "--...");
    expected.insert('8', "---..");
    expected.insert('9', "----.");

    QCOMPARE(coder.codes(), expected);
}

QTEST_APPLESS_MAIN(NumberCoderTest)

#include "tst_numbercodertest.moc"
