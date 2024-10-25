#include "Polynomial.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Helper function to read a polynomial from input
Polynomial readPolynomial(istream& in, int degree) {
    vector<double> coefficients(degree + 1);
    for (int i = 0; i <= degree; ++i) {
        in >> coefficients[i];
    }
    return Polynomial(coefficients);
}

// Helper function to process test cases from the file
void processTestCases(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    int testCaseNumber = 1;

    while (getline(file, line)) {
        istringstream ss(line);

        // Reading degrees of the two polynomials
        int degree1, degree2;
        ss >> degree1;
        Polynomial poly1 = readPolynomial(ss, degree1);

        ss >> degree2;
        Polynomial poly2 = readPolynomial(ss, degree2);

        // Print the polynomials
        cout << "Test Case (" << testCaseNumber++ << "): " << endl;
        cout << "Polynomial 1: " << poly1 << endl;
        cout << "Polynomial 2: " << poly2 << endl;

        // Perform operations
        Polynomial sum = poly1 + poly2;
        Polynomial difference = poly1 - poly2;
        Polynomial product = poly1 * poly2;

        // Print results of operations
        cout << "Sum: " << sum << endl;
        cout << "Subtraction: " << difference << endl;
        cout << "Product: " << product << endl;
        cout << "Degree of Polynomial 1: " << poly1.degree() << endl;

        // Evaluate polynomial at x=2
        double eval = poly1.evaluate(2);
        cout << "Evaluation of Polynomial 1 at x=2: " << eval << endl;

        // Separator between test cases
        cout << "---------------------------------" << endl;
    }
}

int main() {
    // Specify the text file containing the test cases
    string filename = "textCases.txt";
    processTestCases(filename);
    return 0;
}

