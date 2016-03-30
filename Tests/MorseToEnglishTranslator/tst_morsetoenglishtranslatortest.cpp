#include <QString>
#include <QtTest>

#include <morsetoenglishtranslator.h>

class MorseToEnglishTranslatorTest : public QObject
{
    Q_OBJECT

public:
    MorseToEnglishTranslatorTest();

private Q_SLOTS:
    void translateSentense();
    void translateNumbers();
    void translateSymbols();
};

MorseToEnglishTranslatorTest::MorseToEnglishTranslatorTest()
{
}

void MorseToEnglishTranslatorTest::translateSentense()
{
    MorseToEnglishTranslator translator;
    QString result = translator.translate(".--. .- -.-. -.-  "
                                          "-- -.--  "
                                          "-... --- -..-  "
                                          ".-- .. - ....  "
                                          "..-. .. ...- .  "
                                          "-.. --- --.. . -.  "
                                          ".-.. .. --.- ..- --- .-.  "
                                          ".--- ..- --. ...");
    QString expected("Pack my box with five dozen liquor jugs");
    QCOMPARE(result, expected.toLower());
}

void MorseToEnglishTranslatorTest::translateNumbers()
{
    MorseToEnglishTranslator translator;
    QString result = translator.translate("-----  .----  ..---  ...--  ....-  .....  -....  --...  ---..  ----.");
    QString expected("0 1 2 3 4 5 6 7 8 9");
    QCOMPARE(result, expected);
}

void MorseToEnglishTranslatorTest::translateSymbols()
{
    MorseToEnglishTranslator translator;
    QString result = translator.translate(".-.-.-  --..--  ..--..  .----.  -.-.--  -..-.  -.--.  -.--.-  .-...  ---...  -.-.-.  -...-  .-.-.  -....-  ..--.-  .-..-.  ...-..-  .--.-.");
    QString expected(". , ? \' ! / ( ) & ; : = + - _ \" $ @");
    QCOMPARE(result, expected);

}

QTEST_APPLESS_MAIN(MorseToEnglishTranslatorTest)

#include "tst_morsetoenglishtranslatortest.moc"
