#include <iostream>
using namespace std;
class Solution {
public:

    int binary(vector<int>& nums, int n, int target)
    {
        int start = 0, end = n-1;

        while(start<=end)
        {
            int mid = start+(end-start)/2;

            if(nums[mid] == target){
                return mid;
            }

            else if(nums[mid]<target)
            {
                start = mid+1;
            }

            else{
                end = mid-1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        return binary(nums,nums.size(),target);
    }
};