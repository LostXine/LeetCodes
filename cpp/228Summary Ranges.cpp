/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/
#include<iostream>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> range;
        if(nums.empty()){return range;}
        int pre = nums[0];
        bool combo = false;
        int i = 1;
        for(i = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){combo = true;continue;}
            else{
                combo = false;
                stringstream cc;
                cc<<pre;
                if(nums[i-1]!=pre){
                    cc<<"->"<<nums[i-1];
                }
                pre = nums[i];
                range.push_back(cc.str());
            }
        }
        int kt = nums[nums.size()-1];
        stringstream tail;
        if(combo){tail<<pre<<"->"<<kt;}
        else{tail<<kt;}
        range.push_back(tail.str());
        return range;
        
    }
};