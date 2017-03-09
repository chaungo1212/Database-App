// Database-Application.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
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

void PrintTable(Table* t);

int main()
{
	DB* yelp_data = new DB();

	/*
	parse JSON Format files and populate DB object
	*/
	string file_line = "";
	int line_count = 50;

	// Create Users Table
	ifstream user_file("Yelp Data/yelp_academic_dataset_user.json");
	vector<string> user_attributes{ "user_id", "name", "review_count", "yelping_since", "fans", "average_stars" };
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
					r.Set(j, val);
				else if (val.type() == json::value_t::number_float)
				{
					int val_int = val;
					r.Set(j, to_string(val_int));
				}
			}
			users->InsertRecord(r);
		}
	}
	yelp_data->Add("users",users);

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
					r.Set(j, val);
				else if (val.type() == json::value_t::number_float)
				{
					float val_int = val;
					r.Set(j, to_string(val_int));
				}
			}
			businesses->InsertRecord(r);
		}
	}
	yelp_data->Add("businesses",businesses);

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
					r.Set(j, val);
				else if (val.type() == json::value_t::number_float)
				{
					int val_int = val;
					r.Set(j, to_string(val_int));
				}
			}
			reviews->InsertRecord(r);
		}
	}
	yelp_data->Add("reviews", reviews);
	
	//create User x Review table
	Table* user_review = new Table();
	*user_review = users->NaturalJoin(*reviews);
//	cout << "Natural join for users and reviews: " << user_review->GetSize() << endl;
//	PrintTable(user_review);

	//create Business x Review table
	Table* business_review = new Table();
	*business_review = businesses->NaturalJoin(*reviews);
