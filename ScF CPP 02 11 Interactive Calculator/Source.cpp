#include <string>
#include <iostream>
using namespace std;


void showPrompt() {
    cout << "�����������.\n�������� � ������ �������.\n��������� ��������� ��������:\n";
    cout << "+   -   *   /       &   |   ^ ,\n";
    cout << "� ����� ��������� - f\n";
    cout << "� ���������� � ������� - p.\n";
    cout << "����� - q.\n";
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

int getNumber(string prompt) {
    string input;
    cout << prompt;
    while (true) {
        getline(cin, input);
        if ((input == "") ||
            (!isInteger(input)))
            cout << "������������ ����. ���������� ��� ���. \n";
        else {
            return stoi(input);
        }
    }
}


bool existsSuchOperation(char op) {
    for (char o : operations) {
        if (o == op) return true;
    }
    return false;
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

int add(int operand1, int operand2) {
    return operand1 + operand2;
}

int substract(int operand1, int operand2) {
    return operand1 - operand2;
}

int multiplicate(int operand1, int operand2) {
    return operand1 * operand2;
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

