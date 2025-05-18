
#ifndef RANDOMGENHMAC_47_H
#define RANDOMGENHMAC_47_H

#endif // RANDOMGENHMAC_47_H
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
#include<QComboBox>
#include "bee2/crypto/brng.h"
class RandomGenHMAC_47 : public QWidget {
    Q_OBJECT
public:
    RandomGenHMAC_47(QWidget *parent = nullptr);
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


    QLabel * label6;
    QComboBox* numberCombo;

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

    size_t n;
    QString *dataString = new QString();
    QString *keyString = new QString();
    QString filePath;
    QByteArray byteDataArray;
    QByteArray byteKeyArray;
};
