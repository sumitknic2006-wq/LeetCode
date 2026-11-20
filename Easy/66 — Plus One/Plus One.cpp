#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1;i>=0;i--){

            // digit<9
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }

            // digits = 0
            digits[i] = 0;
        }

        // all digits = 9
        digits.insert(digits.begin(),1);

        return digits;

    }
};