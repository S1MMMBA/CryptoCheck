
//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//#include <QMainWindow>
//#include <QWidget>
//#include <QPushButton>
//#include <QHBoxLayout>
//#include <QLabel>
//#include <QListWidget>
//#include <QTextEdit>
//#include <QTreeWidget>
//#include<QStackedWidget>
//#include <QMenuBar>
//#include <QToolBar>
//#include <QAction>
//#include <QSettings>
//class MainWindow : public QMainWindow

//{
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();
//private:
//    QHBoxLayout *mainLayout;
//    QWidget *leftWidget;
//    QStackedWidget *stackedWidget;

//};

//#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QTextEdit>
#include <QTreeWidget>
#include<QStackedWidget>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QSettings>
#include<QStyleFactory>
#include <QApplication>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void toggleTheme();

private:
    void applyTheme(bool darkTheme);
    void createActions();
    void createMenu();

    QHBoxLayout *mainLayout;
    QWidget *leftWidget;
    QStackedWidget *stackedWidget;
    QSettings settings;
    QAction *themeAction;
    bool isDarkTheme;
};
#endif // MAINWINDOW_H
