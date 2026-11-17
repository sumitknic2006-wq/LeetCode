#include <iostream>
using namespace std;
class Solution {
public:

    bool print(string &s,int index,int n)
    {
        if(index>=n)
        {
            return true;
        }

        if(!isalnum(s[index]))
        {
            return print(s,index+1,n);
        }
        if(!isalnum(s[n]))
        {
            return print(s,index,n-1);
        }

        if(tolower(s[index]) != tolower(s[n]))
        {
            return false;
        }
        return print(s,index+1,n-1);
    }
    bool isPalindrome(string s) {

        return print(s,0,s.size()-1);
    }
};