#include"ModifyKey.h"
#include"CommonFunc.h"

ModifyKey::ModifyKey(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label1 = new QLabel("Введите ключ",this);
    label1->setGeometry(10, 10, 300, 30);



    fileDataLabel = new QTextEdit(this);
    fileDataLabel->setStyleSheet("background-color: white;");
    fileDataLabel->setVisible(false);
    fileDataLabel->setGeometry(10,45,600,80);

    openFileDataButton = new QPushButton("Выбрать файл",this);
    openFileDataButton->setVisible(false);
    openFileDataButton->setGeometry(620,45,90,30);

    enterData = new QTextEdit(this);
    enterData->setPlaceholderText("Введите данные"); // Подсказка внутри текстового поля
    enterData->setGeometry(10, 45, 600, 80);        // Увеличьте высоту для многострочного ввода
    enterData->setWordWrapMode(QTextOption::WrapAnywhere); // Автоматический перенос строк
    enterData->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);// Включите скроллбар enterData = new QTextEdit(this);


    label6 = new QLabel("Укажите m",this);
    label6->setGeometry(180,10,155,30);
    numberCombo = new QComboBox(this);
    numberCombo->setGeometry(330,10,70,30);

    numberCombo->addItem(QString::number(128));
    numberCombo->addItem(QString::number(192));
    numberCombo->addItem(QString::number(256));



    dataTypeGroup = new QButtonGroup(this);
//    dataHexRadio = new QRadioButton("hex", this);
//    dataHexRadio->setGeometry(260,10,100,30);
//    dataHexRadio->setChecked(true);
//    dataStrRadio = new QRadioButton("text", this);
//    dataStrRadio->setGeometry(310,10,100,30);


    dataInputGroup = new QButtonGroup(this);
    fileDataRadio = new QRadioButton("Из файла", this);
    fileDataRadio->setGeometry(410,10,100,30);
    manualDataRadio = new QRadioButton("Вручную", this);
    manualDataRadio->setGeometry(510,10,100,30);
    dataInputGroup->addButton(fileDataRadio);
    dataInputGroup->addButton(manualDataRadio);


    label2 = new QLabel("Введите уровень",this);
    label2->setGeometry(10, 130, 90, 30);

    keyInputGroup = new QButtonGroup(this);
    fileKeyRadio = new QRadioButton("Из файла", this);
    fileKeyRadio->setGeometry(410,130,100,30);
    manualKeyRadio = new QRadioButton("Вручную", this);
    manualKeyRadio->setGeometry(510,130,100,30);
    keyInputGroup->addButton(fileKeyRadio);
    keyInputGroup->addButton(manualKeyRadio);

    fileKeyLabel = new QTextEdit(this);
    fileKeyLabel->setStyleSheet("background-color: white;");
    fileKeyLabel->setVisible(false);
    fileKeyLabel->setGeometry(10,165,600,80);

    openFileKeyButton = new QPushButton("Выбрать файл",this);
    openFileKeyButton->setVisible(false);
    openFileKeyButton->setGeometry(620,165,90,30);

    keyInput = new QTextEdit(this);
    keyInput->setPlaceholderText("Введите уровень");
    keyInput->setVisible(false);
    keyInput->setGeometry(10,165,600,80);
    keyInput->setWordWrapMode(QTextOption::WrapAnywhere);
    keyInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //----------------------------------------------------------------------------------
    label5 = new QLabel("Введите заголовок",this);
    label5->setGeometry(10, 265, 140, 30);

    packageInputGroup = new QButtonGroup(this);
    filePackageRadio = new QRadioButton("Из файла", this);
    filePackageRadio->setGeometry(410,265,100,30);
    manualPackageRadio = new QRadioButton("Вручную", this);
    manualPackageRadio->setGeometry(510,265,100,30);
    packageInputGroup->addButton(filePackageRadio);
    packageInputGroup->addButton(manualPackageRadio);

    filePackageLabel = new QTextEdit(this);
    filePackageLabel->setStyleSheet("background-color: white;");
    filePackageLabel->setVisible(false);
    filePackageLabel->setGeometry(10,305,600,80);

    openFilePackageButton = new QPushButton("Выбрать файл",this);
    openFilePackageButton->setVisible(false);
    openFilePackageButton->setGeometry(620,275,90,30);

    packageInput = new QTextEdit(this);
    packageInput->setPlaceholderText("Введите заголовок в hex формате вручную");
    packageInput->setVisible(false);
    packageInput->setGeometry(10,305,600,80);
    packageInput->setWordWrapMode(QTextOption::WrapAnywhere);
    packageInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //----------------------------------------------------------------------------------------


    manualDataRadio->setChecked(true);
    enterData->setVisible(true);
    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);
    manualPackageRadio->setChecked(true);
    packageInput->setVisible(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(290,420,100,30);
    encryptButton = new QPushButton("Преобразовать", this);
    encryptButton->setGeometry(400,420,100,30);
    //decryptButton = new QPushButton("Расшифровать", this);
    //decryptButton->setGeometry(510,420,100,30);

    label4 = new QLabel("Вывод преобразованого ключа",this);
    label4->setGeometry(10, 450, 300, 30);
    OutPutLabel = new QTextEdit(this);
    OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 500, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(openFileDataButton, &QPushButton::clicked, this, &ModifyKey::chooseDataFile);
    connect(fileDataRadio, &QRadioButton::toggled, this, &ModifyKey::toggleDataInput);
    connect(manualDataRadio, &QRadioButton::toggled, this, &ModifyKey::toggleDataInput);

    connect(openFileKeyButton, &QPushButton::clicked, this, &ModifyKey::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &ModifyKey::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &ModifyKey::toggleKeyInput);

    connect(resetButton, &QPushButton::clicked, this, &ModifyKey::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &ModifyKey::encryptData);
    //connect(decryptButton, &QPushButton::clicked, this, &ModifyKey::decryptData);

    connect(openFilePackageButton, &QPushButton::clicked, this, &ModifyKey::choosePackageFile);
    connect(filePackageRadio, &QRadioButton::toggled, this, &ModifyKey::togglePackageInput);
    connect(manualPackageRadio, &QRadioButton::toggled, this, &ModifyKey::togglePackageInput);
}

