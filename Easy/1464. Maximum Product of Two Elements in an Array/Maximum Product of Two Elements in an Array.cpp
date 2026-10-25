#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = i+1;j<n;j++)
        //     {
        //         int curr = (nums[i]-1)*(nums[j]-1);
        //         ans = max(ans,curr);
        //     }
        // }
        // return ans;

        // or --> Time Complexity:- o(nlogn)
        int n = nums.size()-1;
        sort(nums.begin(),nums.end());
        
        int ans = (nums[n]-1)*(nums[n-1]-1);

        return ans;


        // Or --> t:o(n) , s:o(1)

        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for(int num : nums)
        {
            if(num>max1)
            {
                max2 = max1;
                max1 = num;
            }
            else if(num>max2)
            {
                max2 = num;
            }
        }
        return (max1-1)*(max2-1);
    }
};