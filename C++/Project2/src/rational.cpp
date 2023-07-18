#include "../inc/rational.h"

#include <cassert>
#include <cmath>
#include <string>
#include <utility>
#include <iostream>

// Rational::Rational() {
    
// }

// Rational::Rational(int num) {
//     num_ = num;
//     den_ = 1; 
// }

Rational::Rational(int num, int den) {
    num_ = num;
    den_ = den;
    neg_ = ((num < 0) && (den < 0));
    assert(den_ != 0);
}

int Rational::num() const {
    return !neg_ ? num_ : -num_;
}
int Rational::den() const {
    return den_;
}

double Rational::ToDouble() const {
    return static_cast<double>(num()) / static_cast<double>(den_);
}

const std::string Rational::ToString() const {
    if(num_ == 0)
        return "0";
    if(den_ == 1)
        return std::to_string(num_);
    int gcd = GCD(num_, den_);

    return std::to_string(num() / gcd) + '/' + std::to_string(den_ / gcd);
}

bool Rational::Equals(const Rational& right_hand_side) const {
    return num() * right_hand_side.den_ == right_hand_side.num() * den_;
}

bool Rational::operator==(const Rational& right_hand_side) const {
    return Equals(right_hand_side);
}

bool Rational::Equals(int right_hand_side) const {
    if(den_ == 1)
        return num() == right_hand_side;
    else 
        return num()/static_cast<int>(den()) == right_hand_side;
}

bool Rational::operator==(int right_hand_side) const {
    return Equals(right_hand_side);
}

const Rational Rational::DividedBy(const Rational& right_hand_side) const {
    return Rational(num() * right_hand_side.den_, den_ * right_hand_side.num());
}

const Rational Rational::operator/(const Rational& right_hand_side) const {
    return DividedBy(right_hand_side);
}

const Rational Rational::DividedBy(int right_hand_side) const {
    return Rational(num_, den_ * right_hand_side);
}

const Rational Rational::operator/(int right_hand_side) const {
    return DividedBy(right_hand_side);
}

const Rational Rational::Plus(const Rational& right_hand_side) const {
    if(den_ == right_hand_side.den_)
        return Rational(num() + right_hand_side.num(), den_);
    return Rational(num() * right_hand_side.den_ + right_hand_side.num() * den_, den_ * right_hand_side.den_);

}

const Rational Rational::operator+(const Rational& right_hand_side) const {
    return Plus(right_hand_side);
}

const Rational Rational::Plus(int right_hand_side) const {
    return Rational(num() + right_hand_side * den_, den_);
}

const Rational Rational::operator+(int right_hand_side) const {
    return Plus(right_hand_side);
}

int Rational::GCD(int x, int y) const {
    while(x != y) {
        if(x < y)
            x -= y;
        else
            y -= x;
    }
    return x;
}

bool operator==(int left_hand_side, const Rational& right_hand_side) {
    return right_hand_side.Equals(left_hand_side);
}

const Rational operator/(int left_hand_side, const Rational& right_hand_side) {
    return Rational(left_hand_side * right_hand_side.den(), right_hand_side.num());
}

const Rational operator+(int left_hand_side, const Rational& right_hand_side) {
    return right_hand_side.Plus(left_hand_side);
}







