/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
//4ms
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int cl = len;
        for(int i =0;i<cl;i++){
            int tmp;
            if(nums[i]==val){
                do{
                cl--;nums[i]=nums[cl];
                }
                while(nums[cl]==val&& cl>i);
                }
        }
        return cl;
    }
};