#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstring>
using namespace std;


void print_bits(uint64_t bits, int amount_bits) {
    for (int i = amount_bits - 1; i >= 0; i--) {
        cout << ((bits >> i) & uint64_t{1});

        if (i > 0 && i % 8 == 0) {
            cout << ' ';
        }
    }

    cout << endl;
}


void task_1() {
    cout << left << setw(15) << "Тип" << setw(10) << "Размер(байт) " << "Комментарий" << endl;
    cout << string(60, '-') << endl;

    cout << left << setw(15) << "bool" << setw(10) << sizeof(bool) << "Логические значения (True / False)" << endl;
    cout << left << setw(15) << "char" << setw(10) << sizeof(char) << "Обычно код одного символа из ASCII" << endl;
    cout << left << setw(15) << "short int" << setw(10) << sizeof(short) << "Небольшие целые числа" << endl;
    cout << left << setw(15) << "int" << setw(10) << sizeof(int) << "Стандартные целые числа" << endl;
    cout << left << setw(15) << "long int" << setw(10) << sizeof(long int) << "Большие целые числа" << endl;
    cout << left << setw(15) << "long long" << setw(10) << sizeof(long long) << "Ещё большие целые числа" << endl;
    cout << left << setw(15) << "float" << setw(10) << sizeof(float) << "Стандартные дробные числа" << endl;
    cout << left << setw(15) << "double" << setw(10) << sizeof(double) << "Большая точность для дробных чисел" << endl;
    cout << left << setw(15) << "long double" << setw(10) << sizeof(long double) << "Ещё большая точность для дробных чисел" << endl;

    cout << endl;
}


void task_2() {
    int number;
    cout << "Введите целое число:" << endl;
    cin >> number;

    uint32_t bits = 0;
    short amount_bits = sizeof(number) * 8;
    memcpy(&bits, &number, sizeof(number));

    cout << "Бит знака | Биты числа" << endl;
    cout << string(35, '-') << endl;

    for (int i = amount_bits - 1; i >= 0; i--) {
        cout << ((bits >> i) & 1u);

        if (i == amount_bits - 1) {
            cout << " | ";
        }
    }

    cout << endl << endl;

    unsigned int unsigned_number;
    cout << "Введите беззнаковое целое число: " << endl;
    cin >> unsigned_number;

    uint32_t unsigned_bits = 0;
    short unsigned_amount_bits = sizeof(unsigned_number) * 8;
    memcpy(&unsigned_bits, &unsigned_number, sizeof(unsigned_number));

    cout << "Биты беззнакового числа" << endl;
    cout << string(32, '-') << endl;

    for (int i = unsigned_amount_bits - 1; i >= 0; i--) {
        cout << ((unsigned_bits >> i) & 1u);
    }

    cout << endl << endl;
}


void task_3() {
    float float_number;
    cout << "Введите дробное (float) число:" << endl;
    cin >> float_number;

    uint32_t float_bits = 0;
    short float_amount_bits = sizeof(float_number) * 8;
    memcpy(&float_bits, &float_number, sizeof(float_number));

    cout << "Бит знака | Биты порядка | Биты мантиссы" << endl;
    cout << string(40, '-') << endl;

    for (short i = float_amount_bits - 1; i >= 0; i--) {
        cout << ((float_bits >> i) & 1u);

        if (i == float_amount_bits - 1 || i == float_amount_bits - 9) {
            cout << " | ";
        }
    }

    cout << endl << endl;
}


void task_4() {
    double double_number;
    cout << "Введите дробное (double) число:" << endl;
    cin >> double_number;

    uint64_t double_bits = 0;
    short double_amount_bits = sizeof(double_number) * 8;
    memcpy(&double_bits, &double_number, sizeof(double_number));

    cout << "Бит знака | Биты порядка | Биты мантиссы" << endl;
    cout << string(70, '-') << endl;

    for (short i = double_amount_bits - 1; i >= 0; i--) {
        cout << ((double_bits >> i) & 1u);

        if (i == double_amount_bits - 1 || i == double_amount_bits - 12) {
            cout << " | ";
        }
    }

    cout << endl << endl;
}


uint64_t change_bits(uint64_t bits, short action, short position, short amount_bits) {
    if (position < 0 || position >= amount_bits) {
        cout << "Неверный номер бита" << endl;
        return bits;
    }

    uint64_t mask = uint64_t{1} << position;

    switch (action) {
        case 1:
            bits |= mask;
            break;
        case 2:
            bits &= ~mask;
            break;
        case 3:
            bits ^= mask;
            break;
    }

    return bits;
}


