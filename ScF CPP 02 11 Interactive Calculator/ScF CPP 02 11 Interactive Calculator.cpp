// ScF CPP 02 11 Interactive Calculator.cpp 
#include <iostream>
#include <string>
#include <bitset>
#include <locale.h>
#include "Header.h"


using namespace std;

char operations[] = { '+', '-', '*', '/', '&', '|', '^', 'f', 'p', 'q' };
char operation;
long long operand1;
int operand2;
float result;
string wrongOperation;




int main() {
    setlocale(LC_ALL, "Russian");
    showPrompt();
    while (true) {
        operation = getOperation();
        if (operation == 'q') {
            cout << "До свидания.";
            return 0;
        }
        operand1 = getNumber("Введите число : ");
        if (operation == 'f'){
            if (operand1 < 0) cout << "Факториал отрицательных чисел запрещен." << endl;
            else cout << endl << operand1 << "! = " << factorial(operand1) << endl;
        }
        else{
            operand2 = getNumber("Введите второе число: ");
            cout << endl;
            result = calculate(operation, operand1, operand2);
            if (wrongOperation == "") 
                cout << result << endl << endl;
            else cout << wrongOperation;
            if (operation == '&' ||
                operation == '|' ||
                operation == '^') {
                cout << bitset<8>(operand1) << " " << operation << endl;
                cout << bitset<8>(operand2) << endl;
                cout << "--------" << endl;
                cout << bitset<8>(result) << endl;
            }
        }
    }
    return 0;
}

