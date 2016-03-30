#include "txtfileloader.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

TxtFileLoader::TxtFileLoader(QObject *parent) : FileLoader(parent)
{
    m_extensions = "*.txt";
}

TxtFileLoader::~TxtFileLoader()
{
}

QString TxtFileLoader::load(QString filePath)
{
    if(!QFile::exists(filePath))
        return QString();

    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString text = in.readAll();
        return text;
    }
    else
        return QString();
}

QString TxtFileLoader::load()
{
    return this->load(m_filePath);
}
