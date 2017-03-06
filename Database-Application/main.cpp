#include <iostream>
#include <string>

//#include "Database.h"


using namespace std;

int main() {

	//parse JSON Format files and popu;ate DB object

	//create User table
	//create Business table
	//create User x Review table
	//create Business x Review table


	cout << "Options: " << endl 
		<< "1) Print info about a given User" << endl
		<< "2) Print info about a given Business" << endl
		<< "3) Show the reviews for a given User" << endl 
		<< "4) Show the reviews for a given Business" << endl
		<< "5) Max and Min reviews for a given User" << endl
		<< "6) Max and Min reviews for a buisness" << endl
		<< "7) find the most popular user in the data set" << endl
		<< "8) Find the most connected user in the data set" << endl
		<< "9) Find the user with the lowest scoring average reviews" << endl
		<< "10) find the user with the highest scoring average reviews" << endl 
		<< "Q) Exit program" << endl;

	cout << "Enter command: " << endl;

	string command; 


	//char input[256];

	while(cin >> command) 
	{
		//string command = input; 

		if(command == "Q")
		{
			break; 
		}
		else if(command == "1")
		{
			string userID;
			cout << "Enter User ID: ";
			cin >> userID; 

			cout << "option 1 chosen" <<  endl;
		}
		else if (command == "2") 
		{
			string businessID;
			cout << "Enter Business ID: ";
			cin >> businessID;

			cout << "option 2 chosen" << endl;
		}
		else if (command == "3") 
		{
			string userID;
			cout << "Enter User ID: ";
			cin >> userID;

			cout << "option 3 chosen" << endl;
		}
		else if (command == "4") 
		{	
			string businessID;
			cout << "Enter Business ID: ";
			cin >> businessID;

			cout << "option 4 chosen" << endl;
		}
		else if (command == "5") 
		{
			string userID;
			cout << "Enter User ID: ";
			cin >> userID;

			cout << "option 5 chosen" << endl;
		}
		else if (command == "6")
		{
			string businessID;
			cout << "Enter Business ID: ";
			cin >> businessID;

			cout << "option 6 chosen" << endl;
		}
		else if (command == "7")
		{
			cout << "Finding the most popular user in the data set..." << endl;
		}
		else if (command == "8") 
		{
			cout << "finding the most connected user in teh data set..." << endl;
		}
		else if (command == "9")
		{
			cout << "Finding the user with the lowerst scoring average reviews..." << endl;
		}
		else if (command == "10") 
		{
			cout << "Finding the user with the highest scoring average reviews..." << endl;
		}
		else 
		{
			cout << "Command not recognized, try again!" << endl;
		}

		cout << endl; 

		



		cout << "Options: " << endl 
		<< "1) Print info about a given User" << endl
		<< "2) Print info about a given Business" << endl
		<< "3) Show the reviews for a given User" << endl 
		<< "4) Show the reviews for a given Business" << endl
		<< "5) Max and Min reviews for a given User" << endl
		<< "6) Max and Min reviews for a buisness" << endl
		<< "7) find the most popular user in the data set" << endl
		<< "8) Find the most connected user in the data set" << endl
		<< "9) Find the user with the lowest scoring average reviews" << endl
		<< "10) find the user with the highest scoring average reviews" << endl 
		<< "Q) Exit program" << endl;

		cout << "Enter command: " << endl;

	}

	cout << "Program exited!" << endl;
 
}