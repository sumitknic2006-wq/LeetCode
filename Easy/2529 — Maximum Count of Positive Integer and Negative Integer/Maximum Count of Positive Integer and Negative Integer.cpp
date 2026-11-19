#include <iostream>
using namespace std;
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();

        int count0 = 0;
        int count1 = 0;

        for(int i = 0;i<n;i++)
        {
            if(nums[i]>0){
                count0++;
            }
            else if(nums[i]<0){
                count1++;
            }
        }
        return max(count0,count1);
    }
};