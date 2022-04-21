#include "account.h"
#include <string>
#include <fstream>

void Account::setName(std::string name) {
	
	this->name = name;
}

void Account::setpassword(std::string x) {
	 id++;
	this->password = x;
}

void Account::savefile(std::string p, std::string n) {
	std::ofstream file;
	file.open("account.txt", std::ios::app);
	file << p << " " << n << std::endl;
	file.close();
}
bool Account::readfile(std::string p, std::string n) {
	std::ifstream file;
	file.open("account.txt");
	std::string x, y;
	while (file >> x >> y) {
		if (x == p && y == n) {
			return true;
		}
	}
	return false;
}