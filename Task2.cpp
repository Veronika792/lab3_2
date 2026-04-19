#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x;

    cout << "ЗАВДАННЯ 2: Обчислення значення функції y" << endl;
    cout << "==========================================" << endl;

    // Введення значення x
    cout << "Введіть значення x: ";
    cin >> x;
    cout << endl;

    // Виведення вихідних даних
    cout << "Введене значення: x = " << x << endl;
    cout << endl;

    // Виведення формули
    cout << "Формула для обчислення:" << endl;
    cout << "y = (2 * x?- sin?x) / (cos(2x)+x?) - (x + 1) / ln(x)" << endl;
    cout << endl;

    // Перевірка області визначення
    if (x <= 0) {
        cout << "ПОМИЛКА: ln(x) визначено тільки для x > 0!" << endl;
        return 1;
    }

    // Обчислення зменшуваного
    double sin_x = sin(x);
    double cos_2x = cos(2 * x);
    double numerator1 = 2 * pow(x, 2) - pow(sin_x, 2);
    double denominator1 = cos_2x + pow(x, 2);

    // Перевірка першого знаменника
    if (fabs(denominator1) < 1e-12) {
        cout << "ПОМИЛКА: Перший знаменник дорівнює нулю!" << endl;
        return 1;
    }

    double term1 = numerator1 / denominator1;

    // Обчислення від'ємника
    double numerator2 = x + 1;
    double denominator2 = log(x);

    // Перевірка другого знаменника
    if (fabs(denominator2) < 1e-12) {
        cout << "ПОМИЛКА: Другий знаменник дорівнює нулю!" << endl;
        return 1;
    }

    double term2 = numerator2 / denominator2;

    // Обчислення кінцевого результату
    double y = term1 - term2;

    // Виведення проміжних результатів
    cout << "ПРОМІЖНІ ОБЧИСЛЕННЯ:" << endl;
    cout << "---------------------" << endl;
    cout << "sin(x) = sin(" << x << ") = " << sin_x << endl;
    cout << "cos(2x) = cos(" << 2 * x << ") = " << cos_2x << endl;
    cout << "2 * x?- sin?x = 2 * (" << x << ")?- (" << sin_x << ")? = " << numerator1 << endl;
    cout << "cos(2x)+x? = cos " << 2 * x << " + (" << x << ")? = " << denominator1 << endl;
    cout << "Зменшуване: " << numerator1 << " / " << denominator1 << " = " << term1 << endl;
    cout << endl;

    cout << "x + 1 = " << x << " + 1 = " << numerator2 << endl;
    cout << "ln(x) = ln(" << x << ") = " << denominator2 << endl;
    cout << "Від'ємник: " << numerator2 << " / " << denominator2 << " = " << term2 << endl;
    cout << endl;

    // Виведення кінцевого результату
    cout << "РЕЗУЛЬТАТ:" << endl;
    cout << "----------" << endl;
    cout << "y = " << term1 << " - " << term2 << " = " << y << endl;
    cout << "y = " << fixed << setprecision(6) << y << " (з точністю до 6 знаків)" << endl;

    return 0;
}