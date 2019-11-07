//Name of the file: Filter.cpp
//Group number and member names: Jeffrey Washington, Shatoria Poole, Roderick Harris
//Date last edited: 11/5/2019
//Purpose of the program: Filters content of csv file.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>

#include "BaseballStatistic.h"
#include "Filter.h"
#include "Date.h"
#include "StringHelper.h"

using namespace std;


//Swap function

void Filter::swap(vector<BaseballStatistic>& playerList, int oIdx, int nIdx){
    
    BaseballStatistic temp = playerList[oIdx]; //temporary BaseballStatistic variable to hold the old value during swap
    playerList[oIdx] = playerList[nIdx]; // assign the min_idx(element to be moved) to it's position
    playerList[nIdx] = temp; //assign the element previously at the now sorted postion
}

//Will sort by last name

void Filter::sort(vector<BaseballStatistic>& playerList){
    
     int i, j, min_idx; 
    
        string choice;
        StringHelper::toUpper(choice);
 
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < playerList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        //I am using 2 differnt methods of comparing strings. One is the string compare function which is apart of the string class. 
        //The other is standard comparisson operators.
        
        for (j = i+1; j < playerList.size(); j++) 
          if (
             (playerList[j].getLastName().compare(playerList[min_idx].getLastName()) < 0) //if getLastName() @ j is < getLastName() @ min_idx
              
           ||    (playerList[j].getLastName().compare(playerList[min_idx].getLastName()) == 0 && playerList[j].getPosition().compare(playerList[min_idx].getPosition() ) < 0) //getLastName()s are equal and getFirstName() @ j is < getFirstName() @ min_idx
              
           ||   (playerList[j].getLastName().compare(playerList[min_idx].getLastName()) == 0 && playerList[j].getFirstName().compare(playerList[min_idx].getFirstName()) == 0 && playerList[j].getPosition() < playerList[min_idx].getPosition() ) // getLastName()s and getFirstName()s are equal and getTeamName() @ j is < getTeamName() @ min_idx
              )
            min_idx = j; 
      
        // Swap the found minimum element with the first element 
        Filter::swap(playerList, min_idx, i);
        
       
    } 
}

void Filter::sort2(vector<BaseballStatistic>& playerList){
    
     int i, j, min_idx; 
    
        string choice;
        StringHelper::toUpper(choice);
 
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < playerList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        //I am using 2 differnt methods of comparing strings. One is the string compare function which is apart of the string class. 
        //The other is standard comparisson operators.
        
        for (j = i+1; j < playerList.size(); j++) 
          if (
              (playerList[j].getTeamName().compare(playerList[min_idx].getTeamName()) < 0) //if getLastName() @ j is < getLastName() @ min_idx
              
            ||   (playerList[j].getTeamName().compare(playerList[min_idx].getTeamName()) == 0 && playerList[j].getJerseyNum() < playerList[min_idx].getJerseyNum()) //getLastName()s are equal and getFirstName() @ j is < getFirstName() @ min_idx
              
             || (playerList[j].getTeamName().compare(playerList[min_idx].getTeamName()) == 0 && playerList[j].getJerseyNum() < playerList[min_idx].getJerseyNum()) // getLastName()s and getFirstName()s are equal and getTeamName() @ j is < getTeamName() @ min_idx
              )
            min_idx = j; 
      
        // Swap the found minimum element with the first element 
        Filter::swap(playerList, min_idx, i);
        
       
    } 
}


std::vector<BaseballStatistic>Filter::search(std::vector<BaseballStatistic> & temp, std::string filter, std::string key){ 
    
    bool valid;
    vector<BaseballStatistic> result;
    
    for(int i = 0; i < temp.size(); i++){ //Start of for loop
        
        valid = false;
        
        if(filter == "T"){
            if(temp[i].getTeamName() == key)    // Team
                valid = true; 
        }        

        else if(filter == "P"){
            if(temp[i].getPosition() == key) // Position
                valid = true; 
        }
        
        else if(filter == "B"){
            if(temp[i].getBatting() == key[0]) //Batting
                valid = true;
        }
        
        else if(filter == "BA"){
            if(temp[i].getBattingAverage() == atof(key.c_str())) //Batting Average
                valid = true;
        }
        
        else if(filter == "H"){
            if(temp[i].getHR() == atoi(key.c_str())) //Home Runs
                valid = true;
        }
        
        else if(filter == "R"){
            if(temp[i].getRBI() == atoi(key.c_str())) //Runs Batted In
                valid = true;
        }
        
        else if(filter == "S"){
            if(temp[i].getSB() == atoi(key.c_str())) //Stolen Bases
                valid = true;
        }
        
        else if(filter == "O"){
            if(temp[i].getOPS() == atof(key.c_str())) //OPS
                valid = true;
        }
        
        else if(filter == "H"){
            if(temp[i].getERA() == atof(key.c_str())) //ERA
                valid = true;
        }
        
                 // end of if statements
        if(valid)
              result.push_back(temp[i]);
        } // End of for loop
    
    return result;
    
} 



