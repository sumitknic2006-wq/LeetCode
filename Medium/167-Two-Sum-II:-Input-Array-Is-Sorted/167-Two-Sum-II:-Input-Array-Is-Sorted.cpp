#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int n = numbers.size();

        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = i+1;j<n;j++)
        //     {
        //         if(numbers[i]+numbers[j] == target)
        //         {
        //             return {i+1,j+1};
        //         }
        //     }
        // }
        // return {};

        // or two pointer

        int start = 0, end = numbers.size()-1;

        vector<int> ans;

        while(start<end)
        {
            if(numbers[start]+numbers[end] == target)
            {
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }

            else if(numbers[start]+numbers[end] > target){
                end--;
            }

            else{
                start++;
            }
        }

        return ans;
    }
};