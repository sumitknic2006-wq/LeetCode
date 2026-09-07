#include<iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // int n = nums.size();

        // // find the pivot
        // int pivot = -1;

        // for(int i = n-2;i>=0;i--){
        //     if(nums[i]<nums[i+1]){
        //         pivot = i;
        //         break;
        //     }
        // }

        // if(pivot == -1){
        //     reverse(nums.begin(),nums.end());
        //     return;
        // }

        // // 2nd step : next larger element
        // for(int i = n-1; i>pivot; i--){
        //     if(nums[i]>nums[pivot]){
        //         swap(nums[i],nums[pivot]);
        //         break;
        //     }
        // }
        
        // // 3rd step : reverse (pivot to n-1)
        // // reverse(nums.begin() + pivot + 1 , nums.end());

        // int i = pivot+1 , j = n-1;
        // while(i <= j){
        //     swap(nums[i++] , nums[j--]);
        // }

        // or

        next_permutation(nums.begin(), nums.end());
    }
};