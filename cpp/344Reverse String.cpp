
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".


class Solution {
public:
    string reverseString(string s) 
    {
        string out = "";
        for(int i = s.length()-1;i>-1;i--)
        {
            out.push_back(s[i]);
        }
        return out;
    }
};