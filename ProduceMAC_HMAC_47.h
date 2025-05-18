
#ifndef PRODUCEMAC_HMAC_47_H
#define PRODUCEMAC_HMAC_47_H

#endif // PRODUCEMAC_HMAC_47_H

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
class ProduceMAC_HMAC_47 : public QWidget {
    Q_OBJECT
public:
    ProduceMAC_HMAC_47(QWidget *parent = nullptr);
private slots:
    void chooseKeyFile();      // Выбор ключа из файла
    void chooseDataFile();    // Выбор данных из файла
    void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void toggleDataInput();  // Переключение между файлами и вводом вручную данных
    void resetForm();       // Сброс формы
    void produceMAC();     // Выработать имитовставку
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
    //QRadioButton *dataStrRadio;
    //QRadioButton *dataHexRadio;

    QButtonGroup* dataInputGroup;
    QButtonGroup* keyInputGroup;
    QButtonGroup* dataTypeGroup;

    QPushButton * openFileKeyButton;
    QPushButton * openFileDataButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;


    QString *dataString = new QString();
    QString *keyString = new QString();
    QString filePath;
    QByteArray byteDataArray;
    QByteArray byteKeyArray;
};
