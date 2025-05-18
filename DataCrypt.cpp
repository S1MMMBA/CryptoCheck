
#include"DataCrypt.h"
#include"CommonFunc.h"

DataCrypt::DataCrypt(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label1 = new QLabel("Введите данные",this);
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
    enterData->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // Включите скроллбар enterData = new QTextEdit(this);


    dataTypeGroup = new QButtonGroup(this);
    dataHexRadio = new QRadioButton("hex", this);
    dataHexRadio->setGeometry(260,10,100,30);
    dataHexRadio->setChecked(true);
    dataStrRadio = new QRadioButton("text", this);
    dataStrRadio->setGeometry(310,10,100,30);


    dataInputGroup = new QButtonGroup(this);
    fileDataRadio = new QRadioButton("Из файла", this);
    fileDataRadio->setGeometry(410,10,100,30);
    manualDataRadio = new QRadioButton("Вручную", this);
    manualDataRadio->setGeometry(510,10,100,30);
    dataInputGroup->addButton(fileDataRadio);
    dataInputGroup->addButton(manualDataRadio);


    label2 = new QLabel("Введите ключ",this);
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
    keyInput->setPlaceholderText("Введите ключ в hex формате вручную");
    keyInput->setVisible(false);
    keyInput->setGeometry(10,165,600,80);
    keyInput->setWordWrapMode(QTextOption::WrapAnywhere);
    keyInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    manualDataRadio->setChecked(true);
    enterData->setVisible(true);
    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(290,260,100,30);
    encryptButton = new QPushButton("Зашифровать", this);
    encryptButton->setGeometry(400,260,100,30);
    decryptButton = new QPushButton("Расшифровать", this);
    decryptButton->setGeometry(510,260,100,30);

    label4 = new QLabel("Вывод зашифрованного блока",this);
    label4->setGeometry(10, 350, 300, 30);
    OutPutLabel = new QTextEdit(this);
    OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 400, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    //OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(openFileDataButton, &QPushButton::clicked, this, &DataCrypt::chooseDataFile);
    connect(fileDataRadio, &QRadioButton::toggled, this, &DataCrypt::toggleDataInput);
    connect(manualDataRadio, &QRadioButton::toggled, this, &DataCrypt::toggleDataInput);

    connect(openFileKeyButton, &QPushButton::clicked, this, &DataCrypt::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &DataCrypt::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &DataCrypt::toggleKeyInput);
    connect(resetButton, &QPushButton::clicked, this, &DataCrypt::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &DataCrypt::encryptData);
    connect(decryptButton, &QPushButton::clicked, this, &DataCrypt::decryptData);
}

void DataCrypt::chooseDataFile()
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
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }

}

void DataCrypt::chooseKeyFile()
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
void DataCrypt::toggleDataInput()
{
    bool isFileDataSelected = fileDataRadio->isChecked();

    fileDataLabel->setVisible(isFileDataSelected);
    openFileDataButton->setVisible(isFileDataSelected);
    enterData->setVisible(!isFileDataSelected);
    dataHexRadio->setVisible(!isFileDataSelected);
    dataStrRadio->setVisible(!isFileDataSelected);
}
void DataCrypt::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void DataCrypt::resetForm()
{

    enterData->clear();
    keyInput->clear();
    fileKeyLabel->clear();
    fileDataLabel->clear();
    OutPutLabel->clear();
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);
    fileDataRadio->setChecked(false);
    manualDataRadio->setChecked(true);
//    if(!dataString->isEmpty())
//    *dataString = "";
    dataString->clear();
    filePath.clear();
    if(!keyString->isEmpty())
    *keyString = "";
    byteDataArray.clear();
    byteKeyArray.clear();

    toggleKeyInput();
    toggleDataInput();
}

