#include"BlockCrypt.h"


BlockCrypt::BlockCrypt(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label1 = new QLabel("Введите блок данных длиной 16 байт",this);
    label1->setGeometry(10, 10, 300, 30);

    fileDataLabel = new QLabel(this);
    fileDataLabel->setStyleSheet("background-color: white;");
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
    fileKeyLabel->setStyleSheet("background-color: white;");
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
    OutPutLabel->setStyleSheet("background-color: white;");
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


        QByteArray fileContent = file.readAll();
        file.close();


        if (filePath.endsWith(".txt", Qt::CaseInsensitive))
        {
            *dataString = QString::fromUtf8(fileContent);
        }
        if (filePath.endsWith(".bin", Qt::CaseInsensitive))
        {
            *dataString = QString(fileContent);
        }

        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
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


        QByteArray fileContent = file.readAll();
        file.close();


        if (filePath.endsWith(".txt", Qt::CaseInsensitive))
        {
            *keyString = QString::fromUtf8(fileContent);
        }
        if (filePath.endsWith(".bin", Qt::CaseInsensitive))
        {
            *keyString = QString(fileContent);
        }

        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
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
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);
    fileDataRadio->setChecked(false);
    manualDataRadio->setChecked(true);
    *dataString = "";
    *keyString = "";
    toggleKeyInput();
    toggleDataInput();
}

bool BlockCrypt::hexStringToByteArray(const QString& hexString, uint8_t* array, size_t arraySize)
{
    if (hexString.size() != arraySize * 2)
    {
        return false;
    }
    for (size_t i = 0; i < arraySize; ++i)
    {
        QString byteStr = hexString.mid(i * 2, 2);
        bool ok = false; // доп проверка на возможность преобразования
        array[i] = static_cast<uint8_t>(byteStr.toUInt(&ok, 16));
        if (!ok)
        {
            return false;
        }
    }
    return true;
}


void BlockCrypt::printByteArray(const uint8_t* data, size_t size)
{
    QStringList byteStrings;
    for (size_t i = 0; i < size; ++i)
    {
        byteStrings.append(QString("%1").arg(data[i], 2, 16, QChar('0')).toUpper());
    }
    const QString output = byteStrings.join("");
    OutPutLabel->setText(output);
}

void BlockCrypt::encryptData()
{
    QString data;
    QString keyStr;

    if(manualDataRadio->isChecked())
        data = enterData->text();
    if(fileDataRadio->isChecked())
    {
        if(dataString->isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
            return;
        }
        data = *dataString;
    }
    if(manualKeyRadio->isChecked())
        keyStr = keyInput->text();
    if(fileKeyRadio->isChecked())
    {
        if(keyString->isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
            return;
        }
        keyStr = *keyString;
    }


    data = data.simplified().remove(' ');
    keyStr = keyStr.simplified().remove(' ');

    // Проверка на пустоту полей
    if (manualKeyRadio->isChecked() && (data.isEmpty() || keyStr.isEmpty()))
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }

    // Проверка на 16-ричный формат
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };
    if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
    if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Ключ не является корректным 16-ричным числом.");return;}

    uint8_t block[16] = {};
    uint8_t key[32] = {};

    if (!hexStringToByteArray(data, block, 16))
    {
        QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
        return;
    }
    if(!hexStringToByteArray(keyStr,key,32))
    {
        QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байта в 16-ричном формате).");
        return;
    }

    beltBlockEncr(block,(uint32_t *)key);
    printByteArray(block,sizeof(block));


    QMessageBox::information(this, "Шифрование", "Данные успешно зашифрованы!");
}

void BlockCrypt::decryptData()
{
    QString data;
    QString keyStr;

    if(manualDataRadio->isChecked())
        data = enterData->text();
    if(fileDataRadio->isChecked())
    {
        if(dataString->isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
            return;
        }
        data = *dataString;
    }

    if(manualKeyRadio->isChecked())
        keyStr = keyInput->text();
    if(fileKeyRadio->isChecked())
    {
        if(keyString->isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
            return;
        }
        keyStr = *keyString;
    }

    data = data.simplified().remove(' ');
    keyStr = keyStr.simplified().remove(' ');

    if (manualKeyRadio->isChecked() && (data.isEmpty() || keyStr.isEmpty()))
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для расшифровки.");
        return;
    }

    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };
    if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
    if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Ключ не является корректным 16-ричным числом.");return;}

    uint8_t block[16] = {};
    uint8_t key[32] = {};

    if (!hexStringToByteArray(data, block, 16))
    {
        QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 32 символа (16 байт в 16-ричном формате).");
        return;
    }
    if(!hexStringToByteArray(keyStr,key,32))
    {
        QMessageBox::warning(this, "Ошибка", "Данные должны содержать ровно 64 символа (32 байта в 16-ричном формате).");
        return;
    }
    beltBlockDecr(block,(uint32_t *)key);
    printByteArray(block,sizeof(block));

    QMessageBox::information(this, "Расшифровка", "Данные успешно расшифрованы!");
}
