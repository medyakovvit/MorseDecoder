#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include <translatorfactory.h>
#include <txtfileloader.h>
#include <txtfilewriter.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    p_translator(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setBtnCodeText(ui->comboBox->currentText());
    p_txtHolder = new TextHolder(this);
    p_fileLoader = new TxtFileLoader(this);
    p_fileWriter = new TxtFileWriter(this);

    connect(p_txtHolder, &TextHolder::inputLoaded, ui->teInput, &QPlainTextEdit::setPlainText);
    connect(p_txtHolder, &TextHolder::outputChanged, ui->teOutput, &QPlainTextEdit::setPlainText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"),
                                                    QDir::currentPath(),
                                                    p_fileLoader->extensions());

    if(!fileName.isEmpty())
    {
        p_fileLoader->setFilePath(fileName);
        p_txtHolder->load(p_fileLoader);
    }
}

void MainWindow::on_btnCode_clicked()
{
    if(!p_translator)
    {
        TranslatorFactory factory;
        p_translator = factory.createTranslator(ui->comboBox->currentText());
        if(!p_translator)
            return;
    }

    p_txtHolder->setOutput(p_translator->translate(p_txtHolder->input()));
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if(p_translator)
        delete p_translator;

    TranslatorFactory factory;
    p_translator = factory.createTranslator(arg1);

    this->setBtnCodeText(arg1);
}

void MainWindow::on_btnSaveInput_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"),
                                                    QDir::currentPath(),
                                                    p_fileWriter->extension());

    if(!fileName.isEmpty())
    {
        p_fileWriter->setFilePath(fileName);
        p_txtHolder->saveInput(p_fileWriter);
    }
}

void MainWindow::on_teInput_textChanged()
{
    p_txtHolder->setInput(ui->teInput->toPlainText());
}

void MainWindow::on_btnSaveOutput_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"),
                                                    QDir::currentPath(),
                                                    p_fileWriter->extension());

    if(!fileName.isEmpty())
    {
        p_fileWriter->setFilePath(fileName);
        p_txtHolder->saveOutput(p_fileWriter);
    }
}

void MainWindow::setBtnCodeText(const QString &mode)
{
    if(mode == "Morse")
        ui->btnCode->setText("Decode");
    else
        ui->btnCode->setText("Code");
}
