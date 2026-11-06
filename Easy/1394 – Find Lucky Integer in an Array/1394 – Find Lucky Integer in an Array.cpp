#include <iostream>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> freq;
        int max_lucky = -1;

        // Harek element ka freq nikal liye hjai.
        for(int i = 0;i<n;i++)
        {
            freq[arr[i]]++;
        }

        // check to the lucky number
        for(auto &pair : freq)
        {
            int key = pair.first;
            int count = pair.second;
            
            // agar equal key and count then max_lucky updated
            if(key == count)
            {
                max_lucky = max(key,max_lucky);
            }
        }

        return max_lucky;

    }
};