//Name of the file: Filter.cpp
//Group number and member names: Jeffrey Washington, Shatoria Poole, Roderick Harris
//Date last edited: 11/5/2019
//Purpose of the program: Filters content of csv file.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "BaseballStatistic.h"
#include "Filter.h"
#include "Date.h"

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
              
              || (playerList[j].getLastName().compare(playerList[min_idx].getLastName()) == 0 && playerList[j].getFirstName().compare(playerList[min_idx].getFirstName() ) < 0) //getLastName()s are equal and getFirstName() @ j is < getFirstName() @ min_idx
              
            ||   (playerList[j].getLastName().compare(playerList[min_idx].getLastName()) == 0 && playerList[j].getFirstName().compare(playerList[min_idx].getFirstName()) == 0 && playerList[j].getTeamName() < playerList[min_idx].getTeamName() ) // getLastName()s and getFirstName()s are equal and getTeamName() @ j is < getTeamName() @ min_idx
              )
            min_idx = j; 
      
        // Swap the found minimum element with the first element 
        Filter::swap(playerList, min_idx, i);
        
       
    } 
}


int Filter::searchByTeamName(vector<BaseballStatistic> BaseballStatistics, string tname){
  
  int lo = 0;
  int hi = BaseballStatistics.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid 
        if (BaseballStatistics[location].getLastName() == tname) 
            return location; 
  
        // If name greater, ignore left half 
        if ((BaseballStatistics[location].getLastName() < tname) || (BaseballStatistics[location].getLastName() == tname)) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
 
}

int Filter::searchByTeamAndJersey(vector<BaseballStatistic> BaseballStatistics, string teamName, int jerseyNumber){
    
      int lo = 0;
  int hi = BaseballStatistics.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
  
        // Check if name is present at mid 
        if (BaseballStatistics[location].getTeamName() == teamName) 
            return location; 
  
        // If name greater, ignore left half 
        if ((BaseballStatistics[location].getTeamName() < teamName) 
			|| (BaseballStatistics[location].getTeamName() == teamName ) )
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // if we reach here, then element was not present 
    return -1; 
    
}


// && BaseballStatistics[location].getJerseyNum() == jerseyNumber
// && BaseballStatistics[location].getJerseyNum() < jerseyNumber)
