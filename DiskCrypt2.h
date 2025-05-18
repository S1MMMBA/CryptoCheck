
#ifndef DISKCRYPT2_H
#define DISKCRYPT2_H

#endif // DISKCRYPT2_H

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
class DiskCrypt2 : public QWidget {
    Q_OBJECT
public:
    DiskCrypt2(QWidget *parent = nullptr);
private slots:
    void chooseKeyFile();      // Выбор ключа из файла
    void chooseCriticalDataFile();    // Выбор критичных данных из файла

    void chooseTitleFile();    // Выбор данных из файла

    void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void toggleCriticalDataInput();  // Переключение между файлами и вводом вручную данных
    void toggleTitleInput();  // Переключение между файлами и вводом вручную синхропосылки
    void resetForm();       // Сброс формы
    void encryptData();     // Зашифровать данные
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * label5;
    QTextEdit * fileKeyLabel;
    QTextEdit * fileCriticalDataLabel;
    QTextEdit * fileTitleLabel;
    QTextEdit * OutPutLabel;

    QTextEdit *enterCriticalData;
    QTextEdit *keyInput;
    QTextEdit *titleInput;

    QRadioButton *setProtectionRadio;
    QRadioButton *removeProtectionRadio;
    QRadioButton *fileCriticalDataRadio;
    QRadioButton *manualCriticalDataRadio;
    QRadioButton *fileKeyRadio;
    QRadioButton *manualKeyRadio;
    QRadioButton *fileTitleRadio;
    QRadioButton *manualTitleRadio;
    QRadioButton *criticalDataStrRadio;
    QRadioButton *criticalDataHexRadio;

    QButtonGroup* chooseOperation;
    QButtonGroup* criticalDataInputGroup;
    QButtonGroup* keyInputGroup;
    QButtonGroup* criticalDataTypeGroup;
    QButtonGroup* titleInputGroup;

    QPushButton * openFileKeyButton;
    QPushButton * openFileCriticalDataButton;
    QPushButton * openFileTitleButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;


    QString *criticalDataString = new QString();
    QString *keyString = new QString();
    QString filePath;

    QByteArray byteCriticalDataArray;
    QByteArray byteKeyArray;
    QByteArray byteTitleArray;
};
