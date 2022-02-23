#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTranslator>
#include <QPrinter>
#include <QPrintDialog>
#include <QFontDialog>
#include <QTextCharFormat>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool read_only;

private slots:
    void read_only_switch();

    void darkTheme();

    void lightTheme();

    void openText();

    void saveText();

    void helpAbout();

    void switchLanguage();

    void printText();

    void fontChange();

    void leftAlign();

    void rightAlign();

    void centerAlign();

    void copyFormat();

    void pasteFormat();

    void pasteData();

    void pasteTime();

private:
    Ui::MainWindow *ui;
    QAction* read_only_action;
    QTranslator translater;
    QTextCharFormat format;
};

