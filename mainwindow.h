#pragma once

#include <QMainWindow>
#include <QTranslator>

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

private:
    Ui::MainWindow *ui;
    QAction* read_only_action;
    QTranslator translater;
};

