#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    QMenu* fileMenu = menuBar()->addMenu(tr("Файл"));

    QAction* openAct = fileMenu->addAction(tr("Открыть"));
    connect(openAct, SIGNAL(triggered(bool)), this, SLOT(openText()));

    QAction* saveAct = fileMenu->addAction(tr("Сохранить"));
    connect(saveAct, SIGNAL(triggered(bool)), this, SLOT(saveText()));

    QAction* aboutAct = fileMenu->addAction(tr("О программе"));
    connect(aboutAct, SIGNAL(triggered(bool)), this, SLOT(helpAbout()));

    QAction* quitAct = fileMenu->addAction(tr("Выход"));
    connect(quitAct, SIGNAL(triggered(bool)), this, SLOT(close()));

    QAction* switchAct = fileMenu->addAction(tr("Английский язык"));
    connect(switchAct, SIGNAL(triggered(bool)), this, SLOT(switchLanguage()));

    QMenu* themeMenu = menuBar()->addMenu(tr("Выбрать тему"));

    QAction* themeAct = themeMenu->addAction(tr("Темная тема"));
    connect(themeAct, SIGNAL(triggered(bool)), this, SLOT(darkTheme()));

    QAction* themeAct2 = themeMenu->addAction(tr("Светлая тема"));
    connect(themeAct2, SIGNAL(triggered(bool)), this, SLOT(lightTheme()));

    QAction* printAct = fileMenu->addAction(tr("Печать"));
    connect(printAct, SIGNAL(triggered(bool)), this, SLOT(printText()));

    QMenu* formatMenu = menuBar()->addMenu(tr("Форматирование"));

    QAction* fontChangeAct = formatMenu->addAction(tr("Шрифт"));
    connect(fontChangeAct, SIGNAL(triggered(bool)), this, SLOT(fontChange()));

    QAction* leftAlignAct = formatMenu->addAction(tr("Выравнивание по левому краю"));
    connect(leftAlignAct, SIGNAL(triggered(bool)), this, SLOT(leftAlign()));

    QAction* rightAlignAct = formatMenu->addAction(tr("Выравнивание по правому краю"));
    connect(rightAlignAct, SIGNAL(triggered(bool)), this, SLOT(rightAlign()));

    QAction* centerAlignAct = formatMenu->addAction(tr("Выравнивание по центру"));
    connect(centerAlignAct, SIGNAL(triggered(bool)), this, SLOT(centerAlign()));

    QAction* copyFormatAct = formatMenu->addAction(tr("Копировать форматирование"));
    connect(copyFormatAct, SIGNAL(triggered(bool)), this, SLOT(copyFormat()));

    QAction* pasteFormatAct = formatMenu->addAction(tr("Вставить форматирование"));
    connect(pasteFormatAct, SIGNAL(triggered(bool)), this, SLOT(pasteFormat()));

    QMenu* datatimeMenu = menuBar()->addMenu(tr("Вставка даты и времени"));

    QAction* pasteDataAct = datatimeMenu->addAction(tr("Вставить дату"));
    connect(pasteDataAct, SIGNAL(triggered(bool)), this, SLOT(pasteData()));

    QAction* pasteTimeAct = datatimeMenu->addAction(tr("Вставить время"));
    connect(pasteTimeAct, SIGNAL(triggered(bool)), this, SLOT(pasteTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openText()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Открыть"),
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

void MainWindow::saveText()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить"),
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

void MainWindow::helpAbout()
{
    QMessageBox aboutBox;
    aboutBox.setIcon(QMessageBox::Information);
    QFile file (":/desc/about.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray byteArray = file.readAll();
    aboutBox.setText(tr(byteArray.data()));
    aboutBox.exec();
}

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

void MainWindow::darkTheme()
{
    setStyleSheet("QMainWindow {background-color:DimGrey}"
                  "QPlainTextEdit {color:Aqua; background-color:Silver}");
}

void MainWindow::lightTheme()
{
    setStyleSheet("QMainWindow {background-color:Snow}"
                  "QPlainTextEdit {color:MediumBlue; background-color:Azure}");
}

void MainWindow::switchLanguage()
{
    translater.load("./QtLanguage_en_US");
    qApp->installTranslator(&translater);
}

void MainWindow::printText()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    if(dlg.exec() == QDialog::Accepted) {
        ui->plainTextEdit->print(&printer);
    }
}

void MainWindow::leftAlign()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::rightAlign()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::centerAlign()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::fontChange()
{
    QFont font = ui->textEdit->textCursor().charFormat().font();
    QFontDialog fontDialog(font,this);

    bool b[] = {true};
    font = fontDialog.getFont(b);
    if (b[0])
    {
        QTextCharFormat format;
        format.setFont(font);
        ui->textEdit->textCursor().setCharFormat(format);
    }
}

void MainWindow::copyFormat()
{
    format = ui->textEdit->textCursor().charFormat();
}

void MainWindow::pasteFormat()
{
    ui->textEdit->textCursor().setCharFormat(format);
}

/* Добавить в текстовый редактор возможность вставлять дату и время в текст по позиции курсора */

void MainWindow::pasteData()
{
    QDate date = QDate::currentDate();
    QTextCursor cur = ui->textEdit->textCursor();
    cur.insertHtml(date.toString("dddd dd MMMM yyyy"));
}

void MainWindow::pasteTime()
{
    QTime time = QTime::currentTime();
    QTextCursor cur = ui->textEdit->textCursor();
    cur.insertHtml(time.toString("HH:mm:ss"));
}