long double change_long_double_bits(long double value, short action, short position) {
    int amount_bits = sizeof(value) * 8;

    if (position < 0 || position >= amount_bits) {
        cout << "Неверный номер бита" << endl;
        return value;
    }

    unsigned char bytes[sizeof(value)];
    memcpy(bytes, &value, sizeof(value));

    int byte_index = position / 8;
    int bit_index = position % 8;
    unsigned char mask = static_cast<unsigned char>(1u << bit_index);

    switch (action) {
        case 1:
            bytes[byte_index] |= mask;
            break;
        case 2:
            bytes[byte_index] &= static_cast<unsigned char>(~mask);
            break;
        case 3:
            bytes[byte_index] ^= mask;
            break;
    }

    long double result_value;
    memcpy(&result_value, bytes, sizeof(result_value));

    return result_value;
}


uint64_t change_and_print(uint64_t bits, short action, short position, short amount_bits) {
    cout << "Исходные биты: " << endl;
    print_bits(bits, amount_bits);

    uint64_t result_bits = change_bits(bits, action, position, amount_bits);

    cout << "Изменённые биты: " << endl;
    print_bits(result_bits, amount_bits);

    return result_bits;
}


bool is_allowed_type(string type, string allowed_types[], int amount_types) {
    for (int i = 0; i < amount_types; i++) {
        if (type == allowed_types[i]) {
            return true;
        }
    }

    return false;
}


void task_5() {
    string allowed_types[8] = {
        "bool", "char", "short int", "int",
        "long int", "float", "double", "long double"
    };

    string type;
    do {
        cout << "Введите тип данных:" << endl;
        getline(cin, type);

        if (!is_allowed_type(type, allowed_types, 8)) {
            cout << "Неверный тип данных. Попробуйте еще раз." << endl;
        }
    } while (!is_allowed_type(type, allowed_types, 8));

    short action;
    cout << "Выберите действие:" << endl;
    cout << "1 - Установить бит в 1" << endl;
    cout << "2 - Сбросить бит в 0" << endl;
    cout << "3 - Инвертировать бит" << endl;

    do {
        cin >> action;

        if (action < 1 || action > 3) {
            cout << "Неверный код действия, введите еще раз:" << endl;
        }
    } while (action < 1 || action > 3);

    short position;
    cout << "Введите номер бита, который хотите поменять:" << endl;
    cin >> position;

    cout << "Введите значение:" << endl;

    if (type == "bool") {
        bool value;
        cin >> value;

        uint8_t bits = 0;
        memcpy(&bits, &value, sizeof(value));

        uint8_t result_bits = static_cast<uint8_t>(
            change_and_print(bits, action, position, sizeof(value) * 8)
        );

        if (result_bits > 1) {
            cout << "Неверное число для типа bool";
        }
        else {
            bool result_value;
            memcpy(&result_value, &result_bits, sizeof(result_value));
            cout << "Результат: " << result_value;
        }
    }
    else if (type == "char") {
        char value;
        cin >> value;

        uint8_t bits = 0;
        memcpy(&bits, &value, sizeof(value));

        uint8_t result_bits = static_cast<uint8_t>(
            change_and_print(bits, action, position, sizeof(value) * 8)
        );

        char result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "short int") {
        short value;
        cin >> value;

        uint16_t bits = 0;
        memcpy(&bits, &value, sizeof(value));

        uint16_t result_bits = static_cast<uint16_t>(
            change_and_print(bits, action, position, sizeof(value) * 8)
        );

        short result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "int") {
        int value;
        cin >> value;

        uint32_t bits = 0;
        memcpy(&bits, &value, sizeof(value));

        uint32_t result_bits = static_cast<uint32_t>(
            change_and_print(bits, action, position, sizeof(value) * 8)
        );

        int result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "long int") {
        long int value;
        cin >> value;

        uint32_t bits = 0;
        memcpy(&bits, &value, sizeof(value));

        uint32_t result_bits = static_cast<uint32_t>(
            change_and_print(bits, action, position, sizeof(value) * 8)
        );

        long int result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "float") {
        float value;
        cin >> value;

        uint32_t bits = 0;
        memcpy(&bits, &value, sizeof(value));

        uint32_t result_bits = static_cast<uint32_t>(
            change_and_print(bits, action, position, sizeof(value) * 8)
        );

        float result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "double") {
        double value;
        cin >> value;

        uint64_t bits = 0;
        memcpy(&bits, &value, sizeof(value));

        uint64_t result_bits = change_and_print(
            bits, action, position, sizeof(value) * 8
        );

        double result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "long double") {
        long double value;
        cin >> value;

        long double result_value = change_long_double_bits(value, action, position);
        cout << "Результат: " << result_value << endl;
    }
}


int main() {
    short task;

    cout << "Выберите задание:" << endl;
    cout << "1 - Задание 1" << endl;
    cout << "2 - Задание 2" << endl;
    cout << "3 - Задание 3" << endl;
    cout << "4 - Задание 4" << endl;
    cout << "5 - Задание 5" << endl;

    cin >> task;
    cin.ignore();

    switch (task) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            task_3();
            break;
        case 4:
            task_4();
            break;
        case 5:
            task_5();
            break;
        default:
            cout << "Такого задания нет" << endl;
    }

    return 0;
}
