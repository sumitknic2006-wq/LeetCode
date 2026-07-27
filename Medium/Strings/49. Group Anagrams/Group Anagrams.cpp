#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // // sorted string, original string
        // vector<pair<string, string>> arr;

        // // Step 1: Pair banao
        // for (string str : strs) {
        //     string key = str;
        //     sort(key.begin(), key.end());

        //     arr.push_back({key, str});
        // }

        // // Step 2: Key ke basis par sort karo
        // sort(arr.begin(), arr.end());

        // vector<vector<string>> ans;

        // int i = 0;

        // while (i < arr.size()) {

        //     vector<string> group;

        //     group.push_back(arr[i].second);

        //     int j = i + 1;

        //     while (j < arr.size() && arr[j].first == arr[i].first) {
        //         group.push_back(arr[j].second);
        //         j++;
        //     }

        //     ans.push_back(group);

        //     i = j;
        // }

        // return ans;



        // or 

        
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {

            string key = str;

            sort(key.begin(), key.end());

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};