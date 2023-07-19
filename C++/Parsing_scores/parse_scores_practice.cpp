#include <hw2/parse_scores.h>
#include <string>
#include <stdexcept>

bool FormatCheck(const std::string input[], size_t size) {
    if (size <= 0) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        try
        {
            std::string student_name = input[i];
            ++i;
            int num_grades = stoi(input[i]);
            ++i;
            double *student_grades = new double[num_grades];
            for (size_t j = 0; j < num_grades; ++j, ++i) {
                student_grades[j] = stod(input[i]);
            }
        }
        catch(const std::exception& e)
        {
            return false;
        }
        
    }
    return true;
}

double GetGrade(size_t grade_index, const std::string input[], size_t size) {
    if (!FormatCheck(input, size)) {
        return -1;
    }
    if (grade_index > 0 || grade_index > size + 1) {
        return -1;
    }
    if (input == nullptr) {
        return -2;
    }
    for (size_t i = 0; i < size; ++i) {
        if (i == grade_index) {
            return std::stod(input[i]);
        }
    }
    return -2;
}

int GetGradeCount(const std::string input[], size_t size) {

}

std::string GetID(const std::string input[], size_t size) {
    if (FormatCheck(input, size) == false)
    return "";
  else {
    return input[0];
  }
}

double GetMaxGrade(const std::string input[], const size_t kSize);

/*
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
  if(input == nullptr) {
    return -2;
  }
  if(CheckFormat(input, size) == false) {
    if(grade_index == NULL)
      return -1.0;
    else
      return -2.0;
  }
  else {
    try {
      double student_no = std::stod(input[grade_index]);
    } 
    catch (const std::invalid_argument& exception) {
      return -2.0;  // non-numeric student number
    }
    return std::stod(input[grade_index+2]);
    
    // if(input == NULL)
    //   return -2.0;
    // else {
    //   return std::stod(input[grade_index]);
    //}
  }
}
*/