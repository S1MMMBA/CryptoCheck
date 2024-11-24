
#include "mainwindow.h"
#include "bee2/crypto/belt.h"
#include <QApplication>
#include<iostream>

//void printByteArray(const uint8_t* data, size_t size)
//{
//    QStringList byteStrings;
//    for (size_t i = 0; i < size; ++i) {
//        byteStrings.append(QString("%1").arg(data[i], 2, 16, QChar('0')).toUpper());
//    }
//    qDebug() << byteStrings.join(" ");
//}

int main(int argc, char *argv[])
{
//    octet key[16];
//    octet newKey[32];

//    for(int i = 0 ; i< 16; i++)
//    {
//        key[i] = i;
//        qDebug()<< key[i]<<" ";
//    }
//    beltKeyExpand(newKey, key, 16);
//    qDebug()<<"\n";
//    for(int i = 0 ; i< 32; i++)
//    {
//        qDebug()<< newKey[i]<<" ";
//    }



//    u32 a = 0xB194BAC8;
//    u32 b = 0x0A08F53B;
//    u32 c = 0x366D008E;
//    u32 d = 0x584A5DE4;
//    const u32 key[8] = {0xE9DEE72C,0x8F0C0FA6,0x2DDB49F4,0x6F739647,0x06075316,0xED247A37,0x39CBA383,0x03A98BF6};
//    beltBlockEncr3(&a,&b,&c,&d,key);
//    std::cout << "a = "<<std::hex << std::uppercase << a << std::endl;
//    std::cout << "b = "<<std::hex << std::uppercase << b << std::endl;
//    std::cout << "c = "<<std::hex << std::uppercase << c << std::endl;
//    std::cout << "d = "<<std::hex << std::uppercase << d << std::endl;
//    return 0;



//    uint8_t block[16] = {0xB1, 0x94, 0xBA, 0xC8, 0x0A, 0x08, 0xF5, 0x3B, 0x36, 0x6D, 0x00, 0x8E, 0x58, 0x4A, 0x5D, 0xE4};
//    octet block2[16] = {0xB1, 0x94, 0xBA, 0xC8, 0x0A, 0x08, 0xF5, 0x3B, 0x36, 0x6D, 0x00, 0x8E, 0x58, 0x4A, 0x5D, 0xE4};
//    uint8_t key[32] = {0xE9, 0xDE, 0xE7, 0x2C, 0x8F, 0x0C, 0x0F, 0xA6, 0x2D, 0xDB, 0x49, 0xF4, 0x6F, 0x73, 0x96, 0x47,
//                       0x06, 0x07, 0x53, 0x16, 0xED, 0x24, 0x7A, 0x37, 0x39, 0xCB, 0xA3, 0x83, 0x03, 0xA9, 0x8B, 0xF6};

//    u32 key2[8] = {
//        0x00112233, 0x44556677, 0x8899AABB, 0xCCDDEEFF,
//        0x10203040, 0x50607080, 0x90A0B0C0, 0xD0E0F000
//    };

//    beltBlockEncr3((uint32_t *)block, (uint32_t *)(block + 4), (uint32_t *)(block + 8), (uint32_t *)(block + 12), (uint32_t *)key);
//    beltBlockEncr(block2,(uint32_t *)key);
//    printByteArray(block, sizeof(block));
//    printByteArray(block2,sizeof(block2));
//    return 0;
        QApplication a(argc, argv);
        MainWindow w;

    w.show();
    return a.exec();
}
