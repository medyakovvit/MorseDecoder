#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "core_global.h"

#include <QObject>

/*! \class FileLoader
 * \brief Abstract class for file writers
*/

class CORESHARED_EXPORT FileWriter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)

public:
    explicit FileWriter(QObject *parent = 0);

    virtual bool write(const QString& text, const QString& filePath) = 0;
    virtual bool write(const QString& text) = 0;
    QString extension()const{return m_extension;}
    QString filePath()const{return m_filePath;}

signals:
    void filePathChanged(QString path);

public slots:
    void setFilePath(QString path);

protected:
    QString m_extension;
    QString m_filePath;
};

#endif // FILEWRITER_H
