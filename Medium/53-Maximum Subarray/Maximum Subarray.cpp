#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxsum = INT_MIN;
    int currsum = 0;

    for(int num : nums)
    {
        currsum = max(num,currsum+num);
        maxsum = max(maxsum,currsum);
    }
    return maxsum;
    }
};