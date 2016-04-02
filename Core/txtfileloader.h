#ifndef TXTFILELOADER_H
#define TXTFILELOADER_H

#include "core_global.h"

#include <QObject>

#include "fileloader.h"

/*!
 * \class TxtFileLoader
 * \brief Read txt file.
*/

class CORESHARED_EXPORT TxtFileLoader : public FileLoader
{
    Q_OBJECT
public:
    explicit TxtFileLoader(QObject *parent = 0);
    ~TxtFileLoader();

    QString load(QString filePath);
    QString load();

signals:

public slots:
};

#endif // TXTFILELOADER_H
