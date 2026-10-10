#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstring>
using namespace std;


uint8_t change_8bits (uint8_t bits, short action, short position) {
    short amount_bits = sizeof(bits) * 8;
    if (position < 0 || position >= amount_bits) {
        cout << "Неверный номер бита" << endl;
        return bits;
    }

    uint8_t mask = (uint8_t{1} << position);

    switch(action) {
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


uint16_t change_16bits (uint16_t bits, short action, short position) {
    short amount_bits = sizeof(bits) * 8;
    if (position < 0 || position >= amount_bits) {
        cout << "Неверный номер бита" << endl;
        return bits;
    }

    uint16_t mask = (uint16_t{1} << position);

    switch(action) {
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


uint32_t change_32bits(uint32_t bits, short action, short position) {
    short amount_bits = sizeof(bits) * 8;
    if (position < 0 || position >= amount_bits) {
        cout << "Неверный номер бита" << endl;
        return bits;
    }
    
    uint32_t mask = (1u << position);

    switch(action) {
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


uint64_t change_64bits (uint64_t bits, short action, short position) {
    short amount_bits = sizeof(bits) * 8;
    if (position < 0 || position >= amount_bits) {
        cout << "Неверный номер бита" << endl;
        return bits;
    }

    uint64_t mask = (uint64_t{1} << position);

    switch(action) {
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


void print_bits(uint64_t bits, int amount_bits) {
    for (int i = amount_bits - 1; i >= 0; i--) {
        cout << ((bits >> i) & uint64_t{1});
        if (i > 0 && i % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;
}


int main() {
    cout << "Введите тип данных:" << endl;
    string type;
    getline(cin, type);

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
    } while(action < 1 || action > 3);

    short position;
    cout << "Введите номер бита, который хотите поменять:" << endl;
    cin >> position;

    cout << "Введите значение:" << endl;

    if (type == "bool") {
        bool value;
        cin >> value;
        uint8_t bits = 0;
        memcpy(&bits, &value, sizeof(value));
        uint8_t result_bits = change_8bits(bits, action, position);
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

        cout << "Исходные биты: " << endl;
        print_bits(bits, sizeof(value) * 8);

        uint8_t result_bits = change_8bits(bits, action, position);
        cout << "Изменённые биты: " << endl;
        print_bits(result_bits, sizeof(value) * 8);

        char result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "short int") {
        short value;
        cin >> value;
        uint16_t bits = 0;
        memcpy(&bits, &value, sizeof(value));
        
        cout << "Исходные биты: " << endl;
        print_bits(bits, sizeof(value) * 8);

        uint16_t result_bits = change_16bits(bits, action, position);
        cout << "Изменённые биты: " << endl;
        print_bits(result_bits, sizeof(value) * 8);

        short result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "int") {
        int value;
        cin >> value;
        uint32_t bits = 0;
        memcpy(&bits, &value, sizeof(value));
        
        cout << "Исходные биты: " << endl;
        print_bits(bits, sizeof(value) * 8);

        uint32_t result_bits = change_32bits(bits, action, position);
        cout << "Изменённые биты: " << endl;
        print_bits(result_bits, sizeof(value) * 8);

        int result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
        
    }
    else if (type == "long int") {
        long int value;
        cin >> value;
        uint32_t bits = 0;
        memcpy(&bits, &value, sizeof(value));
        uint32_t result_bits = change_32bits(bits, action, position);
        long int result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "float") {
        float value;
        cin >> value;
        uint32_t bits = 0;
        memcpy(&bits, &value, sizeof(value));
        
        cout << "Исходные биты: " << endl;
        print_bits(bits, sizeof(value) * 8);

        uint32_t result_bits = change_32bits(bits, action, position);
        cout << "Изменённые биты: " << endl;
        print_bits(result_bits, sizeof(value) * 8);
        
        float result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        cout << "Результат: " << result_value;
    }
    else if (type == "double") {
        double value;
        cin >> value;
        uint64_t bits = 0;
        memcpy(&bits, &value, sizeof(value));
        
        cout << "Исходные биты: " << endl;
        print_bits(bits, sizeof(value) * 8);

        uint64_t result_bits = change_64bits(bits, action, position);
        cout << "Изменённые биты: " << endl;
        print_bits(result_bits, sizeof(value) * 8);

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

    return 0;
}