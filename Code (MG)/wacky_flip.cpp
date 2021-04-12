#include <iostream> 
#include <string.h> 
using namespace std;

int main ()
{
    char s[30], temp;
    int i, n;
    cout << "Please, enter a string : ";
    gets(s);
    n = strlen(s) - 1;
    for (i = 0; i < n; i++, n--)
    {
    	// swapping
        temp = s[i];
        s[i] = s[n];
        s[n] = temp;
    }
    cout << "Mirror of the string is : " << s;
    return 0;
}