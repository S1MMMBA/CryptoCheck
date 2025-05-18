
#ifndef HASH_34_101_77_H
#define HASH_34_101_77_H

#endif // HASH_34_101_77_H
#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include <QPushButton>
#include<QFileDialog>
#include<QDir>
#include<QRadioButton>
#include<QMessageBox>
#include<QRegularExpression>
#include<QButtonGroup>
#include<QFile>
#include<QComboBox>
#include "bee2/crypto/bash.h"
class Hash_34_101_77 : public QWidget {
    Q_OBJECT
public:
    Hash_34_101_77(QWidget *parent = nullptr);
private slots:
    void chooseDataFile();    // Выбор данных из файла
    void toggleDataInput();  // Переключение между файлами и вводом вручную данных
    void resetForm();       // Сброс формы
    void encryptData();     // Зашифровать данные
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * fileDataLabel;
    QLineEdit * OutPutLabel;

    QLabel * label6;
    QComboBox* numberCombo;

    QLineEdit *enterData;

    QRadioButton *fileDataRadio;
    QRadioButton *manualDataRadio;

    QButtonGroup* dataInputGroup;

    QPushButton * openFileDataButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;
    QPushButton *decryptButton;

    size_t l;
    QString *dataString = new QString();
    QString filePath;
    QByteArray byteDataArray;
};
