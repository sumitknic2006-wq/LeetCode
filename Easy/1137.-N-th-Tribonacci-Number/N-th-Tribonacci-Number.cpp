#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
    
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        
        int f0 = 0;
        int f1 = 1;
        int f2 = 1;
       for(int i = 3;i<=n;i++){
        int ans = f0 + f1 + f2 ;

        f0 = f1;
        f1 = f2;
        f2 = ans;

       }
       return f2;


       // or --> recursive method but ye time limit exceed de dega kiyonki iska t.c: o(3^n), ye kuch time ke bad code bahut slow ho jata hai.

    //    if(n == 0){
    //         return 0;
    //     }

    //     if(n == 1){
    //         return 1;
    //     }

    //     if(n == 2){
    //         return 1;
    //     }

    //     return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);

    }
};