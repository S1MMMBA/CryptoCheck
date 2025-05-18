#include"AuthCrypt_34_101_77.h"
#include"CommonFunc.h"
#include <iostream>

AuthCrypt_34_101_77::AuthCrypt_34_101_77(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    chooseOperation = new QButtonGroup(this);
    setProtectionRadio = new QRadioButton("установка защиты данных", this);
    setProtectionRadio->setGeometry(10,20,175,30);
    removeProtectionRadio = new QRadioButton("снятие защиты данных", this);
    removeProtectionRadio->setGeometry(190,20,175,30);
    chooseOperation->addButton(setProtectionRadio);
    chooseOperation->addButton(removeProtectionRadio);

    label6 = new QLabel("Укажите l",this);
                        label6->setGeometry(375,20,155,30);
                        numberCombo = new QComboBox(this);
                        numberCombo->setGeometry(435,25,50,20);

                        numberCombo->addItem(QString::number(128));
                        numberCombo->addItem(QString::number(192));
                        numberCombo->addItem(QString::number(256));


        label7 = new QLabel("Укажите d",this);
                     label7->setGeometry(505,20,155,30);
                     numberCombo2 = new QComboBox(this);
                     numberCombo2->setGeometry(575,25,50,20);

                     numberCombo2->addItem(QString::number(1));
                     numberCombo2->addItem(QString::number(2));

    label1 = new QLabel("Введите критическое сообщение",this);
    label1->setGeometry(10, 60, 300, 30);

    fileCriticalDataLabel = new QTextEdit(this);
    fileCriticalDataLabel->setStyleSheet("background-color: white;");
    fileCriticalDataLabel->setVisible(false);
    fileCriticalDataLabel->setGeometry(10,95,600,80);

    openFileCriticalDataButton = new QPushButton("Выбрать файл",this);
    openFileCriticalDataButton->setVisible(false);
    openFileCriticalDataButton->setGeometry(620,95,90,30);

    enterCriticalData = new QTextEdit(this);
    enterCriticalData->setPlaceholderText("Введите данные"); // Подсказка внутри текстового поля
    enterCriticalData->setGeometry(10, 95, 600, 80);        // Увеличьте высоту для многострочного ввода
    enterCriticalData->setWordWrapMode(QTextOption::WrapAnywhere); // Автоматический перенос строк
    enterCriticalData->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // Включите скроллбар enterCriticalData = new QTextEdit(this);


    criticalDataTypeGroup = new QButtonGroup(this);
    criticalDataHexRadio = new QRadioButton("hex", this);
    criticalDataHexRadio->setGeometry(260,60,100,30);
    //criticalDataHexRadio->setChecked(true);
    criticalDataStrRadio = new QRadioButton("text", this);
    criticalDataStrRadio->setGeometry(310,60,100,30);


    criticalDataInputGroup = new QButtonGroup(this);
    fileCriticalDataRadio = new QRadioButton("Из файла", this);
    fileCriticalDataRadio->setGeometry(410,60,100,30);
    manualCriticalDataRadio = new QRadioButton("Вручную", this);
    manualCriticalDataRadio->setGeometry(510,60,100,30);
    criticalDataInputGroup->addButton(fileCriticalDataRadio);
    criticalDataInputGroup->addButton(manualCriticalDataRadio);
//----------------------------------------------------------------------------------------
    // создание поля для ввода открытых данных
    openDataLabel = new QLabel("Введите открытое сообщение",this);
    openDataLabel->setGeometry(10, 185, 300, 30);

    fileOpenDataLabel = new QTextEdit(this);
    fileOpenDataLabel->setStyleSheet("background-color: white;");
    fileOpenDataLabel->setVisible(false);
    fileOpenDataLabel->setGeometry(10,220,600,80);

    openFileOpenDataButton = new QPushButton("Выбрать файл",this);
    openFileOpenDataButton->setVisible(false);
    openFileOpenDataButton->setGeometry(620,220,90,30);

    enterOpenData = new QTextEdit(this);
    enterOpenData->setPlaceholderText("Введите данные"); // Подсказка внутри текстового поля
    enterOpenData->setGeometry(10, 220, 600, 80);        // Увеличьте высоту для многострочного ввода
    enterOpenData->setWordWrapMode(QTextOption::WrapAnywhere); // Автоматический перенос строк
    enterOpenData->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // Включите скроллбар enterCriticalData = new QTextEdit(this);


    openDataTypeGroup = new QButtonGroup(this);
    openDataHexRadio = new QRadioButton("hex", this);
    openDataHexRadio->setGeometry(260,185,100,30);
    openDataHexRadio->setChecked(true);
    openDataStrRadio = new QRadioButton("text", this);
    openDataStrRadio->setGeometry(310,185,100,30);
    openDataTypeGroup->addButton(openDataHexRadio);
    openDataTypeGroup->addButton(openDataStrRadio);

    openDataInputGroup = new QButtonGroup(this);
    fileOpenDataRadio = new QRadioButton("Из файла", this);
    fileOpenDataRadio->setGeometry(410,185,100,30);
    manualOpenDataRadio = new QRadioButton("Вручную", this);
    manualOpenDataRadio->setGeometry(510,185,100,30);
    openDataInputGroup->addButton(fileOpenDataRadio);
    openDataInputGroup->addButton(manualOpenDataRadio);
//---------------------------------------------------------------------------------------------

    label2 = new QLabel("Введите ключ",this);
    label2->setGeometry(10, 305, 90, 30);

    keyInputGroup = new QButtonGroup(this);
    fileKeyRadio = new QRadioButton("Из файла", this);
    fileKeyRadio->setGeometry(410,305,100,30);
    manualKeyRadio = new QRadioButton("Вручную", this);
    manualKeyRadio->setGeometry(510,305,100,30);
    keyInputGroup->addButton(fileKeyRadio);
    keyInputGroup->addButton(manualKeyRadio);

    fileKeyLabel = new QTextEdit(this);
    fileKeyLabel->setStyleSheet("background-color: white;");
    fileKeyLabel->setVisible(false);
    fileKeyLabel->setGeometry(10,340,600,80);

    openFileKeyButton = new QPushButton("Выбрать файл",this);
    openFileKeyButton->setVisible(false);
    openFileKeyButton->setGeometry(620,340,90,30);

    keyInput = new QTextEdit(this);
    keyInput->setPlaceholderText("Введите ключ в hex формате вручную");
    keyInput->setVisible(false);
    keyInput->setGeometry(10,340,600,80);
    keyInput->setWordWrapMode(QTextOption::WrapAnywhere);
    keyInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    label5 = new QLabel("Введите синхропосылку",this);
    label5->setGeometry(10, 440, 140, 30);

    packageInputGroup = new QButtonGroup(this);
    filePackageRadio = new QRadioButton("Из файла", this);
    filePackageRadio->setGeometry(410,440,100,30);
    manualPackageRadio = new QRadioButton("Вручную", this);
    manualPackageRadio->setGeometry(510,440,100,30);
    packageInputGroup->addButton(filePackageRadio);
    packageInputGroup->addButton(manualPackageRadio);

    filePackageLabel = new QTextEdit(this);
    filePackageLabel->setStyleSheet("background-color: white;");
    filePackageLabel->setVisible(false);
    filePackageLabel->setGeometry(10,480,600,80);

    openFilePackageButton = new QPushButton("Выбрать файл",this);
    openFilePackageButton->setVisible(false);
    openFilePackageButton->setGeometry(620,450,90,30);

    packageInput = new QTextEdit(this);
    packageInput->setPlaceholderText("Введите синхропосылку hex формате вручную");
    packageInput->setVisible(false);
    packageInput->setGeometry(10,480,600,80);
    packageInput->setWordWrapMode(QTextOption::WrapAnywhere);
    packageInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

//-----------------------------------------------------------------------------------------
    macLabel = new QLabel("Найденая имитовставка",this);
    macLabel->setGeometry(10, 560, 140, 30);

    macInputGroup = new QButtonGroup(this);
    fileMacRadio = new QRadioButton("Из файла", this);
    fileMacRadio->setGeometry(410,560,100,30);
    manualMacRadio = new QRadioButton("Вручную", this);
    manualMacRadio->setGeometry(510,560,100,30);
    macInputGroup->addButton(fileMacRadio);
    macInputGroup->addButton(manualMacRadio);

    fileMacLabel = new QTextEdit(this);
    fileMacLabel->setStyleSheet("background-color: white;");
    fileMacLabel->setVisible(false);
    fileMacLabel->setGeometry(10,600,600,80);

    openFileMacButton = new QPushButton("Выбрать файл",this);
    openFileMacButton->setVisible(false);
    openFileMacButton->setGeometry(620,570,90,30);

    macInput = new QTextEdit(this);
    macInput->setPlaceholderText("Найденая имитовставка");
    macInput->setVisible(false);
    macInput->setGeometry(10,600,600,80);
    macInput->setWordWrapMode(QTextOption::WrapAnywhere);
    macInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

//----------------------------------------------------------------------------------------


    setProtectionRadio->setChecked(true);
    manualCriticalDataRadio->setChecked(true);
    enterCriticalData->setVisible(true);
    manualOpenDataRadio->setChecked(true);
    enterOpenData->setVisible(true);
    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);
    manualPackageRadio->setChecked(true);
    packageInput->setVisible(true);
