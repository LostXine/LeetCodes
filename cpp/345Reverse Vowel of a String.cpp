345. Reverse Vowels of a String  QuestionEditorial Solution  My Submissions
Total Accepted: 41053
Total Submissions: 112641
Difficulty: Easy
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".


class Solution {
public:
    
    bool checkVowel(char p)
    {
        if(p == 'a'||p == 'e'||p == 'i'||p == 'o'||p == 'u')
        {
            return true;
        }
        else if(p == 'A'||p == 'E'||p == 'I'||p == 'O'||p == 'U')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    string reverseVowels(string s) 
    {
        int l = 0,r = s.size()-1;
        bool l_lock = false,r_lock = false;
        while(r>l)
        {
            if(checkVowel(s[l]))
            {
                l_lock = true;
            }
            if(checkVowel(s[r]))
            {
                r_lock = true;
            }
            if(l_lock&& r_lock)
            {
                char t = s[l];
                s[l] = s[r];
                s[r] = t;
                l_lock = false;
                r_lock = false;
            }
            if(!l_lock)
            {
                l++;
            }
            if(!r_lock)
            {
                r--;
            }
            
        }
        
        return s;
        
    }
};