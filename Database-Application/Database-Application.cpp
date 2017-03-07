// Database-Application.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "json.hpp"
#include "Database.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using DB = Database::Database;
using Table = Database::Table;
using Record = Database::Record;
using json = nlohmann::json;

int main()
{
	DB* d = new DB();
	
	/*
		parse JSON Format files and populate DB object
	*/

	// Create Users Table
	ifstream user_file("Yelp Data/yelp_academic_dataset_user.json");
	vector<string> user_attributes{ "user_id", "name" };
	Table* users = new Table(user_attributes);
	/*
	users->add_attribute("user_id");
	users->add_attribute("name");
	users->add_attribute("review_count");
	users->add_attribute("yelping_since");
	users->add_attribute("friends");
	users->add_attribute("useful");
	users->add_attribute("funny");
	users->add_attribute("cool");
	users->add_attribute("fans");
	users->add_attribute("elite");
	users->add_attribute("average_stars");
	users->add_attribute("compliment_hot");
	users->add_attribute("compliment_more");
	users->add_attribute("compliment_profile");
	users->add_attribute("compliment_cute");
	users->add_attribute("compliment_list");
	users->add_attribute("compliment_note");
	users->add_attribute("compliment_plain");
	users->add_attribute("compliment_cool");
	users->add_attribute("compliment_funny");
	users->add_attribute("compliment_writer");
	users->add_attribute("compliment_photos");
	users->add_attribute("type");
	*/

	string file_line = "";
	int line_count = 10;
	for (int i = 0; i < line_count; i++)
	{
		if (getline(user_file, file_line))
		{
			json user = json::parse(file_line.c_str());
			Record r(user_attributes.size());
			for (int j = 0; j < user_attributes.size(); j++)
			{
				r.set(j, user[user_attributes.at(j)]);
			}
			users->add_record(r);
		}
	}
	
	map<string, Record> user_records = users->get_records();
	cout << user_records["0"].get(0) << endl;
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

    	return 0;
}
