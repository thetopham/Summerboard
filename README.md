# Database of Summerboard Routes in Boulder

![Summerboard Boulder](https://github.com/thetopham/Summerboard/blob/main/Summerboard%20Boulder.jpg?raw=true)


My capstone project for CSC 161 C++ completed in summer of 2022

M1 Capstone Project: Summerboard Routes

My project is going to be a database of Summerboard routes in Boulder. I will be starting this new hobby next week when my board arrives and love snowboarding so this way I can snowboard in the summer and create a database of locations to ride for others.

Users can enter their riding level: beginner, intermediate, or expert and choice of pavement type - bike routes, sidewalks, streets, offroad, length of route, location, crowded or empty, etc.  
As the project progresses, I will add more variables to search by and enter. I may make it dynamic/open source and have users be able to upload routes they find.

I will have the challenge ( and fun) of learning a new hobby and how to create a searchable database that allows users to enter new entries and then search those entries and return routes that meet the entered criteria. 

ALGORITHM
Class Routes {

private: 

String route name: name of route

String riding level: beginner, intermediate, expert

String pavement Type: bike routes, sidewalks, street

Int length of route in miles: miles

String location: north boulder, gunbarrel, east boulder, south boulder, Chautauqua, the hill, university of Colorado, downtown, old north boulder, central boulder, 29th street. 

String crowds: not crowded, sort of crowded, very crowded 

}

Program should be able to: 

Give user options based on above criteria, then return results that meet criteria. 

User able to enter new routes into database
Print list of all routes

print list of routes that meet user entered criteria. 
1.	Open the database file, if database does not open, exit the program.

2.	Create list of routes
a.	 Read data and store it in a route object
b.	Insert a route in the database
c.	Repeat steps a and b for each route data in the file 
3.	Show the menu of search options
a.	Search by riding level
b.	Search by pavement type
c.	Search by miles
d.	Search by boulder neighborhood
e.	Search by crowds

Exception Handling: If a user inputs an incorrect character, then the program should throw an error stating invalid input type.
Then the program will cout this error to the user. Finally, the user is then returned to the previous input selection. 

SEARCH, SORT, STORAGE: The program uses an external txt file to store data in strings. A function is used to read the strings from the file and build nodes in a linked list. The linked list is then stored in memory of the program. A search function returns true if the name of a route is found. 

