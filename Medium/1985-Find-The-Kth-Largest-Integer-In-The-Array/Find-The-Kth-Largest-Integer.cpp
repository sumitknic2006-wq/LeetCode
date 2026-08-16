#include <iostream>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        int n = nums.size();

        // sorting of string way
        sort(nums.begin(),nums.end() , [](string a , string b){

            if(a.size() != b.size())
                return a.size() < b.size();

            return a < b;
        });

        return nums[n-k];   /* or -> int j = 1;

                                    for(int i = n-1; i >= 0; i--)
                                    {
                                        if(j == k)
                                            return nums[i];

                                        j++;
                                    }*/
        
    }
};