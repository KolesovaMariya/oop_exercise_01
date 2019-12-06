#include <iostream>
#include"money.h"
#include <fstream>
int main() {
    //для чтения из файла в CLion на винде
    // std::ifstream in(R"(C:\Users\LENOVO\CLionProjects\OOP\lab1\test_01.txt)");
    //std::cin.rdbuf(in.rdbuf());
    Money a, b;
    double c;
    int n = 0;
    std::cout << "Сколько пар сумм вы хотите ввести? ";
    std::cin >> n;
    std::cout << n << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << "TEST # " << i + 1 << std::endl;
        std::cout << "Введите суммы a и b: ";
        a.Read();
        b.Read();
        std::cout << '\n';
        a.Print();
        b.Print();
        std::cout << "Введите дробное число c: ";
        std::cin >> c;
        std::cout << c << std::endl;
        std::cout << "a + b = ";
        a.Sum(b).Print();
        std::cout << "a - b = ";
        if (a.Less(b)) {
            std::cout << "Невозможно выполнить операцию, если из меньшей суммы вычитается большая." << std::endl;
        } else {
            a.Sub(b).Print();
        }
        std::cout << "b - a = ";
        if (b.Less(a)) {
            std::cout << "Невозможно выполнить операцию, если из меньшей суммы вычитается большая." << std::endl;
        } else  {
            b.Sub(a).Print();
        }
        std::cout << "a / b = ";
        if ((b.GetRub() == 0) && (b.GetKop() == 0)) {
            std::cout << "Невозможно вывести результат деления на нулевую сумму" << std::endl;
        } else {
            a.Div(b).Print();
        }
        std::cout << "a / c = ";
        if (c == 0) {
            std::cout << "Невозможно вывести результат деления на 0" << std::endl;
        } else {
            a.DivFract(c).Print();
        }
        std::cout << "b / c = ";
        if (c == 0) {
            std::cout << "Невозможно вывести результат деления на 0" << std::endl;
        } else {
            b.DivFract(c).Print();
        }
        std::cout << "a * c = ";
        a.Mlt(c).Print();
        std::cout << "b * c = ";
        b.Mlt(c).Print();

        std::cout << "a > b? ";
        if (a.More(b)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }

        std::cout << "a < b? ";
        if (a.Less(b)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }

        std::cout << "a == b? ";
        if (a.Equal(b)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}