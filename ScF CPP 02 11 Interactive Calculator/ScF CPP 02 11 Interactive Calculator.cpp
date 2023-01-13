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
            cout << "�� ��������.";
            return 0;
        }
        operand1 = getNumber("������� ����� : ");
        if (operation == 'f'){
            if (operand1 < 0) cout << "��������� ������������� ����� ��������." << endl;
            else cout << endl << operand1 << "! = " << factorial(operand1) << endl;
        }
        else{
            operand2 = getNumber("������� ������ �����: ");
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

float calculate(char operation, int operand1, int operand2) {
    wrongOperation = "";
    string explanation;
    explanation += operation;
    if (operation == 'p') explanation = "� �������";
    cout << operand1 << " " << explanation << " " << operand2 << " = ";
    switch (operation) {
    case '+':
        return add(operand1, operand2);
    case '-':
        return substract(operand1, operand2);
    case '*':
        return multiplicate(operand1, operand2);
    case '/':
        return divide(operand1, (float)operand2);
    case '&':
        return _and(operand1, operand2);
    case '|':
        return _or(operand1, operand2);
    case '^':
        return _xOr(operand1, operand2);
    case 'p':
        if (operand2 < 0) {
            wrongOperation = "����������� �� ����� ��������� � ������������� �������.\n";
            return 0;
        }
        else {
            return expo(operand1, operand2);
        }
    }

}

bool existsSuchOperation(char op) {
    for (char o : operations) {
        if (o == op) return true;
    }
    return false;
}

char getOperation() {
    string input;
    cout << endl << "�������� ��������: ";
    while (true) {
        getline(cin, input);
        if ((input == "") ||
            (input[1] != '\0') ||
            !existsSuchOperation(input[0]))
            cout << "������������ ����. ���������� ��� ���. \n";
        else return input[0];
    }
}

float divide(int operand1, int operand2) {
    if (operand2) {
        return operand1 / (float)operand2;
    }
    else {
        wrongOperation = "������� �� ���� ���������.\n";
        return 0;
    }
}


