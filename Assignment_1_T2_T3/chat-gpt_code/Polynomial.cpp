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
    size_t maxDegree = max(coeffs.size(), other.coeffs.size());
    vector<double> result(maxDegree, 0.0);

    for (size_t i = 0; i < maxDegree; ++i) {
        if (i < coeffs.size()) result[i] += coeffs[i];
        if (i < other.coeffs.size()) result[i] += other.coeffs[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t maxDegree = max(coeffs.size(), other.coeffs.size());
    vector<double> result(maxDegree, 0.0);

    for (size_t i = 0; i < maxDegree; ++i) {
        if (i < coeffs.size()) result[i] += coeffs[i];
        if (i < other.coeffs.size()) result[i] -= other.coeffs[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0.0);
    for (size_t i = 0; i < coeffs.size(); ++i) {
        for (size_t j = 0; j < other.coeffs.size(); ++j) {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }
    return Polynomial(result);
}

// Equality operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// Output operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        if (i != poly.coeffs.size() - 1) out << (poly.coeffs[i] >= 0 ? "+" : "");
        out << poly.coeffs[i];
        if (i > 0) out << "x^" << i;
    }
    return out;
}

// Utility functions
int Polynomial::degree() const {
    return coeffs.size() - 1;
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = degree(); i >= 0; --i) {
        result = result * x + coeffs[i];
    }
    return result;
}

double Polynomial::getCoefficient(int degree) const {
    if (degree < 0 || degree >= coeffs.size()) return 0.0;
    return coeffs[degree];
}

void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;
}

