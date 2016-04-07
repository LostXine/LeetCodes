/*
Implement atoi to convert a string to an integer.

Hint Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

//8ms
class Solution {
public:

    bool aff(char s)
    {
        int jb = s-'0';
        if(jb<10&&jb>=0){return true;}
        return false;
    }
    int myAtoi(string str) {
        int qb = 0;
        bool fu = true;bool z= false;
        bool ha = false;
        for(int i = 0;i<str.length();i++)
        {
            char t = str[i];
            if(t==' '){if(ha){break;}else{continue;}}
            if(t=='+'){if(!z){z = true;}else{return 0;}if(!fu){return 0;}ha = true;continue;}
            if(t=='-'){if(fu){fu = false;}else{return 0;};if(z){return 0;}ha = true;continue;}
            if(aff(t)){int jb = qb;qb = qb * 10 + t-'0';
                if((qb + '0' - t)/10!=jb||qb<0){return (fu)?INT_MAX:INT_MIN;}
                ha = true;
            }
            else{break;}
        }
        if(!fu){qb = -qb;}
        return qb;
    }
};