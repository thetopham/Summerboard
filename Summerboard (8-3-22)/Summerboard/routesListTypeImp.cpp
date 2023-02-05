// Section CSC161 - Computer Science II: C++
// File Name:  Summerboard Boulder
// Student: Matthew Topham
// Description: Summerboard Boulder
// Last Changed: 8/3/22022

#include <iostream>
#include <fstream>
#include <string>
#include "routesListType.h"
#include "routes.h"

using namespace std;

void routesListType::routePrintInfo() const
{
    nodeType<routes>* current;

    current = first;
    while (current != nullptr)
    {
        current->info.printInfo();
        current = current->link;
    }
}

void routesListType::searchrouteList(string name, 
    nodeType<routes>*& current) const
{
      
    current = first; //set current to point to the first node
                     //in the list     
    int i;
    for (i = 0; i < count; i++) {             //search the list once                   
        if (current->info.checkroute(name)) { //the item is found 
            cout << "route found!" << endl;
            current->info.printInfo(); //print all info from node
            current = current->link; //advance current to //the next node  
        }
        else
            current = current->link;
    }        
    cout << "End of search, if no results displayed, try again. \n" << name << "\n" << endl;
}//end searchrouteList

void routesListType::searchlevel(string level, 
    nodeType<routes>*& current) const
{
      
    current = first; //set current to point to the first node
                     //in the list     
    int i;
    for (i = 0; i < count; i++) {             //search the list once                   
        if (current->info.checklevel(level)) { //the item is found 
            cout << "levels found!" << endl;
            current->info.printInfo(); //print all info from node
            current = current->link; //advance current to //the next node  
        }
        else
            current = current->link;
    }
    cout << "End of search, if no results displayed, try again. \n" << level << "\n" << endl;
}//end searchrouteList

void routesListType::searchpavement(string pavement, 
    nodeType<routes>*& current) const
{
        
    current = first; //set current to point to the first node
                     //in the list     
    int i;
    for (i = 0; i < count; i++) {             //search the list once                   
        if (current->info.checkpavement(pavement)) { //the item is found 
            cout << "pavement types found!" << endl;
            current->info.printInfo(); //print all info from node
            current = current->link; //advance current to //the next node  
        }
        else
            current = current->link;
    }
    cout << "End of search, if no results displayed, try again. \n" << pavement << "\n" << endl;
}//end searchrouteList

void routesListType::searchlength(string length, 
    nodeType<routes>*& current) const
{
      
    current = first; //set current to point to the first node
                     //in the list     
    int i;
    for (i = 0; i < count; i++) {             //search the list once                   
        if (current->info.checklength(length)) { //the item is found 
            cout << "lengths found!" << endl;
            current->info.printInfo(); //print all info from node
            current = current->link; //advance current to //the next node  
        }
        else
            current = current->link;
    }
    cout << "End of search, if no results displayed, try again. \n" << length << "\n" << endl;
}//end searchrouteList

void routesListType::searchneighborhood(string neighborhood, 
    nodeType<routes>*& current) const
{
       
    current = first; //set current to point to the first node
                     //in the list     
    int i;
    for (i = 0; i < count; i++) {             //search the list once                   
        if (current->info.checkneighborhood(neighborhood)) { //the item is found 
            cout << "neighborhoods found!" << endl;
            current->info.printInfo(); //print all info from node
            current = current->link; //advance current to //the next node  
        }
        else
            current = current->link;
    }
    cout << "End of search, if no results displayed, try again. \n" << neighborhood << "\n" << endl;
}//end searchrouteList

void routesListType::searchusercrowd(string usercrowd, 
    nodeType<routes>*& current) const
{
    
    current = first; //set current to point to the first node
                     //in the list     
    int i;
    for (i = 0; i < count; i++) {             //search the list once                   
        if (current->info.checkcrowds(usercrowd)) { //the item is found 
            cout << "crowds found!" << endl;
            current->info.printInfo(); //print all info from node
            current = current->link; //advance current to //the next node  
        }
        else
            current = current->link;
    }
    cout << "End of search, if no results displayed, try again. \n" << usercrowd << "\n" << endl;
}//end searchrouteList


bool routesListType::routeSearch(string name) const
{
    bool found = false;
    nodeType<routes>* location;

    searchrouteList(name, location);
    
    return found;
}

