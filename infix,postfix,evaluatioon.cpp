#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

#define MAX 100

/* ---------- CHAR STACK ---------- */
char cstack[MAX];
int ctop = -1;

void cpush(char x) { cstack[++ctop] = x; }
char cpop() { return cstack[ctop--]; }
char cpeek() { return cstack[ctop]; }
bool cisEmpty() { return ctop == -1; }

/* ---------- STRING STACK ---------- */
string sstack[MAX];
int stop = -1;

void spush(string x) { sstack[++stop] = x; }
string spop() { return sstack[stop--]; }

/* ---------- INT STACK ---------- */
int istack[MAX];
int itop = -1;

void ipush(int x) { istack[++itop] = x; }
int ipop() { return istack[itop--]; }

/* ---------- PRECEDENCE ---------- */
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

/* ---------- INFIX TO POSTFIX ---------- */
string infixToPostfix(string infix) {
    ctop = -1; // reset stack
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            cpush(ch);
        }
        else if (ch == ')') {
            while (!cisEmpty() && cpeek() != '(')
                postfix += cpop();
            cpop(); // remove '('
        }
        else {
            while (!cisEmpty() && precedence(cpeek()) >= precedence(ch))
                postfix += cpop();
            cpush(ch);
        }
    }

    while (!cisEmpty())
        postfix += cpop();

    return postfix;
}

/* ---------- POSTFIX TO INFIX ---------- */
string postfixToInfix(string postfix) {
    stop = -1; // reset stack

    for (char ch : postfix) {
        if (isalnum(ch)) {
            spush(string(1, ch));
        } else {
            string b = spop();
            string a = spop();
            spush("(" + a + ch + b + ")");
        }
    }
    return spop();
}

/* ---------- EVALUATE POSTFIX ---------- */
int evaluatePostfix(string postfix) {
    itop = -1; // reset stack

    for (char ch : postfix) {
        if (isdigit(ch)) {
            ipush(ch - '0');
        } else {
            int b = ipop();
            int a = ipop();
            switch (ch) {
                case '+': ipush(a + b); break;
                case '-': ipush(a - b); break;
                case '*': ipush(a * b); break;
                case '/': ipush(a / b); break;
                case '^': ipush(pow(a, b)); break;
            }
        }
    }
    return ipop();
}

/* ---------- MENU ---------- */
int main() {
    int choice;
    string expr;

    do {
        cout << "\n--- Expression Conversion Menu ---\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Postfix to Infix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> expr;
                cout << "Postfix: " << infixToPostfix(expr) << endl;
                break;

            case 2:
                cout << "Enter postfix expression: ";
                cin >> expr;
                cout << "Infix: " << postfixToInfix(expr) << endl;
                break;

            case 3:
                cout << "Enter postfix expression (digits only): ";
                cin >> expr;
                cout << "Result: " << evaluatePostfix(expr) << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
