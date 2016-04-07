/*
58. Length of Last Word My Submissions QuestionEditorial Solution
Total Accepted: 89128 Total Submissions: 305837 Difficulty: Easy
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/ 

class Solution {
public:
    int lengthOfLastWord(string s) {
        int to = 0,lo = 0;
        bool tp = false;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]==' '){lo = to;to = 0;tp = true;while(s[i]==' '){i++;}i--;}
            else{to++;tp = false;}
        }
        if(tp){return lo;}
        return to;
    }
};