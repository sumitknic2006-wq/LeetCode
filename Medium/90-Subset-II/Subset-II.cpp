#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

    void subset(vector<int>& nums, int index, int n, set<vector<int>> &s,vector<int>&temp)
    {
        if(index == n)
        {
            s.insert(temp);
            return;
        }
        // Not include
        subset(nums,index+1,n,s,temp);

        // Include
        temp.push_back(nums[index]);
        subset(nums,index+1,n,s,temp);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;
        vector<int> temp;

        subset(nums,0,nums.size(),s,temp);

        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};