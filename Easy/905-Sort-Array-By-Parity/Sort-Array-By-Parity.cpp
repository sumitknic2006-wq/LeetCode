#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        // int n = nums.size();

        // for(int i = 0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         if(nums[j]%2 == 0){
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }

        // return nums;


        // or

        int n = nums.size();
        
        int j = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]%2 == 0){
              swap(nums[i] , nums[j]);
              j++;
            }
        }

        return nums;
        
    }
};