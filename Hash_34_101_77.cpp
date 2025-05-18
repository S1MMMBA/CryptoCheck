#include"Hash_34_101_77.h"
#include"CommonFunc.h"
Hash_34_101_77::Hash_34_101_77(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    label1 = new QLabel("Введите данные (X)",this);
    label1->setGeometry(10, 10, 300, 30);

    label6 = new QLabel("Укажите l",this);
    label6->setGeometry(180,10,155,30);
    numberCombo = new QComboBox(this);
    numberCombo->setGeometry(330,10,70,30);

    for(int i = 16; i <= 256; i += 16)
    {
        numberCombo->addItem(QString::number(i));
    }
//    numberCombo->addItem(QString::number(128));
//    numberCombo->addItem(QString::number(192));
//    numberCombo->addItem(QString::number(256));


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
        //OutPutLabel->setStyleSheet("background-color: white;");
        OutPutLabel->setGeometry(10, 300, 600, 30);

        connect(openFileDataButton, &QPushButton::clicked, this, &Hash_34_101_77::chooseDataFile);
        connect(fileDataRadio, &QRadioButton::toggled, this, &Hash_34_101_77::toggleDataInput);
        connect(manualDataRadio, &QRadioButton::toggled, this, &Hash_34_101_77::toggleDataInput);


        connect(resetButton, &QPushButton::clicked, this, &Hash_34_101_77::resetForm);
        connect(encryptButton, &QPushButton::clicked, this, &Hash_34_101_77::encryptData);
    }

    void Hash_34_101_77::chooseDataFile()
    {


        filePath = QFileDialog::getOpenFileName(this,
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
            fileDataLabel->setText(byteDataArray.toHex(' ').toUpper());
            file.close();
    }
    }

    void Hash_34_101_77::toggleDataInput()
    {
        bool isFileDataSelected = fileDataRadio->isChecked();

        fileDataLabel->setVisible(isFileDataSelected);
        openFileDataButton->setVisible(isFileDataSelected);
        enterData->setVisible(!isFileDataSelected);
    }
    void Hash_34_101_77::resetForm()
        {

            enterData->clear();
            fileDataLabel->clear();
            OutPutLabel->clear();
            fileDataRadio->setChecked(false);
            manualDataRadio->setChecked(true);
            if(!dataString->isEmpty())
            *dataString = "";
            byteDataArray.clear();
            toggleDataInput();
        }



    void Hash_34_101_77::encryptData()
    {
        // Проверка на 16-ричный формат
        auto isHexFormat = [](const QString& input) -> bool
        {
            QRegularExpression hexRegex("^[0-9a-fA-F]+$");
            QRegularExpressionMatch match = hexRegex.match(input);
            return match.hasMatch();
        };

        l = static_cast<size_t>(numberCombo->currentText().toULongLong());

        QString data;
        //QString keyStr;
        size_t dataSizeBytes = 0;
        //const uint8_t* block = new uint8_t[dataSizeBytes]();
        const uint8_t* block;
        //uint8_t result[] = {};
        uint8_t * result = new uint8_t[l/4]();
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
        }

        if(fileDataRadio->isChecked())
        {
                dataSizeBytes = byteDataArray.size();
                block = reinterpret_cast<const uint8_t*>(byteDataArray.constData());
        }


        bashHash(result,l,block,dataSizeBytes);
        const QString output = printByteArray(result,l/4);
        OutPutLabel->setText(output);

        if(fileDataRadio->isChecked())
        {
                QFileInfo inputFileInfo(filePath);
                QString name = inputFileInfo.completeBaseName();
                QString outputFilePath = QFileInfo(inputFileInfo).absolutePath() +"/"+ name+ "_out_hash.bin";
                QFile outputFile(outputFilePath);

                // Сохраняем в бинарном формате
                if (outputFile.open(QIODevice::WriteOnly))
                {
                    outputFile.write(reinterpret_cast<const char*>(result), l/4);
                    outputFile.close();
                    QMessageBox::information(this, "Шифрование", "Расшифрованые данные успешно сохранены в файл: " + outputFilePath);
                } else
                {
                    QMessageBox::warning(this, "Ошибка", "Не удалось сохранить данные в файл!");
                }
        }

    }


