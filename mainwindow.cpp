#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPlainTextEdit* r_o = ui->plainTextEdit;
    read_only_action = new QAction(tr("Только для чтение(ВКЛ)"), r_o);
    r_o->addAction(read_only_action);
    r_o->setContextMenuPolicy(Qt::ActionsContextMenu);
    r_o->connect(read_only_action, SIGNAL(triggered()), this, SLOT(read_only_switch()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Пример"),
                                     QDir::currentPath(), tr("Текстовый файл(*.txt)"));
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
    QString filename = QFileDialog::getSaveFileName(this, tr("Пример"),
                                     QDir::currentPath(), tr("Текстовый файл(*.txt)"));
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

/* Добавить в текстовый редактор режим «Открыть только для чтения», блокирующий любые правки для документа */

void MainWindow::read_only_switch()
{
    if (!read_only)
    {
        read_only = true;
        read_only_action->setText(tr("Только для чтение(ВЫКЛ)"));
        ui->plainTextEdit->setReadOnly(true);
    }
    else
    {
        read_only = false;
        read_only_action->setText(tr("Только для чтение(ВКЛ)"));
        ui->plainTextEdit->setReadOnly(false);
    }
}

