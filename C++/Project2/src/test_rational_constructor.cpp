// Copyright 2022 CSCE 240
//
// Tests Rational::Rational()
//       Rational::Rational(int)
//       Rational::Rational(int, int)
//       Rational::num() : int
//       Rational::den() : int
//
#include "../inc/test_rational_header.h"

// Tests mapping from constructor parameters to respective accessors
inline bool TestRationalConstructor(const Rational&& obj,
                                    const int&& num,
                                    const int&& den) {
  std::cout << "  Expected " << num << '/' << den
    << ", Actual: " << obj.num() << '/' << obj.den() << '\n';

  return obj.num() == num && obj.den() == den;
}


// Tests three constructors of Rational
inline bool TestRationalConstructor() {
  std::cout << "TESTING " << kRational_c_str << "::Rational()" << std::endl;
  bool passed = TestRationalConstructor(Rational(), 0, 1);

  std::cout << "TESTING " << kRational_c_str << "Rational(int)" << std::endl;
  passed = TestRationalConstructor(Rational(-9), -9, 1) && passed;
  passed = TestRationalConstructor(Rational(7), 7, 1) && passed;

  std::cout << "TESTING " << kRational_c_str << "Rational(int, int)"
    << std::endl;
  passed = TestRationalConstructor(Rational(2, 3), 2, 3)
    && passed;
  passed = TestRationalConstructor(Rational(2, -3), -2, 3)
    && passed;
  passed = TestRationalConstructor(Rational(-2, -2), 2, 2)
    && passed;

  if (passed)
    std::cout << "  PASSED" << std::endl;
  else
    std::cout << "  FAILED" << std::endl;

  return passed;
}


int main(int argc, char* argv[]) {
  return TestRationalConstructor() ? 0 : 1;
}
