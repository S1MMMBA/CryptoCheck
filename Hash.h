
#ifndef HASH_H
#define HASH_H

#endif // HASH_H

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

class Hash : public QWidget {
    Q_OBJECT
public:
    Hash(QWidget *parent = nullptr);
private slots:
    //void chooseKeyFile();      // Выбор ключа из файла
    void chooseDataFile();    // Выбор данных из файла
    //void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void toggleDataInput();  // Переключение между файлами и вводом вручную данных
    void resetForm();       // Сброс формы
    void encryptData();     // Зашифровать данные
    //void decryptData();     // Расшифровать данные
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    //QLabel * fileKeyLabel;
    QLabel * fileDataLabel;
    QLineEdit * OutPutLabel;

    QLineEdit *enterData;
    //QLineEdit *keyInput;

    QRadioButton *fileDataRadio;
    QRadioButton *manualDataRadio;
    //QRadioButton *fileKeyRadio;
    //QRadioButton *manualKeyRadio;

    QButtonGroup* dataInputGroup;
    //QButtonGroup* keyInputGroup;

    //QPushButton * openFileKeyButton;
    QPushButton * openFileDataButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;
    QPushButton *decryptButton;

    QString *dataString = new QString();
    //QString *keyString = new QString();
    QByteArray byteDataArray;
    //QByteArray byteKeyArray;
};
