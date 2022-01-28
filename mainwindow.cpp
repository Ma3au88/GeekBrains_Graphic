#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x1->setReadOnly(true);
    ui->x2->setReadOnly(true);
    ui->degreeButton->setChecked(true);
    ui->x2_2->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Написать программу, которая будет находить корень квадратного уравнения второй степени, входные данные: a, b, c.
 * Если нахождение корня невозможно, выводить сообщение в поле результата (или выводить результат в виде комплексного числа).
 * Учитывать, что число a может быть равно нулю*/

void MainWindow::on_resultButton_clicked()
{
    QString a = ui->a_1->text();
    QString b = ui->b_1->text();
    QString c = ui->c_1->text();

    double a1 = a.replace(",",".").toDouble();
    double b1 = b.replace(",",".").toDouble();
    double c1 = c.replace(",",".").toDouble();

    double d =  qPow(b1,2) - 4*a1*c1;
    double x1;
    double x2;

    QString s1;
    QString s2;

    if (d < 0)
    {
        s1 = "Нет корней";
        s2 = "Нет корней";
    }

    else if (a1 == 0.0 && b1 != 0.0)
    {
     x1 = -c1/b1;
     x2 = x1;
     s1 = QString::number(x1);
     s2 = QString::number(x2);
    }

    else if (a1 == 0.0 && b1 == 0.0 && c1 != 0.0)
    {
        s1 = "Нет корней";
        s2 = "Нет корней";
    }

    else if (a1 == 0.0 && b1 == 0.0 && c1 == 0.0)
    {
        s1 = "Любое число";
        s2 = "Любое число";
    }

    else
    {
        x1 = (-b1 + qSqrt(d))/2*a1;
        x2 = (-b1 - qSqrt(d))/2*a1;
        s1 = QString::number(x1);
        s2 = QString::number(x2);
    }

    ui->x1->setText(s1);
    ui->x2->setText(s2);
}

/*Расчет стороны треугольника по двум сторонам и углом между ними. Дополнительно: добавить переключатель из QRadioButton
 * для выбора единиц, в каких указан угол: градусах или радианах*/

void MainWindow::on_resultButton_2_clicked()
{
    QString a = ui->a_2->text();
    QString b = ui->b_2->text();
    QString angle = ui->angle->text();

    angle.replace(",",".");
    a.replace(",",".");
    b.replace(",",".");

    double a1 = a.toDouble();
    double b1 = b.toDouble();
    double angle1 = angle.toDouble();

    bool angle_in_degree = true;

    if (ui->radButton->isChecked())
        angle_in_degree = false;

    QString s1;

    if (angle_in_degree)
        angle1 = qDegreesToRadians(angle1);

    double c = qPow(a1,2)+qPow(b1,2)-2*a1*b1*qCos(angle1);

    if (c > 0)
    {
        c = qSqrt(c);
        s1 = QString::number(c);
    }

    else
        s1 = "Не существует";

    if (qRadiansToDegrees(angle1) >= 180)
        s1 = "Не существует";

    ui->x2_2->setText(s1);
}

/*Создать программу, разместить два виджета QPlainTextEdit. Добавить две кнопки: первая кнопка будет добавлять текст
 *  из одного текстового виджета в другой, вторая кнопка - заменять текст в одном виджете на текст в другом виджете.
 *  Добавить третью кнопку, которая вставляет в один из текстовый виджет текст произвольного html-кода,
 *  например <font color='red'>Hello</font> (используйте метод setHtml(QString) ).*/

void MainWindow::on_addButton_clicked()
{
    QString s = ui->plainTextEdit->toPlainText();
    ui->textEdit->insertHtml(s);
}

void MainWindow::on_replaceButton_clicked()
{
    QString s = ui->plainTextEdit->toPlainText();
    ui->textEdit->setHtml(s);
}