void ModifyKey::chooseDataFile()
{


    filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    dataString = new QString();
    if (!filePath.isEmpty())
    {
        //fileDataLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }

        byteDataArray = file.readAll();
        file.close();

        if(byteDataArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileDataLabel->setText(byteDataArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Ключ из файла успешно загружен.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }

}

void ModifyKey::chooseKeyFile()
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

void ModifyKey::choosePackageFile()
{


    QString filePathP = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    if (!filePathP.isEmpty())
    {
        //filePackageLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePathP);
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

void ModifyKey::toggleDataInput()
{
    bool isFileDataSelected = fileDataRadio->isChecked();

    fileDataLabel->setVisible(isFileDataSelected);
    openFileDataButton->setVisible(isFileDataSelected);
    enterData->setVisible(!isFileDataSelected);
   // dataHexRadio->setVisible(!isFileDataSelected);
    //dataStrRadio->setVisible(!isFileDataSelected);
}
void ModifyKey::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void ModifyKey::togglePackageInput()
{
    bool isFilePackageSelected = filePackageRadio->isChecked();

    filePackageLabel->setVisible(isFilePackageSelected);
    openFilePackageButton->setVisible(isFilePackageSelected);
    packageInput->setVisible(!isFilePackageSelected);
}
void ModifyKey::resetForm()
{

    enterData->clear();
    keyInput->clear();
    packageInput->clear();
    fileKeyLabel->clear();
    fileDataLabel->clear();
    filePackageLabel->clear();
    OutPutLabel->clear();
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);
    fileDataRadio->setChecked(false);
    manualDataRadio->setChecked(true);
    filePackageRadio->setChecked(false);
    manualPackageRadio->setChecked(true);
    dataString->clear();
    keyString->clear();
    filePath.clear();
//    if(!keyString->isEmpty())
//    *keyString = "";
    byteDataArray.clear();
    byteKeyArray.clear();
    bytePackageArray.clear();
    toggleKeyInput();
    toggleDataInput();
    togglePackageInput();
}

void ModifyKey::encryptData()
{
    QString data;
    QString keyStr;
    QString packStr;
    size_t dataSizeBytes = 0;

    m = static_cast<size_t>(numberCombo->currentText().toULongLong());

    const uint8_t* block = new uint8_t[dataSizeBytes]();
    uint8_t key[12] = {};
    uint8_t package[16] = {};
    uint8_t* result = new uint8_t[dataSizeBytes]();
    //uint8_t* result;
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };

    if(manualDataRadio->isChecked())
    {
         data = enterData->toPlainText();
        data = data.simplified().remove(' ');

        if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
            dataSizeBytes = data.size()/2;
        if(dataSizeBytes != 16 && dataSizeBytes != 24 && dataSizeBytes != 32)
            {
                QMessageBox::warning(this, "Ошибка", "Неверный размер ключа(допустимо 128, 192 или 256 байт)");
                return;
            }
        if(m < dataSizeBytes)
            {
                QMessageBox::warning(this, "Ошибка", "Длина модифицированого ключа должна быть больше длины преобразуемого");
                return;
            }
            block = new uint8_t[dataSizeBytes]();
            result = new uint8_t[dataSizeBytes]();
        if (!hexStringToByteArray(data, (uint8_t*)block,dataSizeBytes))
            {
                QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать строку в массив байт.");
                return;
            }

    }

    if(fileDataRadio->isChecked())
    {
        dataSizeBytes = byteDataArray.size();
        result = new uint8_t[dataSizeBytes]();
        block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
    }

    if(manualPackageRadio->isChecked())
    {
        packStr = packageInput->toPlainText();
        packStr = packStr.simplified().remove(' ');

        if (!isHexFormat(packStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(packStr, (uint8_t*)package,16))
        {
                QMessageBox::warning(this, "Ошибка", "Синхропосылка должна быть ровно 16 байт.");
                return;
        }

    }

    if(filePackageRadio->isChecked())
    {
        if(bytePackageArray.size() != 16)
        {
            QMessageBox::warning(this, "Ошибка", "Синхропосылка должна содержать ровно 16 байт).");
            return;
        }
        std::memcpy(package, bytePackageArray.constData(), bytePackageArray.size());
    }

    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->toPlainText();
        keyStr = keyStr.simplified().remove(' ');

        if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(keyStr, (uint8_t*)key,12))
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 12 байт.");
            return;
        }

    }

    if(fileKeyRadio->isChecked())
    {
        if(byteKeyArray.size() != 12)
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 12 байта).");
            return;
        }
        std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
    }




    beltKRP(result,m/8,block,dataSizeBytes,key,package);
    QString output = printByteArray(result,m/8);
    OutPutLabel->setText(output);

    if(fileDataRadio->isChecked())
    {
        QFileInfo inputFileInfo(filePath);
        QString name = inputFileInfo.completeBaseName();
        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_decrypted.bin";
        QFile outputFile(outputFilePath);

        // Сохраняем в бинарном формате
        if (outputFile.open(QIODevice::WriteOnly))
        {
            outputFile.write(reinterpret_cast<const char*>(result), dataSizeBytes);
            outputFile.close();
            QMessageBox::information(this, "Шифрование", "Расшифрованые данные успешно сохранены в файл: " + outputFilePath);
        } else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить расшифрованые данные в файл!");
        }
    }

    //qDebug()<<QString::fromUtf8(result);
    //QMessageBox::information(this, "Шифрование", "Данные успешно зашифрованы!");

    //delete[] block;
}

