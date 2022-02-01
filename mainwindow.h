#pragma once

#include <QMainWindow>
#include <QMap>
#include "QStandardItem"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_addButton_clicked();

    void on_iconBox_clicked();

    void on_delButton_clicked();

private:
    Ui::MainWindow *ui;

    QMap<QString, QString> symbols;

    QStandardItemModel *model;
};
