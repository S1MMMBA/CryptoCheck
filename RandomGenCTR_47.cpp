#include"RandomGenCTR_47.h"
#include"CommonFunc.h"

RandomGenCTR_47::RandomGenCTR_47(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
//    chooseOperation = new QButtonGroup(this);
//    setProtectionRadio = new QRadioButton("установка защиты ключа", this);
//    setProtectionRadio->setGeometry(10,20,175,30);
//    removeProtectionRadio = new QRadioButton("снятие защиты ключа", this);
//    removeProtectionRadio->setGeometry(190,20,175,30);
//    chooseOperation->addButton(setProtectionRadio);
//    chooseOperation->addButton(removeProtectionRadio);

    label6 = new QLabel("Укажите n",this);
    label6->setGeometry(10,20,155,30);
    numberCombo = new QComboBox(this);
    numberCombo->setGeometry(70,25,50,20);
    for(int i = 0; i < 1000; i++)
    {
     numberCombo->addItem(QString::number(i));
    }





    label1 = new QLabel("Введите доп. входное слово (X)",this);
    label1->setGeometry(10, 60, 300, 30);

    fileCriticalDataLabel = new QTextEdit(this);
    //fileCriticalDataLabel->setStyleSheet("background-color: white;");
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
    manualCriticalDataRadio->setChecked(true);
    criticalDataInputGroup->addButton(fileCriticalDataRadio);
    criticalDataInputGroup->addButton(manualCriticalDataRadio);
//----------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------

    label2 = new QLabel("Введите ключ (K)",this);
    label2->setGeometry(10, 305, 120, 30);

    keyInputGroup = new QButtonGroup(this);
    fileKeyRadio = new QRadioButton("Из файла", this);
    fileKeyRadio->setGeometry(410,305,100,30);
    manualKeyRadio = new QRadioButton("Вручную", this);
    manualKeyRadio->setGeometry(510,305,100,30);
    keyInputGroup->addButton(fileKeyRadio);
    keyInputGroup->addButton(manualKeyRadio);

    fileKeyLabel = new QTextEdit(this);
    //fileKeyLabel->setStyleSheet("background-color: white;");
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
    label5->setGeometry(10, 185, 140, 30);

    titleInputGroup = new QButtonGroup(this);
    fileTitleRadio = new QRadioButton("Из файла", this);
    fileTitleRadio->setGeometry(410,185,100,30);
    manualTitleRadio = new QRadioButton("Вручную", this);
    manualTitleRadio->setGeometry(510,185,100,30);
    titleInputGroup->addButton(fileTitleRadio);
    titleInputGroup->addButton(manualTitleRadio);

    fileTitleLabel = new QTextEdit(this);
    //fileTitleLabel->setStyleSheet("background-color: white;");
    fileTitleLabel->setVisible(false);
    fileTitleLabel->setGeometry(10,220,600,80);

    openFileTitleButton = new QPushButton("Выбрать файл",this);
    openFileTitleButton->setVisible(false);
    openFileTitleButton->setGeometry(620,220,90,30);

    titleInput = new QTextEdit(this);
    titleInput->setPlaceholderText("Введите синхропосылку в hex формате вручную");
    titleInput->setVisible(false);
    titleInput->setGeometry(10,220,600,80);
    titleInput->setWordWrapMode(QTextOption::WrapAnywhere);
    titleInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

//-----------------------------------------------------------------------------------------


//    setProtectionRadio->setChecked(true);
//    manualCriticalDataRadio->setChecked(true);
    enterCriticalData->setVisible(true);

    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);
    manualTitleRadio->setChecked(true);
    titleInput->setVisible(true);
    criticalDataHexRadio->setChecked(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(400,450,100,30);
    encryptButton = new QPushButton("Найти", this);
    encryptButton->setGeometry(510,450,100,30);

    label4 = new QLabel("Псевдослучайные числа:",this);
    label4->setGeometry(10, 480, 300, 30);
    OutPutLabel = new QTextEdit(this);
    //OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 520, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);



    connect(openFileCriticalDataButton, &QPushButton::clicked, this, &RandomGenCTR_47::chooseCriticalDataFile);
    connect(fileCriticalDataRadio, &QRadioButton::toggled, this, &RandomGenCTR_47::toggleCriticalDataInput);
    connect(manualCriticalDataRadio, &QRadioButton::toggled, this, &RandomGenCTR_47::toggleCriticalDataInput);


    connect(openFileKeyButton, &QPushButton::clicked, this, &RandomGenCTR_47::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &RandomGenCTR_47::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &RandomGenCTR_47::toggleKeyInput);

    connect(resetButton, &QPushButton::clicked, this, &RandomGenCTR_47::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &RandomGenCTR_47::encryptData);

    connect(openFileTitleButton, &QPushButton::clicked, this, &RandomGenCTR_47::chooseTitleFile);
    connect(fileTitleRadio, &QRadioButton::toggled, this, &RandomGenCTR_47::toggleTitleInput);
    connect(manualTitleRadio, &QRadioButton::toggled, this, &RandomGenCTR_47::toggleTitleInput);
}

void RandomGenCTR_47::chooseCriticalDataFile()
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
        QMessageBox::warning(this, "Ошибка", "Введите данные.");
        return;
    }

}


