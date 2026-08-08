#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // unordered_set<char> st;

        // int left = 0;
        // int ans = 0;

        // for(int right = 0; right < s.size(); right++) {

        //     while(st.count(s[right])) {

        //         st.erase(s[left]);
        //         left++;
        //     }

        //     st.insert(s[right]);

        //     ans = max(ans, right - left + 1);
        // }

        // return ans;
        


        // or

        vector<bool> count(256, 0);

        int first = 0, second = 0 , len = 0;

        while(second<s.size())
        {
            // Repeating Char
            while(count[s[second]])
            {
                count[s[first]] = 0;
                first++;
            }

            count[s[second]] = 1;

            len = max(len, second-first+1);
            second++;
        }

        return len;
    }
};