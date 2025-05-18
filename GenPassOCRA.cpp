#include"GenPassOCRA.h"
#include"CommonFunc.h"
QChar getFChar(const QString &ocraSuite)
{
    // Находим позицию "Q" в строке
    int qPos = ocraSuite.indexOf('Q');
    if (qPos == -1) {
        qWarning() << "Invalid OCRA suite: 'Q' not found";
        return QChar();
    }

    // Позиция f - это символ после 'Q'
    int fPos = qPos + 1;
    if (fPos >= ocraSuite.length()) {
        qWarning() << "Invalid OCRA suite: no character after 'Q'";
        return QChar();
    }

    return ocraSuite.at(fPos);
}
GenPassOCRA::GenPassOCRA(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label6 = new QLabel("Укажите d",this);
                        label6->setGeometry(10,20,155,30);
                        numberCombo = new QComboBox(this);
                        numberCombo->setGeometry(70,25,50,20);
    numberCombo->addItem(QString::number(6));
    numberCombo->addItem(QString::number(7));
    numberCombo->addItem(QString::number(8));

    label8 = new QLabel("Укажите T0", this);
    label8->setGeometry(10, 740, 155, 30);

    T0input = new QSpinBox(this);
    T0input->setGeometry(80,745, 50, 20);

    label7 = new QLabel("Укажите Ts", this);
    label7->setGeometry(140, 740, 155, 30);
    Tsinput = new QSpinBox(this);
    Tsinput->setGeometry(210, 745, 50, 20);

    label1 = new QLabel("Укажите счетчик",this);
    label1->setGeometry(10, -5, 300, 30);

    fileDataLabel = new QTextEdit(this);
    //fileDataLabel->setStyleSheet("background-color: white;");
    fileDataLabel->setVisible(false);
    fileDataLabel->setGeometry(10,45,600,80);

    openFileDataButton = new QPushButton("Выбрать файл",this);
    openFileDataButton->setVisible(false);
    openFileDataButton->setGeometry(620,45,90,30);

    enterData = new QTextEdit(this);
    enterData->setPlaceholderText("Передайте описатель");
    enterData->setGeometry(10, 45, 600, 80);
    enterData->setWordWrapMode(QTextOption::WrapAnywhere);
    enterData->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    enterTime = new QSpinBox(this);
    enterTime->setGeometry(270, 745, 200, 20);  // QSpinBox не требует высоты 80 и ширины 600
    enterTime->setRange(0, std::numeric_limits<int>::max());           // Диапазон значений (можно настроить по задаче)
    enterTime->setSingleStep(1);              // Шаг увеличения/уменьшения
    enterTime->setToolTip("Укажите время вручную");
    enterTime->setEnabled(false);


    manualTime =new QCheckBox("Указать время вручную", this);
    manualTime->setGeometry(480, 743, 200, 30); // x, y, ширина, высота
    manualTime->setChecked(false); // по умолчанию не отмечен


    dataTypeGroup = new QButtonGroup(this);
    dataHexRadio = new QRadioButton("hex", this);
    dataHexRadio->setGeometry(290,10,100,30);
    dataHexRadio->setChecked(true);
   // dataStrRadio = new QRadioButton("text", this);
    //dataStrRadio->setGeometry(340,10,100,30);


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
//------------------------------Q-------------------------------------------------------------------------------------
    labelq = new QLabel("Введите Q",this);
    labelq->setGeometry(10, 250, 90, 30);

    qInputGroup = new QButtonGroup(this);
    fileQRadio = new QRadioButton("Из файла", this);
    fileQRadio->setGeometry(410,250,100,30);
    manualQRadio = new QRadioButton("Вручную", this);
    manualQRadio->setGeometry(510,250,100,30);
    qInputGroup->addButton(fileQRadio);
    qInputGroup->addButton(manualQRadio);

    fileQLabel = new QTextEdit(this);
    //fileQLabel->setStyleSheet("background-color: white;");
    fileQLabel->setVisible(false);
    fileQLabel->setGeometry(10,285,600,80);

    openFileQButton = new QPushButton("Выбрать файл",this);
    openFileQButton->setVisible(false);
    openFileQButton->setGeometry(620,285,90,30);

    qInput = new QTextEdit(this);
    qInput->setPlaceholderText("Введите Q в hex формате вручную");
    qInput->setVisible(false);
    qInput->setGeometry(10,285,600,80);
    qInput->setWordWrapMode(QTextOption::WrapAnywhere);
    qInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    manualQRadio->setChecked(true);
    qInput->setVisible(true);
//----------------------------------------------------------------------------------------------------------------------
    labelp = new QLabel("Введите P",this);
    labelp->setGeometry(10, 370, 90, 30);

    pInputGroup = new QButtonGroup(this);
    filePRadio = new QRadioButton("Из файла", this);
    filePRadio->setGeometry(410,370,100,30);
    manualPRadio = new QRadioButton("Вручную", this);
    manualPRadio->setGeometry(510,370,100,30);
    pInputGroup->addButton(filePRadio);
    pInputGroup->addButton(manualPRadio);

    filePLabel = new QTextEdit(this);
    //filePLabel->setStyleSheet("background-color: white;");
    filePLabel->setVisible(false);
    filePLabel->setGeometry(10,405,600,80);

    openFilePButton = new QPushButton("Выбрать файл",this);
    openFilePButton->setVisible(false);
    openFilePButton->setGeometry(620,405,90,30);

    pInput = new QTextEdit(this);
    pInput->setPlaceholderText("Введите P в hex формате вручную");
    pInput->setVisible(false);
    pInput->setGeometry(10,405,600,80);
    pInput->setWordWrapMode(QTextOption::WrapAnywhere);
    pInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    manualPRadio->setChecked(true);
    pInput->setVisible(true);
//-----------------------------------------------------------------------------------------------------------------------

    labelc = new QLabel("Введите C",this);
    labelc->setGeometry(10, 490, 90, 30);

    cInputGroup = new QButtonGroup(this);
    fileCRadio = new QRadioButton("Из файла", this);
    fileCRadio->setGeometry(410,490,100,30);
    manualCRadio = new QRadioButton("Вручную", this);
    manualCRadio->setGeometry(510,490,100,30);
    cInputGroup->addButton(fileCRadio);
    cInputGroup->addButton(manualCRadio);

    fileCLabel = new QTextEdit(this);
    //fileCLabel->setStyleSheet("background-color: white;");
    fileCLabel->setVisible(false);
    fileCLabel->setGeometry(10,525,600,80);

    openFileCButton = new QPushButton("Выбрать файл",this);
    openFileCButton->setVisible(false);
    openFileCButton->setGeometry(620,525,90,30);

    cInput = new QTextEdit(this);
    cInput->setPlaceholderText("Введите C в hex формате вручную");
    cInput->setVisible(false);
    cInput->setGeometry(10,525,600,80);
    cInput->setWordWrapMode(QTextOption::WrapAnywhere);
    cInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    manualCRadio->setChecked(true);
    cInput->setVisible(true);
//---------------------------------------------------------------------------------------------------------------------------------------------------

    labels = new QLabel("Введите S",this);
    labels->setGeometry(10, 610, 90, 30);

    sInputGroup = new QButtonGroup(this);
    fileSRadio = new QRadioButton("Из файла", this);
    fileSRadio->setGeometry(410,610,100,30);
    manualSRadio = new QRadioButton("Вручную", this);
    manualSRadio->setGeometry(510,610,100,30);
    sInputGroup->addButton(fileSRadio);
    sInputGroup->addButton(manualSRadio);

    fileSLabel = new QTextEdit(this);
    //fileSLabel->setStyleSheet("background-color: white;");
    fileSLabel->setVisible(false);
    fileSLabel->setGeometry(10,645,600,80);

    openFileSButton = new QPushButton("Выбрать файл",this);
    openFileSButton->setVisible(false);
    openFileSButton->setGeometry(620,645,90,30);

    sInput = new QTextEdit(this);
    sInput->setPlaceholderText("Введите S в hex формате вручную");
    sInput->setVisible(false);
    sInput->setGeometry(10,645,600,80);
    sInput->setWordWrapMode(QTextOption::WrapAnywhere);
    sInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    manualSRadio->setChecked(true);
    sInput->setVisible(true);
//------------------------------------------------------------------------------------------------------------------------------------------------------------
    manualDataRadio->setChecked(true);
    enterData->setVisible(true);
    manualKeyRadio->setChecked(true);
    keyInput->setVisible(true);



    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(620,825,100,30);
    encryptButton = new QPushButton("Найти", this);
    encryptButton->setGeometry(620,790,100,30);

    label4 = new QLabel("Одноразовый пароль",this);
    label4->setGeometry(10, 775, 300, 30);
    OutPutLabel = new QTextEdit(this);
    //OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 780, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    //OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(openFileDataButton, &QPushButton::clicked, this, &GenPassOCRA::chooseDataFile);
    connect(fileDataRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleDataInput);
    connect(manualDataRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleDataInput);

    connect(openFileKeyButton, &QPushButton::clicked, this, &GenPassOCRA::chooseKeyFile);
    connect(fileKeyRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleKeyInput);
    connect(manualKeyRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleKeyInput);
    connect(resetButton, &QPushButton::clicked, this, &GenPassOCRA::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &GenPassOCRA::produceMAC);

    connect(openFileQButton, &QPushButton::clicked, this, &GenPassOCRA::chooseQFile);
    connect(fileQRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleQInput);
    connect(manualQRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleQInput);

    connect(openFilePButton, &QPushButton::clicked, this, &GenPassOCRA::choosePFile);
    connect(filePRadio, &QRadioButton::toggled, this, &GenPassOCRA::togglePInput);
    connect(manualPRadio, &QRadioButton::toggled, this, &GenPassOCRA::togglePInput);

    connect(openFileCButton, &QPushButton::clicked, this, &GenPassOCRA::chooseCFile);
    connect(fileCRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleCInput);
    connect(manualCRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleCInput);

    connect(openFileSButton, &QPushButton::clicked, this, &GenPassOCRA::chooseSFile);
    connect(fileSRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleSInput);
    connect(manualSRadio, &QRadioButton::toggled, this, &GenPassOCRA::toggleSInput);
    connect(manualTime, &QCheckBox::stateChanged, this, [=](int state){
        enterTime->setEnabled(state == Qt::Checked);
    });


}

