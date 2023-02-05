// Section CSC161 - Computer Science II: C++
// File Name:  Summerboard Boulder
// Student: Matthew Topham
// Description: Summerboard Boulder
// Last Changed: 8/3/22022

#ifndef H_routes
#define H_routes

#include <iostream> 
#include <string>

using namespace std;

class routes
{
    friend ostream& operator<< (ostream&, const routes&);    

public:     

    void setrouteInfo(string name, string level,
        string pavement, string length,
        string location, string crowds);
    //Function to set the details of a route. 
    //The member variables are set according to the 
    //parameters.
    //Postcondition:  routeName = name;
    //difficultylevel = level;
    //pavementType = pavement;
    //routelength = length;
    //boulderlocation = location;
    //crowd = crowds;         


    void printroute() const;
    //Function to print the name of a route.

    void printInfo() const;
    //Function to print the details of a route.
    //Postcondition: The route name, level, pavement, etc are displayed.

    bool checkroute(string name);
    //Function to check whether the name is the same as the
    //name of the route.
    //Postcondition: Returns the value true if the name 
    //               is the same as the name of the route;
    //               false otherwise.

        
    bool checklevel(string level);
    bool checkpavement(string pavement);
    bool checklength(string length);
    bool checkneighborhood(string neighborhood);
    bool checkcrowds(string crowds);

    string getroute() const;
    //Function to return the name of the route.
    //Postcondition: The name of the route is returned.

    routes(string name = "", string level = "",
        string pavement = "", string length = "",
        string location = "", string crowds = "");
    //constructor
    //The member variables are set according to the 
    //incoming parameters. If no values are specified, the 
    //default values are assigned.
    //Postcondition:  routeName = name;
    //difficultylevel = level;
    //pavementType = pavement;
    //routelength = length;
    //boulderlocation = location;
    //crowd = crowds;    

    //Overload the relational operators.
    bool operator==(const routes&) const;      
    bool operator!=(const routes&) const;


    string routeName;    //variable to store the name 
                        //of the route
    string difficultylevel;  //variable to store the difficulty 
                        //of the route
    string pavementType;  //variable to store the pavementType 
                        //of the route 
    string routelength; //variable to store the length 
                          //of the route 
    string boulderlocation; //variable to store the name 
                          //of the boulder location 
    string crowd; //variable to store the amount
                              //of crowds
};
#endif 