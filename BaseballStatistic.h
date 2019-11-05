//Name of the file: BaseballStatistic.h
//Group number and member names: Jeffrey Washington, Shatoria Poole, Roderick Harris
//Date last edited: 11/5/2019
//Purpose of the program: Header file for BaseballStatistic.cpp

#ifndef BASEBALL_STATISTIC_H
#define BASEBALL_STATISTIC_H

#include "Date.h"
#include <string>

class BaseballStatistic
{

private:
	std::string firstName,
		lastName,
		teamName,
		position;

	int jerseyNum,
		atBats,
		hr,
		rbi,
		sb;

	char batting,
		throwing;

	double battingAverage,
		ops,
		era;

	Date *dob;

public:
	BaseballStatistic(std::string, std::string, std::string, int,
					  std::string, int, int, int, char, char, int, double, int,
					  int, int, double, double);

	//mutator
	void setFirstName(std::string);
	void setLastName(std::string);
	void setTeamName(std::string);
	void setJerseyNum(int);
	void setPosition(std::string);
	void setBatting(char);
	void setThrowing(char);
	void setAtBats(int);
	void setBattingAverage(double);
	void setHR(int);
	void setRBI(int);
	void setSB(int);
	void setOPS(double);
	void setERA(double);

	//accessor
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getTeamName() const;
	int getJerseyNum() const;
	std::string getPosition() const;
	int getAge() const;
	char getBatting() const;
	char getThrowing() const;
	int getAtBats() const;
	double getBattingAverage() const;
	int getHR() const;
	int getRBI() const;
	int getSB() const;
	double getOPS() const;
	double getERA() const;

	//prints a single statistic row to the terminal
	void print() const;
};

#endif