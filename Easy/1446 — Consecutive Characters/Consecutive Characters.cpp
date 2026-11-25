#include <iostream>
using namespace std;
class Solution {
public:
    int maxPower(string s) {
        int maxlength = 1;
        int currentLength = 1;

        for(int i = 1;i<s.size();i++)
        {
            // equal --> currentlength increases one and update maxlenlength 
            if(s[i] == s[i-1])
            {
                currentLength++;
                maxlength = max(currentLength,maxlength);
            }
            
            // not equal -> phir se new character ke currentlength = 1 se --> start
            else{
                currentLength = 1;
            }
        }
        return maxlength;
    }
};