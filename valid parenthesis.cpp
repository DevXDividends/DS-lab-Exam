#include <iostream>
#include <string>
using namespace std;

#define MAX 100
class stk {
    char arr[MAX];
    int topIndex = -1;
public:
    void push(char c) {
        if (topIndex == MAX - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++topIndex] = c;
    }

    void pop() {
        topIndex--;
    }

    char peek() {
        return arr[topIndex];
    }

    bool is_empty() {
        return topIndex == -1;
    }
};

bool check(char start, char end) {
    return (start == '(' && end == ')') ||
           (start == '{' && end == '}') ||
           (start == '[' && end == ']');
}

bool isValid(string s) {
    stk stackInstance; 

    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {
            stackInstance.push(c);
        } else if(c=='}' || c==']' || c==')'){
            if(stackInstance.is_empty() || !check(stackInstance.peek(),c))return false;
            stackInstance.pop();
        }
      
    }

   
    return stackInstance.is_empty(); 
}

int main() {
    string c;
    cout << "Enter parentheses string: ";
    cin >> c; 

    if (isValid(c)) {
        cout << "The string is valid (1)" << endl;
    } else {
        cout << "The string is invalid (0)" << endl;
    }

    return 0;
}
