#include <iostream>
using namespace std;

class Solution {
public:

    bool isPowerOfTwo(int n) {

        // if(n<0){
        //     return false;
        // }

        // int count = 0;

        // while(n != 0){
        //     count  = count + (n & 1);
        //     n = n >> 1;
        // }
        // return count == 1;

        // or

        if(n<=0) return false;

        return (n & (n-1)) == 0;
    }
};