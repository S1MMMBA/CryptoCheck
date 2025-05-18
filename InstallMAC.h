
#ifndef INSTALLMAC_H
#define INSTALLMAC_H

#endif // INSTALLMAC_H

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
class InstallMAC : public QWidget {
    Q_OBJECT
public:
    InstallMAC(QWidget *parent = nullptr);
private slots:
    void chooseKeyFile();      // Выбор ключа из файла
    void chooseCriticalDataFile();    // Выбор критичных данных из файла
    void chooseOpenDataFile();    // Выбор критичных данных из файла
    void choosePackageFile();    // Выбор данных из файла
    void toggleOperation();     // Выбор установка/снятие имитозащиты
    void chooseMacFile();    // Выбор данных из файла
    void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void toggleCriticalDataInput();  // Переключение между файлами и вводом вручную данных
    void toggleOpenDataInput();  // Переключение между файлами и вводом вручную данных
    void togglePackageInput();  // Переключение между файлами и вводом вручную синхропосылки
    void toggleMacInput();  // Переключение между файлами и вводом вручную синхропосылки
    void resetForm();       // Сброс формы
    void encryptData();     // Зашифровать данные
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * label5;
    QLabel * openDataLabel;
    QLabel * macLabel;
    QTextEdit * fileKeyLabel;
    QTextEdit * fileOpenDataLabel;
    QTextEdit * fileCriticalDataLabel;
    QTextEdit * filePackageLabel;
    QTextEdit * fileMacLabel;
    QTextEdit * OutPutLabel;

    QTextEdit *enterCriticalData;
    QTextEdit *enterOpenData;
    QTextEdit *keyInput;
    QTextEdit *packageInput;
    QTextEdit *macInput;

    QRadioButton *setProtectionRadio;
    QRadioButton *removeProtectionRadio;
    QRadioButton *fileCriticalDataRadio;
    QRadioButton *manualCriticalDataRadio;
    QRadioButton *fileOpenDataRadio;
    QRadioButton *manualOpenDataRadio;
    QRadioButton *fileKeyRadio;
    QRadioButton *manualKeyRadio;
    QRadioButton *filePackageRadio;
    QRadioButton *manualPackageRadio;
    QRadioButton *fileMacRadio;
    QRadioButton *manualMacRadio;
    QRadioButton *criticalDataStrRadio;
    QRadioButton *criticalDataHexRadio;
    QRadioButton *openDataStrRadio;
    QRadioButton *openDataHexRadio;

    QButtonGroup* chooseOperation;
    QButtonGroup* criticalDataInputGroup;
    QButtonGroup* openDataInputGroup;
    QButtonGroup* keyInputGroup;
    QButtonGroup* criticalDataTypeGroup;
    QButtonGroup* openDataTypeGroup;
    QButtonGroup* packageInputGroup;
    QButtonGroup* macInputGroup;

    QPushButton * openFileKeyButton;
    QPushButton * openFileCriticalDataButton;
    QPushButton * openFileOpenDataButton;
    QPushButton * openFilePackageButton;
    QPushButton * openFileMacButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;


    QString *criticalDataString = new QString();
    QString *openDataString = new QString();
    QString *keyString = new QString();
    QString filePath;

    QByteArray byteCriticalDataArray;
    QByteArray byteOpenDataArray;
    QByteArray byteKeyArray;
    QByteArray bytePackageArray;
    QByteArray byteMacArray;
};
