/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

//20ms
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//        if(nums==NULL){return;}
        int m = nums.size();
        int st = 0;
        int zlen = 0;
        while(zlen+st<m)
        {
            if(nums[st+zlen]==0)
            {
                zlen++;
            }
            else
            {
                if(zlen!=0)
                {
                    nums[st] = nums[st+zlen];
                    nums[st+zlen] = 0;
                }
                st++;
            }
        }
    }
};