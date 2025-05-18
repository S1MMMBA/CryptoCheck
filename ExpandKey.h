
#ifndef EXPANDKEY_H
#define EXPANDKEY_H

#endif // EXPANDKEY_H

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
#include "bee2/crypto/belt.h"
class ExpandKey : public QWidget {
    Q_OBJECT
public:
    ExpandKey(QWidget *parent = nullptr);
private slots:
    void chooseKeyFile();      // Выбор ключа из файла
    void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void resetForm();       // Сброс формы
    void expandKey();     // Выработать имитовставку
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * label6;
    QComboBox* numberCombo;
    QTextEdit * fileKeyLabel;
    QTextEdit * OutPutLabel;

   // QTextEdit *enterData;
    QTextEdit *keyInput;



    QRadioButton *fileKeyRadio;
    QRadioButton *manualKeyRadio;



    QButtonGroup* keyInputGroup;


    QPushButton * openFileKeyButton;

    QPushButton *resetButton;
    QPushButton *encryptButton;


    size_t  n;
    QString *keyString = new QString();
    QString filePath;

    QByteArray byteKeyArray;
};
