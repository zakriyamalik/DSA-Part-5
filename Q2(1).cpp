#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& exp) {
    std::stack<char> charStack;

    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            charStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (charStack.empty()) {
                return false;
            }

            char top = charStack.top();
            charStack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; 
            }
        }
    }

    return charStack.empty(); 
}

int main() {
    std::string expression1 = "{[{}{}]}[()]";
    std::string expression2 = "{{}{}]";
    std::string expression3 = "[{}]()";

    if (isBalanced(expression1)) {
        std::cout << "Expression 1 is balanced." << std::endl;
    }
    else {
        std::cout << "Expression 1 is not balanced." << std::endl;
    }

    if (isBalanced(expression2)) {
        std::cout << "Expression 2 is balanced." << std::endl;
    }
    else {
        std::cout << "Expression 2 is not balanced." << std::endl;
    }

    if (isBalanced(expression3)) {
        std::cout << "Expression 3 is balanced." << std::endl;
    }
    else {
        std::cout << "Expression 3 is not balanced." << std::endl;
    }

    return 0;
}
