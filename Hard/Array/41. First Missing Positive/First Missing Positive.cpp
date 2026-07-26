#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // nums vector ke saare elements unordered_set me store kar do
        unordered_set<int> s(nums.begin(), nums.end());  // nums vector ke begin() se end() tak jitne bhi elements hain, un sabko unordered_set s me daal do.
        // num.begin():- Ye vector ke first element ka iterator return karta hai.
        // nums.end():- Ye last element ke baad ki position ko point karta hai.

        // 1 se lekar n+1 tak check karo
        for (int i = 1; i <= nums.size() + 1; i++) {

            // Agar i set me nahi hai to wahi answer hai
            if (!s.count(i)) {
                return i;
            }
        }

        return 0;   // Time Complexity:- O(n) , Space Complexity:- O(n);
    }
};