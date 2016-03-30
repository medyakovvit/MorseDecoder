#include "textholder.h"

#include <QDebug>

TextHolder::TextHolder(QObject *parent) : QObject(parent)
{

}

TextHolder::~TextHolder()
{
}

void TextHolder::load(FileLoader *fileLoader)
{
    if(fileLoader)
        this->setInput(fileLoader->load());
}

void TextHolder::saveInput(FileWriter *fileWriter)
{
    if(fileWriter && !this->input().isEmpty())
        fileWriter->write(this->input());
}

void TextHolder::saveOutput(FileWriter *fileWriter)
{
    if(fileWriter && !this->output().isEmpty())
        fileWriter->write(this->output());
}

void TextHolder::setInput(QString in)
{
    if(m_input == in)
        return;

    m_input = in;
    emit inputChanged(in);
}

void TextHolder::setOutput(QString out)
{
    if(m_output == out)
        return;

    m_output = out;
    emit outputChanged(out);
}
