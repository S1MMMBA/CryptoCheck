#include"ProduceMAC_HMAC_47.h"
#include"CommonFunc.h"

ProduceMAC_HMAC_47::ProduceMAC_HMAC_47(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label1 = new QLabel("Введите сообщение для выработки имитовставки (X)",this);
    label1->setGeometry(10, 10, 300, 30);

    fileDataLabel = new QTextEdit(this);
    //fileDataLabel->setStyleSheet("background-color: white;");
    fileDataLabel->setVisible(false);
    fileDataLabel->setGeometry(10,45,600,80);

    openFileDataButton = new QPushButton("Выбрать файл",this);
    openFileDataButton->setVisible(false);
    openFileDataButton->setGeometry(620,45,90,30);

    enterData = new QTextEdit(this);
    enterData->setPlaceholderText("Введите сообщение для выработки имитовставки");
    enterData->setGeometry(10, 45, 600, 80);
    enterData->setWordWrapMode(QTextOption::WrapAnywhere);
    enterData->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    dataTypeGroup = new QButtonGroup(this);
    //dataHexRadio = new QRadioButton("hex", this);
    //dataHexRadio->setGeometry(290,10,100,30);
    //dataHexRadio->setChecked(true);
    //dataStrRadio = new QRadioButton("text", this);
    //dataStrRadio->setGeometry(340,10,100,30);


    dataInputGroup = new QButtonGroup(this);
    fileDataRadio = new QRadioButton("Из файла", this);
    fileDataRadio->setGeometry(410,10,100,30);
    manualDataRadio = new QRadioButton("Вручную", this);
    manualDataRadio->setGeometry(510,10,100,30);
    dataInputGroup->addButton(fileDataRadio);
    dataInputGroup->addButton(manualDataRadio);


    label2 = new QLabel("Введите ключ (K)",this);
    label2->setGeometry(10, 130, 130, 30);

    keyInputGroup = new QButtonGroup(this);
    fileKeyRadio = new QRadioButton("Из файла", this);
    fileKeyRadio->setGeometry(410,130,100,30);
    manualKeyRadio = new QRadioButton("Вручную", this);
    manualKeyRadio->setGeometry(510,130,100,30);
    keyInputGroup->addButton(fileKeyRadio);
    keyInputGroup->addButton(manualKeyRadio);

    fileKeyLabel = new QTextEdit(this);
    //fileKeyLabel->setStyleSheet("background-color: white;");
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
    resetButton->setGeometry(390,260,100,30);
    encryptButton = new QPushButton("Найти", this);
    encryptButton->setGeometry(500,260,100,30);

    label4 = new QLabel("Вывод имитовставки (Y)",this);
    label4->setGeometry(10, 350, 300, 30);
    OutPutLabel = new QTextEdit(this);
    //OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 400, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    //OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(openFileDataButton, &QPushButton::clicked, this, &ProduceMAC_HMAC_47::chooseDataFile);
    connect(fileDataRadio, &QRadioButton::toggled, this, &ProduceMAC_HMAC_47::toggleDataInput);
    connect(manualDataRadio, &QRadioButton::toggled, this, &ProduceMAC_HMAC_47::toggleDataInput);

    connect(openFileKeyButton, &QPushButton::clicked, this, &ProduceMAC_HMAC_47::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &ProduceMAC_HMAC_47::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &ProduceMAC_HMAC_47::toggleKeyInput);
    connect(resetButton, &QPushButton::clicked, this, &ProduceMAC_HMAC_47::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &ProduceMAC_HMAC_47::produceMAC);

}

void ProduceMAC_HMAC_47::chooseDataFile()
{


    filePath = QFileDialog::getOpenFileName(this,
                                                "Выберите файл",
                                                QDir::homePath(),
                                                "Текстовые файлы (*.txt);;Бинарные файлы (*.bin)");
    dataString = new QString();
    if (!filePath.isEmpty())
    {
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

void ProduceMAC_HMAC_47::chooseKeyFile()
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
void ProduceMAC_HMAC_47::toggleDataInput()
{
    bool isFileDataSelected = fileDataRadio->isChecked();

    fileDataLabel->setVisible(isFileDataSelected);
    openFileDataButton->setVisible(isFileDataSelected);
    enterData->setVisible(!isFileDataSelected);
    //dataHexRadio->setVisible(!isFileDataSelected);
    //dataStrRadio->setVisible(!isFileDataSelected);
}
void ProduceMAC_HMAC_47::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void ProduceMAC_HMAC_47::resetForm()
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
    dataString->clear();
    filePath.clear();
    if(!keyString->isEmpty())
    *keyString = "";
    byteDataArray.clear();
    byteKeyArray.clear();

    toggleKeyInput();
    toggleDataInput();
}

void ProduceMAC_HMAC_47::produceMAC()
{
    QString data;
    QString keyStr;
    size_t dataSizeBytes = 0;
    //const uint8_t* block;
    uint8_t* block = new uint8_t[dataSizeBytes]();
    uint8_t* key;
    size_t keySizeBytes = 0;
    uint8_t* result = new uint8_t[32]();
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
//        if(dataHexRadio->isChecked())
//             {
                if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
                dataSizeBytes = data.size()/2;
                block = new uint8_t[dataSizeBytes]();
                //result = new uint8_t[dataSizeBytes]();
                if (!hexStringToByteArray(data, (uint8_t*)block,dataSizeBytes))
                {
                    QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать строку в массив байт.");
                    return;
                }
 //            }

    }

    if(fileDataRadio->isChecked())
    {
         dataSizeBytes = byteDataArray.size();
         block = new uint8_t[dataSizeBytes]();
         //result = new uint8_t[dataSizeBytes]();
         memcpy(block, byteDataArray.constData(),dataSizeBytes);
    }

    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->toPlainText();
        keyStr = keyStr.simplified().remove(' ');
        keySizeBytes = keyStr.size()/2;
        key = new uint8_t[keySizeBytes]();
        if (!keyStr.isEmpty() && !isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(keyStr, (uint8_t*)key,keySizeBytes))
        {
                QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать ключ");
                return;
        }

    }

    if(fileKeyRadio->isChecked())
    {
        keySizeBytes = byteKeyArray.size();
        key = new uint8_t[keySizeBytes]();
        std::memcpy(key, byteKeyArray.constData(),keySizeBytes);
    }




    beltHMAC(result,block,dataSizeBytes,key,keySizeBytes);
    QString output = printByteArray(result,32);
    OutPutLabel->setText(output);

    if(fileDataRadio->isChecked())
    {
        QFileInfo inputFileInfo(filePath);
        QString name = inputFileInfo.completeBaseName();
        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_mac.bin";
        QFile outputFile(outputFilePath);

        // Сохраняем в бинарном формате
        if (outputFile.open(QIODevice::WriteOnly))
        {
            outputFile.write(reinterpret_cast<const char*>(result), dataSizeBytes);
            outputFile.close();
            QMessageBox::information(this, "Имитовствака", "Имитовставка успешно сохранена в файл: " + outputFilePath);
        } else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить имитовставку в файл!");
        }
    }
}



