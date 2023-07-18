// Copyright 2022 CSCE 240
//
#ifndef PROJECT2_INC_TEST_GRADE_HEADER_H_
#define PROJECT2_INC_TEST_GRADE_HEADER_H_

#include <cstdlib>  // atoi
#include <iostream>
#include <iomanip>
#include <string>

#include "../inc/grade.h"
#include "../inc/rational.h"


const char *kRational_c_str = "Rational";
const char *kGrade_c_str = "Grade";

inline void PrintPassed(bool passed) {
  std::cout << (passed ? "  PASSED" : "  FAILED") << std::endl;
}

#endif  // PROJECT2_INC_TEST_GRADE_HEADER_H_
