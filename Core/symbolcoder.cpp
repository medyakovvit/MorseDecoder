#include "symbolcoder.h"

SymbolCoder::SymbolCoder()
{
    m_codes.insert('.', ".-.-.-");
    m_codes.insert(',', "--..--");
    m_codes.insert('?', "..--..");
    m_codes.insert('\'', ".----.");
    m_codes.insert('!', "-.-.--");
    m_codes.insert('/', "-..-.");
    m_codes.insert('(', "-.--.");
    m_codes.insert(')', "-.--.-");
    m_codes.insert('&', ".-...");
    m_codes.insert(';', "---...");
    m_codes.insert(':', "-.-.-.");
    m_codes.insert('=', "-...-");
    m_codes.insert('+', ".-.-.");
    m_codes.insert('-', "-....-");
    m_codes.insert('_', "..--.-");
    m_codes.insert('\"', ".-..-.");
    m_codes.insert('$', "...-..-");
    m_codes.insert('@', ".--.-.");
}
