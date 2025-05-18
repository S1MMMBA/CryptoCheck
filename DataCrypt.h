
#ifndef DATACRYPT_H
#define DATACRYPT_H

#endif // DATACRYPT_H

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
class DataCrypt : public QWidget {
    Q_OBJECT
public:
    DataCrypt(QWidget *parent = nullptr);
private slots:
    void chooseKeyFile();      // Выбор ключа из файла
    void chooseDataFile();    // Выбор данных из файла
    void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void toggleDataInput();  // Переключение между файлами и вводом вручную данных
    void resetForm();       // Сброс формы
    void encryptData();     // Зашифровать данные
    void decryptData();     // Расшифровать данные
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QTextEdit * fileKeyLabel;
    QTextEdit * fileDataLabel;
    QTextEdit * OutPutLabel;

    QTextEdit *enterData;
    QTextEdit *keyInput;

    QRadioButton *fileDataRadio;
    QRadioButton *manualDataRadio;
    QRadioButton *fileKeyRadio;
    QRadioButton *manualKeyRadio;
    QRadioButton *dataStrRadio;
    QRadioButton *dataHexRadio;

    QButtonGroup* dataInputGroup;
    QButtonGroup* keyInputGroup;
    QButtonGroup* dataTypeGroup;

    QPushButton * openFileKeyButton;
    QPushButton * openFileDataButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;
    QPushButton *decryptButton;


    QString *dataString = new QString();
    QString *keyString = new QString();

    QByteArray byteDataArray;
    QByteArray byteKeyArray;

    QString filePath;
};
