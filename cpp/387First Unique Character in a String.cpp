387. First Unique Character in a String
387. First Unique Character in a String  QuestionEditorial Solution  My Submissions
Total Accepted: 12523
Total Submissions: 28934
Difficulty: Easy
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int>hash[26];
        for(int i = 0;i<s.size();i++)
        {
            hash[s[i]-'a'].push_back(i);
        }
        int min = -1;
        for(auto &p:hash)
        {
            if(p.size()==1)
            {
                if(min<0)
                {
                    min = p[0];
                }
                else
                {
                    min = (min<p[0])?min:p[0];
                }
            }
        }
        return min;
    }
};