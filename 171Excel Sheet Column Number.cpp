/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i = s.length()-1;i>-1;i--)
        {
            result = result + int(s[i]-'A'+1) * pow(26,s.length()-i-1);
        }
        return result;
    }
};