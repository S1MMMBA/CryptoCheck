#include"Hash.h"
#include"CommonFunc.h"
Hash::Hash(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label1 = new QLabel("Введите данные",this);
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



        manualDataRadio->setChecked(true);
        enterData->setVisible(true);


        resetButton = new QPushButton("Сбросить", this);
        resetButton->setGeometry(400,160,100,30);
        encryptButton = new QPushButton("Хэшировать", this);
        encryptButton->setGeometry(510,160,100,30);

        label4 = new QLabel("Вывод хэш-значения",this);
        label4->setGeometry(10, 250, 300, 30);
        OutPutLabel = new QLineEdit(this);
       // OutPutLabel->setStyleSheet("background-color: white;");
        OutPutLabel->setGeometry(10, 300, 600, 30);

        connect(openFileDataButton, &QPushButton::clicked, this, &Hash::chooseDataFile);
        connect(fileDataRadio, &QRadioButton::toggled, this, &Hash::toggleDataInput);
        connect(manualDataRadio, &QRadioButton::toggled, this, &Hash::toggleDataInput);


        connect(resetButton, &QPushButton::clicked, this, &Hash::resetForm);
        connect(encryptButton, &QPushButton::clicked, this, &Hash::encryptData);
      //  connect(decryptButton, &QPushButton::clicked, this, &Hash::decryptData);
    }

    void Hash::chooseDataFile()
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
    }
    }

    void Hash::toggleDataInput()
    {
        bool isFileDataSelected = fileDataRadio->isChecked();

        fileDataLabel->setVisible(isFileDataSelected);
        openFileDataButton->setVisible(isFileDataSelected);
        enterData->setVisible(!isFileDataSelected);
    }
    //void BlockCrypt::toggleKeyInput()
    //{
    //    bool isFileKeySelected = fileKeyRadio->isChecked();

    //    fileKeyLabel->setVisible(isFileKeySelected);
    //    openFileKeyButton->setVisible(isFileKeySelected);
    //    keyInput->setVisible(!isFileKeySelected);
    //}
    void Hash::resetForm()
        {

            enterData->clear();
            //keyInput->clear();
            //fileKeyLabel->clear();
            fileDataLabel->clear();
            OutPutLabel->clear();
            //fileKeyRadio->setChecked(false);
            //manualKeyRadio->setChecked(true);
            fileDataRadio->setChecked(false);
            manualDataRadio->setChecked(true);
            if(!dataString->isEmpty())
            *dataString = "";
            //if(!keyString->isEmpty())
            //*keyString = "";
            //byteKeyArray.clear();
            byteDataArray.clear();
            //toggleKeyInput();
            toggleDataInput();
        }



    void Hash::encryptData()
    {
        // Проверка на 16-ричный формат
        auto isHexFormat = [](const QString& input) -> bool
        {
            QRegularExpression hexRegex("^[0-9a-fA-F]+$");
            QRegularExpressionMatch match = hexRegex.match(input);
            return match.hasMatch();
        };

        QString data;
        //QString keyStr;
        size_t dataSizeBytes = 0;
        //const uint8_t* block = new uint8_t[dataSizeBytes]();
        const uint8_t* block;
        uint8_t result[32] = {};
        if(manualDataRadio->isChecked())
        {

            data = enterData->text();
            data = data.simplified().remove(' ');
            if(!data.isEmpty())
                {
                    if (!isHexFormat(data)){QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами."); return;}
                    dataSizeBytes = data.size()/2;
                    byteDataArray = QByteArray::fromHex(data.toUtf8());
                    block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
                }
            else{
                    QMessageBox::warning(this, "Ошибка", "Введенные данные не являются корректными 16-ричными числами.");
                    return;
            }
        }

        if(fileDataRadio->isChecked())
        {
                dataSizeBytes = byteDataArray.size();
                block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
        }


        beltHash(result,block,dataSizeBytes);
        const QString output = printByteArray(result,sizeof(result));
        OutPutLabel->setText(output);

        QMessageBox::information(this, "Шифрование", "Данные успешно зашифрованы!");

    }

