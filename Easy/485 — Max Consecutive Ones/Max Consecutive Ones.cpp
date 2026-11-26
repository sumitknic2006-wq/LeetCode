#include <iostream>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int MaxLength = 0;
        int currentLength = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                currentLength++;
                MaxLength = max(MaxLength,currentLength);
            }
            else{
                currentLength = 0;
            }
        }
        return MaxLength;
    }
};