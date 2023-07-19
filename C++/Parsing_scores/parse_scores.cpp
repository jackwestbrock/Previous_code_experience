// Copyright 2023 CSCE 240
//
#include <hw2/parse_scores.h>
#include <string>
#include <stdexcept>
//#include <iostream>



bool CheckFormat(const std::string input[], const size_t kSize) {
  if (kSize < 2)
    return false;

  size_t index = 1;  // start at number of grades
  if (index >= kSize)  // validate index in range
    return false;

  // validate number of grades--non-negative integer
  int grade_no;
  try {
    grade_no = std::stoi(input[index]);
    if (grade_no < 0)
      return false;
  } catch (const std::invalid_argument& exception) {
    return false;
  }

  ++index;  // update to first grade
  for (int j = 0; j < grade_no; ++j) {
    if (index >= kSize)
      return false;

    // validate grade---floating point
    try {
      double grade = std::stod(input[index]);
      if (grade < 0)
        return false;
    } catch (const std::invalid_argument& exception) {
      return false;
    }
    ++index;  // update to next grade
  }

  return true;
}

double GetGrade(size_t grade_index, const std::string input[], size_t size) {
    if (!CheckFormat(input, size)) { // check input format
        return -1;
    }
    if (input == nullptr) { // check if input array is null
        return -2;
    }
    for (size_t i = 2; i < size; ++i) { // iterate through input array
        if ((i - 2) == grade_index) { // find grade at specific index
            try
            {
              double grade = std::stod(input[i]); // convert string to double grade
              if (grade < 0) { // check for negative grdae value
                return -1;
              }
            }
            catch (const std::exception& e)
            {
              return -1;
            }
            
            return std::stod(input[i]); // return the calculated grade
        }
    }
    return -2; // return error code if grade index is out of range
}

int GetGradeCount(const std::string input[], size_t size) { //Parses the input array to determine how many grades are claimed to be present and validates the claim
  if (!CheckFormat(input, size)) {
        return -1;
    }
  try
  {
    return stoi(input[1]);
  }
  catch (const std::exception& e)
  {
    return -1;
  }
  
  return -1;
}

std::string GetID(const std::string input[], size_t size) { //Extracts the ID for the present student.
  if (CheckFormat(input, size) == false)
    return "";
  else {
    return input[0];
  }
}

double GetMaxGrade(const std::string input[], const size_t kSize) { //Extracts the highest grade.
  if (!CheckFormat(input, kSize)) {
        return -1;
    }
    if (input == nullptr) {
        return -2;
    }
    double max_grade = 0;
    for (size_t i = 2; i < kSize; ++i) {
        try
        {
          double current_grade = stod(input[i]);
          if (current_grade < 0) {
            return -1;
          }
          if (current_grade > max_grade) {
            max_grade = current_grade;
          }
        }
        catch (const std::exception& e)
        {
          return -1;
        }
    }
    if (max_grade != 0) {
      return max_grade;
    }
    return -2;
}

