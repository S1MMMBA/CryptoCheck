
#include "mainwindow.h"
#include "BlockCrypt.h"
#include "DataCrypt.h"
#include "DataCryptCBC.h"
#include "DataCryptCFB.h"
#include "DataCryptCTR.h"
#include "ProduceMAC.h"
#include "InstallMAC.h"
#include "InstallKeyMAC.h"
#include "Hash.h"
#include "DiskCrypt.h"
#include "DiskCrypt2.h"
#include "SaveFormatCrypt.h"
#include "ExpandKey.h"
#include "ModifyKey.h"
#include "Hash_34_101_77.h"
#include"HashProg_34_101_77.h"
#include"AuthCrypt_34_101_77.h"
#include"ProduceMAC_HMAC_47.h"
#include"RandomGenCTR_47.h"
#include"RandomGenHMAC_47.h"
#include"GenPassHOTP.h"
#include"GenPassTOTP.h"
#include"GenPassOCRA.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), settings("MyCompany", "MyApp")
{
    isDarkTheme = settings.value("darkTheme", false).toBool();

    setFixedSize(1000, 900);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    createMenu();//+
    createActions();//+

    mainLayout = new QHBoxLayout(centralWidget);

    QTreeWidget *treeWidget = new QTreeWidget;
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabels({"Стандарты"});

    // Добавление подэлементов
    QTreeWidgetItem *standart_1 = new QTreeWidgetItem(treeWidget);
    standart_1->setText(0, "СТБ 34.101.31");
        QTreeWidgetItem *standart_1_1 = new QTreeWidgetItem(standart_1);
        standart_1_1->setText(0, "Шифрование блока");
        QTreeWidgetItem *standart_1_2 = new QTreeWidgetItem(standart_1);
        standart_1_2->setText(0, "Шифрование данных");
            QTreeWidgetItem *standart_1_2_1 = new QTreeWidgetItem(standart_1_2);
            standart_1_2_1->setText(0, "Простая замена (7.1)");
            QTreeWidgetItem *standart_1_2_2 = new QTreeWidgetItem(standart_1_2);
            standart_1_2_2->setText(0, "Сцепление блоков (7.2)");
            QTreeWidgetItem *standart_1_2_3 = new QTreeWidgetItem(standart_1_2);
            standart_1_2_3->setText(0, "Гаммирование с обратной связью (7.3)");
            QTreeWidgetItem *standart_1_2_4 = new QTreeWidgetItem(standart_1_2);
            standart_1_2_4->setText(0, "Счетчик (7.4)");
        QTreeWidgetItem *standart_1_3 = new QTreeWidgetItem(standart_1);
        standart_1_3->setText(0, "Выборка имитовставки");
        QTreeWidgetItem *standart_1_4 = new QTreeWidgetItem(standart_1);
        standart_1_4->setText(0, "Аутентифицированное шифрование данных");
        QTreeWidgetItem *standart_1_5 = new QTreeWidgetItem(standart_1);
        standart_1_5->setText(0, "Шифрование и имитозащита ключа");
        QTreeWidgetItem *standart_1_6 = new QTreeWidgetItem(standart_1);
        standart_1_6->setText(0, "Хэширование");
        QTreeWidgetItem *standart_1_7 = new QTreeWidgetItem(standart_1);
        standart_1_7->setText(0, "Блоковое дисковое шифрование");
        QTreeWidgetItem *standart_1_8 = new QTreeWidgetItem(standart_1);
        standart_1_8->setText(0, "Секторное дисковое шифрование");
        QTreeWidgetItem *standart_1_9 = new QTreeWidgetItem(standart_1);
        standart_1_9->setText(0, "Шифрование с сохранением формата");
        QTreeWidgetItem *standart_1_10 = new QTreeWidgetItem(standart_1);
        standart_1_10->setText(0, "Расширение ключа");
        QTreeWidgetItem *standart_1_11 = new QTreeWidgetItem(standart_1);
        standart_1_11->setText(0, "Преобразование ключа");


        QTreeWidgetItem *standart_3 = new QTreeWidgetItem(treeWidget);
        standart_3->setText(0, "СТБ 34.101.47");
        QTreeWidgetItem *standart_3_1 = new QTreeWidgetItem(standart_3);
        standart_3_1->setText(0, "Выработка имитовставки (HMAC)");
        QTreeWidgetItem *standart_3_2 = new QTreeWidgetItem(standart_3);
        standart_3_2->setText(0, "Ген. псевдослуч. чисел (счетчик)");
        QTreeWidgetItem *standart_3_3 = new QTreeWidgetItem(standart_3);
        standart_3_3->setText(0, "Ген. псевдослуч. чисел (HMAC)");
        QTreeWidgetItem *standart_3_4 = new QTreeWidgetItem(standart_3);
        standart_3_4->setText(0, "Ген. одноразовых паролей (HOTP)");
        QTreeWidgetItem *standart_3_5 = new QTreeWidgetItem(standart_3);
        standart_3_5->setText(0, "Ген. одноразовых паролей (TOTP)");
        QTreeWidgetItem *standart_3_6 = new QTreeWidgetItem(standart_3);
        standart_3_6->setText(0, "Ген. одноразовых паролей (OCRA)");


    QTreeWidgetItem *standart_2 = new QTreeWidgetItem(treeWidget);
    standart_2->setText(0, "СТБ 34.101.77");
        QTreeWidgetItem *standart_2_1 = new QTreeWidgetItem(standart_2);
        standart_2_1->setText(0, "Хэширование");
        QTreeWidgetItem *standart_2_2 = new QTreeWidgetItem(standart_2);
        standart_2_2->setText(0, "Хэширование (программируемые алгоритмы)");
        QTreeWidgetItem *standart_2_3 = new QTreeWidgetItem(standart_2);
        standart_2_3->setText(0, "Аутентифицированное шифрование");





    stackedWidget = new QStackedWidget();
    BlockCrypt * BlockCryptWidget = new BlockCrypt();
    DataCrypt * DataCryptWidget = new DataCrypt();
    DataCryptCBC * DataCryptCBCWidget = new DataCryptCBC();
    DataCryptCFB * DataCryptCFBWidget = new DataCryptCFB();
    DataCryptCTR * DataCryptCTRWidget = new DataCryptCTR();
    ProduceMAC * ProduceMACWidget = new ProduceMAC();
    InstallMAC * InstallMACWidget = new InstallMAC();
    InstallKeyMAC * InstallKeyMACWidget = new InstallKeyMAC();
    Hash * HashWidget = new Hash();
    DiskCrypt * DiskCryptWidget = new DiskCrypt();
    DiskCrypt2 * DiskCryptWidget2 = new DiskCrypt2();
    SaveFormatCrypt * SaveFormatWidget = new SaveFormatCrypt();
    ExpandKey * ExpandKeyWidget = new ExpandKey();
    ModifyKey * ModifyKeyWidget = new ModifyKey();
    Hash_34_101_77 * Hash_34_101_77_Widget = new Hash_34_101_77();
    HashProg_34_101_77 * HashProgWidget = new HashProg_34_101_77();
    AuthCrypt_34_101_77 * AuthCryptWidget = new AuthCrypt_34_101_77();
    ProduceMAC_HMAC_47 * ProduceMAC_HMAC_47_Widget = new ProduceMAC_HMAC_47();
    RandomGenCTR_47 * RandomGenCTR_47_Widget = new RandomGenCTR_47();
    RandomGenHMAC_47 * RandomGenHMAC_47_Widget = new RandomGenHMAC_47();
    GenPassHOTP * GenPassHOTPWidget = new GenPassHOTP();
    GenPassTOTP * GenPassTOTPWidget = new GenPassTOTP();
    GenPassOCRA * GenPassOCRAWidget = new GenPassOCRA();


    QLabel *label = new QLabel("Для начала работы выберите необходимый стандарт в меню \"Стандарты\"");
    label->setStyleSheet("font-weight: bold;");
    label->setStyleSheet("font-size: 16pt;");
    label->setAlignment(Qt::AlignCenter);


    stackedWidget->addWidget(label);
    stackedWidget->addWidget(BlockCryptWidget);
    stackedWidget->addWidget(DataCryptWidget);
    stackedWidget->addWidget(DataCryptCBCWidget);
    stackedWidget->addWidget(DataCryptCFBWidget);
    stackedWidget->addWidget(DataCryptCTRWidget);
    stackedWidget->addWidget(ProduceMACWidget);
    stackedWidget->addWidget(InstallMACWidget);
    stackedWidget->addWidget(InstallKeyMACWidget);
    stackedWidget->addWidget(InstallKeyMACWidget);
    stackedWidget->addWidget(HashWidget);
    stackedWidget->addWidget(DiskCryptWidget);
    stackedWidget->addWidget(DiskCryptWidget2);
    stackedWidget->addWidget(SaveFormatWidget);
    stackedWidget->addWidget(ExpandKeyWidget);
    stackedWidget->addWidget(ModifyKeyWidget);
    stackedWidget->addWidget(Hash_34_101_77_Widget);
    stackedWidget->addWidget(HashProgWidget);
    stackedWidget->addWidget(AuthCryptWidget);
    stackedWidget->addWidget(ProduceMAC_HMAC_47_Widget);
    stackedWidget->addWidget(RandomGenCTR_47_Widget);
    stackedWidget->addWidget(RandomGenHMAC_47_Widget);
    stackedWidget->addWidget(GenPassHOTPWidget);
    stackedWidget->addWidget(GenPassTOTPWidget);
    stackedWidget->addWidget(GenPassOCRAWidget);

    mainLayout->addWidget(treeWidget);
    mainLayout->addWidget(stackedWidget);


    // Настраиваем растяжение (левый столбец меньше, правый больше)
    mainLayout->setStretch(0, 1);
    mainLayout->setStretch(1, 3);


    connect(treeWidget, &QTreeWidget::itemClicked, this,
            [this,standart_1_1, standart_1_2_1,standart_1_2_2,standart_1_2_3,standart_1_2_4, standart_1_3, standart_1_4, standart_1_5, standart_1_6, standart_1_7,standart_1_8,standart_1_9,standart_1_10,standart_1_11
                ,standart_2_1,standart_2_2,standart_2_3
                ,standart_3_1,standart_3_2,standart_3_3,standart_3_4,standart_3_5,standart_3_6](QTreeWidgetItem *item, int column)
            {
                if (item == standart_1_1) {
                    stackedWidget->setCurrentIndex(1); // Переход к виджету BlockCryptWidget
                } else if (item == standart_1_2_1) {
                    stackedWidget->setCurrentIndex(2); // Переход к виджету DataCryptWidget ECB
                } else if (item == standart_1_2_2) {
                    stackedWidget->setCurrentIndex(3); //  виджет CBC
                } else if (item == standart_1_2_3) {
                    stackedWidget->setCurrentIndex(4); // виджет CFB
                }else if (item == standart_1_2_4) {
                    stackedWidget->setCurrentIndex(5); // виджет CTR
                }else if (item == standart_1_3) {
                    stackedWidget->setCurrentIndex(6); // Выработка MAC вставки
                }else if (item == standart_1_4) {
                    stackedWidget->setCurrentIndex(7); // Применение MAC вставки
                }else if (item == standart_1_5){
                    stackedWidget->setCurrentIndex(8); // Применение MAC вставки ключа
                }else if (item == standart_1_6){
                    stackedWidget->setCurrentIndex(9); // Хэширование
                }else if (item == standart_1_7){
                    stackedWidget->setCurrentIndex(10); // Блоковое дисковое шифрование
                    }else if (item == standart_1_8){
                    stackedWidget->setCurrentIndex(11); // Секторное дисковое шифрование
                }else if (item == standart_1_9){
                    stackedWidget->setCurrentIndex(12); // Шифрование с сохранением формата
                    }else if (item == standart_1_10){
                    stackedWidget->setCurrentIndex(13); // Расширение ключа
                }else if (item == standart_1_11){
                    stackedWidget->setCurrentIndex(14); // Преобразование ключа
                    }
                // 34.101.77
                 else if (item == standart_2_1){
                    stackedWidget->setCurrentIndex(15); // Хэширование
                }else if (item == standart_2_2){
                    stackedWidget->setCurrentIndex(16); // Программируемое хэширование
                    }else if (item == standart_2_3){
                    stackedWidget->setCurrentIndex(17); // Аутентифицированное шифрование
                }
                // 34.101.47
                    else if (item == standart_3_1){
                    stackedWidget->setCurrentIndex(18); // Выработка MAC вставки HMAC
                    }else if (item == standart_3_2){
                    stackedWidget->setCurrentIndex(19); //  Генерация псевдослучайных чисел в режиме счетчика
                    }else if (item == standart_3_3){
                    stackedWidget->setCurrentIndex(20); //  Генерация псевдослучайных чисел HMAC
                    }else if (item == standart_3_4){
                    stackedWidget->setCurrentIndex(21); //  Выработка одноразового пароля HOTP
                    }else if (item == standart_3_5){
                    stackedWidget->setCurrentIndex(22); //  Выработка одноразового пароля TOTP
                    }else if (item == standart_3_6){
                    stackedWidget->setCurrentIndex(23); //  Выработка одноразового пароля OCRA
                    }
            });

    applyTheme(isDarkTheme);
}
void MainWindow::createMenu()
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *viewMenu = menuBar->addMenu("Вид");
    themeAction = new QAction("Темная тема", this);
    themeAction->setCheckable(true);
    themeAction->setChecked(isDarkTheme);
    viewMenu->addAction(themeAction);
    setMenuBar(menuBar);
}

