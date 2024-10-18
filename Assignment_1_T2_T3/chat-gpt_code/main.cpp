#include "Polynomial.h"
#include "Polynomial.hpp"





void displayMenu() {
    cout << "Polynomial Operations Menu:\n";
    cout << "1. Add two polynomials\n";
    cout << "2. Subtract two polynomials\n";
    cout << "3. Multiply two polynomials\n";
    cout << "4. Evaluate a polynomial at a point\n";
    cout << "5. Display a polynomial\n";
    cout << "6. Exit\n";
    cout << "Please enter your choice: ";
}

int main() {
    int choice;
    Polynomial p1, p2, result;
    vector<double> coefficients;
    int degree;
    double value;

    // Menu loop
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Add two polynomials
                cout << "Enter the degree of the first polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the first polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p1 = Polynomial(coefficients);

                cout << "Enter the degree of the second polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the second polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p2 = Polynomial(coefficients);

                result = p1 + p2;
                cout << "The result of addition is: " << result << endl;
                break;

            case 2: // Subtract two polynomials
                cout << "Enter the degree of the first polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the first polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p1 = Polynomial(coefficients);

                cout << "Enter the degree of the second polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the second polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p2 = Polynomial(coefficients);

                result = p1 - p2;
                cout << "The result of subtraction is: " << result << endl;
                break;

            case 3: // Multiply two polynomials
                cout << "Enter the degree of the first polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the first polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p1 = Polynomial(coefficients);

                cout << "Enter the degree of the second polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the second polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p2 = Polynomial(coefficients);

                result = p1 * p2;
                cout << "The result of multiplication is: " << result << endl;
                break;

            case 4: // Evaluate polynomial at a point
                cout << "Enter the degree of the polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p1 = Polynomial(coefficients);

                cout << "Enter the value of x to evaluate the polynomial: ";
                cin >> value;

                cout << "The value of the polynomial at x = " << value << " is: " << p1.evaluate(value) << endl;
                break;

            case 5: // Display polynomial
                cout << "Enter the degree of the polynomial: ";
                cin >> degree;
                coefficients.resize(degree + 1);
                cout << "Enter the coefficients of the polynomial: ";
                for (int i = 0; i <= degree; ++i) {
                    cin >> coefficients[i];
                }
                p1 = Polynomial(coefficients);

                cout << "The polynomial is: " << p1 << endl;
                break;

            case 6: // Exit
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