//void ModifyKey::decryptData()
//{
//    QString data;
//    QString keyStr;
//    QString packStr;
//    size_t dataSizeBytes = 0;
//    //const uint8_t* block;
//    const uint8_t* block = new uint8_t[dataSizeBytes]();
//    uint8_t key[32] = {};
//    uint8_t package[16] = {};
//    uint8_t* result = new uint8_t[dataSizeBytes]();
//    //uint8_t* result;
//    auto isHexFormat = [](const QString& input) -> bool
//    {
//        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
//        QRegularExpressionMatch match = hexRegex.match(input);
//        return match.hasMatch();
//    };

//    if(manualDataRadio->isChecked())
//    {
//        data = enterData->toPlainText();
//        data = data.simplified().remove(' ');
//        if(dataHexRadio->isChecked())
//        {
//            if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
//            dataSizeBytes = data.size()/2;
////            if(dataSizeBytes < 16)
////            {
////                    QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
////                    return;
////            }
//            block = new uint8_t[dataSizeBytes]();
//           // result = new uint8_t[dataSizeBytes]();
//            if (!hexStringToByteArray(data, (uint8_t*)block,dataSizeBytes))
//            {
//                    QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать строку в массив байт.");
//                    return;
//            }
//        }
//        if(dataStrRadio->isChecked())
//        {
//            byteDataArray = data.toUtf8();
//            dataSizeBytes = byteDataArray.size();
////            if(dataSizeBytes < 16)
////            {
////                    QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
////                    return;
////            }
//            block = new uint8_t[dataSizeBytes]();
//           // result = new uint8_t[dataSizeBytes]();
//            block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
//        }
//    }

