66. Plus One  QuestionEditorial Solution  My Submissions
Total Accepted: 120680
Total Submissions: 339709
Difficulty: Easy
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> result;
        vector<int>::iterator tp = digits.end();
        bool add = false,first = true;
        while(tp != digits.begin())
        {
            tp--;
            if(first||add)
            {
                (*tp)++;
                first = false;
                add = false;
            }
            if(*tp>9)
            {
                *tp = (*tp)%10;
                add = true;
            }
        }
        
        if(add)
        {
            result.reserve(digits.size()+1);
            result.push_back(1);
        }
        else
        {
            result.reserve(digits.size());
        }
        tp = digits.begin();
        while(tp !=digits.end())
        {
            result.push_back(*tp);
            tp++;
        }
        return result;
        
    }
};