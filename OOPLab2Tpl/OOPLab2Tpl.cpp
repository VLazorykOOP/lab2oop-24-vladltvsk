#include <iostream>

int main() {
    int a, b, c, d;
    std::cout << "Введіть значення a, b, c та d: ";
    std::cin >> a >> b >> c >> d;

    // Обчислення ((200*a + 312*c)/16) - d*120 + c*124 без множення та ділення

    // Заміна множення на операції зсуву та додавання
    int result = (((a << 7) + (c << 8) - (c << 3)) >> 4) - ((d << 7) + (d << 3)) + ((c << 7) + (c << 6) + (c << 3));

    std::cout << "Результат: " << result << std::endl;

    return 0;
}

/*
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

// Функція для доповнення рядка пробілами до 8 символів
void padString(char s[8][9]) {
    for (int i = 0; i < 8; i++) {
        int len = strlen(s[i]);
        if (len < 8) {
            for (int j = len; j < 8; j++) {
                s[i][j] = ' '; // Доповнюємо пробілами до 8 символів
            }
            s[i][8] = '\0'; // Закриваємо рядок
        }
    }
}

int main() {
    char inputText[8][9];
    ifstream ifs("in.dat");
    if (!ifs) {
        cout << "File in.dat not open" << endl;
        return -1;
    }

    for (int i = 0; i < 8; i++) {
        ifs.getline(inputText[i], 9); // Зчитуємо рядок тексту (максимум 8 символів)
    }
    ifs.close();

    padString(inputText); // Доповнюємо кожен рядок пробілами до 8 символів

    ofstream ofs("outb.dat", ios::binary);
    if (!ofs) {
        cout << "Cannot open outb.dat for writing!" << endl;
        return -1;
    }

    // Шифрування тексту
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char character = inputText[i][j];
            unsigned short byte = 0;

            // Формування байту
            byte |= ((i & 0x07) << 13);                 // Біти 0-2: номер рядка символу
            byte |= ((character & 0x0F) << 6);          // Біти 3-6: молодша частина ASCII коду
            byte |= ((character & 0xF0) << 8);          // Біти 8-11: старша частина ASCII коду
            byte |= ((j & 0x07) << 3);                  // Біти 12-14: позиція символу в рядку
            byte |= ((i ^ character ^ j) & 0x01) << 15; // Біт парності

            // Записуємо шифрований байт у файл
            ofs.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
        }
    }

    ofs.close();

    cout << "Encryption completed. Encrypted text saved to outb.dat." << endl;

    return 0;
}
*/