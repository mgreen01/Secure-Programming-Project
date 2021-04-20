// C++ program to check if the first
// and the last characters of a string
// are equal or not.
#include<iostream>
  
using namespace std;
  
// Function to check if the first
// and the last haracters of a
// string are equal or not.
int areCornerEqual(string s)
    {
        int n = s.length();
        if (n < 2)
        return -1;
        if (s[0] == s[n - 1])
        return 1;
        else
        return 0;
    }
  
// Driver code
int main()
    {
        string s = "GfG";
        int res = areCornerEqual(s);
        if (res == -1)
            cout<<"Invalid Input";
        else if (res == 1)
            cout<<"Equal";
        else
            cout<<"Not Equal";
    }
      
// This code is contributed by 
// Smitha Dinesh Semwal