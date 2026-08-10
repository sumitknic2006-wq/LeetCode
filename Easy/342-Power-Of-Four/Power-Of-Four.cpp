#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {


        // if(n<1){
        //     return false;
        // }

        // for(long long i = 0;i<=20;i++){
        //     if(n == pow(4 , i)){
        //         return true;
        //     }
        // }

        // return false;



        // OR


        // if(n<1){
        //     return 0;
        // }

        // while(n != 1){
        //     if(n%4 != 0){
        //         return 0;
        //     }
        //     n /= 4;
        // }
        // return 1;


        // OR -> Bitwise Operator

        // if(n<=0) return false;
        // int zero = 0;
        // int one = 0;

        // while(n != 0){
        //     if((n&1) == 0)
        //     zero++;
        //     else
        //     one++;

        //     n >>= 1;
        // }

        // return (one == 1) && ((zero % 2) == 0);


        // or

        if(n<=0) return false;
        return ((n&(n-1)) == 0) && n%3 == 1;
    }
};