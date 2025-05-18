#include"BlockCrypt.h"
#include"CommonFunc.h"

BlockCrypt::BlockCrypt(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label1 = new QLabel("Введите блок данных длиной 16 байт",this);
    label1->setGeometry(10, 10, 300, 30);

    fileDataLabel = new QLabel(this);
    //fileDataLabel->setStyleSheet("background-color: white;");
    fileDataLabel->setVisible(false);
    fileDataLabel->setGeometry(10,45,600,30);

    openFileDataButton = new QPushButton("Выбрать файл",this);
    openFileDataButton->setVisible(false);
    openFileDataButton->setGeometry(620,45,90,30);

    enterData = new QLineEdit(this);
    enterData->setPlaceholderText("Введите данные");
    enterData->setVisible(false);
    enterData->setGeometry(10, 45, 600, 30);



    dataInputGroup = new QButtonGroup(this);
    fileDataRadio = new QRadioButton("Из файла", this);
    fileDataRadio->setGeometry(410,10,100,30);
    manualDataRadio = new QRadioButton("Вручную", this);
    manualDataRadio->setGeometry(510,10,100,30);
    dataInputGroup->addButton(fileDataRadio);
    dataInputGroup->addButton(manualDataRadio);




    label2 = new QLabel("Введите ключ",this);
    label2->setGeometry(10, 80, 90, 30);

    keyInputGroup = new QButtonGroup(this);
    fileKeyRadio = new QRadioButton("Из файла", this);
    fileKeyRadio->setGeometry(410,80,100,30);
    manualKeyRadio = new QRadioButton("Вручную", this);
    manualKeyRadio->setGeometry(510,80,100,30);
    keyInputGroup->addButton(fileKeyRadio);
    keyInputGroup->addButton(manualKeyRadio);

    fileKeyLabel = new QLabel(this);
    //fileKeyLabel->setStyleSheet("background-color: white;");
    fileKeyLabel->setVisible(false);
    fileKeyLabel->setGeometry(10,115,600,30);

    openFileKeyButton = new QPushButton("Выбрать файл",this);
    openFileKeyButton->setVisible(false);
    openFileKeyButton->setGeometry(620,115,90,30);

    keyInput = new QLineEdit(this);
    keyInput->setPlaceholderText("Введите ключ вручную");
    keyInput->setVisible(false);
    keyInput->setGeometry(10,115,600,30);


    manualDataRadio->setChecked(true);
    enterData->setVisible(true);
    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(290,160,100,30);
    encryptButton = new QPushButton("Зашифровать", this);
    encryptButton->setGeometry(400,160,100,30);
    decryptButton = new QPushButton("Расшифровать", this);
    decryptButton->setGeometry(510,160,100,30);

    label4 = new QLabel("Вывод зашифрованного блока",this);
    label4->setGeometry(10, 250, 300, 30);
    OutPutLabel = new QLineEdit(this);
    //OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 300, 600, 30);

    connect(openFileDataButton, &QPushButton::clicked, this, &BlockCrypt::chooseDataFile);
    connect(fileDataRadio, &QRadioButton::toggled, this, &BlockCrypt::toggleDataInput);
    connect(manualDataRadio, &QRadioButton::toggled, this, &BlockCrypt::toggleDataInput);

    connect(openFileKeyButton, &QPushButton::clicked, this, &BlockCrypt::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &BlockCrypt::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &BlockCrypt::toggleKeyInput);
    connect(resetButton, &QPushButton::clicked, this, &BlockCrypt::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &BlockCrypt::encryptData);
    connect(decryptButton, &QPushButton::clicked, this, &BlockCrypt::decryptData);
}

void BlockCrypt::chooseDataFile()
{


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    dataString = new QString();
    if (!filePath.isEmpty())
    {
        fileDataLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }


        byteDataArray = file.readAll();// если читаем из bin файла, дальше работаем с сырым массивом byteDataArray, доп. проверок/преобразований не требуется.
        file.close();


        if (filePath.endsWith(".txt", Qt::CaseInsensitive))
        {
            QString buf = QString::fromUtf8(byteDataArray);
            if(buf.isEmpty())
            {
                QMessageBox::warning(this, "Ошибка", "Введите данные для шифрования.");
                return;
            }
            buf = buf.simplified().remove(' ');
            *dataString = buf;
        }

        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные для шифрования.");
        return;
    }

}

void BlockCrypt::chooseKeyFile()
{


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    if (!filePath.isEmpty())
    {
        fileKeyLabel->setText("Выбранный файл: " + filePath);
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения.");
            return;
        }


        byteKeyArray = file.readAll(); // если читаем из bin файла, дальше работаем с сырым массивом byteKeyArray, доп. проверок/преобразований не требуется.
        file.close();

        if (filePath.endsWith(".txt", Qt::CaseInsensitive))
        {
            QString buf = QString::fromUtf8(byteKeyArray);
            if(buf.isEmpty())
            {
                QMessageBox::warning(this, "Ошибка", "Введите ключ для шифрования.");
                return;
            }
            buf = buf.simplified().remove(' ');
            *keyString = buf;
        }

        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите ключ для шифрования.");
        return;
    }
}
void BlockCrypt::toggleDataInput()
{
    bool isFileDataSelected = fileDataRadio->isChecked();

    fileDataLabel->setVisible(isFileDataSelected);
    openFileDataButton->setVisible(isFileDataSelected);
    enterData->setVisible(!isFileDataSelected);
}
void BlockCrypt::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void BlockCrypt::resetForm()
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
    if(!dataString->isEmpty())
    *dataString = "";
    if(!keyString->isEmpty())
    *keyString = "";
    byteKeyArray.clear();
    byteDataArray.clear();
    toggleKeyInput();
    toggleDataInput();
}



