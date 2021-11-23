#include <iostream>
#include <fstream>
using namespace std;


string hashFunc(string key) {
	string ret = "";
	for (int i = 0; i < key.size(); i++) {
		ret += to_string((int)key[i] % 16);
	}
	return ret;
}

bool signup(string usr, string pass) {
	string filename = "users//" + usr + ".txt";
	ofstream file;
	file.open(filename);
	if (file.is_open()) {	
		file << hashFunc(pass) << endl;
		return true;
	} 
	return false;
}

bool login(string usr, string pass){
	string filename = "users//" + usr + ".txt";	
	ifstream file(filename);
	if(!file.is_open()) {
		cout << "Cannot Open File" << endl;
		return false;
	}
	string password_hash = "";
	file >> password_hash;
	if (file.fail()) {
		cout << "Cannot read data" << endl;
		return false;
	}
	return (hashFunc(pass) == password_hash);	
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
					cout << "Enter your username(-1 to exit): ";
					cin >> usr;
					if (usr == "-1") {
						break;
					}
					cout << "Enter your password:";
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
