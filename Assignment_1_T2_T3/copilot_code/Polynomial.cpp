#include "Polynomial.h"

// Constructors
Polynomial::Polynomial() : coeffs(1, 0.0) {}

Polynomial::Polynomial(const vector<double>& coefficients) : coeffs(coefficients) {}

Polynomial::Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}

// Destructor
Polynomial::~Polynomial() {}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coeffs = other.coeffs;
    }
    return *this;
}

// Arithmetic operators
Polynomial Polynomial::operator+(const Polynomial& other) const {
    int max_deg = max(coeffs.size(), other.coeffs.size());
    vector<double> result_coeffs(max_deg, 0.0);
    for (int i = 0; i < max_deg; ++i) {
        if (i < coeffs.size()) result_coeffs[i] += coeffs[i];
        if (i < other.coeffs.size()) result_coeffs[i] += other.coeffs[i];
    }
    return Polynomial(result_coeffs);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    int max_deg = max(coeffs.size(), other.coeffs.size());
    vector<double> result_coeffs(max_deg, 0.0);
    for (int i = 0; i < max_deg; ++i) {
        if (i < coeffs.size()) result_coeffs[i] += coeffs[i];
        if (i < other.coeffs.size()) result_coeffs[i] -= other.coeffs[i];
    }
    return Polynomial(result_coeffs);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<double> result_coeffs(coeffs.size() + other.coeffs.size() - 1, 0.0);
    for (int i = 0; i < coeffs.size(); ++i) {
        for (int j = 0; j < other.coeffs.size(); ++j) {
            result_coeffs[i + j] += coeffs[i] * other.coeffs[j];
        }
    }
    return Polynomial(result_coeffs);
}

// Equality operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// Output operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        if (poly.coeffs[i] != 0) {
            if (i != poly.coeffs.size() - 1 && poly.coeffs[i] > 0)
                out << "+";
            out << poly.coeffs[i];
            if (i > 0)
                out << "x^" << i << " ";
        }
    }
    return out;
}

// Utility functions
int Polynomial::degree() const {
    return coeffs.size() - 1;
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i < coeffs.size(); ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result;
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result = result * q + Polynomial(vector<double>{coeffs[i]});
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    vector<double> result_coeffs(coeffs.size() - 1, 0.0);
    for (int i = 1; i < coeffs.size(); ++i) {
        result_coeffs[i - 1] = coeffs[i] * i;
    }
    return Polynomial(result_coeffs);
}

Polynomial Polynomial::integral() const {
    vector<double> result_coeffs(coeffs.size() + 1, 0.0);
    for (int i = 0; i < coeffs.size(); ++i) {
        result_coeffs[i + 1] = coeffs[i] / (i + 1);
    }
    return Polynomial(result_coeffs);
}

double Polynomial::integral(double x1, double x2) const {
    Polynomial integrated = integral();
    return integrated.evaluate(x2) - integrated.evaluate(x1);
}

double Polynomial::getRoot(double guess, double tolerance, int maxIter) {
    Polynomial deriv = derivative();
    for (int i = 0; i < maxIter; ++i) {
        double value = evaluate(guess);
        if (abs(value) < tolerance) return guess;
        double slope = deriv.evaluate(guess);
        if (slope == 0) break;
        guess -= value / slope;
    }
    throw runtime_error("Root not found within the specified tolerance and iterations.");
}

void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;
}

double Polynomial::getCoefficient(int degree) const {
    if (degree < 0 || degree >= coeffs.size())
        throw out_of_range("Degree is out of range.");
    return coeffs[degree];
}

