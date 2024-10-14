#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
private:
    vector<double> coeffs; // Store coefficients of the polynomial

public:
    // Constructors
    Polynomial();
    explicit Polynomial(const vector<double>& coefficients);
    Polynomial(const Polynomial& other);

    // Destructor
    ~Polynomial();

    // Assignment operator
    Polynomial& operator=(const Polynomial& other);

    // Arithmetic operators
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    // Equality operator
    bool operator==(const Polynomial& other) const;

    // Output operator
    friend ostream& operator<<(ostream& out, const Polynomial& poly);

    // Utility functions
    int degree() const;
    double evaluate(double x) const;
    double getCoefficient(int degree) const;
    void setCoefficients(const vector<double>& coefficients);
};

#endif // POLYNOMIAL_H