void RandomGenCTR_47::chooseKeyFile()
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
        QMessageBox::warning(this, "Ошибка", "Введите данные.");
        return;
    }
}

void RandomGenCTR_47::chooseTitleFile()
{


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    if (!filePath.isEmpty())
    {
        //fileTitleLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }


        byteTitleArray = file.readAll();
        file.close();

        if(byteTitleArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileTitleLabel->setText(byteTitleArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Синхропосылка из файла успешно загружена.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите синхропосылку для шифрования.");
        return;
    }
}


void RandomGenCTR_47::toggleCriticalDataInput()
{
    bool isFileDataSelected = fileCriticalDataRadio->isChecked();

    fileCriticalDataLabel->setVisible(isFileDataSelected);
    openFileCriticalDataButton->setVisible(isFileDataSelected);
    enterCriticalData->setVisible(!isFileDataSelected);
    criticalDataHexRadio->setVisible(!isFileDataSelected);
    criticalDataStrRadio->setVisible(!isFileDataSelected);
}

void RandomGenCTR_47::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void RandomGenCTR_47::toggleTitleInput()
{
    bool isFileTitleSelected = fileTitleRadio->isChecked();

    fileTitleLabel->setVisible(isFileTitleSelected);
    openFileTitleButton->setVisible(isFileTitleSelected);
    titleInput->setVisible(!isFileTitleSelected);
}

void RandomGenCTR_47::resetForm()
{

    enterCriticalData->clear();
    //enterOpenData->clear();
    keyInput->clear();
    titleInput->clear();
    //macInput->clear();
    fileKeyLabel->clear();
    fileCriticalDataLabel->clear();
    //fileOpenDataLabel->clear();
    fileTitleLabel->clear();
    //fileMacLabel->clear();
    OutPutLabel->clear();
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);
    fileCriticalDataRadio->setChecked(false);
    manualCriticalDataRadio->setChecked(true);
    //fileOpenDataRadio->setChecked(false);
    //manualOpenDataRadio->setChecked(true);
    fileTitleRadio->setChecked(false);
    manualTitleRadio->setChecked(true);
    //fileMacRadio->setChecked(false);
    //manualMacRadio->setChecked(true);
    criticalDataString->clear();
    //openDataString->clear();
    keyString->clear();
//    if(!keyString->isEmpty())
//    *keyString = "";
    byteCriticalDataArray.clear();
    //byteOpenDataArray.clear();
    byteKeyArray.clear();
    byteTitleArray.clear();
    //byteMacArray.clear();
    toggleKeyInput();
    toggleCriticalDataInput();
    //toggleOpenDataInput();
    toggleTitleInput();
}

void RandomGenCTR_47::encryptData()
{
    n = static_cast<size_t>(numberCombo->currentText().toULongLong());
    //d = static_cast<size_t>(numberCombo2->currentText().toULongLong());
    QString criticalData;
    //QString openData;
    QString keyStr;
    QString packStr;
    size_t criticalDataSizeBytes = 0;
    size_t packSizeBytes = 0;
    size_t keySizeBytes = 0;
    uint8_t* criticalblock = new uint8_t[criticalDataSizeBytes]();
    uint8_t* key;
    uint8_t* title ;
    //uint8_t mac[16] = {};
    //uint8_t* result = new uint8_t[32* l]();
    //uint8_t state[1024];
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


//------------------------------------------------------------------------------------------------------------------------------------------------
    if(manualTitleRadio->isChecked())
    {
        packStr = titleInput->toPlainText();
        packStr = packStr.simplified().remove(' ');
        packSizeBytes = packStr.size()/2;
        title = new uint8_t[packSizeBytes]();

        if (!packStr.isEmpty() && !isHexFormat(packStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

        if (!hexStringToByteArray(packStr, (uint8_t*)title,packSizeBytes))
        {
                QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать в массив байт");
                return;
        }
    }

    if(fileTitleRadio->isChecked())
    {
        if(byteTitleArray.size() !=  32)
        {
            QMessageBox::warning(this, "Ошибка", "Анонс должен быть 256 байт.");
            return;
        }
        packSizeBytes = byteTitleArray.size();
        title = new uint8_t[packSizeBytes]();
        std::memcpy(title, byteTitleArray.constData(), byteTitleArray.size());
    }

    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->toPlainText();
        keyStr = keyStr.simplified().remove(' ');
        keySizeBytes = keyStr.size()/2;
        key = new uint8_t[keySizeBytes]();
        if (!keyStr.isEmpty() && !isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(keyStr, (uint8_t*)key,32))
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен быть 256 байт.");
            return;
        }

    }

    if(fileKeyRadio->isChecked())
    {
        if(byteKeyArray.size() !=  32)
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен быть 256 байт.");
            return;
        }
        key = new uint8_t[byteKeyArray.size()]();
        std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
    }
//    for(int i = 0; i< criticalDataSizeBytes;i++)
//    {
//         qDebug() << QString::number(criticalblock[i], 16);
//    }
    brngCTRRand(criticalblock,criticalDataSizeBytes,key,title);


        QString output = printByteArray(criticalblock,criticalDataSizeBytes);
        OutPutLabel->setText(output);



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
            QMessageBox::information(this, "Генерация", "Псевдослуч. числа успешно сохранены в файл: " + outputFilePath);
        } else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить данные в файл!");
        }
    }
}
