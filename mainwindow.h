#pragma once

#include <QMainWindow>

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
    void on_openButton_clicked();

    void on_saveButton_clicked();

    void on_aboutButton_clicked();

    void read_only_switch();


private:
    Ui::MainWindow *ui;
    QAction* read_only_action;

};

