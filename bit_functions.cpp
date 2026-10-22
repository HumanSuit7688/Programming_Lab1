#include <iostream>
#include <cstring>
#include "bit_functions.h"
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


uint64_t change_and_print(uint64_t bits, short action, short position, short amount_bits) {
    cout << "Исходные биты: " << endl;
    print_bits(bits, amount_bits);

    uint64_t result_bits = change_bits(bits, action, position, amount_bits);

    cout << "Изменённые биты: " << endl;
    print_bits(result_bits, amount_bits);

    return result_bits;
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

long int change_long_int_and_print(long int value, short action, short position) {
    int amount_bits = sizeof(value) * 8;

    cout << "Исходные биты: " << endl;

    if (sizeof(value) <= sizeof(uint64_t)) {
        uint64_t bits = 0;
        memcpy(&bits, &value, sizeof(value));
        print_bits(bits, amount_bits);

        uint64_t result_bits = change_bits(bits, action, position, amount_bits);
        cout << "Изменённые биты: " << endl;
        print_bits(result_bits, amount_bits);

        long int result_value;
        memcpy(&result_value, &result_bits, sizeof(result_value));
        return result_value;
    }

    unsigned char bytes[sizeof(value)];
    memcpy(bytes, &value, sizeof(value));

    for (int byte_index = sizeof(value) - 1; byte_index >= 0; byte_index--) {
        for (int bit_index = 7; bit_index >= 0; bit_index--) {
            cout << ((bytes[byte_index] >> bit_index) & 1u);
        }
        if (byte_index > 0) cout << ' ';
    }
    cout << endl;

    if (position < 0 || position >= amount_bits) {
        cout << "Неверный номер бита" << endl;
        return value;
    }

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

    cout << "Изменённые биты: " << endl;
    for (int byte_index = sizeof(value) - 1; byte_index >= 0; byte_index--) {
        for (int bit_index = 7; bit_index >= 0; bit_index--) {
            cout << ((bytes[byte_index] >> bit_index) & 1u);
        }
        if (byte_index > 0) cout << ' ';
    }
    cout << endl;

    long int result_value;
    memcpy(&result_value, bytes, sizeof(result_value));
    return result_value;
}
