#include <QString>
#include <QtTest>

#include <txtfilewriter.h>

class TxtFileWriterTest : public QObject
{
    Q_OBJECT

public:
    TxtFileWriterTest();

private Q_SLOTS:
    void write();
    void writeStrangeFileName();
};

const QString expected = "Pack my box with five dozen liquor jugs "
                     "0123456789 "
                     ".,?!-_=+()";

const QString fileName("test.txt");

TxtFileWriterTest::TxtFileWriterTest()
{
}

void TxtFileWriterTest::write()
{
    TxtFileWriter writer;
    writer.setFilePath(fileName);
    QVERIFY(writer.write(expected));

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QFAIL("Failed to open file");

    else
    {
        QTextStream in(&file);
        QString actual = in.readAll();
        QCOMPARE(actual, expected);
        if(!file.remove())
            QFAIL("Failed to remove file");
    }
}

void TxtFileWriterTest::writeStrangeFileName()
{
    TxtFileWriter writer;
    writer.setFilePath(":::");
    QVERIFY(!writer.write(expected));
}

QTEST_APPLESS_MAIN(TxtFileWriterTest)

#include "tst_txtfilewritertest.moc"
