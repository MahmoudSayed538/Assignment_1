#include "Polynomial.h"

void runMenu();

int main() {
    runMenu();
    return 0;
}

void runMenu() {
    int choice;
    do {
        cout << "\nPolynomial Operations Menu:\n";
        cout << "1. Add Polynomials\n";
        cout << "2. Subtract Polynomials\n";
        cout << "3. Multiply Polynomials\n";
        cout << "4. Evaluate Polynomial\n";
        cout << "5. Find Polynomial Degree\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) break;

        cout << "Enter the degree of the polynomial: ";
        int degree;
        cin >> degree;

        vector<double> coeffs1(degree + 1);
        vector<double> coeffs2(degree + 1);

        cout << "Enter coefficients for first polynomial (from constant term to highest degree): ";
        for (int i = 0; i <= degree; ++i) {
            cin >> coeffs1[i];
        }

        cout << "Enter coefficients for second polynomial (from constant term to highest degree): ";
        for (int i = 0; i <= degree; ++i) {
            cin >> coeffs2[i];
        }

        Polynomial p1(coeffs1);
        Polynomial p2(coeffs2);

        switch (choice) {
            case 1: {
                Polynomial result = p1 + p2;
                cout << "Result of addition: " << result << endl;
                break;
            }
            case 2: {
                Polynomial result = p1 - p2;
                cout << "Result of subtraction: " << result << endl;
                break;
            }
            case 3: {
                Polynomial result = p1 * p2;
                cout << "Result of multiplication: " << result << endl;
                break;
            }
            case 4: {
                cout << "Enter a value to evaluate the polynomial: ";
                double x;
                cin >> x;
                double value = p1.evaluate(x);
                cout << "Polynomial evaluated at " << x << " is " << value << endl;
                break;
            }
            case 5: {
                cout << "Degree of the first polynomial: " << p1.degree() << endl;
                cout << "Degree of the second polynomial: " << p2.degree() << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);
}

