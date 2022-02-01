#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCursor>
#include <QModelIndexList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    symbols.insert("R", "&#8381;");
    symbols.insert("E", "&euro;");
    symbols.insert("C", "&copy;");
    symbols.insert("P", "&permil;");

    model = new QStandardItemModel(this);
    ui->listView->setModel(model);

    QStandardItem* item;
    item = new QStandardItem(QIcon(":/c++.png"), "C++");
    item->setFlags(item->flags() ^ (Qt::ItemIsDropEnabled));
    model->appendRow(item);

    item = new QStandardItem(QIcon(":/python.png"), "Python");
    item->setFlags(item->flags() ^ (Qt::ItemIsDropEnabled));
    model->appendRow(item);

    item = new QStandardItem(QIcon(":/java.png"), "Java");
    item->setFlags(item->flags() ^ (Qt::ItemIsDropEnabled));
    model->appendRow(item);

    item = new QStandardItem(QIcon(":/c-sharp.png"), "C#");
    item->setFlags(item->flags() ^ (Qt::ItemIsDropEnabled));
    model->appendRow(item);

    item = new QStandardItem(QIcon(":/php.png"), "PHP");
    item->setFlags(item->flags() ^ (Qt::ItemIsDropEnabled));
    model->appendRow(item);

    item = new QStandardItem(QIcon(":/javascript.png"), "JavaScript");
    item->setFlags(item->flags() ^ (Qt::ItemIsDropEnabled));
    model->appendRow(item);

    ui->listView->setAcceptDrops(true);
    ui->listView->setDragEnabled(true);
    ui->listView->setDefaultDropAction(Qt::MoveAction);

    if (ui->iconBox->isChecked())
        ui->listView->setViewMode(QListView::IconMode);
    else
        ui->listView->setViewMode(QListView::ListMode);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*  Написать класс, который будет вставлять в текст спецсимволы (4–5).
 *  Пригодится для символов, для которых нет клавиши на клавиатуре, но они часто используются в тексте:
 *  © — знак охраны авторского права, ‰ — промилле, ®, € — евро, ₽ — рубль. Например, ввод рубля в программе #@RUB@, или руб.
 *  (автоматически заменить на знак) */

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    int position = 0;
    while (true)
    {
        int a = text.indexOf("#@", position);

        if (a == -1)
            return;

        position = a + 1;

        int b  = text.indexOf('@', a + 2);

        if (b > 0 && b > a)
        {
            QString s = text.mid(a + 2, b - a - 2);

            if (symbols.contains(s))
            {
                QTextCursor cursor = ui->textEdit->textCursor();
                QString symbol = symbols[s];
                text.remove(a, 6);
                text.insert(a + 1, symbol);
                ui->textEdit->setHtml(text);
                ui->textEdit->setTextCursor(cursor);
            }
        }
    }
}

/* Создать список с названиями языков программирования (С++, Python, Java, C#, PHP, JavaScript).
 * Для каждого элемента списка рядом отобразить иконку с логотипом языка программирования.
 * Предусмотреть возможно изменения текста в каждом элементе списка. Добавить возможность перемещения элементов в списке.
 * Создать кнопку для добавления нового языка программирования в список. Иконку для него поставить любую (по-умолчанию).
 * Создать кнопку для удаления элемента из списка (в этом случае элемент должен быть выбран).
 * Создать CheckBox и когда будет стоять галочка, отобразить список в режиме иконок (нужен метод setViewMode()).
 * Когда галочка не стоит, то список должен отображаться в обычном режиме */


void MainWindow::on_addButton_clicked()
{
    model->appendRow(new QStandardItem(QIcon(":/default.png"), "newLang"));
}

void MainWindow::on_delButton_clicked()
{
    QModelIndexList indexes = ui->listView->selectionModel()->selectedRows();
       while (!indexes.isEmpty())
       {
           model->removeRows(indexes.last().row(), 1);
           indexes.removeLast();
       }
}

void MainWindow::on_iconBox_clicked()
{
    if (ui->iconBox->isChecked())
        ui->listView->setViewMode(QListView::IconMode);
    else
        ui->listView->setViewMode(QListView::ListMode);

    ui->listView->setAcceptDrops(true);
    ui->listView->setDragEnabled(true);
    ui->listView->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listView->setDefaultDropAction(Qt::MoveAction);
}
