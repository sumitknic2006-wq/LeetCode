#include<iostream>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();
        
        // Edge cases: agar size 1 ho ya answer bilkul start/end par ho
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int start = 0, end = n-2;

        while(start<=end)
        {
            int mid = start+(end-start)/2;

            // Agar mid apne left aur right dono se alag hai
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }

            // Agar mid apne left element ke barabar hai
            if(nums[mid] == nums[mid-1])
            {
                if(mid%2  == 1)
                {
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            
            // Agar mid apne right element ke barabar hai
            else if(nums[mid] == nums[mid+1])
            {
                if(mid%2 == 0)
                {
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};