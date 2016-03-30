#include <QString>
#include <QtTest>

#include <QFile>

#include "txtfileloader.h"

class TxtFileLoaderTest : public QObject
{
    Q_OBJECT

public:
    TxtFileLoaderTest();

private Q_SLOTS:
    void loadNotExistedFile();
    void load();
};

const QString text = "Pack my box with five dozen liquor jugs "
        "0123456789 "
        ".,?!-_=+()";

TxtFileLoaderTest::TxtFileLoaderTest()
{
}

void TxtFileLoaderTest::loadNotExistedFile()
{
    TxtFileLoader loader;

    QCOMPARE(loader.load(""), QString());
}

void TxtFileLoaderTest::load()
{
    TxtFileLoader loader;

    QFile file("test.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << text;
    }
    else
        QFAIL(QString("Failed to write file %1").arg(file.fileName()).toLatin1());

    QCOMPARE(loader.load(file.fileName()), text);
    file.close();
    if(!file.remove())
        QFAIL(QString("Failed to remove file %1").arg(file.fileName()).toLatin1());
}

QTEST_APPLESS_MAIN(TxtFileLoaderTest)

#include "tst_txtfileloadertest.moc"