void MainWindow::createActions()
{
    connect(themeAction, &QAction::toggled, this, &MainWindow::toggleTheme);
}

void MainWindow::toggleTheme()
{
    isDarkTheme = !isDarkTheme;
    settings.setValue("darkTheme", isDarkTheme);
    applyTheme(isDarkTheme);
}

void MainWindow::applyTheme(bool darkTheme)
{
    QPalette palette;
    if(darkTheme) {
        // Настройка темной палитры
        palette.setColor(QPalette::Window, QColor(53,53,53));
        palette.setColor(QPalette::WindowText, Qt::white);
        palette.setColor(QPalette::Base, QColor(35,35,35));
        palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
        palette.setColor(QPalette::ToolTipBase, Qt::white);
        palette.setColor(QPalette::ToolTipText, Qt::white);
        palette.setColor(QPalette::Text, Qt::white);
        palette.setColor(QPalette::Button, QColor(53,53,53));
        palette.setColor(QPalette::ButtonText, Qt::white);
        palette.setColor(QPalette::BrightText, Qt::red);
        palette.setColor(QPalette::Highlight, QColor(142,45,197));
        palette.setColor(QPalette::HighlightedText, Qt::black);

        qApp->setStyle(QStyleFactory::create("Fusion"));
    } else {
        // Сброс к стандартной светлой теме
        qApp->setStyle(QStyleFactory::create("Fusion"));
        palette = qApp->style()->standardPalette();
    }
    qApp->setPalette(palette);

    // Обновление стиля всех виджетов
    qApp->style()->polish(qApp);
}

MainWindow::~MainWindow()
{
}


