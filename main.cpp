#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstring>
using namespace std;


void task_1 () {

    cout << left << setw(15) << "Тип" << setw(10) << "Размер(байт) " << "Комментарий" << endl;
    cout << string(60, '-') << endl;

    cout << left << setw(15) << "bool" << setw(10) << sizeof(bool) << "Логические значения (True / False)" << endl;

    cout << left << setw(15) << "char" << setw(10) << sizeof(char) << "Обычно код одного символа из ASCII" << endl;

    cout << left << setw(15) << "short" << setw(10) << sizeof(short) << "Небольшие целые числа" << endl;

    cout << left << setw(15) << "int" << setw(10) << sizeof(int) << "Стандартные целые числа" << endl;

    cout << left << setw(15) << "long int" << setw(10) << sizeof(long int) << "Большие целые числа" << endl;

    cout << left << setw(15) << "long long" << setw(10) << sizeof(long long) << "Ещё большие целые числа" << endl;

    cout << left << setw(15) << "float" << setw(10) << sizeof(float) << "Стандартные дробные числа" << endl;

    cout << left << setw(15) << "double" << setw(10) << sizeof(double) << "Большая точность для дробных чисел" << endl;

    cout << left << setw(15) << "long double" << setw(10) << sizeof(long double) << "Ещё большая точность для дробных чисел" << endl;
}


void task_2() {
    int number_1;
    cout << "Введите целое число:" << endl;
    cin >> number_1;
    
    uint32_t bits = 0;
    short amount_bits = sizeof(number_1) * 8;
    memcpy(&bits, &number_1, sizeof(number_1));

    cout << setw(10) << "Бит знака" << " | " << "Биты числа" << endl;
    cout << string(43, '-') << endl;

    for (int i = amount_bits-1; i >=0; i--) {
        cout << ((bits >> i) & 1u);

        if (i == amount_bits-1) {
            cout << " | ";
        }
    }

    cout << endl << endl;

    unsigned int unsigned_number;
    cout << "Введите беззнаковое целое число: " << endl;
    cin >> unsigned_number;

    uint32_t unsigned_bits = 0;
    short unsigned_amount_bits = sizeof(unsigned_number) * 8;

    memcpy(&unsigned_bits, &unsigned_number, sizeof(unsigned_bits));

    cout << "Биты беззнакового числа" << endl;
    cout << string(40, '-') << endl;

    for (int i = unsigned_amount_bits - 1; i >= 0; i--) {
        cout << ((unsigned_bits >> i) & 1u);
    }

    cout << endl << endl;
}

int main () {

    // task_1();
    task_2();
    
    return 0;
}