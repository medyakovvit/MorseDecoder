#include "numbercoder.h"

NumberCoder::NumberCoder()
{
    m_codes.insert('0', "-----");
    m_codes.insert('1', ".----");
    m_codes.insert('2', "..---");
    m_codes.insert('3', "...--");
    m_codes.insert('4', "....-");
    m_codes.insert('5', ".....");
    m_codes.insert('6', "-....");
    m_codes.insert('7', "--...");
    m_codes.insert('8', "---..");
    m_codes.insert('9', "----.");
}
