#include"HashProg_34_101_77.h"
#include"CommonFunc.h"
#include "bee2/crypto/bash.h"


HashProg_34_101_77::HashProg_34_101_77(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);


    label6 = new QLabel("Укажите l",this);
    label6->setGeometry(10,20,155,30);
    numberCombo = new QComboBox(this);
    numberCombo->setGeometry(70,25,50,20);

    numberCombo->addItem(QString::number(128));
    numberCombo->addItem(QString::number(192));
    numberCombo->addItem(QString::number(256));


    label7 = new QLabel("Укажите d",this);
    label7->setGeometry(140,20,155,30);
    numberCombo2 = new QComboBox(this);
    numberCombo2->setGeometry(210,25,50,20);

    numberCombo2->addItem(QString::number(1));
    numberCombo2->addItem(QString::number(2));

    label8 = new QLabel("Укажите n",this);
    label8->setGeometry(280,20,155,30);
    spinBoxN = new QSpinBox(this);
    spinBoxN->setGeometry(350,25,50,20);


    label1 = new QLabel("Введите хэшируемое сообщение (X)",this);
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
    criticalDataInputGroup->addButton(fileCriticalDataRadio);
    criticalDataInputGroup->addButton(manualCriticalDataRadio);
//----------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------



    label5 = new QLabel("Введите анонс (A)",this);
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
    titleInput->setPlaceholderText("Введите заголовок в hex формате вручную");
    titleInput->setVisible(false);
    titleInput->setGeometry(10,220,600,80);
    titleInput->setWordWrapMode(QTextOption::WrapAnywhere);
    titleInput->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

//-----------------------------------------------------------------------------------------


//    setProtectionRadio->setChecked(true);
    manualCriticalDataRadio->setChecked(true);
    enterCriticalData->setVisible(true);


    manualTitleRadio->setChecked(true);
    titleInput->setVisible(true);
    criticalDataHexRadio->setChecked(true);

    resetButton = new QPushButton("Сбросить", this);
    resetButton->setGeometry(400,330,100,30);
    encryptButton = new QPushButton("Найти", this);
    encryptButton->setGeometry(510,330,100,30);

    label4 = new QLabel("Вывод блока",this);
    label4->setGeometry(10, 400, 300, 30);
    OutPutLabel = new QTextEdit(this);
    //OutPutLabel->setStyleSheet("background-color: white;");
    OutPutLabel->setGeometry(10, 440, 600, 80);
    OutPutLabel->setWordWrapMode(QTextOption::WrapAnywhere);
    OutPutLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);



    connect(openFileCriticalDataButton, &QPushButton::clicked, this, &HashProg_34_101_77::chooseCriticalDataFile);
    connect(fileCriticalDataRadio, &QRadioButton::toggled, this, &HashProg_34_101_77::toggleCriticalDataInput);
    connect(manualCriticalDataRadio, &QRadioButton::toggled, this, &HashProg_34_101_77::toggleCriticalDataInput);




    connect(resetButton, &QPushButton::clicked, this, &HashProg_34_101_77::resetForm);
    connect(encryptButton, &QPushButton::clicked, this, &HashProg_34_101_77::encryptData);

    connect(openFileTitleButton, &QPushButton::clicked, this, &HashProg_34_101_77::chooseTitleFile);
    connect(fileTitleRadio, &QRadioButton::toggled, this, &HashProg_34_101_77::toggleTitleInput);
    connect(manualTitleRadio, &QRadioButton::toggled, this, &HashProg_34_101_77::toggleTitleInput);
}

void HashProg_34_101_77::chooseCriticalDataFile()
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


void HashProg_34_101_77::chooseTitleFile()
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
        QMessageBox::information(this, "Файл загружен", "Анонс из файла успешно загружен.");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Введите анонс для шифрования.");
        return;
    }
}


void HashProg_34_101_77::toggleCriticalDataInput()
{
    bool isFileDataSelected = fileCriticalDataRadio->isChecked();

    fileCriticalDataLabel->setVisible(isFileDataSelected);
    openFileCriticalDataButton->setVisible(isFileDataSelected);
    enterCriticalData->setVisible(!isFileDataSelected);
    criticalDataHexRadio->setVisible(!isFileDataSelected);
    criticalDataStrRadio->setVisible(!isFileDataSelected);
}

