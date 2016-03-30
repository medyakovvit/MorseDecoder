#include "englishcharcoder.h"

EnglishCharCoder::EnglishCharCoder()
{
    m_codes.insert('a', ".-");
    m_codes.insert('b', "-...");
    m_codes.insert('c', "-.-.");
    m_codes.insert('d', "-..");
    m_codes.insert('e', ".");
    m_codes.insert('f', "..-.");
    m_codes.insert('g', "--.");
    m_codes.insert('h', "....");
    m_codes.insert('i', "..");
    m_codes.insert('j', ".---");
    m_codes.insert('k', "-.-");
    m_codes.insert('l', ".-..");
    m_codes.insert('m', "--");
    m_codes.insert('n', "-.");
    m_codes.insert('o', "---");
    m_codes.insert('p', ".--.");
    m_codes.insert('q', "--.-");
    m_codes.insert('r', ".-.");
    m_codes.insert('s', "...");
    m_codes.insert('t', "-");
    m_codes.insert('u', "..-");
    m_codes.insert('v', "...-");
    m_codes.insert('w', ".--");
    m_codes.insert('x', "-..-");
    m_codes.insert('y', "-.--");
    m_codes.insert('z', "--..");
}
