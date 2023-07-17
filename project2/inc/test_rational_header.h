// Copyright 2022 CSCE 240
//
#ifndef PROJECT2_INC_TEST_RATIONAL_HEADER_H_
#define PROJECT2_INC_TEST_RATIONAL_HEADER_H_


#include <cstdlib>  //atoi
#include <iostream>
#include <iomanip>
#include <string>

#include "../inc/rational.h"


const char *kRational_c_str = "Rational";

inline void PrintPassed(bool passed) {
  std::cout << (passed ? "  PASSED" : "  FAILED") << std::endl;
}

inline std::ostream& operator<<(std::ostream& lhs, const Rational& rhs) {
  return lhs << rhs.ToString();
}

#endif  // PROJECT2_INC_TEST_RATIONAL_HEADER_H_
