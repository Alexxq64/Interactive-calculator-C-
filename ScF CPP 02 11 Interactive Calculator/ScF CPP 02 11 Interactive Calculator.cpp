// ScF CPP 02 11 Interactive Calculator.cpp 
#include <iostream>
#include <string>
#include <bitset>
#include <locale.h>
#include <cstdlib>

using namespace std;

char operations[] = { '+', '-', '*', '/', '&', '|', '^', 'f', 'p', 'q'};
char operation;
long long operand1;
int operand2;
float result;

int inputNumber(string);
long long expo(int, int);
long long factorial(long long);
bool suchOperationExists(char);
float calculate(char, int, int);
//void showBinary(char, int, int);
bool isInteger(string);


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Калькулятор. Работает с целыми числами. Выполняет следующие операции:\n";
    cout << "+ - * /     & | ^,\n";
    cout << "а также факториал - f\n";
    cout << "и возведение в степень - p.\n";
    cout << "Выход - q.\n";
	while (true) {
        cout << endl << endl << "Выберите операцию: ";
		do {
			cin >> operation;
            //cin.clear();
		} while (!suchOperationExists(operation));
		if (operation == 'q') {
			cout << "До свидания";
			return 0;
		}
		operand1 = inputNumber("Введите число : ");

		if (operation == 'f')
		{
			cout << endl << operand1 << "! = ";
			cout << factorial(operand1) << endl;
		}
		else
		{
            operand2 = inputNumber("Введите второе число: ");
            cout << endl;
            result = calculate(operation, operand1, operand2);
            cout << result << endl;
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

int inputNumber(string prompt) {
    string input;
    cout << prompt;
    while (true) {
        getline(cin,input);
        if (input == "") cout << endl << "Test !!!!!" << endl;
        if (isInteger(input)) return stoi(input);
        else cout << "Неправильный ввод. Попробуйте еще раз. \n";
    } 

}

bool suchOperationExists(char op) {
    for (char o : operations)
    {
        if (o == op) return true;
    }
    cout << "Нет такой операции.\n";
    return false;
 }

float calculate(char operation, int operand1, int operand2) {
    string explanation;
    explanation += operation;
    if (operation == 'p') explanation = "в степени";
    cout << operand1 << " " << explanation << " " << operand2 << " = ";
    switch (operation)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
    {
        if (operand2)
        {
            return operand1 / (float)operand2;
        }
        else
        {
            cout << "Деление на ноль запрещено.\n";
            return 0;
        }
    }
    case '&':
        //showBinary(operation, operand1, operand2);
        return operand1 & operand2;
    case '|':
        return operand1 | operand2;
    case '^':
        return operand1 ^ operand2;
    case 'p':
        return expo(operand1, operand2);
    }

}

long long expo(int number, int power) {
    int  result = 1;
    for (int i = 1; i <= power; i++)
    {
        result *= number;
    }
    return result;
}

long long factorial(long long n) {
    return ((n == 1) || (n == 0)) ? 1 : n * factorial(n - 1);
}

bool isInteger(string input) {
    bool firstChar = true;
    if (input == "") return false;
    for (char c : input)
    {
        if (firstChar) {
            firstChar = false;
            if (!((c == '-') || (c >= '0' && c <= '9'))) return false;
        }
        else
            if (!(c >= '0' && c <= '9')) return false;
    }
    return true;
}

//void showBinary(char operation, int operand1, int operand2) {
//    cout << bitset<8>(operand1) << " " << operation << endl;
//    cout << bitset<8>(operand2) << endl;
//
//}