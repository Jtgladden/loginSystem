#include <iostream>
#include <fstream>
using namespace std;

bool signup(string usr, string pass) {
	string filename = usr + ".txt";
	ofstream file;
	file.open(filename);
	if (file.is_open()) {
		file << "Username: " << usr << endl;
		file << "Password: " << pass << endl;
		file.close();
		return true;
	} else {
		file.close();
		return false;
	}
}

int main () {
	string usr, pass;

	cout << "Enter a username: ";
	cin >> usr;
	cout << "Enter a password: ";
	cin >> pass;
	if (signup(usr, pass)) {
		cout << "Account createdf succesfully!" << endl;
	} else {
		cout << "Oops :( something went wrong" << endl;
	}
	return 0;
}
