#include <iostream>
#include <fstream>
#include <string.h>
#include <limits>
#include <cstring>
#include <stdlib.h>
#include <sstream>
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

fstream& GotoLine(fstream& file, unsigned int num)
{
    file.seekg(ios::beg);
    for(int i = 0; i < num -1; ++i){
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return file;
}


void encrypt(char passArray[30], string usr)
{
    cout << "this is a test cout" <<endl;
    string file = "users//" + usr + ".txt";
    ofstream ofs;
    ofs.open(file, ofstream::out | ofstream::trunc);

    if(ofs.is_open()){
    for(int i = 0; (i < 30 && passArray[i] != '/0'); i++)
        passArray[i] = passArray [i] + 2;
    cout <<"\n Encrypted string: " << passArray << endl;
    ofs << usr << endl;
    ofs << passArray << endl;
    ofs.close();
    }
    else
        cout << "hello there, file is not open" << endl;



}


void arrayConvert(string usr, string pass)
{
    string linepass;
    string line, text;
    ostringstream sstream;
    fstream file("users//" + usr + ".txt");

    GotoLine(file , 2);
    file >> linepass;
    cin.get();

    int len = linepass.size() + 1;
    char passArray[len];

    if(file.is_open()){
        for (int i = 0; i < linepass.length(); i++){
            passArray[i] = linepass[i];
        }
        passArray[len - 1] = '\0';
        file.close();
        encrypt(passArray,usr);
    }
    else
        cout << "can't open file";
}


int main () {
	string usr, pass;
	int choice;
    while (true) {
	cout << "Options: " <<endl;
	cout << "1. sign up" << endl;
	cout << "2. login" << endl;
	cout << "3. Exit" << endl;

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
			    arrayConvert(usr, pass);
				exit(0);
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}

	return 0;
}
