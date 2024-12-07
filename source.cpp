#include <iostream>
#include <stdexcept>


double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

void printHistory(const double* history, int historySize);
void clearHistory(double*& history, int& historySize);

int main() {
    double* history = nullptr;
    int historySize = 0;
    int choice;

    while (true) {
        std::cout << "\nSimple Calculator with History\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n";
        std::cout << "5. View History\n";
        std::cout << "6. Clear History\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: Add";
        std::cin >> choice;

        double num1, num2, result;

        switch (choice) {
            case 1:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                result = add(num1, num2);
                break;
            case 2:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                result = subtract(num1, num2);
                break;
            case 3:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                result = multiply(num1, num2);
                break;
            case 4:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                try {
                    result = divide(num1, num2);
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                    continue;
                }
                break;
            case 5:
                printHistory(history, historySize);
                continue;
            case 6:
                clearHistory(history, historySize);
                continue;
            case 7:
                clearHistory(history, historySize);
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice, please try again.\n";
                continue;
        }


        auto* tempHistory = new double[historySize + 1]; // Resize the history array
        for (int i = 0; i < historySize; ++i) {
            tempHistory[i] = history[i];
        }
        tempHistory[historySize] = result;
        delete[] history;
        history = tempHistory;
        ++historySize;

        std::cout << "Result: " << result << std::endl;
    }
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Error: Division by zero.");
    }
    return a / b;
}

void printHistory(const double* history, int historySize) {
    if (historySize == 0) {
        std::cout << "No history available.\n";
    } else {
        std::cout << "Calculation History:\n";
        for (int i = 0; i < historySize; ++i) {
            std::cout << history[i] << std::endl;
        }
    }
}

void clearHistory(double*& history, int& historySize) {
    delete[] history;
    history = nullptr;
    historySize = 0;
    std::cout << "History cleared.\n";
}
