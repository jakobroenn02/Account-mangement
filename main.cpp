#include <iostream>
#include <string>
#include <limits>
#include "account.h"

bool login(bool* x) {
	std::string username;
	std::string password;
	Account account;
	std::cout << "Enter exit to exit. \n";
	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;
	if (username == "exit") {
		*x = true;
		return false;
	}
	if (account.readfile(password, username) == true) { return true; }
	else { return false; }
}
void createAccount() {
	Account newAccount;
	std::string username;
	std::string password;
	std::cout << "Enter username: ";
	std::cin >> username;
	newAccount.setName(username);
	std::cout << "\nEnter password: ";
	std::cin >> password;
	newAccount.setpassword(password);
	newAccount.savefile(password, username);
}
void userfunction() {
	std::string a = "Welcome to this program! \n The following options are availible:\n 1.Login \n 2.Create Account \n 3.Exit \n";
	int choice{};
	bool done = false;
	bool* ptr = &done;
	std::cout << a;
	std::cin >> choice;
	do {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch (choice) {
		case 1:
			if (login(ptr) == true) {
				std::cout << "Login successful! \n";
			}
			else {
				std::cout << "Login failed! \n";
			}
			break;
		case 2:
			createAccount();
			choice = 0;
			break;

		case 3:
			std::cout << "Exiting program... \n";
			done = true;
			break;
		default:
			std::cout << "Invalid input! \n \n \n";
			userfunction();
			break;
		}
	} while (!done);
	
}
int main()
{
	userfunction();
	return 0;
}

