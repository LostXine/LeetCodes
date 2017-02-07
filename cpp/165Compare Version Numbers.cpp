165. Compare Version Numbers  QuestionEditorial Solution  My Submissions
Total Accepted: 64091
Total Submissions: 346021
Difficulty: Easy
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

//要考虑1.0和1是一样的！

class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        version1.push_back('.');
        version2.push_back('.');
        
        int s1,s2;
        
		//为了减少难度所以增加个结尾标志位
        int v1s = version1.size(),v2s=version2.size();
        
        do
        {
            int v1 = -1,v2 = -1;
            s1 = 0;s2 = 0;//因为这两个是一样的所以从0初始化
            
            if(v1s>1)
            {
                v1 = version1.find_first_of('.');
            }
            if(v2s>1)
            {
                v2 = version2.find_first_of('.');
            }
            
            if(v1>0)
            {
                s1 = atoi(version1.substr(0,v1).c_str());
                if(v1+1 != version1.size())
                {
                    version1 = version1.substr(v1+1);
                    v1s = version1.size();
                }
                else
                {
                    v1s = 0;
                }
                
            }
            
            if(v2>0)
            {
                s2 = atoi(version2.substr(0,v2).c_str());
                if(v2+1 != version2.size())
                {
                    version2 = version2.substr(v2+1);
                    v2s = version2.size();
                }
                else
                {
                    v2s = 0;
                }
            }
            
        }
        while(s1 == s2 &&((v2s+v1s)>0));
        
        if(s1 < s2){return -1;}
        if(s1 > s2){return 1;}
        
        return 0;
    }
};