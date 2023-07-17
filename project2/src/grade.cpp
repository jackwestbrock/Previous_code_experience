#include <cassert>
#include <cmath>
#include <string>
#include <iostream>

#include "../inc/grade.h"



Grade::Grade(unsigned int points_scored, unsigned int total_points) {
    assert(points_scored >= 0);
    assert(total_points > 0);
    num_ = points_scored;
        //std::cout << num_ << std::endl;

    den_ = total_points;
        //std::cout << den_ << std::endl;

    score = static_cast<double>(scored() / static_cast<double>(total()));
}

unsigned int Grade::scored() const {
    return num_;
}

unsigned int Grade::total() const {
    return den_;
}

double Grade::ToDouble(unsigned int power) const {
    double precision = pow(10, power + 2);
    double grade = precision * (static_cast<double>(num_) / den_);
    grade = round(grade) /pow(10, power);
    return grade;
}
double Grade::ToDouble() const {
    return ToDouble(3);
}

const std::string Grade::ToString() const {
    if(num_ == 0)
        return "0";
    return std::to_string(num_) + "/" + std::to_string(den_);
}

bool Grade::operator==(const Grade& right_hand_side) const {
    if(scored() == right_hand_side.scored() && total() == right_hand_side.total())
        return true;
    return false;
}

bool Grade::operator==(int right_hand_side) const {
    if(score == right_hand_side)
        return true;
    return false;
}

bool operator==(int left_hand_side, const Grade& right_hand_side) {
    double score = static_cast<double>(right_hand_side.scored() / right_hand_side.total());
    if(score == left_hand_side)
        return true;
    return false;
}