void GenPassOCRA::chooseDataFile()
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

void GenPassOCRA::chooseKeyFile()
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

void GenPassOCRA::chooseQFile()
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


        byteQArray = file.readAll();
        file.close();

        if(byteQArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileQLabel->setText(byteQArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }
}

void GenPassOCRA::choosePFile()
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


        bytePArray = file.readAll();
        file.close();

        if(bytePArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        filePLabel->setText(bytePArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }
}
void GenPassOCRA::chooseCFile()
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


        byteCArray = file.readAll();
        file.close();

        if(byteCArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileCLabel->setText(byteCArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }
}
void GenPassOCRA::chooseSFile()
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


        byteSArray = file.readAll();
        file.close();

        if(byteSArray.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Файл пуст.");
            return;
        }
        fileSLabel->setText(byteSArray.toHex(' ').toUpper());
        QMessageBox::information(this, "Файл загружен", "Данные из файла успешно загружены.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные и ключ для шифрования.");
        return;
    }
}
void GenPassOCRA::toggleDataInput()
{
    bool isFileDataSelected = fileDataRadio->isChecked();

    fileDataLabel->setVisible(isFileDataSelected);
    openFileDataButton->setVisible(isFileDataSelected);
    enterData->setVisible(!isFileDataSelected);
    dataHexRadio->setVisible(!isFileDataSelected);
   // dataStrRadio->setVisible(!isFileDataSelected);
}
void GenPassOCRA::toggleKeyInput()
{
    bool isFileKeySelected = fileKeyRadio->isChecked();

    fileKeyLabel->setVisible(isFileKeySelected);
    openFileKeyButton->setVisible(isFileKeySelected);
    keyInput->setVisible(!isFileKeySelected);
}
void GenPassOCRA::toggleQInput()
{
    bool isFileQSelected = fileQRadio->isChecked();
    fileQLabel->setVisible(isFileQSelected);
    openFileQButton->setVisible(isFileQSelected);
    qInput->setVisible(!isFileQSelected);
}
void GenPassOCRA::toggleCInput()
{
    bool isFileCSelected = fileCRadio->isChecked();
    fileCLabel->setVisible(isFileCSelected);
    openFileCButton->setVisible(isFileCSelected);
    cInput->setVisible(!isFileCSelected);
}
void GenPassOCRA::toggleSInput()
{
    bool isFileSSelected = fileSRadio->isChecked();
    fileSLabel->setVisible(isFileSSelected);
    openFileSButton->setVisible(isFileSSelected);
    sInput->setVisible(!isFileSSelected);
}
void GenPassOCRA::togglePInput()
{
    bool isFilePSelected = filePRadio->isChecked();
    filePLabel->setVisible(isFilePSelected);
    openFilePButton->setVisible(isFilePSelected);
    pInput->setVisible(!isFilePSelected);
}
void GenPassOCRA::resetForm()
{

    enterData->clear();
    keyInput->clear();
    fileKeyLabel->clear();

    qInput->clear();
    fileQLabel->clear();
    fileDataLabel->clear();

    pInput->clear();
    filePLabel->clear();

    cInput->clear();
    fileCLabel->clear();

    sInput->clear();
    fileSLabel->clear();

    OutPutLabel->clear();
    fileKeyRadio->setChecked(false);
    manualKeyRadio->setChecked(true);

    fileQRadio->setChecked(false);
    manualQRadio->setChecked(true);

    fileCRadio->setChecked(false);
    manualCRadio->setChecked(true);

    fileSRadio->setChecked(false);
    manualSRadio->setChecked(true);

    filePRadio->setChecked(false);
    manualPRadio->setChecked(true);

    fileDataRadio->setChecked(false);
    manualDataRadio->setChecked(true);
    dataString->clear();
    filePath.clear();
    if(!keyString->isEmpty())
    *keyString = "";

    if(!qString->isEmpty())
        *qString = "";

    if(!pString->isEmpty())
    *pString = "";

    if(!cString->isEmpty())
        *cString = "";

    if(!sString->isEmpty())
        *sString = "";

    byteDataArray.clear();
    byteKeyArray.clear();
    byteQArray.clear();
    bytePArray.clear();
    byteCArray.clear();
    byteSArray.clear();

    toggleKeyInput();
    toggleQInput();
    togglePInput();
    toggleCInput();
    toggleSInput();
    toggleDataInput();
}

