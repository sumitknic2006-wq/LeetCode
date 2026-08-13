#include <iostream>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {

        int reverse = 0;

        while(n != 0){
            int rem = n % 10;
            reverse = reverse*10 + rem;
            n = n/10;
        }
        
        int ans  = 0 , i = 0;

        while(reverse != 0)
        {
            int rem = reverse%10;
            
            // even index
            if(i%2 == 0)
            {
                ans = ans + rem;
                i++;
            }
            
            // odd index
            else{
                ans = ans - rem;
                i++;
            }

            reverse = reverse/10;
        }

        return ans;
    }
};