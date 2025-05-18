#include"ExpandKey.h"
#include"CommonFunc.h"

ExpandKey::ExpandKey(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);




    label6 = new QLabel("Укажите n",this);
    label6->setGeometry(250,10,155,30);
    numberCombo = new QComboBox(this);

    numberCombo->addItem(QString::number(4));
    numberCombo->addItem(QString::number(6));
    numberCombo->addItem(QString::number(8));

    numberCombo->setGeometry(330,10,70,30);

    label2 = new QLabel("Введите ключ",this);
    label2->setGeometry(10, 10, 90, 30);

    keyInputGroup = new QButtonGroup(this);
    fileKeyRadio = new QRadioButton("Из файла", this);
    fileKeyRadio->setGeometry(410,10,100,30);
    manualKeyRadio = new QRadioButton("Вручную", this);
    manualKeyRadio->setGeometry(510,10,100,30);
    keyInputGroup->addButton(fileKeyRadio);
    keyInputGroup->addButton(manualKeyRadio);

    fileKeyLabel = new QTextEdit(this);
    fileKeyLabel->setStyleSheet("background-color: white;");
    fileKeyLabel->setVisible(false);
    fileKeyLabel->setGeometry(10,45,600,80);

    openFileKeyButton = new QPushButton("Выбрать файл",this);
    openFileKeyButton->setVisible(false);
    openFileKeyButton->setGeometry(620,45,90,30);

    keyInput = new QTextEdit(this);
    keyInput->setPlaceholderText("Введите ключ в hex формате вручную");
    keyInput->setVisible(false);
    keyInput->setGeometry(10,45,600,80);
    keyInput->setWordWrapMode(QTextOption::WrapAnywhere);
    keyInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);



    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(390,160,100,30);
    encryptButton = new QPushButton("Расширить", this);
    encryptButton->setGeometry(500,160,100,30);

    label4 = new QLabel("Расширенный ключ",this);
    label4->setGeometry(10, 250, 300, 30);
    OutPutLabel = new QTextEdit(this);
    OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 300, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    //OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    connect(openFileKeyButton, &QPushButton::clicked, this, &ExpandKey::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &ExpandKey::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &ExpandKey::toggleKeyInput);
    connect(resetButton, &QPushButton::clicked, this, &ExpandKey::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &ExpandKey::expandKey);

}


void ExpandKey::chooseKeyFile()
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

void ExpandKey::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void ExpandKey::resetForm()
{
    keyInput->clear();
    fileKeyLabel->clear();

    OutPutLabel->clear();
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);

    filePath.clear();
    if(!keyString->isEmpty())
    *keyString = "";

    byteKeyArray.clear();

    toggleKeyInput();

}

void ExpandKey::expandKey()
{

    QString keyStr;
    n = static_cast<size_t>(numberCombo->currentText().toULongLong());
    //const uint8_t* block;
    //const uint8_t* block = new uint8_t[dataSizeBytes]();
    uint8_t* key = new uint8_t[4*n]();;
    uint8_t* result = new uint8_t[32]();
    //uint8_t* result;
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };





    if(manualKeyRadio->isChecked())
    {
        keyStr = keyInput->toPlainText();
        keyStr = keyStr.simplified().remove(' ');

        if (!isHexFormat(keyStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        if (!hexStringToByteArray(keyStr, (uint8_t*)key,4*n))
        {
                QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 32*n символа (4*n байта).");
                return;
        }

    }

    if(fileKeyRadio->isChecked())
    {
        if(byteKeyArray.size() != 4*n)
        {
            QMessageBox::warning(this, "Ошибка", "Ключ должен содержать ровно 4*n байта.");
            return;
        }
        std::memcpy(key, byteKeyArray.constData(), byteKeyArray.size());
    }




    beltKeyExpand(result,key,n*4);
    QString output = printByteArray(result,32);
    OutPutLabel->setText(output);

    if(fileKeyRadio->isChecked())
    {
        QFileInfo inputFileInfo(filePath);
        QString name = inputFileInfo.completeBaseName();
        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_mac.bin";
        QFile outputFile(outputFilePath);

        // Сохраняем в бинарном формате
        if (outputFile.open(QIODevice::WriteOnly))
        {
            outputFile.write(reinterpret_cast<const char*>(result), 32);
            outputFile.close();
            QMessageBox::information(this, "Имитовствака", "Имитовставка успешно сохранена в файл: " + outputFilePath);
        } else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить имитовставку в файл!");
        }
    }
}



