#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

/*  Добавьте на форму виджет текстового редактора. Добавьте две кнопки: сохранить и открыть. Предоставьте возможность
 *  пользователю выбрать куда сохранять файл и какой файл открывать. Добавьте в текстовый редактор справку. Текстовый файл
 *  с описанием разместить в ресурсах программы. Для вызова справки разместить на форме соответствующую кнопку. */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Пример",
                                     QDir::currentPath(),"Текстовый файл(*.txt)");
    if (filename.length())
    {
        QFile file (filename);
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            QString s = tr(byteArray.data());
            ui->plainTextEdit->setPlainText(s);
            file.close();
        }
    }
}


void MainWindow::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Пример",
                                     QDir::currentPath(),"Текстовый файл(*.txt)");
    if (filename.length())
    {
        QFile file (filename);
        if (file.open(QIODevice::WriteOnly))
        {
            QString s = ui->plainTextEdit->toPlainText();
            QByteArray text = s.toUtf8();
            file.write(text, text.length());
            file.close();
        }
    }
}


void MainWindow::on_aboutButton_clicked()
{
    QMessageBox aboutBox;
    aboutBox.setIcon(QMessageBox::Information);
    QFile file (":/desc/about.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray byteArray = file.readAll();
    aboutBox.setText(tr(byteArray.data()));
    aboutBox.exec();
}

