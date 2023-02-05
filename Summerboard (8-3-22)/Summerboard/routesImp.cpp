// Section CSC161 - Computer Science II: C++
// File Name:  Summerboard Boulder
// Student: Matthew Topham
// Description: Summerboard Boulder
// Last Changed: 8/3/22022

#include <iostream>
#include <string>
#include "routes.h"
#include "routesList.h"

using namespace std;

void routes::setrouteInfo(string name, string level,
    string pavement, string length,
    string location, string crowds)
{
    routeName = name;
    difficultylevel = level;
    pavementType = pavement;
    routelength = length;
    boulderlocation = location;
    crowd = crowds;
}

void routes::printroute() const
{
    cout << "Route Name: " << routeName << endl;
}

void routes::printInfo() const
{
    cout << "\nRoute Name: " << routeName << endl;
    cout << "Difficulty Level: " << difficultylevel << endl;
    cout << "Pavement Type: " << pavementType << endl;
    cout << "Route Length: " << routelength << endl;
    cout << "Boulder Neighborhood: " << boulderlocation
        << endl;
    cout << "Crowded?: " << crowd <<"\n" << endl;
    
}

bool routes::checkroute(string name)
{
    return(routeName.find(name) != string::npos);         
}

bool routes::checklevel(string level)
{
    return(difficultylevel.find(level) != string::npos);
}

bool routes::checkpavement(string pavement)
{
    return(pavementType.find(pavement) != string::npos);
}

bool routes::checklength(string length)
{
    return(routelength.find(length) != string::npos);
}

bool routes::checkneighborhood(string neighborhood)
{
    return(boulderlocation.find(neighborhood) != string::npos);
}

bool routes::checkcrowds(string crowds)
{
    return(crowd.find(crowds) != string::npos);
}

//user input search variables
string name;
string level;
string pavement;
string length;
string neighborhood;
string usercrowd;

string routes::getroute() const
{
    return routeName;
}

routes::routes(string name, string level,
    string pavement, string length,
    string location, string crowds)
{
    setrouteInfo(name, level, pavement, length, location,
        crowds);
}

bool routes::operator==(const routes& other) const
{
    return (routeName == other.routeName);
}

bool routes::operator!=(const routes& other) const
{
    return (routeName != other.routeName);
}

ostream& operator<< (ostream& osObject, const routes& routeList)
{
    osObject << endl;
    osObject << "Route Name: " << routeList.routeName << endl;
    osObject << "Difficulty Level: " << routeList.difficultylevel << endl;
    osObject << "Pavement Type: " << routeList.pavementType << endl;
    osObject << "Route Length: " << routeList.routelength << endl;
    osObject << "Boulder Neighborhood "
        << routeList.boulderlocation << endl;
    osObject << "_____________________________________" << endl;

    return osObject;
}


