// ScF CPP 02 11 Interactive Calculator.cpp 
#include <iostream>
#include <string>
#include <bitset>
#include <locale.h>

using namespace std;

char operations[] = { '+', '-', '*', '/', '&', '|', '^', 'f', 'p', 'q', 'r'};
char operation;
long long operand1;
int operand2;
float result;
string wrongOperation;

void showPrompt();
char getOperation();
int getNumber(string);
__int64 expo(int, int);
unsigned __int64 factorial(int);
bool existsSuchOperation(char);
float calculate(char, int, int);
bool isInteger(string);

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
            if (operation == 'r') {
                calculate(operation, operand1, operand2);
                cout << "Поменялись местами с помощью трех исключающих или." << endl;
                cout << operand1 << " " << operand2 << endl;
                cout << operand1 << " " << operand2 << endl;
                cout << operand1 << " " << operand2 << endl;
                cout << operand1 << " " << operand2 << endl;
                continue;
            }
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

void showPrompt(){
    cout << "Калькулятор.\nРаботает с целыми числами.\nВыполняет следующие операции:\n";
    cout << "+   -   *   /       &   |   ^ ,\n";
    cout << "а также факториал - f\n";
    cout << "и возведение в степень - p.\n";
    cout << "Выход - q.\n";
}

char getOperation() {
    string input;
    cout << endl << "Выберите операцию: ";
    while (true) {
        getline(cin,input);
        if ((input == "") ||
            (input[1] != '\0') ||
            !existsSuchOperation(input[0]))
            cout << "Неправильный ввод. Попробуйте еще раз. \n";
        else return input[0];
    } 
}

int getNumber(string prompt){
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


bool existsSuchOperation(char op) {
    for (char o : operations){
        if (o == op) return true;
    }
    return false;
 }

float calculate(char operation, int operand1, int operand2) {
    wrongOperation = "";
    string explanation;
    explanation += operation;
    if (operation == 'p') explanation = "в степени";
    cout << operand1 << " " << explanation << " " << operand2 << " = ";
    switch (operation){
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':{
        if (operand2){
            return operand1 / (float)operand2;
        }
        else{
            wrongOperation = "Деление на ноль запрещено.\n";
            return 0;
        }
    }
    case '&':
        return operand1 & operand2;
    case '|':
        return operand1 | operand2;
    case '^':
        return operand1 ^ operand2;
    case 'r': 
        ::operand1 ^= ::operand2;
        ::operand2 ^= ::operand1;
        return ::operand1 ^= ::operand2;
    case 'p':
        if (operand2 < 0) {
            wrongOperation = "Калькулятор не умеет возводить в отрицательную степень.\n";
            return 0;
        }
        else {
            return expo(operand1, operand2);
        }
    }

}

__int64 expo(int number, int power) {
    int  result = 1;
    for (int i = 1; i <= power; i++){
        result *= number;
    }
    return result;
}

unsigned __int64 factorial(int n) {
    float result = 1;
    if (n == 0) return 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

bool isInteger(string input) {
    bool firstChar = true;
    if (input == "") return false;
    for (char c : input){
        if (firstChar) {
            firstChar = false;
            if (!((c == '-') || (c >= '0' && c <= '9'))) return false;
        }
        else
            if (!(c >= '0' && c <= '9')) return false;
    }
    return true;
}

