#include "fileloader.h"

FileLoader::FileLoader(QObject *parent) : QObject(parent)
{

}

void FileLoader::setFilePath(QString path)
{
    if(m_filePath == path)
        return;

    m_filePath = path;
    emit filePathChanged(m_filePath);
}