void DataCrypt::encryptData()
{
    QString data;
    QString keyStr;
    size_t dataSizeBytes = 0;
    //const uint8_t* block;
    const uint8_t* block = new uint8_t[dataSizeBytes]();
    uint8_t key[32] = {};
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
        if(dataHexRadio->isChecked())
             {
                if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
                dataSizeBytes = data.size()/2;
                if(dataSizeBytes < 16)
                {
                    QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
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
        if(dataStrRadio->isChecked())
             {
                byteDataArray = data.toUtf8();
                dataSizeBytes = byteDataArray.size();
                if(dataSizeBytes < 16)
                {
                    QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
                    return;
                }
                block = new uint8_t[dataSizeBytes]();
                result = new uint8_t[dataSizeBytes]();
                block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
             }
    }

    if(fileDataRadio->isChecked())
    {
        dataSizeBytes = byteDataArray.size();
        if(dataSizeBytes < 16)
            {
                QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
                return;
            }
        //block = new uint8_t[dataSizeBytes]();
        result = new uint8_t[dataSizeBytes]();
        block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
    }

    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->toPlainText();
        keyStr = keyStr.simplified().remove(' ');

        if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(keyStr, (uint8_t*)key,32))
        {
                QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 64 символа (32 байта в 16-ричном формате).");
                return;
        }

    }

    if(fileKeyRadio->isChecked())
    {
        if(byteKeyArray.size() != 32)
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 32 байта).");
            return;
        }
        std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
    }




    beltECBEncr(result,block,dataSizeBytes,key,32);
    QString output = printByteArray(result,dataSizeBytes);
    OutPutLabel->setText(output);
    if(fileDataRadio->isChecked())
    {
        QFileInfo inputFileInfo(filePath);
        QString name = inputFileInfo.completeBaseName();
        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_encrypted.bin";
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
    //delete[] block;
}

void DataCrypt::decryptData()
{
    QString data;
    QString keyStr;
    size_t dataSizeBytes = 0;
    //const uint8_t* block;
    const uint8_t* block = new uint8_t[dataSizeBytes]();
    uint8_t key[32] = {};
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
        if(dataHexRadio->isChecked())
        {
            if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
            dataSizeBytes = data.size()/2;
            if(dataSizeBytes < 16)
            {
                    QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
                    return;
            }
            block = new uint8_t[dataSizeBytes]();
           // result = new uint8_t[dataSizeBytes]();
            if (!hexStringToByteArray(data, (uint8_t*)block,dataSizeBytes))
            {
                    QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать строку в массив байт.");
                    return;
            }
        }
        if(dataStrRadio->isChecked())
        {
            byteDataArray = data.toUtf8();
            dataSizeBytes = byteDataArray.size();
            if(dataSizeBytes < 16)
            {
                    QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
                    return;
            }
            block = new uint8_t[dataSizeBytes]();
           // result = new uint8_t[dataSizeBytes]();
            block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
        }
    }

    if(fileDataRadio->isChecked())
    {
        dataSizeBytes = byteDataArray.size();
        if(dataSizeBytes < 16)
        {
            QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 16 байт");
            return;
        }
        //block = new uint8_t[dataSizeBytes]();
        //result = new uint8_t[dataSizeBytes]();
        block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
    }

    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->toPlainText();
        keyStr = keyStr.simplified().remove(' ');

        if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(keyStr, (uint8_t*)key,32))
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 64 символа (32 байта в 16-ричном формате).");
            return;
        }

    }

    if(fileKeyRadio->isChecked())
    {
        if(byteKeyArray.size() != 32)
        {
            QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 байта.");
            return;
        }
        std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
    }

    result = new uint8_t[dataSizeBytes]();
    //qDebug()<<sizeof(result);
    beltECBDecr(result,block,dataSizeBytes,key,32);
    //qDebug()<<sizeof(result);
    const QString output = printByteArray(result,dataSizeBytes);
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

    //QMessageBox::information(this, "Расшифровка", "Данные успешно расшифрованы!");
}
