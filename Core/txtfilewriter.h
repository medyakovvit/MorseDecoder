#ifndef TXTFILEWRITER_H
#define TXTFILEWRITER_H

#include <QObject>
#include "filewriter.h"

/*!
 * \class TxtFileWriter
 * Writes text to *.txt file.
*/

class CORESHARED_EXPORT TxtFileWriter : public FileWriter
{
    Q_OBJECT
public:
    explicit TxtFileWriter(QObject *parent = 0);

signals:

public slots:

    // FileWriter interface
public:
    bool write(const QString& text, const QString& filePath);
    bool write(const QString& text);
};

#endif // TXTFILEWRITER_H
