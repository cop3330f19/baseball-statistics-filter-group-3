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
#include <cstdlib>

#include "BaseballStatistic.h"
#include "Filter.h"
#include "StringHelper.h"
#include "Date.h"

using namespace std;

//Function declaration.

void loadFile(vector<BaseballStatistic> &);

//Main Program
//************
//************
//************
//************

int main()
{

    //Dummy variables

    string fname, lname, teamName, position;
    int jerseyNumber, atBat, homeRun, runsBattedIn, sB, year, month, day;
    char bat, thrower, option;
    double batAvg, opss, eraa;

    //Creation of objects
    vector<BaseballStatistic> test1;

    Filter processor;

    string key, filter;
    //Process

    loadFile(test1);

    cout << "******FILTER OPTIONS******" << endl;
    cout << "* T   - Team             *" << endl;
    cout << "* P   - Position         *" << endl;
    cout << "* B   - Batting          *" << endl;
    cout << "* BA  - Batting Average  *" << endl;
    cout << "* H   - Home Runs        *" << endl;
    cout << "* R   - Runs Batted In   *" << endl;
    cout << "* S   - Stolen Bases     *" << endl;
    cout << "* O   - OPS              *" << endl;
    cout << "* E   - ERA              *" << endl;
    cout << "**************************" << endl;

    vector<BaseballStatistic> result = test1;

    do
    {
        cout << "Enter all filter key pairs you would like to use (enter F when finished): " << endl;
        cin >> filter >> key;
        StringHelper::toUpper(filter);
        if (filter != "F" && filter != "T" && filter != "P" && filter != "B" && filter != "BA" && filter != "H" && filter != "R" && filter != "S" && filter != "O" && filter != "E")
        {
            cout << "Invalid input! Please select from the filter options or F to end filter options." << endl;
        }
        else if (filter != "F" && filter != "f")
        {
            result = Filter::search(result, filter, key);
        }
    } while (filter != "F" && filter != "f");

    cout << "*********SORTING OPTIONS*********" << endl;
    cout << "* 1 - By Player Name & Position *" << endl;
    cout << "* 2 - By Team & Jersey Number   *" << endl;
    cout << "* 3 - None                      *" << endl;
    cout << "*********************************" << endl;

    int input;
    bool inputTest = false;

    while (!inputTest)
    {

        cin >> input;

        if (input == 1)
        {
            inputTest = true;
            processor.sort(result);
            for (int x = 0; x < result.size(); x++)
            {
                result[x].print();
            }
        }

        else if (input == 2)
        {
            inputTest = true;
            processor.sort2(result);
            for (int x = 0; x < result.size(); x++)
            {
                result[x].print();
            }
        }

        else if (input == 3)
        {
            inputTest = true;
            for (int x = 0; x < result.size(); x++)
            {
                result[x].print();
            }
        }

        else
        {
            cout << "Invalid input try again" << endl;
        }
    }

    return 0;
}

//Loads CSV file into program to allow manipulation of data
//*********************************************************
//*********************************************************
//*********************************************************

//Function definitions

void loadFile(vector<BaseballStatistic> &playerList)
{
    ifstream in;
    in.open("BStats.csv");
    if (!in)
        cout << "File wont open" << endl;

    string fname, lname, teamName, position, line;
    int jerseyNumber, atBat, homeRun, runsBattedIn, sB, year, month, day;
    char bat, thrower;
    double batAvg, opss, eraa;

    int cnt;

    while (in.good())
    {
        //use line string variable to read in value
        getline(in, line, ',');
        //set read in value to corresponding variable
        teamName = line;
        getline(in, line, ',');
        //convert the string to an int
        stringstream temporaryLine1(line);
        //set converted variable to corresponding variable
        temporaryLine1 >> jerseyNumber;
        getline(in, line, ',');
        fname = line;
        getline(in, line, ',');
        lname = line;
        getline(in, line, ',');
        stringstream temporaryLine2(line);
        temporaryLine2 >> year;
        getline(in, line, ',');
        stringstream temporaryLine3(line);
        temporaryLine3 >> month;
        getline(in, line, ',');
        stringstream temporaryLine4(line);
        temporaryLine4 >> day;
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
        stringstream temporaryLine5(line);

        temporaryLine5 >> atBat;
        getline(in, line, ',');
        stringstream temporaryLine6(line);

        temporaryLine6 >> batAvg;
        getline(in, line, ',');
        stringstream temporaryLine7(line);

        temporaryLine7 >> homeRun;
        getline(in, line, ',');
        stringstream temporaryLine8(line);

        temporaryLine8 >> runsBattedIn;
        getline(in, line, ',');
        stringstream temporaryLine9(line);

        temporaryLine9 >> sB;
        getline(in, line, ',');
        stringstream temporaryLine10(line);

        temporaryLine10 >> opss;
        getline(in, line, ',');
        stringstream temporaryLine11(line);

        temporaryLine11 >> eraa;
        getline(in, line);
        position = line;

        BaseballStatistic temp(fname, lname, teamName, jerseyNumber, position, atBat, homeRun, runsBattedIn, bat, thrower, sB, batAvg, year, month, day, opss, eraa);
        //add that new object to the vector
        playerList.push_back(temp);
    }
    in.close();
}

//in >> teamName >> jerseyNumber >> lname >> fname >> year >> month >> day >> bat >> thrower >> atBat >> batAvg >> homeRun >> runsBattedIn >> sB >> opss >> eraa >> position