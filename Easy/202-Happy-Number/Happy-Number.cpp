#include <iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        // initial approach

        // while(n != 1){
        //     int ans = 0;

        //     while(n != 0){
        //         int rem = n%10;

        //         ans = ans + rem * rem;

        //         n = n/10;
        //     }

        //     n = ans;

        // }

        // return true;

        // isme isliye time limit likha rha hai ki jo bhi nyumber le rhe uske individual sqare ke sum ke 1 ke barabar nahi hai.




        // or->  unordered_set


        unordered_set<int>ans;

        while(n != 1){

            // Agar number already aa chuka hai,
            // matlab cycle hai
            if (ans.count(n)) {
                return false;
            }

            ans.insert(n);


            int ans = 0;

            while(n != 0){
                int rem = n%10;

                ans = ans + rem * rem;

                n = n/10;
            }

            n = ans;
        }

        return true;
    }
};