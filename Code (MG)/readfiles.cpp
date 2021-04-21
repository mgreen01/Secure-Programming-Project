#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main () {
    ifstream inputFile;
    string user_name;
    int user_age;
    int user_type;
    string user_password;

    cout << "Enter your username: " << endl;
    cin >> user_name;
    string user_name2 = user_name +".txt";
    cout << user_name2 << endl;

    inputFile.open(user_name2);

    if (inputFile.is_open()){
        while (getline(inputFile, user_name))
        {
            cout << user_name << "\n";
        }
        inputFile.close();
    }



    



}