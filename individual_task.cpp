#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstring>
using namespace std;

void print_bits(float value, int amount_bits) {
    uint32_t bits = 0;
    memcpy(&bits, &value, sizeof(value));
    for (int i = amount_bits - 1; i >= 0; i--) {
        cout << ((bits >> i) & uint32_t{1});
        if (i > 0 && i % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;
}


float invert_mantiss(float value) {
    uint32_t bits = 0;
    memcpy(&bits, &value, sizeof(value));

    uint32_t mask = (uint32_t{1} << 23) - 1;
    bits ^= mask;

    float result;
    memcpy(&result, &bits, sizeof(result));

    return result;
}


int main() {
    cout << "Введите число типа float:" << endl;
    float value;
    cin >> value;

    float new_value = invert_mantiss(value);

    cout << "Исходные биты: " << endl;    
    print_bits(value, sizeof(value) * 8);


    cout << "Изменённые биты: " << endl;    
    print_bits(new_value, sizeof(value) * 8);

    cout << "Результат" << new_value;

    return 0;
}