//    manualMacRadio->setChecked(true);
//    fileMacRadio->setChecked(false);
    manualMacRadio->setVisible(false);
    //manualMacRadio->setChecked(true);
    fileMacRadio->setVisible(false);
    macInput->setVisible(true);
    macInput->setReadOnly(true);
    criticalDataHexRadio->setChecked(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(400,715,100,30);
    encryptButton = new QPushButton("Найти", this);
    encryptButton->setGeometry(510,715,100,30);

    label4 = new QLabel("Вывод зашифрованного блока",this);
    label4->setGeometry(10, 745, 300, 30);
    OutPutLabel = new QTextEdit(this);
    OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 795, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(setProtectionRadio,&QPushButton::clicked,this,&AuthCrypt_34_101_77::toggleOperation);
    connect(removeProtectionRadio,&QPushButton::clicked,this,&AuthCrypt_34_101_77::toggleOperation);

    connect(openFileCriticalDataButton, &QPushButton::clicked, this, &AuthCrypt_34_101_77::chooseCriticalDataFile);
    connect(fileCriticalDataRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleCriticalDataInput);
    connect(manualCriticalDataRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleCriticalDataInput);

    connect(openFileOpenDataButton, &QPushButton::clicked, this, &AuthCrypt_34_101_77::chooseOpenDataFile);
    connect(fileOpenDataRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleOpenDataInput);
    connect(manualOpenDataRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleOpenDataInput);

    connect(openFileKeyButton, &QPushButton::clicked, this, &AuthCrypt_34_101_77::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleKeyInput);

    connect(resetButton, &QPushButton::clicked, this, &AuthCrypt_34_101_77::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &AuthCrypt_34_101_77::encryptData);

    connect(openFilePackageButton, &QPushButton::clicked, this, &AuthCrypt_34_101_77::choosePackageFile);
    connect(filePackageRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::togglePackageInput);
    connect(manualPackageRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::togglePackageInput);

    connect(openFileMacButton, &QPushButton::clicked, this, &AuthCrypt_34_101_77::chooseMacFile);
    connect(fileMacRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleMacInput);
    connect(manualMacRadio, &QRadioButton::toggled, this, &AuthCrypt_34_101_77::toggleMacInput);
}

