
#include "mainwindow.h"
//#include "bee2/crypto/belt.h"
#include <QApplication>
#include <QStyleFactory>
#include<iostream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

     a.setStyle("Fusion"); // Базовый стиль



    MainWindow w;
    w.show();
    return a.exec();
}
