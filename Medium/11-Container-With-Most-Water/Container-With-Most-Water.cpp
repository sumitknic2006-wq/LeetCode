#include<iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {

        // BrutesForce Approach

        // int n = height.size();

        // int temp = 0;
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = n-1;j>0;j--)
        //     {
        //         if(i<j){
        //             int hei = min(height[i],height[j]);
        //             int curr = hei*(j-i);
        //             temp = max(temp,curr);
        //         }
        //     }
        // }
        // return temp;
        

        // two pointer approach

        int n = height.size();

        int start = 0, end = n-1;

        int temp = 0;

        while(start<end){

            int hei = min(height[start],height[end]);
            int curr = hei*(end-start);
            
            temp = max(curr,temp);
    
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return temp;
    }
};