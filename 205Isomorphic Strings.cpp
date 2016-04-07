/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int ct[128],cs[128];
        for(int j = 0;j<128;j++){ct[j] = -1;cs[j] = -1;}
        for(int i = 0;i<s.length();i++)
        {
            if(ct[s[i]]==t[i]&&cs[t[i]]==s[i])
            {
                continue;
            }
            else if (ct[s[i]]==-1&&cs[t[i]]==-1)
            {
                ct[s[i]] = t[i];
                cs[t[i]] = s[i];
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};