#include <QString>
#include <QtTest>

#include <engtomorsetranslator.h>

class EngToMorseTranslatorTest : public QObject
{
    Q_OBJECT

public:
    EngToMorseTranslatorTest();

private Q_SLOTS:
    void translateNumbers();
    void translateSymbols();
    void translateAlphabet();
    void translateSentense();
    void translateNotExistSymb();
};

EngToMorseTranslatorTest::EngToMorseTranslatorTest()
{
}

void EngToMorseTranslatorTest::translateNumbers()
{
    EngToMorseTranslator translator;
    QString result = translator.translate("0 1 2 3 4 5 6 7 8 9");
    QString expected("-----  .----  ..---  ...--  ....-  .....  -....  --...  ---..  ----.");
    QCOMPARE(result, expected);
}

void EngToMorseTranslatorTest::translateSymbols()
{
    EngToMorseTranslator translator;
    QString result = translator.translate(". , ? \' ! / ( ) & ; : = + - _ \" $ @");
    QString expected(".-.-.-  --..--  ..--..  .----.  -.-.--  -..-.  -.--.  -.--.-  .-...  ---...  -.-.-.  -...-  .-.-.  -....-  ..--.-  .-..-.  ...-..-  .--.-.");
    QCOMPARE(result, expected);
}

void EngToMorseTranslatorTest::translateAlphabet()
{
    EngToMorseTranslator translator;
    QString result = translator.translate("a b c d e f g h i j k l m n o p q r s t u v w x y z");
    QString expected(".-  -...  -.-.  -..  .  ..-.  --.  ....  ..  .---  -.-  .-..  --  -.  "
                     "---  .--.  --.-  .-.  ...  -  ..-  ...-  .--  -..-  -.--  --..");
    QCOMPARE(result, expected);
}

void EngToMorseTranslatorTest::translateSentense()
{
    EngToMorseTranslator translator;
    QString result = translator.translate("Pack my box with five dozen liquor jugs");
    QString expected(".--. .- -.-. -.-  "
                     "-- -.--  "
                     "-... --- -..-  "
                     ".-- .. - ....  "
                     "..-. .. ...- .  "
                     "-.. --- --.. . -.  "
                     ".-.. .. --.- ..- --- .-.  "
                     ".--- ..- --. ...");
    QCOMPARE(result, expected);
}

void EngToMorseTranslatorTest::translateNotExistSymb()
{
    EngToMorseTranslator translator;
    QString result = translator.translate("^Pack^ my% box~ with{ five} dozen[ liquor] jugs#");
    QString expected(".--. .- -.-. -.-  "
                     "-- -.--  "
                     "-... --- -..-  "
                     ".-- .. - ....  "
                     "..-. .. ...- .  "
                     "-.. --- --.. . -.  "
                     ".-.. .. --.- ..- --- .-.  "
                     ".--- ..- --. ...");
    QCOMPARE(result, expected);
}

QTEST_APPLESS_MAIN(EngToMorseTranslatorTest)

#include "tst_engtomorsetranslatortest.moc"
