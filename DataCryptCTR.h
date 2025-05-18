
#ifndef DATACRYPTCTR_H
#define DATACRYPTCTR_H

#endif // DATACRYPTCTR_H
#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QTextEdit>
#include <QPushButton>
#include<QFileDialog>
#include<QDir>
#include<QRadioButton>
#include<QMessageBox>
#include<QRegularExpression>
#include<QButtonGroup>
#include<QFile>
#include<QSpinBox>
#include "bee2/crypto/belt.h"


class DataCryptCTR : public QWidget {
    Q_OBJECT
public:
    DataCryptCTR(QWidget *parent = nullptr);
private slots:
    void chooseKeyFile();      // Выбор ключа из файла
    void chooseDataFile();    // Выбор данных из файла
    void choosePackageFile();    // Выбор данных из файла
    void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void toggleDataInput();  // Переключение между файлами и вводом вручную данных
    void togglePackageInput();  // Переключение между файлами и вводом вручную синхропосылки
    void resetForm();       // Сброс формы
    void encryptData();     // Зашифровать данные
    void decryptData();     // Расшифровать данные
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * label5;
    QTextEdit * fileKeyLabel;
    QTextEdit * fileDataLabel;
    QTextEdit * filePackageLabel;
    QTextEdit * OutPutLabel;

    QTextEdit *enterData;
    QTextEdit *keyInput;
    QTextEdit *packageInput;

    QRadioButton *fileDataRadio;
    QRadioButton *manualDataRadio;
    QRadioButton *fileKeyRadio;
    QRadioButton *manualKeyRadio;
    QRadioButton *filePackageRadio;
    QRadioButton *manualPackageRadio;
    QRadioButton *dataStrRadio;
    QRadioButton *dataHexRadio;

    QButtonGroup* dataInputGroup;
    QButtonGroup* keyInputGroup;
    QButtonGroup* dataTypeGroup;
    QButtonGroup* packageInputGroup;

    QPushButton * openFileKeyButton;
    QPushButton * openFileDataButton;
    QPushButton * openFilePackageButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;
    QPushButton *decryptButton;


    QString *dataString = new QString();
    QString *keyString = new QString();
    QString filePath;

    QByteArray byteDataArray;
    QByteArray byteKeyArray;
    QByteArray bytePackageArray;
};
