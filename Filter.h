
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