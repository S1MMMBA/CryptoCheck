
#ifndef GENPASSOCRA_H
#define GENPASSOCRA_H

#endif // GENPASSOCRA_H

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
#include<QCheckBox>
#include <QDateTime>
#include "bee2/crypto/botp.h"
class GenPassOCRA : public QWidget {
    Q_OBJECT
public:
    GenPassOCRA(QWidget *parent = nullptr);
private slots:
    void chooseKeyFile();      // Выбор ключа из файла
    void chooseQFile();
    void choosePFile();
    void chooseCFile();
    void chooseSFile();
    void chooseDataFile();    // Выбор данных из файла
    void toggleKeyInput();  // Переключение между файлами и вводом вручную ключа
    void toggleQInput();
    void toggleCInput();
    void toggleSInput();
    void togglePInput();
    void toggleDataInput();  // Переключение между файлами и вводом вручную данных
    void resetForm();       // Сброс формы
    void produceMAC();     // Выработать имитовставку
private:
    QVBoxLayout *layout;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * labelq;
    QLabel * labelp;
    QLabel * labelc;
    QLabel * labels;
    QTextEdit * fileKeyLabel;
    QTextEdit * fileQLabel;
    QTextEdit * filePLabel;
    QTextEdit * fileCLabel;
    QTextEdit * fileSLabel;
    QTextEdit * fileDataLabel;
    QTextEdit * OutPutLabel;

    QSpinBox *enterTime;

    QTextEdit *enterData;
    QTextEdit *keyInput;
    QTextEdit *qInput;
    QTextEdit *pInput;
    QTextEdit *cInput;
    QTextEdit *sInput;


    QLabel * label6;
    QComboBox* numberCombo;

    QLabel * label7;
    QLabel * label8;
    QSpinBox * T0input;
    QSpinBox * Tsinput;
    QCheckBox * manualTime;


    QRadioButton *fileDataRadio;
    QRadioButton *manualDataRadio;
    QRadioButton *fileKeyRadio;
    QRadioButton *manualKeyRadio;
    QRadioButton *fileQRadio;
    QRadioButton *manualQRadio;
    QRadioButton *filePRadio;
    QRadioButton *manualPRadio;
    QRadioButton *fileCRadio;
    QRadioButton *manualCRadio;
    QRadioButton *fileSRadio;
    QRadioButton *manualSRadio;
    QRadioButton *dataStrRadio;
    QRadioButton *dataHexRadio;

    QButtonGroup* dataInputGroup;
    QButtonGroup* keyInputGroup;
    QButtonGroup* qInputGroup;
    QButtonGroup* cInputGroup;
    QButtonGroup* sInputGroup;
    QButtonGroup* pInputGroup;
    QButtonGroup* dataTypeGroup;

    QPushButton * openFileKeyButton;
    QPushButton * openFileQButton;
    QPushButton * openFileCButton;
    QPushButton * openFileSButton;
    QPushButton * openFilePButton;
    QPushButton * openFileDataButton;
    QPushButton *resetButton;
    QPushButton *encryptButton;

    size_t n;
    QString *dataString = new QString();
    QString *keyString = new QString();
    QString *qString = new QString();
    QString *cString = new QString();
    QString *sString = new QString();
    QString *pString = new QString();
    QString filePath;
    QByteArray byteDataArray;
    QByteArray byteKeyArray;
    QByteArray byteQArray;
    QByteArray bytePArray;
    QByteArray byteCArray;
    QByteArray byteSArray;
    int T0;
    int Ts;
    int t;
    time_t time;
};
