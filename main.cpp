#include "mainwindow.h"

#include <QApplication>
#include <QResource>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("./QtLanguage_en_US" + QLocale::system().name());
    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
