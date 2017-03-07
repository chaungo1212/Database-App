// Database-Application.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "json.hpp"
#include "Database.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using DB = Database::Database;
using Table = Database::Table;
using Record = Database::Record;
using json = nlohmann::json;

int main()
{
	DB* yelp_data = new DB();
	
	/*
		parse JSON Format files and populate DB object
	*/
	string file_line = "";
	int line_count = 100;

	// Create Users Table
	ifstream user_file("Yelp Data/yelp_academic_dataset_user.json");
	vector<string> user_attributes{ "user_id", "name", "review_count", "yelping_since", "average_stars" };
	Table* users = new Table(user_attributes);

	for (int i = 0; i < line_count; i++)
	{
		if (getline(user_file, file_line))
		{
			json user = json::parse(file_line.c_str());
			Record r(user_attributes.size());
			for (int j = 0; j < user_attributes.size(); j++)
			{
				auto val = user[user_attributes.at(j)];
				if (val.type() == json::value_t::string)
					r.set(j, val);
				else if (val.type() == json::value_t::number_unsigned)
				{
					int val_int = val;
					r.set(j, to_string(val_int));
				}
			}
			users->add_record(r);
		}
	}
	yelp_data->add_table(*users, "users");

	// Create Business table
	ifstream business_file("Yelp Data/yelp_academic_dataset_business.json");
	vector<string> business_attributes{ "business_id", "name", "postal code", "stars", "review_count" };
	Table* businesses = new Table(business_attributes);

	for (int i = 0; i < line_count; i++)
	{
		if (getline(business_file, file_line))
		{
			json business = json::parse(file_line.c_str());
			Record r(business_attributes.size());
			for (int j = 0; j < business_attributes.size(); j++)
			{
				auto val = business[business_attributes.at(j)];
				if (val.type() == json::value_t::string)
					r.set(j, val);
				else if (val.type() == json::value_t::number_unsigned)
				{
					int val_int = val;
					r.set(j, to_string(val_int));
				}
			}
			businesses->add_record(r);
		}
	}
	yelp_data->add_table(*businesses, "businesses");

	// Create Review Table
	ifstream review_file("Yelp Data/yelp_academic_dataset_review.json");
	vector<string> review_attributes{ "review_id", "user_id", "business_id", "stars", "date", "text" };
	Table* reviews = new Table(review_attributes);

	for (int i = 0; i < line_count; i++)
	{
		if (getline(review_file, file_line))
		{
			json review = json::parse(file_line.c_str());
			Record r(review_attributes.size());
			for (int j = 0; j < review_attributes.size(); j++)
			{
				auto val = review[review_attributes.at(j)];
				if (val.type() == json::value_t::string)
					r.set(j, val);
				else if (val.type() == json::value_t::number_unsigned)
				{
					int val_int = val;
					r.set(j, to_string(val_int));
				}
			}
			reviews->add_record(r);
		}
	}
	yelp_data->add_table(*reviews, "reviews");


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
