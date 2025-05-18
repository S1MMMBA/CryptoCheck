#include "CommonFunc.h"
#include "qregularexpression.h"
const QString printByteArray(const uint8_t* data, size_t size)
{
    QStringList byteStrings;
    for (size_t i = 0; i < size; ++i)
    {
        byteStrings.append(QString("%1").arg(data[i], 2, 16, QChar('0')).toUpper());
    }
    const QString output = byteStrings.join("");
    return output;
    //OutPutLabel->setText(output);
}

const QString printByteArray(const uint16_t* data, size_t size, int base, const QString& delimiterSource)
{
    // Определим первый символ-разделитель
    QChar delimiter;
    for (QChar ch : delimiterSource)
    {
        if (!ch.isDigit())
        {
            delimiter = ch;
            break;
        }
    }

    // Если не нашли разделитель, используем пробел по умолчанию
    if (delimiter.isNull())
    {
        delimiter = ' ';
    }

    QStringList parts;
    for (size_t i = 0; i < size; ++i)
    {
        QString numberStr;
        switch (base)
        {
        case 16:
            numberStr = QString("%1").arg(data[i], 4, base, QChar('0')).toUpper();
            break;
        case 10:
            numberStr = QString::number(data[i], base);
            break;
        case 8:
            numberStr = QString("%1").arg(data[i], 6, base, QChar('0'));
            break;
        case 2:
            numberStr = QString("%1").arg(data[i], 16, base, QChar('0'));
            break;
        default:
            numberStr = QString::number(data[i], base); // Без лидирующих нулей
        }
        parts.append(numberStr);
    }

    return parts.join(delimiter);
}

bool hexStringToByteArray(const QString& hexString, uint8_t* array, size_t arraySize)
{

    if (hexString.size() != arraySize * 2)
    {
        return false;
    }
    for (size_t i = 0; i < arraySize; ++i)
    {
        QString byteStr = hexString.mid(i * 2, 2);
        bool ok = false; // доп проверка на возможность преобразования
        array[i] = static_cast<uint8_t>(byteStr.toUInt(&ok, 16));
        if (!ok)
        {
            return false;
        }
    }
    return true;
}

const uint16_t* parseStringToUShortArray(const QString& input, size_t& outSize)
{
    QRegularExpression re(R"([^0-9]+)");
    QStringList parts = input.split(re, Qt::SkipEmptyParts);

    // Подсчитываем количество корректных чисел
    QVector<uint16_t> tempList;
    for (const QString& part : parts)
    {
        bool ok = false;
        uint16_t value = part.toUShort(&ok, 10); // десятичная система
        if (ok)
        {
            tempList.append(value);
        }
    }

    outSize = static_cast<size_t>(tempList.size());
    uint16_t* result = new uint16_t[outSize];

    for (size_t i = 0; i < outSize; ++i)
    {
        result[i] = tempList[static_cast<int>(i)];
    }

    return result; // вызывающая сторона обязана вызвать delete[]
}
