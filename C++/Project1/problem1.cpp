#include "problem1.h"

#include <iostream>

std::string SumDigits(const std::string& value) {
    std::string temp;
    bool pos = true;
    int sum = 0;
    if(value.at(0) == '-') {
        if(std::isdigit(value.at(1))==0) 
            return " empty string";
        pos = false;
        
    }
    int num;
    if(!pos)
        num = std::stoi(value.substr(1));
    else
        num = std::stoi(value);
    
    for(const char ch : value) {
        while(num >0 )
        {
            sum += num % 10;
            num /= 10;
        }
    }
    if(!pos)
        temp = "-" + std::to_string(sum);
    else
        temp = std::to_string(sum);
    
    return temp;

}

