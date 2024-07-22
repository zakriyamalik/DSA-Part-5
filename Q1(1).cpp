#include <iostream>
#include <cstring>

// Function to print the Fibonacci series up to n using recursion
void printFibonacci(int n, int a = 0, int b = 1) {
    if (n > 0) {
        std::cout << a << " ";
        printFibonacci(n - 1, b, a + b);
    }
}

// Function to calculate the factorial of a number n using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to compare two strings recursively
int stringCompare(const char* string1, const char* string2) {
    if (*string1 == '\0' && *string2 == '\0') {
        return 0; // Strings are equal
    }
    if (*string1 > *string2) {
        return 1;
    }
    if (*string1 < *string2) {
        return -1;
    }
    return stringCompare(string1 + 1, string2 + 1);
}

// Function to find the product of two numbers a and b using recursion
int product(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b > 0) {
        return a + product(a, b - 1);
    }
    if (b < 0) {
        return -product(a, -b);
    }
}

int main() {
    int choice, n;
    char str1[100], str2[100];

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Print Fibonacci series\n";
        std::cout << "2. Calculate Factorial\n";
        std::cout << "3. Compare Strings\n";
        std::cout << "4. Find Product of Two Numbers\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the value of n: ";
            std::cin >> n;
            std::cout << "Fibonacci series up to " << n << ": ";
            printFibonacci(n);
            std::cout << "\n";
            break;
        case 2:
            std::cout << "Enter the value of n: ";
            std::cin >> n;
            std::cout << "Factorial of " << n << ": " << factorial(n) << "\n";
            break;
        case 3:
            std::cout << "Enter the first string: ";
            std::cin >> str1;
            std::cout << "Enter the second string: ";
            std::cin >> str2;
            int result = stringCompare(str1, str2);
            if (result == 0) {
                std::cout << "Strings are equal.\n";
            }
            else if (result > 0) {
                std::cout << "String 1 is greater.\n";
            }
            else {
                std::cout << "String 2 is greater.\n";
            }
            break;
        case 4:
            int a, b;
            std::cout << "Enter the value of a: ";
            std::cin >> a;
            std::cout << "Enter the value of b: ";
            std::cin >> b;
            std::cout << "Product of " << a << " and " << b << ": " << product(a, b) << "\n";
            break;
        case 5:
            std::cout << "Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
