import binascii

def write_hex_to_binary(hex_string, file_path):
    try:
        hex_string = hex_string.replace(" ", "").replace("\t", "")
        # Проверяем, состоит ли строка только из допустимых hex-символов
        if not all(c in "0123456789ABCDEFabcdef" for c in hex_string):
            print("Ошибка: строка должна содержать только шестнадцатеричные символы!")
            return
        
        # Преобразуем шестнадцатеричную строку в бинарные данные
        binary_data = binascii.unhexlify(hex_string)
        
        # Записываем бинарные данные в файл
        with open(file_path, "wb") as file:
            file.write(binary_data)
        
        print(f"Данные успешно записаны в файл: {file_path}")
    
    except binascii.Error:
        print("Ошибка: Неправильный формат шестнадцатеричной строки!")

# Ввод данных от пользователя
pairs = "BE 32 97 13 43 FC 9A 48 A0 2A 88 5F 19 4B 09 A1 7E CD A4 D0 15 44 AF 8C A5 84 50 BF 66 D2 E8 8A"
#"E9 DE E7 2C 8F 0C 0F A6 2D DB 49 F4 6F 73 96 47 06 07 53 16 ED 24 7A 37 39 CB A3 83 03 A9 8B F6"
#"B1 94 BA C8 0A 08 F5 3B 36 6D 00 8E 58 4A 5D E4 85 04 FA 9D 1B B6 C7 AC 25 2E 72 C2 02 FD CE 0D 5B E3 D6 12 17 B9 61 81 FE 67 86 AD 71 6B 89 0B 5C B0 C0 FF 33 C3 56 B8 35 C4 05 AE D8 E0 7F 99 E1 2B DC 1A E2 82 57 EC 70 3F CC F0 95 EE 8D F1 C1 AB 76 38 9F E6 78 CA F7 C6 F8 60 D5 BB 9C 4F "
print(pairs)
file_path = "D:\\university\\Coursework\\CryptoCheck\\testData\\RandomGenCTR_47\\iv.bin"


write_hex_to_binary(pairs, file_path)
