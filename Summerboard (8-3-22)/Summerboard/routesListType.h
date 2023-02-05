// Section CSC161 - Computer Science II: C++
// File Name:  Summerboard Boulder
// Student: Matthew Topham
// Description: Summerboard Boulder
// Last Changed: 8/3/22022

#ifndef H_routesListType
#define H_routesListType

#include <string>
#include <iostream>
#include "unorderedLinkedList.h"
#include "routes.h" 

using namespace std;

class routesListType :public unorderedLinkedList<routes>
{
public:

    bool routeSearch(string name) const;
    //Function to search the list to see whether a
    //particular route name, specified by the parameter name,
    //is in the list.
   
    bool levelSearch(string level) const;
    bool pavementSearch(string pavement) const;
    bool lengthSearch(string length) const;
    bool neighborhoodSearch(string neighborhood) const;
    bool usercrowdSearch(string usercrowd) const;
    //Function to search the list to see whether a
    //particular route name, specified by the parameter name,
    //is in the list.
    //Postcondition: Returns true if the name is found,
    //               and false otherwise.
    
           
    void routePrintName() const;
    //Function to print the name of all the routes in 
    //the list.

    void routePrintInfo() const;    
    
    void destroyList();

    void userinput(string routeName, string difficultylevel,
        string pavementType, string routelength,
        string boulderlocation, string crowd);
    
    void searchrouteList(string name, nodeType<routes>*& current) const ;    
    //This function searches the route list for a 
    //particular name, specified by the parameter name.    
    
    void searchlevel(string level, nodeType<routes>*& current) const;
    void searchpavement(string pavement, nodeType<routes>*& current) const;
    void searchlength(string length, nodeType<routes>*& current) const;
    void searchneighborhood(string neighborhood, nodeType<routes>*& current) const;
    void searchusercrowd(string usercrowd, nodeType<routes>*& current) const; 
    
};

#endif