void GenPassOCRA::produceMAC()
{
    n = static_cast<size_t>(numberCombo->currentText().toULongLong());
    QString data;
    QString keyStr;
    QString qStr;
    QString pStr;
    QString cStr;
    QString sStr;
    size_t dataSizeBytes = 0;
    size_t qSizeBytes = 0;
    size_t pSizeBytes = 0;
    size_t cSizeBytes = 8;
    size_t sSizeBytes = 0;

    char * descr = nullptr;
    char * qChar = nullptr;
    uint8_t* key = nullptr;
    uint8_t * q = nullptr;
    uint8_t * p = nullptr;
    //uint8_t* c = new uint8_t[8]();
    uint8_t c[8];
    uint8_t * s = nullptr;
    size_t keySizeBytes = 0;
    char* result = new char[n+1]();
    //uint8_t* result;
    auto isHexFormat = [](const QString& input) -> bool
    {
        QRegularExpression hexRegex("^[0-9a-fA-F]+$");
        QRegularExpressionMatch match = hexRegex.match(input);
        return match.hasMatch();
    };
    auto isAlphaNumeric = [](const QString& input) -> bool
    {
        QRegularExpression alphaNumRegex("^[0-9A-Za-z]+$");
        QRegularExpressionMatch match = alphaNumRegex.match(input);
        return match.hasMatch();
    };
    auto isNumeric = [](const QString& input) -> bool
    {
        QRegularExpression alphaNumRegex("^[0-9]+$");
        QRegularExpressionMatch match = alphaNumRegex.match(input);
        return match.hasMatch();
    };

    if(manualDataRadio->isChecked())
    {
        data = enterData->toPlainText();
        //data = data.simplified().remove(' ');
        byteDataArray = data.toUtf8();
        byteDataArray.append('\0');
        descr = new char[byteDataArray.size()];
        int temp = byteDataArray.size();
        memcpy(descr, byteDataArray.constData(),byteDataArray.size());
//        for (size_t i = 0; i < byteDataArray.size(); ++i) {
//            qDebug().noquote() << QString("%1").arg(descr[i], 2, 16, QChar('0')).toUpper() << " ";
//        }

    }

    if(fileDataRadio->isChecked())
    {
         dataSizeBytes = byteDataArray.size();
         descr = new char[dataSizeBytes + 1];
         strcpy(descr, byteDataArray.constData());
    }

    if(manualQRadio->isChecked())
    {
         qStr = qInput->toPlainText();
         qStr = qStr.simplified().remove(' ');
         qSizeBytes = qStr.size()/2;

             if(qSizeBytes > 64 || qSizeBytes < 4)
             {
                QMessageBox::warning(this, "Ошибка", "Допустимая длина запроса от 4 до 64 байт");
                return;
             }

             if(getFChar(data) == 'N' || getFChar(data) == 'A')
             {
                if(!isNumeric(qStr) && !isAlphaNumeric(qStr))
                {
                    QMessageBox::warning(this, "Ошибка", "Содержаться символы не принадлежащие алфавиту N и A");
                    return;
                }
                byteQArray = qStr.toLatin1();
                qSizeBytes = byteQArray.size();
//                byteQArray = qStr.toUtf8();
//                qChar = new char[byteQArray.size() + 1];
//                strcpy(qChar, byteQArray.constData());
             }
             else
             {
                if(!isHexFormat(qStr))
                {
                    QMessageBox::warning(this, "Ошибка", "Содержаться символы не принадлежащие алфавиту H");
                    return;
                }
                byteQArray = QByteArray::fromHex(qStr.toUtf8());
             }


         q = new uint8_t[qSizeBytes]();
         memcpy(q, byteQArray.constData(),byteQArray.size());

    }

    if(fileQRadio->isChecked())
    {
         qSizeBytes = byteQArray.size();
         q = new uint8_t[qSizeBytes]();
         if(qSizeBytes > 64 || qSizeBytes < 4)
         {
                    QMessageBox::warning(this, "Ошибка", "Допустимая длина запроса от 4 до 64 байт");
                    return;
         }
         memcpy(q, byteQArray.constData(),qSizeBytes);
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

    if(manualPRadio->isChecked())
    {
        pStr = pInput->toPlainText();
        pStr = pStr.simplified().remove(' ');
        if (!isHexFormat(pStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        pSizeBytes = pStr.size()/2;
//        if(pSizeBytes > 64 || pSizeBytes < 4)
//        {
//                QMessageBox::warning(this, "Ошибка", "Допустимая длина запроса от 4 до 64 байт");
//                return;
//        }
        bytePArray = QByteArray::fromHex(pStr.toUtf8());
        p = new uint8_t[pSizeBytes]();
        memcpy(p, bytePArray.constData(),pSizeBytes);

    }

    if(filePRadio->isChecked())
    {
        pSizeBytes = bytePArray.size();
        p = new uint8_t[pSizeBytes]();
//        if(pSizeBytes > 64 || pSizeBytes < 4)
//        {
//                QMessageBox::warning(this, "Ошибка", "Допустимая длина запроса от 4 до 64 байт");
//                return;
//        }
        memcpy(p, bytePArray.constData(),pSizeBytes);
    }

    if(manualCRadio->isChecked())
    {
        cStr = cInput->toPlainText();
        cStr = cStr.simplified().remove(' ');
        if (!isHexFormat(cStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        cSizeBytes = cStr.size()/2;
        if(cSizeBytes != 8)
        {
                QMessageBox::warning(this, "Ошибка", "Допустимая длина счетчика 8 байт");
                return;
        }
        byteCArray = QByteArray::fromHex(cStr.toUtf8());
        //c = new uint8_t[cSizeBytes]();
        memcpy(c, byteCArray.constData(),8);

    }

    if(fileCRadio->isChecked())
    {
        cSizeBytes = byteCArray.size();
        //c = new uint8_t[cSizeBytes]();
        if(cSizeBytes != 8)
        {
                QMessageBox::warning(this, "Ошибка", "Допустимая длина счетчика 8 байт");
                return;
        }
        memcpy(c, byteCArray.constData(),cSizeBytes);
    }

    if(manualSRadio->isChecked())
    {
        sStr = sInput->toPlainText();
        sStr = sStr.simplified().remove(' ');
        if (!isHexFormat(sStr)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
        sSizeBytes = sStr.size()/2;
                if(sSizeBytes > 512)
                {
                        QMessageBox::warning(this, "Ошибка", "Допустимая длина хеш-значения менее 512 байт");
                        return;
                }
        byteSArray = QByteArray::fromHex(sStr.toUtf8());
        s = new uint8_t[sSizeBytes]();
        memcpy(s, byteSArray.constData(),sSizeBytes);

    }

//    for (size_t i = 0; i < sSizeBytes; ++i) {
//        //qDebug().noquote() << QString("%1").arg(s[i], 2, 16, QChar('0')).toUpper();
//        // Или в одну строку с пробелами:
//         qDebug().noquote() << QString("%1").arg(s[i], 2, 16, QChar('0')).toUpper() << " ";
//    }

    if(fileSRadio->isChecked())
    {
        sSizeBytes = byteSArray.size();
        s = new uint8_t[sSizeBytes]();
            if(sSizeBytes > 512)
            {
                            QMessageBox::warning(this, "Ошибка", "Допустимая длина хеш-значения менее 512 байт");
                            return;
            }
        memcpy(s, byteSArray.constData(),sSizeBytes);
    }
    T0 = T0input->value();
    Ts = Tsinput->value();

    if(manualTime->isChecked())
    {
        t = enterTime->value();

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
        for (size_t i = 0; i < sSizeBytes; ++i) {
            //qDebug().noquote() << QString("%1").arg(s[i], 2, 16, QChar('0')).toUpper();
            // Или в одну строку с пробелами:
             qDebug().noquote() << QString("%1").arg(s[i], 2, 16, QChar('0')).toUpper() << " ";
        }
    err_t err = botpOCRARand(result,descr,key,keySizeBytes,q,qSizeBytes,c,p,s,time);

    QString output = "";
    for(int i = 0; i< n; i++)
    {
        output = output + result[i];
    }
    OutPutLabel->setText(output);

    if(fileDataRadio->isChecked())
    {
        QFileInfo inputFileInfo(filePath);
        QString name = inputFileInfo.completeBaseName();
        QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name + "_out_mac.bin";
        QFile outputFile(outputFilePath);

        // Сохраняем в бинарном формате
        if (outputFile.open(QIODevice::WriteOnly))
        {
            outputFile.write(reinterpret_cast<const char*>(result), n);
            outputFile.close();
            QMessageBox::information(this, "Имитовствака", "Имитовставка успешно сохранена в файл: " + outputFilePath);
        } else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить имитовставку в файл!");
        }
    }

    //delete[] c;
}