void AuthCrypt_34_101_77::chooseCriticalDataFile()
{


    filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    criticalDataString = new QString();
    if (!filePath.isEmpty())
    {
        //fileCriticalDataLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }

        byteCriticalDataArray = file.readAll();
        file.close();

        if(byteCriticalDataArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileCriticalDataLabel->setText(byteCriticalDataArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }

}

void AuthCrypt_34_101_77::chooseOpenDataFile()
{


    filePath = QFileDialog::getOpenFileName(this,
                                            "Выберите файл",
                                            QDir::homePath(),
                                            "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    openDataString = new QString();
    if (!filePath.isEmpty())
    {
        //fileOpenDataLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }

        byteOpenDataArray = file.readAll();
        file.close();

        if(byteOpenDataArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileOpenDataLabel->setText(byteOpenDataArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }

}

void AuthCrypt_34_101_77::chooseKeyFile()
{


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    if (!filePath.isEmpty())
    {
        //fileKeyLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }


        byteKeyArray = file.readAll();
        file.close();

        if(byteKeyArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileKeyLabel->setText(byteKeyArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }
}

void AuthCrypt_34_101_77::choosePackageFile()
{


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    if (!filePath.isEmpty())
    {
        //filePackageLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }


        bytePackageArray = file.readAll();
        file.close();

        if(bytePackageArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        filePackageLabel->setText(bytePackageArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Синхропосылка из файла успешно загружена.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите синхропосылку для шифрования.");
        return;
    }
}

void AuthCrypt_34_101_77::chooseMacFile()
{


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    if (!filePath.isEmpty())
    {
        //fileMacLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }


        byteMacArray = file.readAll();
        file.close();

        if(byteMacArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileMacLabel->setText(byteMacArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Имитовствка из файла успешно загружена.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите имитовствку для шифрования.");
        return;
    }
}

void AuthCrypt_34_101_77::toggleCriticalDataInput()
{
    bool isFileDataSelected = fileCriticalDataRadio->isChecked();

    fileCriticalDataLabel->setVisible(isFileDataSelected);
    openFileCriticalDataButton->setVisible(isFileDataSelected);
    enterCriticalData->setVisible(!isFileDataSelected);
    criticalDataHexRadio->setVisible(!isFileDataSelected);
    criticalDataStrRadio->setVisible(!isFileDataSelected);
}
void AuthCrypt_34_101_77::toggleOpenDataInput()
{
    bool isFileDataSelected = fileOpenDataRadio->isChecked();

    fileOpenDataLabel->setVisible(isFileDataSelected);
    openFileOpenDataButton->setVisible(isFileDataSelected);
    enterOpenData->setVisible(!isFileDataSelected);
    openDataHexRadio->setVisible(!isFileDataSelected);
    openDataStrRadio->setVisible(!isFileDataSelected);
}
void AuthCrypt_34_101_77::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void AuthCrypt_34_101_77::togglePackageInput()
{
    bool isFilePackageSelected = filePackageRadio->isChecked();

    filePackageLabel->setVisible(isFilePackageSelected);
    openFilePackageButton->setVisible(isFilePackageSelected);
    packageInput->setVisible(!isFilePackageSelected);
}
void AuthCrypt_34_101_77::toggleMacInput()
{
    bool isFileMacSelected = fileMacRadio->isChecked();

    fileMacLabel->setVisible(isFileMacSelected);
    openFileMacButton->setVisible(isFileMacSelected);
    macInput->setVisible(!isFileMacSelected);

}
void AuthCrypt_34_101_77::toggleOperation()
{
    bool isSetSelected = setProtectionRadio->isChecked();
    if(isSetSelected)
        macInput->setPlaceholderText("Найденая имитовставка");
    else
        macInput->setPlaceholderText("Введите имитовставку длиной 8 байт");
    macInput->setVisible(isSetSelected);
    fileMacLabel->setVisible(!isSetSelected);
    fileMacRadio->setVisible(!isSetSelected);
    manualMacRadio->setVisible(!isSetSelected);
    macInput->setReadOnly(isSetSelected);

}
void AuthCrypt_34_101_77::resetForm()
{

    enterCriticalData->clear();
    enterOpenData->clear();
    keyInput->clear();
    packageInput->clear();
    macInput->clear();
    fileKeyLabel->clear();
    fileCriticalDataLabel->clear();
    fileOpenDataLabel->clear();
    filePackageLabel->clear();
    fileMacLabel->clear();
    OutPutLabel->clear();
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);
    fileCriticalDataRadio->setChecked(false);
    manualCriticalDataRadio->setChecked(true);
    fileOpenDataRadio->setChecked(false);
    manualOpenDataRadio->setChecked(true);
    filePackageRadio->setChecked(false);
    manualPackageRadio->setChecked(true);
    fileMacRadio->setChecked(false);
    manualMacRadio->setChecked(true);
    criticalDataString->clear();
    openDataString->clear();
    keyString->clear();
//    if(!keyString->isEmpty())
//    *keyString = "";
    byteCriticalDataArray.clear();
    byteOpenDataArray.clear();
    byteKeyArray.clear();
    bytePackageArray.clear();
    byteMacArray.clear();
    toggleKeyInput();
    toggleCriticalDataInput();
    toggleOpenDataInput();
    togglePackageInput();
}

void AuthCrypt_34_101_77::encryptData()
{
    l = static_cast<size_t>(numberCombo->currentText().toULongLong());
    d = static_cast<size_t>(numberCombo2->currentText().toULongLong());
    QString openData;
    QString criticalData;
    QString keyStr;
    QString packStr;
    size_t criticalDataSizeBytes = 0;
    size_t openDataSizeBytes = 0;
    size_t packSizeBytes = 0;
    size_t keySizeBytes = 0;
    size_t macSizeBytes = 0;
    uint8_t* criticalblock;

    uint8_t* openblock; // убрал тут const!!!
    uint8_t* key;
    uint8_t title[480];

    uint8_t* mac = new uint8_t[l/8]();
    uint8_t* result = new uint8_t[l/8]();
    uint8_t state[1024];
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };

    if(manualCriticalDataRadio->isChecked())
    {
        criticalData = enterCriticalData->toPlainText();
        criticalData = criticalData.simplified().remove(' ');
        if(criticalDataHexRadio->isChecked())
        {
            if (!criticalData.isEmpty() && !isHexFormat(criticalData)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
            criticalDataSizeBytes = criticalData.size()/2;
            //criticalblock = new uint8_t[criticalDataSizeBytes]();
            byteCriticalDataArray = QByteArray::fromHex(criticalData.toUtf8());
            //criticalblock = reinterpret_cast<uint8_t*>(const_cast<char*>(byteCriticalDataArray.constData()));
            criticalblock = new uint8_t[criticalDataSizeBytes]();
            memcpy(criticalblock, byteCriticalDataArray.constData(),criticalDataSizeBytes);
        }
        if(criticalDataStrRadio->isChecked())
        {
            byteCriticalDataArray = criticalData.toUtf8();
            criticalDataSizeBytes = byteCriticalDataArray.size();
            criticalblock = new uint8_t[criticalDataSizeBytes]();
           memcpy(criticalblock, byteCriticalDataArray.constData(),criticalDataSizeBytes);
        }
    }

    if(fileCriticalDataRadio->isChecked())
    {
        criticalDataSizeBytes = byteCriticalDataArray.size();
        criticalblock = new uint8_t[criticalDataSizeBytes]();
        memcpy(criticalblock, byteCriticalDataArray.constData(),criticalDataSizeBytes);
        //criticalblock = reinterpret_cast<uint8_t*>(const_cast<char*>(byteCriticalDataArray.constData()));
    }
//-----------------------------------------------------------------------------------------------------------------------------------------------
    //ОБРАБАТЫВАЕМ ОТКРЫТОЕ СООБЩЕНИЕ
    if(manualOpenDataRadio->isChecked())
    {
        openData = enterOpenData->toPlainText();
        openData = openData.simplified().remove(' ');
        if(openDataHexRadio->isChecked())
        {
                if (!openData.isEmpty() && !isHexFormat(openData)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
                openDataSizeBytes = openData.size()/2;
                openblock = new uint8_t[openDataSizeBytes]();
                if (!hexStringToByteArray(openData, (uint8_t*)openblock,openDataSizeBytes))
                {
                    QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать строку в массив байт.");
                    return;
                }
        }
        if(openDataStrRadio->isChecked())
        {
                byteOpenDataArray = openData.toUtf8();
                openDataSizeBytes = byteOpenDataArray.size();
                openblock = new uint8_t[openDataSizeBytes]();
                //openblock = reinterpret_cast<const uint8_t*>(byteOpenDataArray.constData());
                memcpy(openblock, byteOpenDataArray.constData(),openDataSizeBytes);
        }
    }

    if(fileOpenDataRadio->isChecked())
    {
        openDataSizeBytes = byteOpenDataArray.size();
        openblock = new uint8_t[openDataSizeBytes]();
        memcpy(openblock, byteOpenDataArray.constData(),openDataSizeBytes);
        //openblock = reinterpret_cast<const uint8_t*>(byteOpenDataArray.constData());
    }



//------------------------------------------------------------------------------------------------------------------------------------------------
    //package == title == ананонс
    if(manualPackageRadio->isChecked())
    {
        packStr = packageInput->toPlainText();
        packStr = packStr.simplified().remove(' ');
        packSizeBytes = packStr.size()/2;
        //title = new uint8_t[packSizeBytes]();
        std::fill(title, title + 480, 0);
        if(packSizeBytes > 480)
        {
                QMessageBox::warning(this, "Ошибка", "Анонс должен быть менее 480 байт.");
                return;
        }

        if (!packStr.isEmpty() && !isHexFormat(packStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

        if (!hexStringToByteArray(packStr, (uint8_t*)title,packSizeBytes))
        {
                QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать в массив байт");
                return;
        }
    }

    if(filePackageRadio->isChecked())
    {
        if(bytePackageArray.size() > 480)
        {
                QMessageBox::warning(this, "Ошибка", "Анонс должен быть менее 480 байт.");
                return;
        }
        packSizeBytes = bytePackageArray.size();
        std::memcpy(title, bytePackageArray.constData(),packSizeBytes);
    }
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->toPlainText();
        keyStr = keyStr.simplified().remove(' ');
        keySizeBytes = keyStr.size()/2;
        key = new uint8_t[keySizeBytes]();
        if(keySizeBytes > 480)
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен быть не более 480 байт.");
            return;
        }
        if (!keyStr.isEmpty() && !isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(keyStr, (uint8_t*)key,keySizeBytes))
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен не более 480 байт.");
            return;
        }

    }

    if(fileKeyRadio->isChecked())
    {
        if(byteKeyArray.size() > 480)
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен быть не более 480 байт.");
            return;
        }
        keySizeBytes = byteKeyArray.size();
        key = new uint8_t[keySizeBytes]();
        std::memcpy(key, byteKeyArray.constData(),keySizeBytes);
    }
    if(setProtectionRadio->isChecked())
    {
        //criticalDataSizeBytes = 192;
        bashPrgStart(state,l,d,title,packSizeBytes,key,keySizeBytes);
        bashPrgAbsorb(openblock,openDataSizeBytes,state);
        bashPrgEncr(criticalblock,criticalDataSizeBytes,state);
        bashPrgSqueeze(result,l/8,state);
        QString output = printByteArray(criticalblock,criticalDataSizeBytes);
        QString foundMac = printByteArray(result,l/8);
        OutPutLabel->setText(output);
        macInput->setText(foundMac);
    }
    if(removeProtectionRadio->isChecked())
    {
        if(manualMacRadio->isChecked())
        {
            macStr = macInput->toPlainText();
            macStr = macStr.simplified().remove(' ');
            macSizeBytes = macStr.size()/2;
            if (!isHexFormat(macStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
            hexStringToByteArray(macStr, (uint8_t*)mac,macSizeBytes);
        }

        if(fileMacRadio->isChecked())
        {
            if(byteMacArray.size() != l/8)
            {
                    QMessageBox::warning(this, "Ошибка", "Имитовставка должна быть ровно 8 байт.");
                    return;
            }
            std::memcpy(mac, byteMacArray.constData(), byteMacArray.size());
        }

        for(int i = 0;i<criticalDataSizeBytes;i++)
        {
            qDebug() << QString::number(criticalblock[i], 16);

        }
        bashPrgStart(state,l,d,title,packSizeBytes,key,keySizeBytes);
        bashPrgAbsorb(openblock,openDataSizeBytes,state);
        bashPrgDecr(criticalblock,criticalDataSizeBytes,state);
        bashPrgSqueeze(result,l/8,state);
        bool check = true;
        for(int i = 0;i<macSizeBytes;i++)
        {
            if(mac[i] != result[i])
            {
                    OutPutLabel->setText("Несовпадение имитовставок");
                    check = false;
            }
        }
        if(check)
        {
            QString output = printByteArray(criticalblock,criticalDataSizeBytes);
            OutPutLabel->setText(output);

        }
    }

    if(fileCriticalDataRadio->isChecked())
    {
        QFileInfo inputFileInfo(filePath);
        QString name = inputFileInfo.completeBaseName();
        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_decrypted.bin";
        QFile outputFile(outputFilePath);

        // Сохраняем в бинарном формате
        if (outputFile.open(QIODevice::WriteOnly))
        {
            outputFile.write(reinterpret_cast<const char*>(criticalblock),criticalDataSizeBytes);
            outputFile.close();
            QMessageBox::information(this, "Шифрование", "Расшифрованые данные успешно сохранены в файл: " + outputFilePath);
        } else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить расшифрованые данные в файл!");
        }
    }

    //OutPutLabel->setText("выполнено");
}
