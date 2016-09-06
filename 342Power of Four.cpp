342. Power of Four  QuestionEditorial Solution  My Submissions
Total Accepted: 36296
Total Submissions: 99966
Difficulty: Easy
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        if(num <= 0)
        {
            return false;
        }
        if((num & (num-1)) == 0)
        {
            return ((num & 0xAAAAAAAA) == 0 );
        }
         return false;
    }
};