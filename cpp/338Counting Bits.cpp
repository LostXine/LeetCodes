/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        int ex2 = 1;
        
        for(int i = 1;i<=num;i++)
        {
            int ind = i-ex2;
            if(ind==ex2)
            {
                result.push_back(1);
                ex2 = ex2<<1;
            }
            else
            {
                result.push_back(result[ind]+1);
            }
        }
        return result;
    }
};