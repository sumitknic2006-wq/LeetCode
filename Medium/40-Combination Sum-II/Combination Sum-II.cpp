#include<iostream>
using namespace std;

class Solution {
public:

    void comb(vector<int>& candidates , int index, int n , int target, vector<vector<int>> &s, vector<int> &temp  )
    {
        if(target == 0)
        {
            s.push_back(temp);
            return;
        }
        if(target<0)
        {
            return;
        }

        for(int i = index;i<n;i++)
        {
            if(i>index && candidates[i] == candidates[i-1])
            continue;
            temp.push_back(candidates[i]);
            comb(candidates,i+1,n,target-candidates[i],s,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> s;
        vector<int> temp;

        comb(candidates,0,candidates.size(),target,s,temp);

        // vector<vector<int>> ans(s.begin(),s.end());
        return s;

    }
};