#include"GenPassTOTP.h"
#include"CommonFunc.h"

GenPassTOTP::GenPassTOTP(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label8 = new QLabel("Укажите d",this);
    label8->setGeometry(10,20,155,30);
    numberCombo = new QComboBox(this);
    numberCombo->setGeometry(80,25,50,20);
    numberCombo->addItem(QString::number(6));
    numberCombo->addItem(QString::number(7));
    numberCombo->addItem(QString::number(8));

    label6 = new QLabel("Укажите T0", this);
    label6->setGeometry(10, 60, 155, 30);

    T0input = new QSpinBox(this);
    T0input->setGeometry(80,65, 50, 20);

    label7 = new QLabel("Укажите Ts", this);
    label7->setGeometry(10, 100, 155, 30);
    Tsinput = new QSpinBox(this);
    Tsinput->setGeometry(80, 105, 50, 20);

//    label1 = new QLabel("Укажите счетчик",this);
//    label1->setGeometry(10, -5, 300, 30);

    fileDataLabel = new QTextEdit(this);
    //fileDataLabel->setStyleSheet("background-color: white;");
    fileDataLabel->setVisible(false);
    fileDataLabel->setGeometry(10,45,600,80);

    openFileDataButton = new QPushButton("Выбрать файл",this);
    openFileDataButton->setVisible(false);
    openFileDataButton->setGeometry(620,45,90,30);

    enterData = new QSpinBox(this);
    enterData->setGeometry(150, 23, 200, 20);  // QSpinBox не требует высоты 80 и ширины 600
    enterData->setRange(0, std::numeric_limits<int>::max());           // Диапазон значений (можно настроить по задаче)
    enterData->setSingleStep(1);              // Шаг увеличения/уменьшения
    enterData->setToolTip("Укажите время вручную");
    enterData->setEnabled(false);


    manualTime =new QCheckBox("Указать время вручную", this);
    manualTime->setGeometry(380, 20, 200, 30); // x, y, ширина, высота
    manualTime->setChecked(false); // по умолчанию не отмечен

    dataTypeGroup = new QButtonGroup(this);
//    dataHexRadio = new QRadioButton("hex", this);
//    dataHexRadio->setGeometry(290,10,100,30);
//    dataHexRadio->setChecked(true);
   // dataStrRadio = new QRadioButton("text", this);
    //dataStrRadio->setGeometry(340,10,100,30);


//    dataInputGroup = new QButtonGroup(this);
//    fileDataRadio = new QRadioButton("Из файла", this);
//    fileDataRadio->setGeometry(410,10,100,30);
//    manualDataRadio = new QRadioButton("Вручную", this);
//    manualDataRadio->setGeometry(510,10,100,30);
//    dataInputGroup->addButton(fileDataRadio);
//    dataInputGroup->addButton(manualDataRadio);


    label2 = new QLabel("Введите ключ (K)",this);
    label2->setGeometry(10, 130, 120, 30);

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


    //manualDataRadio->setChecked(true);
    enterData->setVisible(true);
    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(390,260,100,30);
    encryptButton = new QPushButton("Найти", this);
    encryptButton->setGeometry(500,260,100,30);

    label4 = new QLabel("Одноразовый пароль:",this);
    label4->setGeometry(10, 350, 300, 30);
    OutPutLabel = new QTextEdit(this);
    //OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 400, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    //OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //connect(openFileDataButton, &QPushButton::clicked, this, &GenPassTOTP::chooseDataFile);
    //connect(fileDataRadio, &QRadioButton::toggled, this, &GenPassTOTP::toggleDataInput);
    //connect(manualDataRadio, &QRadioButton::toggled, this, &GenPassTOTP::toggleDataInput);

    connect(openFileKeyButton, &QPushButton::clicked, this, &GenPassTOTP::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &GenPassTOTP::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &GenPassTOTP::toggleKeyInput);
    connect(resetButton, &QPushButton::clicked, this, &GenPassTOTP::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &GenPassTOTP::produceMAC);
    connect(manualTime, &QCheckBox::stateChanged, this, [=](int state){
        enterData->setEnabled(state == Qt::Checked);
    });

}



void GenPassTOTP::chooseKeyFile()
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
//void GenPassTOTP::toggleDataInput()
//{
//    bool isFileDataSelected = fileDataRadio->isChecked();

//    fileDataLabel->setVisible(isFileDataSelected);
//    openFileDataButton->setVisible(isFileDataSelected);
//    enterData->setVisible(!isFileDataSelected);
//    dataHexRadio->setVisible(!isFileDataSelected);
//   // dataStrRadio->setVisible(!isFileDataSelected);
//}
void GenPassTOTP::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void GenPassTOTP::resetForm()
{

    enterData->clear();
    keyInput->clear();
    fileKeyLabel->clear();
    fileDataLabel->clear();
    OutPutLabel->clear();
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);
    //fileDataRadio->setChecked(false);
    //manualDataRadio->setChecked(true);
    dataString->clear();
    filePath.clear();
    manualTime->setChecked(false);
    if(!keyString->isEmpty())
    *keyString = "";
    //byteDataArray.clear();
    byteKeyArray.clear();

    toggleKeyInput();
    //toggleDataInput();
}

void GenPassTOTP::produceMAC()
{
    d = static_cast<size_t>(numberCombo->currentText().toULongLong());
    T0 = T0input->value();
    Ts = Tsinput->value();

    QString data;
    QString keyStr;
    size_t dataSizeBytes = 0;

    uint8_t* block = new uint8_t[dataSizeBytes]();
    uint8_t* key = nullptr;
    size_t keySizeBytes = 0;
    char* result = new char[d+1]();
    //uint8_t* result;
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };

    if(manualTime->isChecked())
    {
        t = enterData->value();

    }
    else
    {
        t = QDateTime::currentSecsSinceEpoch();
    }
    if(T0 >= t)
    {
        QMessageBox::warning(this, "Ошибка", "Должно выполняться ограничение: 𝑇0 < T. ");
        return;
    }
    time = (t-T0)/Ts;

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




    botpTOTPRand(result,d,key,keySizeBytes,time);
    QString output = "";
    for(int i = 0; i< d; i++)
    {
        output = output + result[i];
    }
    OutPutLabel->setText(output);

//    if(fileDataRadio->isChecked())
//    {
//        QFileInfo inputFileInfo(filePath);
//        QString name = inputFileInfo.completeBaseName();
//        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_pass.bin";
//        QFile outputFile(outputFilePath);

//        // Сохраняем в бинарном формате
//        if (outputFile.open(QIODevice::WriteOnly))
//        {
//            outputFile.write(reinterpret_cast<const char*>(result), d);
//            outputFile.close();
//            QMessageBox::information(this, "Имитовствака", "Пароль успешно сохранен в файл: " + outputFilePath);
//        } else
//        {
//            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить пароль в файл!");
//        }
//    }
}
