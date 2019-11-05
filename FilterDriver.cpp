//Name of the file: FilterDriver.cpp
//Group number and member names: Jeffrey Washington, Shatoria Poole, Roderick Harris
//Date last edited: 11/5/2019
//Purpose of the program: Main program to filter baseball csv file.

#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "BaseballStatistic.h"
#include "Filter.h"
#include "StringHelper.h"
#include "Date.h"

using namespace std;

//Function declaration.

void loadFile (vector<BaseballStatistic> &);

//Main Program
//************
//************
//************
//************

int main(){

    //Dummy variables
    
    string fname, lname, teamName, position;
    int jerseyNumber, atBat, homeRun, runsBattedIn, sB, year, month, day;
    char bat, thrower;
	double batAvg, opss, eraa;

    //Creation of objects
    vector <BaseballStatistic> test1;
    Filter processor;
    
    teamName = "Marlins";
    jerseyNumber = 50;
    
    //Process
    loadFile(test1);
    processor.sort(test1);
    
    int n = processor.searchByTeamName(test1, "Cubs");
    
    //Printing out csv file.
    for (int x = 0; x < test1.size(); x++){
               test1[x].print();
    
  }
    return 0;
}

//Loads CSV file into program to allow manipulation of data
//*********************************************************
//*********************************************************
//*********************************************************


//Function definitions

void loadFile(vector<BaseballStatistic>& playerList){
	ifstream in;
	in.open("BStats.csv");
        if(!in)
            cout << "File wont open" << endl;
	
	string fname, lname, teamName, position, line;
    int jerseyNumber, atBat, homeRun, runsBattedIn, sB, year, month, day;
    char bat, thrower;
	double batAvg, opss, eraa;
    
    int cnt;
	
	while(in.good())
    {
       //use line string variable to read in value
        getline(in, line, ',');
       //set read in value to corresponding variable
       teamName = line;
        getline(in, line,',');
       //convert the string to an int
       stringstream geek1(line);
       //set converted variable to corresponding variable 
       geek1 >> jerseyNumber;
       getline(in, line, ',');
       fname = line;
       getline(in, line, ',');
       lname = line;
       getline(in, line, ',');
       stringstream geek2(line);
       geek2 >> year;
       getline(in, line, ',');
       stringstream geek3(line);
       geek3 >> month;
       getline(in, line, ',');
       stringstream geek4(line);
       geek4 >> day;
       getline(in, line, ',');
       //create a char variable of the same length of the read in variable
       char p[line.length()];
       //set the line char variable to the read in variable
       p[0] = line[0];
       //set the line char variable to the corresponding variable
       bat = p[0];
       getline(in, line, ',');
       p[0] = line[0];
       thrower = p[0];
       getline(in, line, ',');
       stringstream geek5(line);
       geek5 >> atBat;
       getline(in, line, ',');
       stringstream geek6(line);
       geek6 >> batAvg;
       getline(in, line, ',');
       stringstream geek7(line);
       geek7 >> homeRun;
       getline(in, line, ',');
       stringstream geek8(line);
       geek8 >> runsBattedIn;
       getline(in, line, ',');
       stringstream geek9(line);
       geek9 >> sB;
       getline(in, line, ',');
       stringstream geek10(line);
       geek10 >> opss;
       getline(in, line, ',');
       stringstream geek11(line);
       geek11 >> eraa;
       getline(in, line);
       position = line;
 
       BaseballStatistic temp (fname, lname, teamName, jerseyNumber, position, atBat, homeRun, runsBattedIn, bat, thrower, sB, batAvg, year, month, day, opss, eraa);
       //add that new object to the vector
       playerList.push_back(temp);
               
    }
    in.close();
}



//in >> teamName >> jerseyNumber >> lname >> fname >> year >> month >> day >> bat >> thrower >> atBat >> batAvg >> homeRun >> runsBattedIn >> sB >> opss >> eraa >> position