#ifndef TEXTHOLDER_H
#define TEXTHOLDER_H

#include <QObject>

#include <fileloader.h>
#include <filewriter.h>

class TextHolder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString input READ input WRITE setInput NOTIFY inputChanged)
    Q_PROPERTY(QString output READ output WRITE setOutput NOTIFY outputChanged)

public:
    explicit TextHolder(QObject *parent = 0);
    ~TextHolder();
    void load(FileLoader* fileLoader);
    void saveInput(FileWriter* fileWriter);
    void saveOutput(FileWriter* fileWriter);

    QString input()const{return m_input;}
    QString output()const{return m_output;}

signals:
    void inputChanged(QString in);
    void inputLoaded(QString text);
    void outputChanged(QString out);

public slots:
    void setInput(QString in);
    void setOutput(QString out);

protected:
    QString m_input;
    QString m_output;
};

#endif // TEXTHOLDER_H
