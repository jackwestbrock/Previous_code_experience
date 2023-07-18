#include "problem2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <array>
//#include <algorithm>


double Max(const std::string& file_name) {
    std::ifstream inFil(file_name);
    if(inFil) {
        double x = 0.0;
        std::vector<double> num_list;
        inFil >> x;

        while(inFil) {
            num_list.push_back(x);
            inFil >> x;
        }
        return *max_element(num_list.begin(), num_list.end());

    }
    else
        return 0.0;

}
double Min(const std::string& file_name) {
    std::ifstream inFil(file_name);
    if(inFil) {
        double x = 0.0;
        std::vector<double> num_list;
        inFil >> x;

        while(inFil) {
            num_list.push_back(x);
            inFil >> x;
        }
        return *min_element(num_list.begin(), num_list.end());

    }
    else
        return 0.0;
}
double Sum(const std::string& file_name) {
    std::ifstream inFil(file_name);
    if(inFil) {
        double x = 0.0;
        std::vector<double> num_list;
        inFil >> x;
        double sum = 0;

        while(inFil) {
            num_list.push_back(x);
            inFil >> x;
        }
        for(std::vector<double>::iterator i = num_list.begin()+1; i != num_list.end(); ++i)
            sum += *i;
        return sum;

    }
    else
        return 0.0;

}
double Avg(const std::string& file_name) {
    std::ifstream inFil(file_name);
    if(inFil) {
        double x = 0.0;
        std::vector<double> num_list;
        inFil >> x;
        double sum = 0.0;
        double avg = 0.0;

        while(inFil) {
            num_list.push_back(x);
            inFil >> x;
        }
        for(std::vector<double>::iterator i = num_list.begin()+1; i != num_list.end(); ++i)
            sum += *i;
        
        avg = sum / *(num_list.begin());
        return avg;
    }
    else
        return 0.0;

}
void Sort(const std::string& filename, double ordered_doubles[]) {
    std::ifstream inFil(filename);
    if(inFil) {
        double x = 0.0;
        double num_list[5];
        inFil >> x;
        int i = 0;
        while(inFil) {
            num_list[i] = x;
            inFil >> x;
            ++i;
        }
        for(int i = 1; i < 5; ++i)
            ordered_doubles[i-1] = num_list[i]; 

        for(int i = 0; i<4; i++) {
            for(int j = i+1; j<4; j++) {
                if(ordered_doubles[j] < ordered_doubles[i]) {
                    double temp = ordered_doubles[i];
                    ordered_doubles[i] = ordered_doubles[j];
                    ordered_doubles[j] = temp;
                }
            }
        }         
    }

}