void HashProg_34_101_77::toggleTitleInput()
{
    bool isFileTitleSelected = fileTitleRadio->isChecked();

    fileTitleLabel->setVisible(isFileTitleSelected);
    openFileTitleButton->setVisible(isFileTitleSelected);
    titleInput->setVisible(!isFileTitleSelected);
}

void HashProg_34_101_77::resetForm()
{

    enterCriticalData->clear();


    titleInput->clear();


    fileCriticalDataLabel->clear();

    fileTitleLabel->clear();
    OutPutLabel->clear();

    fileCriticalDataRadio->setChecked(false);
    manualCriticalDataRadio->setChecked(true);

    fileTitleRadio->setChecked(false);
    manualTitleRadio->setChecked(true);

    criticalDataString->clear();



    byteCriticalDataArray.clear();

    byteKeyArray.clear();
    byteTitleArray.clear();

    //toggleKeyInput();
    toggleCriticalDataInput();

    toggleTitleInput();
}

void HashProg_34_101_77::encryptData()
{
    l =static_cast<size_t>(numberCombo->currentText().toULongLong());
    d = static_cast<size_t>(numberCombo2->currentText().toULongLong());
    n = static_cast<size_t>(spinBoxN->value());
    if(n == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Введите корректную длину хэш-значения.");
        return;
    }
    QString criticalData;

    QString packStr;
    size_t criticalDataSizeBytes = 0;
    size_t packSizeBytes = 0;
    size_t keySizeBytes = 0;
    const uint8_t* criticalblock = new uint8_t[criticalDataSizeBytes]();
    uint8_t* key = nullptr;
    uint8_t* title ;
    //uint8_t mac[16] = {};
    uint8_t* result = new uint8_t[n]();
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
                criticalblock = new uint8_t[criticalDataSizeBytes]();
                //result = new uint8_t[criticalDataSizeBytes]();

                if (!hexStringToByteArray(criticalData, (uint8_t*)criticalblock,criticalDataSizeBytes))
                {
                    QMessageBox::warning(this, "Ошибка", "Не удалось преобразовать строку в массив байт.");
                    return;
                }
             }
        if(criticalDataStrRadio->isChecked())
             {
                byteCriticalDataArray = criticalData.toUtf8();
                criticalDataSizeBytes = byteCriticalDataArray.size();
                if(criticalDataSizeBytes < 8)
                {
                    QMessageBox::warning(this, "Ошибка", "Данные должны занимать больше 8 байт");
                    return;
                }
                criticalblock = new uint8_t[criticalDataSizeBytes]();
                //result = new uint8_t[criticalDataSizeBytes]();
                criticalblock = reinterpret_cast<const uint8_t*>(byteCriticalDataArray.constData());
             }
    }

    if(fileCriticalDataRadio->isChecked())
    {
        criticalDataSizeBytes = byteCriticalDataArray.size();


        criticalblock = reinterpret_cast<const uint8_t*>(byteCriticalDataArray.constData());
    }
//-----------------------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------------------------
    if(manualTitleRadio->isChecked())
    {
        packStr = titleInput->toPlainText();
        packStr = packStr.simplified().remove(' ');
        packSizeBytes = packStr.size()/2;
        title = new uint8_t[packSizeBytes]();
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

    if(fileTitleRadio->isChecked())
    {
        if(byteTitleArray.size() > 480)
        {
            QMessageBox::warning(this, "Ошибка", "Анонс должен быть менее 480 байт.");
            return;
        }
        std::memcpy(title, byteTitleArray.constData(), byteTitleArray.size());
    }




        bashPrgStart(state,l,d,title,packSizeBytes,key,keySizeBytes);
        bashPrgAbsorb(criticalblock,criticalDataSizeBytes,state);
        bashPrgSqueeze(result,n,state);


        QString output = printByteArray(result,n);
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
            outputFile.write(reinterpret_cast<const char*>(result),criticalDataSizeBytes);
            outputFile.close();
            QMessageBox::information(this, "Шифрование", "Данные успешно сохранены в файл: " + outputFilePath);
        } else
        {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить  данные в файл!");
        }
    }
}
