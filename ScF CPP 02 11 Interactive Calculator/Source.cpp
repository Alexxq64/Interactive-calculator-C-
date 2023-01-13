#include <string>
#include <iostream>
using namespace std;

bool isInteger(string);

void showPrompt() {
    cout << "Калькулятор.\nРаботает с целыми числами.\nВыполняет следующие операции:\n";
    cout << "+   -   *   /       &   |   ^ ,\n";
    cout << "а также факториал - f\n";
    cout << "и возведение в степень - p.\n";
    cout << "Выход - q.\n";
}

int getNumber(string prompt) {
    string input;
    cout << prompt;
    while (true) {
        getline(cin, input);
        if ((input == "") ||
            (!isInteger(input)))
            cout << "Неправильный ввод. Попробуйте еще раз. \n";
        else {
            return stoi(input);
        }
    }
}


int add(int operand1, int operand2) {
    return operand1 + operand2;
}

int substract(int operand1, int operand2) {
    return operand1 - operand2;
}

int multiplicate(int operand1, int operand2) {
    return operand1 * operand2;
}

int _and(int operand1, int operand2) {
    return operand1 & operand2;
}

int _or(int operand1, int operand2) {
    return operand1 | operand2;
}

int _xOr(int operand1, int operand2) {
    return operand1 ^ operand2;
}

__int64 expo(__int64 number, int power) {
    return power == 0 ? 1 : number * expo(number, power - 1);
}

unsigned __int64 factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}

bool isInteger(string input) {
    bool firstChar = true;
    if (input == "") return false;
    for (char c : input) {
        if (firstChar) {
            firstChar = false;
            if (!((c == '-') || (c >= '0' && c <= '9'))) return false;
        }
        else
            if (!(c >= '0' && c <= '9')) return false;
    }
    return true;
}

