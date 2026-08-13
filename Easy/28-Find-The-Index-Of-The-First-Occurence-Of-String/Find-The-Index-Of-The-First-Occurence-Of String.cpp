#include <iostream>
using namespace std;

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
        
        // int n = haystack.size() , m = needle.size();

        // for(int i = 0;i<=n-m;i++)
        // {
        //     int first = i , second = 0;

        //     while(second<m){

        //         if(haystack[first] != needle[second])
        //         {
        //             break;
        //         }

        //         else{
        //             first++ , second++;
        //         }
        //     }

        //     if(second == m){
        //         return first - second;
        //     }
        // }

        // return -1;

//     }
// }



class Solution {
public:

   void lpsfind(vector<int>&lps,string s){
        int pre = 0 , suf = 1;
        
        while(suf<s.size())
        {
         // Match
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                suf++ , pre++;
            }
         
            else{
                if(pre == 0){
                    lps[suf] = 0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
   }
        


    int strStr(string haystack, string needle) {


        // or -> second Approach

        vector<int> lps(needle.size(),0);
        lpsfind(lps , needle);

        int first = 0 , second = 0;

        while(second<needle.size() && first<haystack.size())
        {

            // matched
            if(needle[second] == haystack[first])
            {
                second++ , first++;
            }

            // not matched
            else
            {
                if(second == 0)
                {
                    first++;
                }

                else{
                    second = lps[second-1];
                }
            }
        }

        // Answer exist
        if(second == needle.size()){
            return first - second;
        }

        return -1;
    }
};