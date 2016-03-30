#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fileloader.h>
#include <filewriter.h>
#include <abstracttranslator.h>

#include "textholder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_btnCode_clicked();
    void on_comboBox_activated(const QString &arg1);
    void on_btnSaveInput_clicked();
    void on_teInput_textChanged();
    void on_btnSaveOutput_clicked();

    // Set button text to "Code" or "Decode"
    void setBtnCodeText(const QString& mode);

protected:
    TextHolder* p_txtHolder;
    FileLoader* p_fileLoader;
    FileWriter* p_fileWriter;
    AbstractTranslator* p_translator;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
