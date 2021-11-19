#include <iostream>
#include <fstream>
using namespace std;

bool signup(string usr, string pass) {
	string filename = "users//" + usr + ".txt";
	ofstream file;
	file.open(filename);
	if (file.is_open()) {
		file << usr << endl;
		file << pass << endl;
		file.close();
		return true;
	} else {
		file.close();
		return false;
	}
}

bool login(string usr, string pass) {
	string filename = "users//" + usr + ".txt";
	string username, password;
	ifstream file (filename);
	if (file.is_open()){
		getline(file, username);
		getline(file, password);
		if (usr == username && pass == password) {
			file.close();
			return true;
		} else {
			file.close();
			return false;
		}
	} else {
		file.close();
		return false;
	}
}

int main () {
	string usr, pass;
	int choice;

	cout << "Options: " <<endl;
	cout << "1. sign up" << endl;
	cout << "2. login" << endl;
	cout << "3. Exit" << endl;
	while (true) {
		cout << endl << "Choice: ";
		cin >> choice;
		switch(choice) {
			case 1:
				
				cout << "Enter a username: ";
				cin >> usr;
				cout << "Enter a password: ";
				cin >> pass;
				if (signup(usr, pass)) {
					cout << "Account created succesfully!" << endl;
				} else {
					cout << "Oops :( something went wrong" << endl;
				}
				break;
			case 2:
				while (true) {
					cout << "Enter your username: ";
					cin >> usr;
					cout << "Enter your password: ";
					cin >> pass;
					if (login(usr, pass)) {
						cout << "Login Successful!!" <<endl;
						break;
					} else {
						cout << endl << "Incorrect username or password" <<endl;
					}
				}
				break;
			case 3:
				exit(0);
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}

	return 0;
}
