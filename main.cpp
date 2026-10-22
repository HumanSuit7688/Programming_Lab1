#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <limits>
#include "bit_functions.h"
using namespace std;

template <typename T>
short read_value(string message, T& value) {
    string input;
    cout << message << endl;
    getline(cin, input);

    if (input.empty()) {
        return 0;
    }

    stringstream input_stream(input);
    if (!(input_stream >> value)) {
        cout << "Неверный ввод. Попробуйте еще раз." << endl;
        return -1;
    }

    return 1;
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
    while (true) {
        int number;
        short status = read_value("Введите целое число или пустую строку для выхода:", number);
        if (status == 0) break;
        if (status == -1) continue;

        uint32_t bits = 0;
        short amount_bits = sizeof(number) * 8;
        memcpy(&bits, &number, sizeof(number));

        cout << "Бит знака | Биты числа" << endl;
        cout << string(35, '-') << endl;
        for (int i = amount_bits - 1; i >= 0; i--) {
            cout << ((bits >> i) & 1u);
            if (i == amount_bits - 1) cout << " | ";
        }
        cout << endl << endl;

        unsigned int unsigned_number;
        status = read_value("Введите беззнаковое целое число или пустую строку для выхода:", unsigned_number);
        if (status == 0) break;
        if (status == -1) continue;

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
}

void task_3() {
    while (true) {
        float float_number;
        short status = read_value("Введите дробное (float) число или пустую строку для выхода:", float_number);
        if (status == 0) break;
        if (status == -1) continue;

        uint32_t float_bits = 0;
        short amount_bits = sizeof(float_number) * 8;
        memcpy(&float_bits, &float_number, sizeof(float_number));

        cout << "Бит знака | Биты порядка | Биты мантиссы" << endl;
        cout << string(40, '-') << endl;
        for (short i = amount_bits - 1; i >= 0; i--) {
            cout << ((float_bits >> i) & 1u);
            if (i == amount_bits - 1 || i == amount_bits - 9) cout << " | ";
        }
        cout << endl << endl;
    }
}

void task_4() {
    while (true) {
        double double_number;
        short status = read_value("Введите дробное (double) число или пустую строку для выхода:", double_number);
        if (status == 0) break;
        if (status == -1) continue;

        uint64_t double_bits = 0;
        short amount_bits = sizeof(double_number) * 8;
        memcpy(&double_bits, &double_number, sizeof(double_number));

        cout << "Бит знака | Биты порядка | Биты мантиссы" << endl;
        cout << string(70, '-') << endl;
        for (short i = amount_bits - 1; i >= 0; i--) {
            cout << ((double_bits >> i) & 1u);
            if (i == amount_bits - 1 || i == amount_bits - 12) cout << " | ";
        }
        cout << endl << endl;
    }
}

void task_5();

void demonstration_task_2() {
    int numbers[2] = {42, -42};

    cout << "Положительное целое: " << numbers[0] << endl;
    cout << "Бит знака | Биты числа" << endl;
    cout << string(35, '-') << endl;
    uint32_t bits = 0;
    memcpy(&bits, &numbers[0], sizeof(numbers[0]));
    for (int i = sizeof(numbers[0]) * 8 - 1; i >= 0; i--) {
        cout << ((bits >> i) & 1u);
        if (i == sizeof(numbers[0]) * 8 - 1) cout << " | ";
    }
    cout << endl << endl;

    cout << "Отрицательное целое: " << numbers[1] << endl;
    cout << "Бит знака | Биты числа" << endl;
    cout << string(35, '-') << endl;
    memcpy(&bits, &numbers[1], sizeof(numbers[1]));
    for (int i = sizeof(numbers[1]) * 8 - 1; i >= 0; i--) {
        cout << ((bits >> i) & 1u);
        if (i == sizeof(numbers[1]) * 8 - 1) cout << " | ";
    }
    cout << endl << endl;
}

void demonstration_task_3() {
    float numbers[2] = {3.14f, numeric_limits<float>::denorm_min()};

    for (int number_index = 0; number_index < 2; number_index++) {
        uint32_t bits = 0;
        memcpy(&bits, &numbers[number_index], sizeof(numbers[number_index]));
        cout << (number_index == 0 ? "Обычное значение float: " : "Денормализованное значение float: ")
             << numbers[number_index] << endl;
        cout << "Бит знака | Биты порядка | Биты мантиссы" << endl;
        cout << string(40, '-') << endl;
        for (int i = sizeof(float) * 8 - 1; i >= 0; i--) {
            cout << ((bits >> i) & 1u);
            if (i == sizeof(float) * 8 - 1 || i == sizeof(float) * 8 - 9) cout << " | ";
        }
        cout << endl << endl;
    }
}

void demonstration_task_4() {
    double numbers[2] = {3.141592653589793, numeric_limits<double>::denorm_min()};

    for (int number_index = 0; number_index < 2; number_index++) {
        uint64_t bits = 0;
        memcpy(&bits, &numbers[number_index], sizeof(numbers[number_index]));
        cout << (number_index == 0 ? "Обычное значение double: " : "Денормализованное значение double: ")
             << numbers[number_index] << endl;
        cout << "Бит знака | Биты порядка | Биты мантиссы" << endl;
        cout << string(70, '-') << endl;
        for (int i = sizeof(double) * 8 - 1; i >= 0; i--) {
            cout << ((bits >> i) & 1u);
            if (i == sizeof(double) * 8 - 1 || i == sizeof(double) * 8 - 12) cout << " | ";
        }
        cout << endl << endl;
    }
}

void demonstration_mode() {
    cout << "Демонстрация задания 2" << endl;
    demonstration_task_2();
    cout << "Демонстрация задания 3" << endl;
    demonstration_task_3();
    cout << "Демонстрация задания 4" << endl;
    demonstration_task_4();
}

void user_mode() {
    while (true) {
        short task;
        cout << "Выберите задание:" << endl;
        cout << "1 - Задание 1" << endl;
        cout << "2 - Задание 2" << endl;
        cout << "3 - Задание 3" << endl;
        cout << "4 - Задание 4" << endl;
        cout << "5 - Задание 5" << endl;
        cout << "0 - Вернуться в главное меню" << endl;

        short status = read_value("", task);
        if (status == 0 || task == 0) break;
        if (status == -1 || task < 1 || task > 5) {
            cout << "Неверный номер задания." << endl;
            continue;
        }

        switch (task) {
            case 1: task_1(); break;
            case 2: task_2(); break;
            case 3: task_3(); break;
            case 4: task_4(); break;
            case 5: task_5(); break;
        }
    }
}

bool is_allowed_type(string type, string allowed_types[], int amount_types) {
    for (int i = 0; i < amount_types; i++) {
        if (type == allowed_types[i]) return true;
    }
    return false;
}

void task_5() {
    string allowed_types[8] = {
        "bool", "char", "short int", "int", "long int", "float", "double", "long double"
    };

    while (true) {
        string type;
        do {
            cout << "Введите тип данных или пустую строку для выхода:" << endl;
            getline(cin, type);
            if (type.empty()) break;
            if (!is_allowed_type(type, allowed_types, 8)) {
                cout << "Неверный тип данных. Попробуйте еще раз." << endl;
            }
        } while (!is_allowed_type(type, allowed_types, 8));

        if (type.empty()) break;

        short action;
        short status = read_value("Выберите действие или пустую строку для выхода:\n1 - Установить бит в 1\n2 - Сбросить бит в 0\n3 - Инвертировать бит", action);
        if (status == 0) break;
        if (status == -1 || action < 1 || action > 3) {
            cout << "Неверный код действия, введите еще раз:" << endl;
            continue;
        }

        short position;
        status = read_value("Введите номер бита или пустую строку для выхода:", position);
        if (status == 0) break;
        if (status == -1) continue;

        cout << "Введите значение:" << endl;

        if (type == "bool") {
            bool value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            uint8_t bits = 0;
            memcpy(&bits, &value, sizeof(value));
            uint8_t result_bits = static_cast<uint8_t>(change_and_print(bits, action, position, sizeof(value) * 8));
            if (result_bits > 1) cout << "Неверное число для типа bool";
            else {
                bool result_value;
                memcpy(&result_value, &result_bits, sizeof(result_value));
                cout << "Результат: " << result_value;
            }
        }
        else if (type == "char") {
            char value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            uint8_t bits = 0;
            memcpy(&bits, &value, sizeof(value));
            uint8_t result_bits = static_cast<uint8_t>(change_and_print(bits, action, position, sizeof(value) * 8));
            char result_value;
            memcpy(&result_value, &result_bits, sizeof(result_value));
            cout << "Результат: " << result_value << endl;
        }
        else if (type == "short int") {
            short value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            uint16_t bits = 0;
            memcpy(&bits, &value, sizeof(value));
            uint16_t result_bits = static_cast<uint16_t>(change_and_print(bits, action, position, sizeof(value) * 8));
            short result_value;
            memcpy(&result_value, &result_bits, sizeof(result_value));
            cout << "Результат: " << result_value << endl;
        }
        else if (type == "int") {
            int value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            uint32_t bits = 0;
            memcpy(&bits, &value, sizeof(value));
            uint32_t result_bits = static_cast<uint32_t>(change_and_print(bits, action, position, sizeof(value) * 8));
            int result_value;
            memcpy(&result_value, &result_bits, sizeof(result_value));
            cout << "Результат: " << result_value << endl;
        }
        else if (type == "long int") {
            long int value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            long int result_value = change_long_int_and_print(value, action, position);
            cout << "Результат: " << result_value << endl;
        }
        else if (type == "float") {
            float value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            uint32_t bits = 0;
            memcpy(&bits, &value, sizeof(value));
            uint32_t result_bits = static_cast<uint32_t>(change_and_print(bits, action, position, sizeof(value) * 8));
            float result_value;
            memcpy(&result_value, &result_bits, sizeof(result_value));
            cout << "Результат: " << result_value << endl;
        }
        else if (type == "double") {
            double value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            uint64_t bits = 0;
            memcpy(&bits, &value, sizeof(value));
            uint64_t result_bits = change_and_print(bits, action, position, sizeof(value) * 8);
            double result_value;
            memcpy(&result_value, &result_bits, sizeof(result_value));
            cout << "Результат: " << result_value << endl;
        }
        else if (type == "long double") {
            long double value;
            status = read_value("", value);
            if (status == 0) break;
            if (status == -1) continue;
            long double result_value = change_long_double_bits(value, action, position);
            cout << "Результат: " << result_value << endl;
        }
    }
}

int main() {
    while (true) {
        short mode;
        cout << "Главное меню:" << endl;
        cout << "1 - Пользовательский режим" << endl;
        cout << "2 - Демонстрация заданий 2, 3 и 4" << endl;
        cout << "0 - Выход" << endl;

        short status = read_value("", mode);
        if (status == 0 || mode == 0) break;
        if (status == -1) continue;

        switch (mode) {
            case 1:
                user_mode();
                break;
            case 2:
                demonstration_mode();
                break;
            default:
                cout << "Неверный пункт меню." << endl;
        }
    }

    return 0;
}
