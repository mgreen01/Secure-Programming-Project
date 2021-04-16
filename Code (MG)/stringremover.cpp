#include <iostream>

using std::cout;
using std::string;

int main(){
	string s = "Random string";
	cout << s.substr(2) << '\n';
	cout << s.replace(0,1,"") << '\n';
}