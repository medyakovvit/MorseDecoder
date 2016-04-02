#ifndef FILELOADER_H
#define FILELOADER_H

#include "core_global.h"

#include <QObject>

/*! \class FileLoader
 * \brief Abstract class for file loaders
*/

class CORESHARED_EXPORT FileLoader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)

public:
    explicit FileLoader(QObject *parent = 0);

    virtual QString load(QString filePath) = 0;
    virtual QString load() = 0;
    QString extensions()const{return m_extensions;}
    QString filePath()const{return m_filePath;}

signals:
    void filePathChanged(QString path);

public slots:
    void setFilePath(QString path);

protected:
    QString m_extensions;
    QString m_filePath;
};

#endif // FILELOADER_H
