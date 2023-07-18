// Copyright 2022 CSCE 240

#include "../inc/grade.h"
#include <string>
#include <cmath>
#include <iostream>

// unsigned int POINTS_SCORED;
// unsigned int TOTAL_POINTS;

Grade::Grade(unsigned int points_scored, unsigned int total_points) {
    num_ = points_scored;
    den_ = total_points;
}

unsigned int Grade::scored() const {
    return num_;
}

unsigned int Grade::total() const {
    return den_;
}

double setPrecision(double var, unsigned int precis)
{
    double value = (int) ((var * 1 * (std::pow(10,precis))) +.5);
    return (double)value / std::pow(10,precis);
}

double Grade::ToDouble(unsigned int precision) const {
    double percent = (num_ /(double) den_) * 100;
    percent = setPrecision(percent, precision);
    return percent;
}

const std::string Grade::ToString() const {
    std::string sReturn = std::to_string(num_);
    if (num_ == 0) return sReturn;
    sReturn += "/";
    sReturn += std::to_string(den_);
    return sReturn;
}

const std::string Grade::ToLetter(unsigned int threshold) const {
    if(threshold == 0){
        if(Grade::ToDouble() >= 90.0)
            return "A";
        if(Grade::ToDouble() >= 80.0)
            return "B";
        if(Grade::ToDouble() >= 70.0)
            return "C";
        if(Grade::ToDouble() >= 60.0)
            return "D";
        else   
            return "F";
    }
    if(Grade::ToDouble() >= 90.0 + (threshold *.1))
        return "A+";
    if(Grade::ToDouble() >= 90.0 && Grade::ToDouble() < 90.0 + (threshold * .1))
        return "A";
    if(Grade::ToDouble() >= 80.0 + (threshold *.1))
        return "B+";
    if(Grade::ToDouble() >= 80.0 && Grade::ToDouble() < 80.0 + (threshold * .1))
        return "B";
    if(Grade::ToDouble() >= 70.0 + (threshold *.1))
        return "C+";
    if(Grade::ToDouble() >= 70.0 && Grade::ToDouble() < 70.0 + (threshold * .1))
        return "C";
    if(Grade::ToDouble() >= 60.0 + (threshold *.1))
        return "D+";
    if(Grade::ToDouble() >= 60.0 && Grade::ToDouble() < 60.0 + (threshold * .1))
        return "D";
    else   
        return "F";
}

bool Grade::Equals(const Grade& right_hand_side) const {
    unsigned int lhs_num = num_ * right_hand_side.den_;
    unsigned int rhs_num = right_hand_side.num_ * den_;
    return lhs_num == rhs_num;
    
}

const Grade Grade::DividedBy(const Grade& right_hand_side) const {
    int num = num_ * right_hand_side.den_;
    int den = den_ * right_hand_side.num_;
    Grade divide_Grade = Grade(num, den);
    return divide_Grade;

}

const Grade Grade::Plus(const Grade& right_hand_side) const {
    if(den_ == right_hand_side.den_)
        return Grade(num_ + right_hand_side.num_, den_);
    else {
        return Grade(right_hand_side.num_ * den_ + num_, den_);
    }
    return Grade(num_ * right_hand_side.den_ + right_hand_side.num_, den_ * right_hand_side.den_);
}



