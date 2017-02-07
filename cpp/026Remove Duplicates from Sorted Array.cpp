26. Remove Duplicates from Sorted Array  QuestionEditorial Solution  My Submissions
Total Accepted: 154375
Total Submissions: 446616
Difficulty: Easy
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

class Solution {
public:


    int removeDuplicates(vector<int>& nums) 
    {
        int len = nums.size();
        if(len < 2){ return len;}
        
        vector<int>::iterator tp = nums.begin(),st;
        int size = 1;
        
        int val = *tp;
        st = tp;
        tp++;
        
        bool dup = false;
        while(tp != nums.end())
        {
            if(*tp > val)
            {
                st++;
                if(dup)
                {
                    //close
                    dup = false;
                }
                if(tp!=st)
                {
                    *st = *tp;
                }
                size++;
                val = *tp;
            }
            else if(*tp == val)
            {
                if(!dup)
                {
                    //open
                    dup = true;
                }
            }
            tp ++;
        }
        return size;
    }
    
};