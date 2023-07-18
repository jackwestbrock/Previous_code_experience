// Copyright 2022 CSCE 240
//
// assumes Rational::Rational()
//         Rational::Rational(int)
//         Rational::Rational(int, int)
//         Rational::num() : int
//         Rational::den() : int
//         Rational::ToString()
//         Rational::operator==(Rational)
//         Rational::operator==(int)
// tests Rational::Plus(Rational)
//       Rational::Plus(int)
//       Rational::operator+(Rational)
//       Rational::operator+(int)
//       operator+(int, Rational)

#include "../inc/test_rational_header.h"


// Tests Rational::Plus(Rational)
inline bool TestRationalPlus(int&& num1, int&& den1,
                                  int&& num2, int&& den2,
                                  const Rational&& expected) {
  std::cout << "TESTING " << kRational_c_str << "::Rational("
    << num1 << ", " << den1 << ")::Plus(\n    " << kRational_c_str
    << "::Rational(" << num2 << ", " << den2 << ")" << std::endl;

  const Rational kLHS(num1, den1), kRHS(num2, den2);

  Rational kActual = kLHS.Plus(kRHS);

  std::cout << "  Expected " << expected << ", Actual " << kActual << '\n';

  PrintPassed(kActual == expected);

  return kActual == expected;
}


// Tests Rational::operator+(Rational)
inline bool TestRationalPlusOp(int&& num1, int&& den1,
                                    int&& num2, int&& den2,
                                    const Rational&& expected) {
  std::cout << "TESTING " << kRational_c_str << "::Rational("
    << num1 << ", " << den1 << ")::operator+(\n    " << kRational_c_str
    << "::Rational(" << num2 << ", " << den2 << ")" << std::endl;

  const Rational kLHS(num1, den1), kRHS(num2, den2);

  const Rational kActual = kLHS + kRHS;

  std::cout << "  Expected " << expected << ", Actual " << kActual << '\n';

  PrintPassed(expected == kActual);

  return expected == kActual;
}


// Tests Rational::Plus(int)
inline bool TestRationalPlusInt(int&& num, int&& den,
                             int&& rhs,
                             const Rational&& expected) {
  std::cout << "TESTING " << kRational_c_str << "::Rational("
    << num << ", " << den << ")::Plus(" << rhs << ")" << std::endl;

  const Rational kLHS(num, den);

  const Rational kActual = kLHS.Plus(rhs);

  std::cout << "  Expected: " << expected << ", Actual: " << kActual << '\n';

  PrintPassed(expected == kActual);

  return expected == kActual;
}


// Tests Rational::operator+(int)
// Tests operator+(int, Rational)
inline bool TestRationalPlusIntOp(int&& num, int&& den,
                               int&& rhs,
                               const Rational&& expected) {
  std::cout << "TESTING " << kRational_c_str << "::Rational("
    << num << ", " << den << ")::operator+(" << rhs << ")" << std::endl;

  const Rational kLHS(num, den);

  const Rational kActual1 = kLHS + rhs;

  std::cout << "  Expected: " << expected << ", Actual: " << kActual1 << '\n';

  std::cout << "TESTING operator+(" << rhs << ", "
    << kRational_c_str << "::Rational(" << num << ", " << den << "))" << std::endl;

  const Rational kActual2 = rhs + kLHS;

  std::cout << "  Expected: " << expected << ", Actual: " << kActual2 << '\n';

  PrintPassed(expected == kActual2);

  return kActual1 == expected && kActual2 == expected;
}


// Calls the function above with various scores and expected values. Uses
// recursion to call all or an individual function. Recursion occurs when test
// is -1 and never surpases depth 1.
int RunTests(int test) {
  if (test == -1) {
    int kTest_count = 4;
    int code = 0;
    for (int i = 0; i < kTest_count; ++i)
      if (code == 0)
        code = RunTests(i);
      else
        RunTests(i);

    return code;
  }

  switch (test) {
    case 0:
      return TestRationalPlus(1, 2, 1, 4, Rational(6, 8)) ? 0 : 1;
    case 1:
      return TestRationalPlusOp(1, 2, 1, 4, Rational(6, 8)) ? 0 : 1;
    case 2:
      return TestRationalPlusInt(1, 2, 3, Rational(7, 2)) ? 0 : 1;
    case 3:
      return TestRationalPlusIntOp(1, 2, 3, Rational(7, 2)) ? 0 : 1;
  }

  return -1;
}


int main(int argc, char* argv[]) {
  const int kTest_idx = 1;

  return RunTests(argc == 2 ? atoi(argv[kTest_idx]) : -1);
}
