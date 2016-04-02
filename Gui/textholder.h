#ifndef TEXTHOLDER_H
#define TEXTHOLDER_H

#include <QObject>

#include <fileloader.h>
#include <filewriter.h>

/*!
 * \class TextHolder
 * Holds texts for input and output fields.
*/

class TextHolder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString input READ input WRITE setInput NOTIFY inputChanged)
    Q_PROPERTY(QString output READ output WRITE setOutput NOTIFY outputChanged)

public:
    explicit TextHolder(QObject *parent = 0);
    ~TextHolder();

    /*!
     * Load text from file using appropriate file loader.
     * @param fileLoader
    */
    void load(FileLoader* fileLoader);

    /*!
     * Save text from input field using appropriate file loader.
     * @param fileWriter
    */
    void saveInput(FileWriter* fileWriter);

    /*!
     * Save text from output field using appropriate file loader.
     * @param fileWriter
    */
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
