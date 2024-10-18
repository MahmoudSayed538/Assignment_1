#include "Polynomial.h"
#include "Polynomial.hpp"

void displayMenu() {
    cout << "\n===== Polynomial Operations Menu =====\n";
    cout << "1. Enter Polynomial\n";
    cout << "2. Display Polynomial\n";
    cout << "3. Add Two Polynomials\n";
    cout << "4. Subtract Two Polynomials\n";
    cout << "5. Multiply Two Polynomials\n";
    cout << "6. Evaluate Polynomial at a Given Point\n";
    cout << "7. Find Derivative of Polynomial\n";
    cout << "8. Find Integral of Polynomial\n";
    cout << "9. Calculate Definite Integral\n";
    cout << "10. Find Root using Newton's Method\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

Polynomial inputPolynomial() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    
    vector<double> coefficients(degree + 1);
    cout << "Enter the coefficients (from constant to highest degree term): ";
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
    }
    
    return Polynomial(coefficients);
}

int main() {
    Polynomial p1, p2, result;
    bool running = true;

    while (running) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                p1 = inputPolynomial();
                cout << "Polynomial set!\n";
                break;
            }
            case 2: {
                cout << "Polynomial: " << p1 << endl;
                break;
            }
            case 3: {
                cout << "Enter the second polynomial to add:\n";
                p2 = inputPolynomial();
                result = p1 + p2;
                cout << "Result: " << result << endl;
                break;
            }
            case 4: {
                cout << "Enter the second polynomial to subtract:\n";
                p2 = inputPolynomial();
                result = p1 - p2;
                cout << "Result: " << result << endl;
                break;
            }
            case 5: {
                cout << "Enter the second polynomial to multiply:\n";
                p2 = inputPolynomial();
                result = p1 * p2;
                cout << "Result: " << result << endl;
                break;
            }
            case 6: {
                double x;
                cout << "Enter the value of x: ";
                cin >> x;
                cout << "Value of the polynomial at x = " << x << ": " << p1.evaluate(x) << endl;
                break;
            }
            case 7: {
                result = p1.derivative();
                cout << "Derivative: " << result << endl;
                break;
            }
            case 8: {
                result = p1.integral();
                cout << "Integral: " << result << endl;
                break;
            }
            case 9: {
                double x1, x2;
                cout << "Enter the limits (x1 and x2) for the definite integral: ";
                cin >> x1 >> x2;
                cout << "Definite integral: " << p1.integral(x1, x2) << endl;
                break;
            }
            case 10: {
                double guess, tolerance;
                int maxIter;
                cout << "Enter the initial guess: ";
                cin >> guess;
                cout << "Enter the tolerance: ";
                cin >> tolerance;
                cout << "Enter the maximum number of iterations: ";
                cin >> maxIter;
                try {
                    double root = p1.getRoot(guess, tolerance, maxIter);
                    cout << "Root found at: " << root << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 0:
                running = false;
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    
    return 0;
}