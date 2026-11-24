#include <iostream>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {

      int n = word.length();
      int capitalCount = 0;

        // Count uppercase letters
        for(int i = 0; i < n; i++) {

            if(isupper(word[i])) {
                capitalCount++;
            }
        }

        // Case 1: All letters capital
        if(capitalCount == n) {
            return true;
        }

        // Case 2: All letters small
        if(capitalCount == 0) {
            return true;
        }

        // Case 3: Only first letter capital
        if(capitalCount == 1 && isupper(word[0])) {
            return true;
        }

        return false;
        
    }
};