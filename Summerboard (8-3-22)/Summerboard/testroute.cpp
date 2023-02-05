// Section CSC161 - Computer Science II: C++
// File Name:  Summerboard Boulder
// Student: Matthew Topham
// Description: Summerboard Boulder
// Last Changed: 8/3/22022

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "routes.h" 
#include "routesListType.h"
#include "unorderedLinkedList.h"
#include "routesList.h"

using namespace std;

void createroutesList(ifstream& infile,
    routesListType& routeList);

void displayMenu();

int main()
{     
    routesListType routeList;
    routes route;
    int choice;
    char ch;

    //user input search variables
    string name;
    string level;
    string pavement;
    string length;
    string neighborhood;
    string usercrowd;    
    
    //program route variables
    string routeName;
    string difficultylevel;
    string pavementType;
    string routelength;
    string boulderlocation;
    string crowd;

    //------------------
    ifstream infile;
    ofstream outfile;

    //open the input file
    infile.open("routeDat.txt");
    
    if (!infile)
    {
        cout << "The input file does not exist. "
            << "The program terminates!!!" << endl;
        return 1;
    }

    //create the route list
    createroutesList(infile, routeList);

    infile.close();
   

    //show the ascii
    cout << " --------------------------------------------------------------------------------------------------------------" << endl;
    cout << "   ######  ##     ## ##     ## ##     ## ######## ########  ########   #######     ###    ########  ########  " << endl;
    cout << "  ##    ## ##     ## ###   ### ###   ### ##       ##     ## ##     ## ##     ##   ## ##   ##     ## ##     ## " << endl;
    cout << "  ##       ##     ## #### #### #### #### ##       ##     ## ##     ## ##     ##  ##   ##  ##     ## ##     ## " << endl;
    cout << "   ######  ##     ## ## ### ## ## ### ## ######   ########  ########  ##     ## ##     ## ########  ##     ## " << endl;
    cout << "        ## ##     ## ##     ## ##     ## ##       ##   ##   ##     ## ##     ## ######### ##   ##   ##     ## " << endl;
    cout << "  ##    ## ##     ## ##     ## ##     ## ##       ##    ##  ##     ## ##     ## ##     ## ##    ##  ##     ## " << endl;
    cout << "   ######   #######  ##     ## ##     ## ######## ##     ## ########   #######  ##     ## ##     ## ########  " << endl;
    cout << " --------------------------------------------------------------------------------------------------------------" << endl;
                     cout << "                   ########   #######  ##     ## ##       ########  ######## ########  " << endl;
                     cout << "                   ##     ## ##     ## ##     ## ##       ##     ## ##       ##     ## " << endl;
                     cout << "                   ##     ## ##     ## ##     ## ##       ##     ## ##       ##     ## " << endl;
                     cout << "                   ########  ##     ## ##     ## ##       ##     ## ######   ########  " << endl;
                     cout << "                   ##     ## ##     ## ##     ## ##       ##     ## ##       ##   ##   " << endl;
                     cout << "                   ##     ## ##     ## ##     ## ##       ##     ## ##       ##    ##  " << endl;
                     cout << "                   ########   #######   #######  ######## ########  ######## ##     ## " << endl;
    cout << " --------------------------------------------------------------------------------------------------------------" << endl;
    cout << "" << endl;

    //show the menu
    displayMenu();

    cout << "Enter your choice: ";
    cin >> choice;    //get the request    
    cin.get(ch);
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Invalid Selection." << endl;
    }
    
    cout << endl;
   

    //process the requests
    while (choice != 11)
    {
        switch (choice)
        {        

        case 1:
            routeList.routePrintName();
            break;

        case 2:

            routeList.routePrintInfo();
            break;

        case 3:
            //search goes here;    
            cout << "Enter route name to seach by: " << endl;          
            getline(cin, name);
            cout << endl;
            routeList.routeSearch(name);

            break;

        case 4:
            //search goes here;   
                        
            cout << "Enter riding dificulty to seach by: (beginner, intermediate, expert)" << endl;
            getline(cin, level);
            cout << endl;
            routeList.levelSearch(level);

            break;

        case 5:
            //search goes here;             

            cout << "Enter pavement type to seach by: (bikepath, sidewalks, streets)" << endl;
            getline(cin, pavement);
            cout << endl;
            routeList.pavementSearch(pavement);

            break;

        case 6:
            //search goes here;             

            cout << "Enter route length to seach by: (in miles)" << endl;
            getline(cin, length);
            cout << endl;
            routeList.lengthSearch(length);

            break;

        case 7:
            //search goes here;             

            cout << "Enter boulder neighborhood to seach by: " << endl;
            cout << "(north boulder, gunbarrel, old north boulder, central boulder, east boulder," << endl;
            cout << "downtown / pearlstreet, 29th street, the hill, university, chautauqua, or south boulder" << endl;
           
            getline(cin, neighborhood);
            cout << endl;
            routeList.neighborhoodSearch(neighborhood);

            break;

        case 8:
            //search goes here;             

            cout << "Enter crowds to seach by: (not crowded, sort of crowded, very crowded)" << endl;
            getline(cin, usercrowd);
            cout << endl;
            routeList.usercrowdSearch(usercrowd);
              
            break;

        case 9: 
            //user input route info goes here
           
            routeList.userinput(routeName, difficultylevel, pavementType, routelength, boulderlocation, crowd);

            ////recreates list after user inputs new data
          infile.open("routeDat.txt");

            if (!infile)
            {
                cout << "The input file does not exist. "
                    << "The program terminates!!!" << endl;
               return 1;
           }

            ///destroys current list           
            routeList.destroyList();            
            
            ///recreates list after user inputs new data
            createroutesList(infile, routeList);
            infile.close();

            break;


        default:
            cout << "Invalid selection." << endl;
        }//end switch
       
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;    //get the request
        cin.get(ch);
       if (cin.fail()) {
            cin.clear();
           cin.ignore();
           } 
        cout << endl;
       
    }//end while
    return 0;
}


void createroutesList(ifstream& infile,
   routesListType& routeList)
{
    string name;
    string difficultylevel;
    string pavementType;
    string routelength;
    string boulderlocation;
    string crowd;
    char ch;    

    routes newroute;

    getline(infile, name);

    while (infile)
    {
        getline(infile, difficultylevel);
        getline(infile, pavementType);
        getline(infile, routelength);
        getline(infile, boulderlocation);
        getline(infile, crowd);
         infile.get(ch);
        newroute.setrouteInfo(name, difficultylevel, pavementType, routelength,
            boulderlocation, crowd);
        routeList.insertFirst(newroute);
        

        getline(infile, name);
    }//end while
}//end createrouteList

void displayMenu()
{
    cout << "" << endl;
    cout << "Select one of the following:" << endl;
    cout << "1: To print only the names of all the routes."
        << endl;
    cout << "2: To print a list of all the routes and info." << endl;
    cout << "3: To search by route name." << endl;
    cout << "4: To search by difficulty level." << endl;
    cout << "5: To search by pavement type." << endl;
    cout << "6: To search by route length." << endl;
    cout << "7: To search by neighborhood." << endl;
    cout << "8: To search by crowds." << endl;
    cout << "9: Enter new route to database." << endl;
    cout << "10: To exit" << endl;
    cout << "" << endl;
} //end displayMenu


