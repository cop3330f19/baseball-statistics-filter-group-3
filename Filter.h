//Name of the file: Filter.h
//Group number and member names: Jeffrey Washington, Shatoria Poole, Roderick Harris
//Date last edited: 11/5/2019
//Purpose of the program: Header file

#ifndef FILTER
#define FILTER

#include <vector>
#include <string>
#include "BaseballStatistic.h"

class Filter
{
public:
    void swap(std::vector<BaseballStatistic> &, int, int);
    void sort(std::vector<BaseballStatistic> &);
    void sort2(std::vector<BaseballStatistic> &);
    static std::vector<BaseballStatistic> search(std::vector<BaseballStatistic> &, std::string, std::string);
};

#endif