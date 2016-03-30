#ifndef ABSTRACTTRANSLATOR_H
#define ABSTRACTTRANSLATOR_H

#include "core_global.h"

#include <QObject>

class CORESHARED_EXPORT AbstractTranslator : public QObject
{
    Q_OBJECT
public:
    explicit AbstractTranslator(QObject *parent = 0);
    virtual QString translate(const QString& text) = 0;

signals:

public slots:
};

#endif // ABSTRACTTRANSLATOR_H
