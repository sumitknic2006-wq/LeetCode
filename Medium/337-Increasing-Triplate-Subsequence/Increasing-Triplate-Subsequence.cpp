#include<iostream>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int first = INT_MAX;
        int second = INT_MAX;
        
        for(int num : nums)
        {
            // first minimum --> first element , sabse chota element
            if(num <= first)
            {
                first = num;
            }

            // second minimum --> second elemnet mila lekin first se bada
            else if(num <= second)
            {
                second = num;
            }

            // Third elemnet lekin first and second se bada.
            else{
                return true;
            }
        }
        return false;
    }
};