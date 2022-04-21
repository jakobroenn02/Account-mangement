#pragma once
#include <string>
#include <iostream>
class Account {
	public:
		
		int id;
		
		void setName(std::string name); 
		
		void setpassword(std::string x);
		
		void savefile(std::string p , std::string n);

		bool readfile(std::string p, std::string n);
			
	private:
		std::string password;
		std::string name;

		
};