//This is a blank file
#include <iostream>
using namespace std;


class Crypto {
    string plain_password;
    string encrypted_password;
};

class User {
    public:
    string username;
    int age;
    string password;
};

int main () {
    cout << "Please enter a new username: " << endl;
    User new_user;
    cin >> new_user.username;
    return 0;
};