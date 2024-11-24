
#include "mainwindow.h"
#include "BlockCrypt.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(1000, 900);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QHBoxLayout(centralWidget);

    //leftWidget = new QWidget();
    //QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);

    QTreeWidget *treeWidget = new QTreeWidget;
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabels({"Стандарты"});

    // Добавление подэлементов
    QTreeWidgetItem *standart_1 = new QTreeWidgetItem(treeWidget);
    standart_1->setText(0, "СТБ 34.101.31");
        QTreeWidgetItem *standart_1_1 = new QTreeWidgetItem(standart_1);
        standart_1_1->setText(0, "шифрование блока");
        QTreeWidgetItem *standart_1_2 = new QTreeWidgetItem(standart_1);
        standart_1_2->setText(0, "шифрование данных");
        QTreeWidgetItem *standart_1_3 = new QTreeWidgetItem(standart_1);
        standart_1_3->setText(0, "выборка имитовставки");
        QTreeWidgetItem *standart_1_4 = new QTreeWidgetItem(standart_1);
        standart_1_4->setText(0, "шифрование и имитозащита данных");
        QTreeWidgetItem *standart_1_5 = new QTreeWidgetItem(standart_1);
        standart_1_5->setText(0, "шифрование и имитозащита ключа");
        QTreeWidgetItem *standart_1_6 = new QTreeWidgetItem(standart_1);
        standart_1_6->setText(0, "хеширование");
        QTreeWidgetItem *standart_1_7 = new QTreeWidgetItem(standart_1);
        standart_1_7->setText(0, "расширение/преобразование ключа");
    QTreeWidgetItem *standart_2 = new QTreeWidgetItem(treeWidget);
    standart_2->setText(0, "СТБ 34.101.77");
    QTreeWidgetItem *standart_3 = new QTreeWidgetItem(treeWidget);
    standart_3->setText(0, "СТБ 34.101.45");

    //leftLayout->addWidget(treeWidget);


    stackedWidget = new QStackedWidget();
    BlockCrypt * BlockCryptWidget = new BlockCrypt();

    stackedWidget->addWidget(new QLabel("Выберите элемент из дерева."));
    stackedWidget->addWidget(BlockCryptWidget);

    stackedWidget->setCurrentIndex(0);


    mainLayout->addWidget(treeWidget);
    mainLayout->addWidget(stackedWidget);


    // Настраиваем растяжение (левый столбец меньше, правый больше)
    mainLayout->setStretch(0, 1);
    mainLayout->setStretch(1, 3);


    connect(treeWidget, &QTreeWidget::itemClicked, this,
            [this,standart_1_1, standart_1_2, standart_1_3, standart_1_4, standart_1_5, standart_1_6, standart_1_7](QTreeWidgetItem *item, int column)
            {
                if (item == standart_1_1) {
                    stackedWidget->setCurrentIndex(1); // Переход к виджету BlockCryptWidget
                } else if (item == standart_1_2) {
                    stackedWidget->setCurrentIndex(2); // Другой виджет
                } else if (item == standart_1_3) {
                    stackedWidget->setCurrentIndex(3); // Ещё один виджет
                } else {
                    stackedWidget->setCurrentIndex(0); // По умолчанию
                }
            });

}

MainWindow::~MainWindow()
{
}


