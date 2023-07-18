// Copyright 2022 CSCE 240

#include "../inc/gradebook.h"


GradeBook::GradeBook() {}

GradeBook::GradeBook(std::vector<Grade> grades) {
    grades_ = grades;
}


size_t GradeBook::size() const {
    return grades_.size();
}

const Grade GradeBook::Get(size_t index) const {
    if(index < 0 || index > grades_.size()-1)
        return Grade(0,1);
    return grades_.at(index);
}

void GradeBook::Add(const Grade& grade) {
    grades_.push_back(grade);
    
}

const GradeBook GradeBook::Add(const GradeBook& that) const {
    GradeBook new_book;
    new_book.grades_.insert(new_book.grades_.begin(),
                            grades_.begin(),
                            grades_.end());
    new_book.grades_.insert(new_book.grades_.end(),
                            that.grades_.begin(),
                            that.grades_.end());
    
    return new_book;
}

const Grade GradeBook::CalcAverage() const {
    Grade average(0,0);
    for(const Grade& grade : grades_)
        average = average.Plus(grade);
    

    if(grades_.size() > 0)
        return average.DividedBy(Grade(grades_.size(), 1));
    else
        return Grade(1,1);
}
