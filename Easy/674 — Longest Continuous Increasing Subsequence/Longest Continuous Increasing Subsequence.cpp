#include <iostream>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength = 1;
        int currentLength = 1;

        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
                currentLength++;
                maxLength = max(currentLength,maxLength);
            }
            else{
                currentLength = 1;
            }
        }
        return maxLength;
    }
};