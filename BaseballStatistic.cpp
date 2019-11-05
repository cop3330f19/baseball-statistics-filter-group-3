//Name of the file: BaseballStatistic.cpp
//Group number and member names: Jeffrey Washington, Shatoria Poole, Roderick Harris
//Date last edited: 11/5/2019
//Purpose of the program: Initializes all values for constructor and prints row.


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>


#include "BaseballStatistic.h"
#include "Date.h"
#include "Filter.h"

using namespace std;

//Default constructor

BaseballStatistic::BaseballStatistic (string fName, string lName, string tN, int jN,
string pos, int atBat , int homeRun, int runsBattedIn, char bat, char thrower, int esbee, double batAvg, int y,
int m, int d, double opss, double eraa){
                firstName = fName;
                lastName = lName;
                teamName = tN;
                jerseyNum = jN;
                position = pos;
                atBats = atBat;
                hr = homeRun;
                rbi = runsBattedIn;
                batting = bat;
                throwing = thrower;
                sb = esbee;
                battingAverage = batAvg;
                ops = opss;
                era = eraa;
                dob = new Date(y, m, d);
              

}


//Mutators

//Set Functions
void BaseballStatistic::setFirstName(string fName){
    firstName = fName;
}

void BaseballStatistic::setLastName(string lName){
    lastName = lName;
}

void BaseballStatistic::setTeamName(string tName){
    teamName = tName;
}

void BaseballStatistic::setJerseyNum(int jNum){
    jerseyNum = jNum;
}

void BaseballStatistic::setPosition(string ps){
    position = ps;
}

void BaseballStatistic::setBatting(char b){
    batting = b;
}

void BaseballStatistic::setThrowing(char t){
    throwing = t;
}

void BaseballStatistic::setAtBats(int atb){
    atBats = atb;
}

void BaseballStatistic::setBattingAverage(double ba){
    battingAverage = ba;
}

void BaseballStatistic::setHR(int homeRun){
    hr = homeRun;
}

void BaseballStatistic::setRBI(int runsBattedIn){
    rbi = runsBattedIn;
}

void BaseballStatistic::setSB(int stolenBase){
    sb = stolenBase;
}

void BaseballStatistic::setOPS(double onBasePlusSlugging){
    ops = onBasePlusSlugging;
}

void BaseballStatistic::setERA(double earnedRunAverage){
    era = earnedRunAverage;
}

//Get functions

string BaseballStatistic::getFirstName()const{
    return firstName;
}

string BaseballStatistic::getLastName()const{
    return lastName;
}

string BaseballStatistic::getTeamName()const{
    return teamName;
}

int BaseballStatistic::getJerseyNum()const{
    return jerseyNum;
}

string BaseballStatistic::getPosition()const{
    return position;
}

char BaseballStatistic::getBatting()const{
    return batting;
}

char BaseballStatistic::getThrowing()const{
    return throwing;
}

int BaseballStatistic::getAtBats()const{
    return atBats;
}

double BaseballStatistic::getBattingAverage()const{
    return battingAverage;
}

int BaseballStatistic::getHR()const{
    return hr; 
}

int BaseballStatistic::getRBI()const{
    return rbi;
}

int BaseballStatistic::getSB()const{
    return sb;
}

double BaseballStatistic::getOPS()const{
    return ops;
}

double BaseballStatistic::getERA()const{
    return era;
}    

//Print function

void BaseballStatistic::print()const{
   cout << left << lastName << ',' << firstName << right << setw(10) << teamName << right << setw(10) << jerseyNum << " " << dob->getDate() << " " << dob->getAge() << " " << batting << " " << throwing << " " << atBats << " " << battingAverage << " " << hr << " " << rbi << " " << sb << " " << ops << " " << era << " " << position <<  endl;
}