bool routesListType::levelSearch(string level) const
{
    bool found = false;
    nodeType<routes>* location;

    searchlevel(level, location);

    return found;
}
bool routesListType::pavementSearch(string pavement) const
{
    bool found = false;
    nodeType<routes>* location;

    searchpavement(pavement, location);

    return found;
}
bool routesListType::lengthSearch(string length) const
{
    bool found = false;
    nodeType<routes>* location;

    searchlength(length, location);

    return found;
}
bool routesListType::neighborhoodSearch(string neighborhood) const
{
    bool found = false;
    nodeType<routes>* location;

    searchneighborhood(neighborhood, location);

    return found;
}
bool routesListType::usercrowdSearch(string usercrowd) const
{
    bool found = false;
    nodeType<routes>* location;

    searchusercrowd(usercrowd, location);

    return found;
}

void routesListType::routePrintName() const
{
    nodeType<routes>* current;

    current = first;
    while (current != nullptr)
    {
        current->info.printroute();
        current = current->link;
    }
}

//-------------------------------------------------------------------------------

void routesListType::destroyList()
{
    nodeType<routes>* temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != nullptr)   //while there are nodes in 
    {                          //the list
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = nullptr; //initialize last to nullptr; first has 
               //already been set to nullptr by the while loop
    count = 0;
}

//-------------------------------------------------------------------------------

void routesListType::userinput(string name, string level,
    string pavement, string length,
    string location, string crowds) {

    ifstream infile;
    ofstream outfile;

    string routeName;
    string difficultylevel;
    string pavementType;
    string routelength;
    string boulderlocation;
    string crowd;

    routeName = name;
    difficultylevel = level;
    pavementType = pavement;
    routelength = length;
    boulderlocation = location;
    crowd = crowds;

    
    cout << "" << endl;
    cout << "Enter Route Name:" << endl;
    getline(cin, routeName);
    for (int n = 0; n < routeName.length(); n++) { 
        routeName[n] = tolower(routeName[n]);
    }    

    do {
        cout << "" << endl;
        cout << "Enter Difficulty Level: (beginner, intermediate, expert)" << endl;
        getline(cin, difficultylevel);
        for (int n = 0; n < difficultylevel.length(); n++) {
            difficultylevel[n] = tolower(difficultylevel[n]);
        } 
        
    } while (difficultylevel != "beginner" && difficultylevel != "intermediate" && difficultylevel != "expert");
    

    do {
        cout << "" << endl;
        cout << "Enter Pavement Type: (bikepath, sidewalks, streets)" << endl;
        getline(cin, pavementType);
        for (int n = 0; n < pavementType.length(); n++) {
            pavementType[n] = tolower(pavementType[n]);
        }
    } while (pavementType != "bikepath" && pavementType != "sidewalks" && pavementType != "streets");


    
        cout << "" << endl;
        cout << "Enter Route Length: (in miles)" << endl;
        getline(cin, routelength);
        for (int n = 0; n < routelength.length(); n++) {
            routelength[n] = tolower(routelength[n]);
        }  
    

        do {
            cout << "" << endl;            
            cout << "Enter boulder neighborhood to seach by: " << endl;
            cout << "(north boulder, gunbarrel, old north boulder, central boulder, east boulder," << endl;
            cout << "downtown / pearlstreet, 29th street, the hill, university, chautauqua, or south boulder" << endl;
            getline(cin, boulderlocation);
            for (int n = 0; n < boulderlocation.length(); n++) {
                boulderlocation[n] = tolower(boulderlocation[n]);
            }
        } while (boulderlocation != "north boulder" && boulderlocation != "gunbarrel" && boulderlocation != "old north boulder" && boulderlocation != "central boulder" && boulderlocation != "east boulder" && boulderlocation != "downtown/pearlstreet" && boulderlocation != "29th street" && boulderlocation != "the hill" && boulderlocation != "university" && boulderlocation != "chautauqua" && boulderlocation != "south boulder");

        do {
            cout << "" << endl;
            cout << "Enter Crowded?: (not crowded, sort of crowded, very crowded)" << endl;
            getline(cin, crowd);
            for (int n = 0; n < crowd.length(); n++) {
                crowd[n] = tolower(crowd[n]);
            }
        } while (crowd != "not crowded" && crowd != "sort of crowded" && crowd != "very crowded");
        
    outfile.open("routeDat.txt", fstream::app);
    outfile  << "\n" << routeName << endl;
    outfile  << difficultylevel << endl;
    outfile  << pavementType << endl;
    outfile  << routelength << endl;
    outfile  << boulderlocation
        << endl;
    outfile << crowd << endl;

    cout << "" << endl;
    cout << "route sucessfully entered " << endl;

    outfile.close();       

}


