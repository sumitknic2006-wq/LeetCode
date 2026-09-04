#include<iostream>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        // int n = nums.size();

        // int i = 0;
        // while((0<=i && i<=n-1)){
        //     int result = max(nums[0] , nums[i]) - min(nums[i] , nums[n-1]);

        //     if(result<=k){
        //         return k;
        //     }
        //     i++;
        // }

        // return -1;
        
        // ye approach me all case pass nahi karta hai ye mera innitial approach tha


        // or

        int n = nums.size();
        for(int i = 0; i < n; i++){

            int maxi = nums[0];
            int mini = nums[i];

            for(int j = 0; j <= i; j++){
                maxi = max(maxi, nums[j]);
            }

            for(int j = i; j < n; j++){
                mini = min(mini, nums[j]);
            }

            int result = maxi - mini;

            if(result <= k){
                return i;
            }
        }

        return -1;
        
    }
};