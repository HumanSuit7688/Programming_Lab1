#include <iostream>
#include <iomanip>
using namespace std;

void task1 () {

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

int main () {

    task1();

    return 0;
}