//    if(fileDataRadio->isChecked())
//    {
//        dataSizeBytes = byteDataArray.size();
//        if(dataSizeBytes < 16)
//        {
//            QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
//            return;
//        }
//        //block = new uint8_t[dataSizeBytes]();
//        //result = new uint8_t[dataSizeBytes]();
//        block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
//    }

//    if(manualKeyRadio->isChecked())
//    {
//        keyStr = keyInput->toPlainText();
//        keyStr = keyStr.simplified().remove(' ');

//        if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
//        if (!hexStringToByteArray(keyStr, (uint8_t*)key,32))
//        {
//            QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 64 символа (32 байта в 16-ричном формате).");
//            return;
//        }

//    }

//    if(fileKeyRadio->isChecked())
//    {
//        if(byteKeyArray.size() != 32)
//        {
//            QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 32 байта).");
//            return;
//        }
//        std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
//    }

//    if(manualPackageRadio->isChecked())
//    {
//        packStr = packageInput->toPlainText();
//        packStr = packStr.simplified().remove(' ');

//        if (!isHexFormat(packStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
//        if (!hexStringToByteArray(packStr, (uint8_t*)package,16))
//        {
//            QMessageBox::warning(this, "Ошибка", "Синхропосылка должна быть ровно 16 байт.");
//            return;
//        }

//    }

//    if(filePackageRadio->isChecked())
//    {
//        if(bytePackageArray.size() != 16)
//        {
//            QMessageBox::warning(this, "Ошибка", "Синхропосылка должна содержать ровно 16 байт).");
//            return;
//        }
//        std::memcpy(package, bytePackageArray.constData(), bytePackageArray.size());
//    }

//    result = new uint8_t[dataSizeBytes]();
//    //qDebug()<<sizeof(result);
//    beltCFBDecr(result,block,dataSizeBytes,key,32,package);
//    //qDebug()<<sizeof(result);
//    const QString output = printByteArray(result,dataSizeBytes);
//    OutPutLabel->setText(output);

//    if(fileDataRadio->isChecked())
//    {
//        QFileInfo inputFileInfo(filePath);
//        QString name = inputFileInfo.completeBaseName();
//        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_decrypted.bin";
//        QFile outputFile(outputFilePath);

//        // Сохраняем в бинарном формате
//        if (outputFile.open(QIODevice::WriteOnly))
//        {
//            outputFile.write(reinterpret_cast<const char*>(result), dataSizeBytes);
//            outputFile.close();
//            QMessageBox::information(this, "Шифрование", "Зашифрованые данные успешно сохранены в файл: " + outputFilePath);
//        } else
//        {
//            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить зашифрованые данные в файл!");
//        }
//    }

//    //QMessageBox::information(this, "Расшифровка", "Данные успешно расшифрованы!");
//}
