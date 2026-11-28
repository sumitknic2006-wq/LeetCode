#include <iostream>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int maxPerson = 0;
        int current = 0;

        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == 'E')
            {
                current++;
                maxPerson = max(maxPerson,current); 
            }
            else{
                current--;
            }
        }
        return maxPerson;
    }
};