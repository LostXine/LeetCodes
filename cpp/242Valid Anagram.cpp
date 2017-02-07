/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){return false;}
        int cot[26];
        memset(cot,0,sizeof(cot));
        
        for(int i =0;i<s.length();i++)
        {
            int st=  int(s[i]-'a');
            cot[st]++;
            st = int(t[i]-'a');
            cot[st]--;
        }
        for(int j = 0;j<26;j++){
            if(cot[j]!=0)return false;
        }
        return true;
    }
};