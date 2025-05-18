
#ifndef COMMONFUNC_H
#define COMMONFUNC_H

#endif // COMMONFUNC_H
#include <stdint.h>  // For uint8_t and other fixed-width integer types
#include <stddef.h>  // For size_t
#include "bee2/crypto/belt.h"

#include<QString>
#include<QStringList>
#include <QRegularExpression>
const QString printByteArray(const uint8_t* data, size_t size);  // Вывод шифртекста в форму
const QString printByteArray(const uint16_t* data, size_t size, int base, const QString& delimiterSource);
const uint16_t* parseStringToUShortArray(const QString& input, size_t& outSize); // преобразуем строку в массив uint16_t
bool hexStringToByteArray(const QString& hexString, uint8_t* array, size_t arraySize); // преобразование строки в массив HEX

