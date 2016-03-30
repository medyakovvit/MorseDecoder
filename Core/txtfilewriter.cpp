#include "txtfilewriter.h"

#include <QDebug>
#include <QFile>

TxtFileWriter::TxtFileWriter(QObject *parent) : FileWriter(parent)
{
    m_extension = "*.txt";
}

bool TxtFileWriter::write(const QString& text, const QString& filePath)
{
    QFile file;
    if(!filePath.endsWith(".txt"))
        file.setFileName(filePath + ".txt");
    else
        file.setFileName(filePath);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << text;
        file.close();
        return true;
    }
    else
        return false;
}

bool TxtFileWriter::write(const QString& text)
{
    return this->write(text, this->filePath());
}
