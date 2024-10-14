#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

class Polynomial {
private:
    vector<double> coeffs; // Store coefficients of the polynomial
public:
    // Constructors
    Polynomial() : coeffs(1, 0.0) {}
    Polynomial(const vector<double>& coefficients) : coeffs(coefficients) {}
    Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}

    // Destructor
    ~Polynomial() {}

    // Assignment operator
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            coeffs = other.coeffs;
        }
        return *this;
    }

    // Arithmetic operators
    Polynomial operator+(const Polynomial& other) const {
        vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] += other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] -= other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0.0);
        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < other.coeffs.size(); ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return Polynomial(result);
    }

    // Equality operator
    bool operator==(const Polynomial& other) const {
        return coeffs == other.coeffs;
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
            if (poly.coeffs[i] != 0) {
                if (i != poly.coeffs.size() - 1) out << " + ";
                out << poly.coeffs[i];
                if (i > 0) out << "x^" << i;
            }
        }
        return out;
    }

    // Utility functions
    int degree() const {
        return coeffs.size() - 1;
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            result = result * x + coeffs[i];
        }
        return result;
    }

    Polynomial compose(const Polynomial& q) const {
        Polynomial result({0});
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            result = result * q + Polynomial({coeffs[i]});
        }
        return result;
    }

    Polynomial derivative() const {
        if (coeffs.size() == 1) return Polynomial({0});
        vector<double> deriv(coeffs.size() - 1);
        for (size_t i = 1; i < coeffs.size(); ++i) {
            deriv[i - 1] = coeffs[i] * i;
        }
        return Polynomial(deriv);
    }

    Polynomial integral() const {
        vector<double> integr(coeffs.size() + 1, 0.0);
        for (size_t i = 0; i < coeffs.size(); ++i) {
            integr[i + 1] = coeffs[i] / (i + 1);
        }
        return Polynomial(integr);
    }

    double integral(double x1, double x2) const {
        Polynomial integralPoly = integral();
        return integralPoly.evaluate(x2) - integralPoly.evaluate(x1);
    }

    double getRoot(double guess = 1, double tolerance = 1e-6, int maxIter = 100) {
        Polynomial derivPoly = derivative();
        for (int i = 0; i < maxIter; ++i) {
            double fVal = evaluate(guess);
            if (fabs(fVal) < tolerance) return guess;
            double fPrimeVal = derivPoly.evaluate(guess);
            if (fPrimeVal == 0) break; // Avoid division by zero
            guess = guess - fVal / fPrimeVal;
        }
        return guess;
    }

    void setCoefficients(const vector<double>& coefficients) {
        coeffs = coefficients;
    }

    double getCoefficient(int degree) const {
        if (degree < 0 || degree >= static_cast<int>(coeffs.size())) return 0.0;
        return coeffs[degree];
    }
};

// Test function
void runTests() {
    // Test Case 1: Default constructor and degree
    Polynomial p1;
    assert(p1.degree() == 0);

    // Test Case 2: Constructor with coefficients
    Polynomial p2({1, 2, 3});
    assert(p2.degree() == 2);

    // Test Case 3: Addition of polynomials
    Polynomial p3({1, 2, 3});
    Polynomial p4({3, 4, 5});
    Polynomial pAdd = p3 + p4;
    assert(pAdd.getCoefficient(0) == 4 && pAdd.getCoefficient(1) == 6 && pAdd.getCoefficient(2) == 8);

    // Test Case 4: Subtraction of polynomials
    Polynomial pSub = p4 - p3;
    assert(pSub.getCoefficient(0) == 2 && pSub.getCoefficient(1) == 2 && pSub.getCoefficient(2) == 2);

    // Test Case 5: Multiplication of polynomials
    Polynomial pMul = p3 * p4;
    assert(pMul.getCoefficient(0) == 3 && pMul.getCoefficient(1) == 10 && pMul.getCoefficient(2) == 22);

    // Test Case 6: Polynomial evaluation
    double val = p3.evaluate(2);
    assert(val == 17);

    // Test Case 7: Polynomial composition
    Polynomial pComp = p3.compose(p2);
    assert(pComp.getCoefficient(0) == 1);

    // Test Case 8: Polynomial derivative
    Polynomial pDeriv = p3.derivative();
    assert(pDeriv.getCoefficient(0) == 2 && pDeriv.getCoefficient(1) == 6);

    // Test Case 9: Polynomial integral (indefinite)
    Polynomial pInt = p3.integral();
    assert(pInt.getCoefficient(0) == 0 && pInt.getCoefficient(1) == 1 && pInt.getCoefficient(2) == 1 && pInt.getCoefficient(3) == 1);

    // Test Case 10: Polynomial integral (definite)
    double intVal = p3.integral(0, 1);
    assert(fabs(intVal - 2.5) < 1e-6);

    // Test Case 11: Finding roots
    Polynomial pRoot({-6, 1});
    double root = pRoot.getRoot(0);
    assert(fabs(root - 6) < 1e-6);

    // Test Case 12: Copy constructor
    Polynomial pCopy(p3);
    assert(pCopy == p3);

    // Test Case 13: Assignment operator
    Polynomial pAssign;
    pAssign = p3;
    assert(pAssign == p3);

    // More test cases similar to earlier...
    cout << "All tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}