//	cout << "Natural join for business and reviews: " << business_review->GetSize() << endl;
//	PrintTable(business_review);

	//Max and Min for user
		string user_max = users->Max("fans");
		string user_min = users->Min("fans");

	//Max and Min for business
		string business_max = businesses->Max("stars");
		string business_min = businesses->Min("stars");	
	
	cout << "Options: " << endl
		<< "1) Print info about a given User" << endl
		<< "2) Print info about a given Business" << endl
		<< "3) Show the reviews for a given User" << endl
		<< "4) Show the reviews for a given Business" << endl
		<< "5) Find Max and Min review counts in Users" << endl
		<< "6) Find Max and Min review counts in Businesses" << endl
		<< "7) Find the most popular user in the data set" << endl
		<< "8) Find the user with the lowest scoring average reviews" << endl
		<< "9) Find the user with the highest scoring average reviews" << endl
		<< "Q) Exit program" << endl;

	cout << "Enter command: " << endl;

	string command;


	//char input[256];

	while (cin >> command)
	{
		//string command = input; 

		if (command == "Q")
		{
			break;
		}
		else if (command == "1")
		{
			string userID;
			cout << "Enter User ID: ";
			cin >> userID;
			Record* user;
			for(user = users->GetFirstRecord(); user != NULL; user=user->next)
			{
				if( user->Get(0) == userID ) 
				{
					//should print "NA" for unavailable data points
					cout << "User ID: " << user->Get(0) << endl
						<< "Name: " << user->Get(1) << endl
						<< "Number of reviews: " << user->Get(2) << endl
						<< "Yelping since: " << user->Get(3) << endl
						<< "Average review rating: " << user->Get(4) << endl;
				}
			}
		}
		else if (command == "2")
		{
			string businessID;
			cout << "Enter Business ID: ";
			cin >> businessID;

			Record* business;
			for(business = businesses->GetFirstRecord(); business != NULL; business=business->next)
			{
				if( business->Get(0) == businessID )
				{
					//should print "NA" for unavailable data points
					cout << "Business ID: " << business->Get(0) << endl
						<< "Name: " << business->Get(1) << endl
						<< "Stars: " << business->Get(2) << endl
						<< "Number of reviews: " << business->Get(3) << endl;
				}
			}	
		}
else if (command == "3") //user_review
  {
   string userID;
   cout << "Enter User ID: ";
   cin >> userID;

   Record* review;
   int index_userID = user_review->getIndexOfAttribute("user_id");
   int index_review = user_review->getIndexOfAttribute("text");
   for(review = user_review->GetFirstRecord(); review != NULL; review=review->next)
   {
    if( review->Get(index_userID) == userID ) 
    {
     //should print "NA" for unavailable data points
		cout << "User ID: " << review->Get(index_userID) << endl
			<< "Review text: " << review->Get(index_review) << endl;
    }
   }
  }
  else if (command == "4") //business_review
  {
   string businessID;
   cout << "Enter Business ID: ";
   cin >> businessID;

   Record* review;
   int index_businessID = business_review->getIndexOfAttribute("business_id");
   int index_review = business_review->getIndexOfAttribute("text");
   for(review = business_review->GetFirstRecord(); review != NULL; review=review->next)
   {
    if( review->Get(index_businessID) == businessID ) 
    {
     //should print "NA" for unavailable data points
		cout << "Business ID: " << review->Get(index_businessID) << endl
			<< "Review text: " << review->Get(index_review) << endl;
    }
   }
  }
	else if (command == "5") // Find Users with Max and min review 
  {
   cout << "Max review counts in Users: " << users->Max("review_count") << endl
    << "Min review counts in Users: " << users->Min("review_count") << endl;
  }
  else if (command == "6") // Find Businesses with Max and min review 
  {
   cout << "Max review counts in Businesses: " << businesses->Max("review_count") << endl
    << "Min review counts in Businesses: " << businesses->Min("review_count") << endl;
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
			try {
				cout << "Finding the most popular user in the data set..." << endl;
				string max_fans = users->Max("fans");
				Table* user = yelp_data->Query("user_id", "users", "fans = " + max_fans);
				cout << user->GetFirstRecord()->Get(0) << endl;
			}
			catch (...)
			{
				cout << "Unable to find user with the highest number of fans..." << endl;
			}
			
		}
		else if (command == "8")
		{
			try {
				cout << "Finding the user with the lowerst scoring average reviews..." << endl;
				string min_review_avg = users->Min("average_stars");
				Table* user = yelp_data->Query("user_id", "users", "average_stars = " + min_review_avg);
				cout << user->GetFirstRecord()->Get(0) << endl;
			}
			catch (...)
			{
				cout << "Unable to find user with the lowerst scoring average reviews..." << endl;
			}
			
		}
		else if (command == "9")
		{
			try {
				cout << "Finding the user with the highest scoring average reviews..." << endl;
				string max_review_avg = users->Max("average_stars");
				Table* user = yelp_data->Query("user_id", "users", "average_stars = " + max_review_avg);
				cout << user->GetFirstRecord()->Get(0) << endl;
			}
			catch (...)
			{
				cout << "Unable to find user with the highest scoring average reviews..." << endl;
			}
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
			<< "5) Find Max and Min review counts in Users" << endl
			<< "6) Find Max and Min review counts in Businesses" << endl
			<< "7) Find the most popular user in the data set" << endl
			<< "8) Find the user with the lowest scoring average reviews" << endl
			<< "9) Find the user with the highest scoring average reviews" << endl
			<< "Q) Exit program" << endl;

		cout << "Enter command: " << endl;

	}

	cout << "Program exited!" << endl;

	return 0;
}

void PrintTable(Table* t) {
	std::cout << "====================================================\n";
	Record* current = t->GetFirstRecord();
	std::vector<std::string> values;
	while (current != NULL) {
		values = current->values;
		std::cout << "----------------------------------------------------\n";
		for (int i = 0; i < values.size(); i++)
			std::cout << values[i] << " ";
		std::cout << std::endl;
		std::cout << "----------------------------------------------------\n";
		current = current->next;
	}
	std::cout << "====================================================\n";
}
