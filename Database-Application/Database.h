#pragma once

// Database.h - Contains declaration of Database, Table and Record classes  
#pragma once  

#ifdef DATABASE_EXPORTS  
#define DATABASE_API __declspec(dllexport)   
#else  
#define DATABASE_API __declspec(dllimport)   
#endif  

#include <string>
#include <map>
#include <vector>
#include <exception>
#include <memory>

namespace Database {
	class Record {
		struct r_hider;
		r_hider* r_ptr;	
	public:
		DATABASE_API Record(int size = 0);
		DATABASE_API ~Record();
		DATABASE_API int get_size();
		DATABASE_API void add_attribute(std::string attribute);
		DATABASE_API void remove_attribute(int position);
		DATABASE_API void set(int position, std::string value);
		DATABASE_API void set_key(int position);
		DATABASE_API std::string get(int position);
	};

	class Table {
		struct t_hider;
		std::unique_ptr<t_hider> t_ptr;
	public:
		typedef std::map<std::string, Record>::iterator iterator;
		DATABASE_API Table();
		DATABASE_API Table(std::vector<std::string> attributes);
		DATABASE_API ~Table();
		DATABASE_API Table(const Table& other);
		DATABASE_API Table(Table&&);
		DATABASE_API Table& operator=(const Table& other);
		DATABASE_API void add_attribute(std::string attribute_name);
		DATABASE_API std::vector<std::string> get_attributes();
		DATABASE_API std::map<std::string, Record> get_records();
		DATABASE_API int get_size();
		DATABASE_API void delete_attribute(std::string attribute);
		DATABASE_API void add_record(Record r);
		DATABASE_API void designate_attribute_as_key(std::string attribute_name);
		DATABASE_API Table cross_join(Table t1, Table t2);
		DATABASE_API Table natural_join(Table t1, Table t2);
		DATABASE_API std::string minimum(std::string attribute_name);
		DATABASE_API std::string maximum(std::string attribute_name);
		DATABASE_API int count(std::string attribute_name);
		DATABASE_API Record get_record(std::string key);
		DATABASE_API Record get_record_at(int position);
		DATABASE_API iterator begin();
		DATABASE_API iterator end();
	};

	class Database {
		struct d_hider;
		std::unique_ptr<d_hider> d_ptr;
	public:
		DATABASE_API Database();
		DATABASE_API ~Database();
		DATABASE_API Database(const Database & other);
		DATABASE_API Database & operator=(const Database & other);
		DATABASE_API Database(Database&&);
		DATABASE_API void add_table(Table t, std::string table_name);
		DATABASE_API void drop_table(std::string table_name);
		DATABASE_API std::map<std::string, Table> get_tables();
		DATABASE_API std::vector<std::string> list_all_tables();
		DATABASE_API Table query(std::string select, std::string from, std::string where);

	};
}
