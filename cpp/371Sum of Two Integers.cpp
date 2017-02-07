371. Sum of Two Integers  QuestionEditorial Solution  My Submissions
Total Accepted: 31650
Total Submissions: 61150
Difficulty: Easy
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

class Solution {
public:
    int getSum(int a, int b) 
    {
        int tmp;
        do
        {
            tmp = a^b;
            b = (a&b)<<1;
            a = tmp;
        }
        while(b!=0);
        return a;
    }
};