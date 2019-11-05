//Name of the file: Filter.h
//Group number and member names: Jeffrey Washington, Shatoria Poole, Roderick Harris
//Date last edited: 11/5/2019
//Purpose of the program: Header file

#ifndef FILTER
#define FILTER

#include <vector>
#include <string>
#include "BaseballStatistic.h"


class Filter{
    public:

        void swap (std::vector<BaseballStatistic> &, int, int);
        void sort (std::vector<BaseballStatistic> &);
        int searchByTeamName (std::vector<BaseballStatistic>, std::string);
        int searchByTeamAndJersey (std::vector<BaseballStatistic>, std::string, int);

};


#endif