void BlockCrypt::encryptData()
{
    // Проверка на 16-ричный формат
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };

    QString data;
    QString keyStr;
    uint8_t block[16] = {};
    uint8_t key[32] = {};

    if(manualDataRadio->isChecked())
    {
        data = enterData->text();
        data = data.simplified().remove(' ');
        if(!data.isEmpty())
            {
                if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

                if (!hexStringToByteArray(data, block, 16))
                {
                    QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
                    return;
                }
            }
        else
            {
                    QMessageBox::warning(this, "Ошибка", "Введите данные для шифрования.");
                    return;
            }
    }
    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->text();
        keyStr = keyStr.simplified().remove(' ');
        if(!keyStr.isEmpty())
            {
                    if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

                    if (!hexStringToByteArray(keyStr, key, 32))
                    {
                        QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байт в 16-ричном формате).");
                        return;
                    }
            }
        else
            {
                    QMessageBox::warning(this, "Ошибка", "Введите ключ для шифрования.");
                    return;
            }
    }


    if(fileDataRadio->isChecked())
    {
        if(!dataString->isEmpty()) // переменная dataString заполнена, только если исп. ввод из txt файла, если пустая, значит ввод произошел из bin файла
        {                          // проверки на пустоту dataString в других случаях провели на этапе считывания
            data = *dataString;
             if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

             if (!hexStringToByteArray(data, block, 16))
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
                 return;
             }
        }
        else // для bin файлов
        {
             if(byteDataArray.size() != 16)
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
                 return;
             }
             else
             {
                std::memcpy(block, byteDataArray.constData(), byteDataArray.size());
             }

        }
    }

    if(fileKeyRadio->isChecked())
    {
        if(!keyString->isEmpty()) // переменная dataString заполнена, только если исп. ввод из txt файла, если пустая, значит ввод произошел из bin файла
        {                          // проверки на пустоту dataString в других случаях провели на этапе считывания
                keyStr = *keyString;
             if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

             if (!hexStringToByteArray(keyStr, key, 32))
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байт в 16-ричном формате).");
                 return;
             }
        }
        else // для bin файлов
        {
             if(byteKeyArray.size() != 32)
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байт в 16-ричном формате).");
                 return;
             }
             std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
        }

    }

    beltBlockEncr(block,(uint32_t *)key);
    const QString output = printByteArray(block,sizeof(block));
    OutPutLabel->setText(output);

    QMessageBox::information(this, "Шифрование", "Данные успешно зашифрованы!");
}

void BlockCrypt::decryptData()
{
    // Проверка на 16-ричный формат
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };

    QString data;
    QString keyStr;
    uint8_t block[16] = {};
    uint8_t key[32] = {};

    if(manualDataRadio->isChecked())
    {
        data = enterData->text();
        data = data.simplified().remove(' ');
        if(!data.isEmpty())
        {
             if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

             if (!hexStringToByteArray(data, block, 16))
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
                 return;
             }
        }
        else
        {
             QMessageBox::warning(this, "Ошибка", "Введите данные для шифрования.");
             return;
        }
    }
    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->text();
        keyStr = keyStr.simplified().remove(' ');
        if(!keyStr.isEmpty())
        {
             if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

             if (!hexStringToByteArray(keyStr, key, 32))
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байт в 16-ричном формате).");
                 return;
             }
        }
        else
        {
             QMessageBox::warning(this, "Ошибка", "Введите ключ для шифрования.");
             return;
        }
    }


    if(fileDataRadio->isChecked())
    {
        if(!dataString->isEmpty()) // переменная dataString заполнена, только если исп. ввод из txt файла, если пустая, значит ввод произошел из bin файла
        {                          // проверки на пустоту dataString в других случаях провели на этапе считывания
             data = *dataString;
             if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

             if (!hexStringToByteArray(data, block, 16))
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
                 return;
             }
        }
        else // для bin файлов
        {
             if(byteDataArray.size() != 16)
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
                 return;
             }
             else
             {
                 std::memcpy(block, byteDataArray.constData(), byteDataArray.size());
             }

        }
    }

    if(fileKeyRadio->isChecked())
    {
        if(!keyString->isEmpty()) // переменная dataString заполнена, только если исп. ввод из txt файла, если пустая, значит ввод произошел из bin файла
        {                          // проверки на пустоту dataString в других случаях провели на этапе считывания
             keyStr = *keyString;
             if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}

             if (!hexStringToByteArray(keyStr, key, 32))
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байт в 16-ричном формате).");
                 return;
             }
        }
        else // для bin файлов
        {
             if(byteKeyArray.size() != 32)
             {
                 QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байт в 16-ричном формате).");
                 return;
             }
             std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
        }

    }
    beltBlockDecr(block,(uint32_t *)key);
    const QString output = printByteArray(block,sizeof(block));
    OutPutLabel->setText(output);

    QMessageBox::information(this, "Расшифровка", "Данные успешно расшифрованы!");
}

