#include "filewriter.h"

FileWriter::FileWriter(QObject *parent) : QObject(parent)
{

}

void FileWriter::setFilePath(QString path)
{
    if(m_filePath == path)
        return;

    m_filePath = path;
    emit filePathChanged(m_filePath);
}
