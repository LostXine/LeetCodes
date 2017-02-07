386. Lexicographical Numbers  QuestionEditorial Solution  My Submissions
Total Accepted: 4227
Total Submissions: 13173
Difficulty: Medium
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int> out;
        
        if(n<10)
        {
            for(int p = 1;p<=n;p++)
            {
                out.push_back(p);
            }
            return out;
        }
        
        vector<int> stake;
        int top = -1;
        //push single number
        for(int i = 9;i>0;i--)
        {
            stake.push_back(i);
            top++;
        }
        
        while(top >= 0)
        {
            //out of stake
            int now = stake[top];
            out.push_back(now);
            stake.pop_back();
            top--;
            
            //push numbers
            for(int p = 9;p>-1;p--)
            {
                int ex = now*10+p;
                if(ex<=n)
                {
                    stake.push_back(ex);
                    top++;
                }
            }
            
        }
        
        return out;
    }
};

//另一种直接用深度优先方法寻找的 速度快一半
class Solution {
public:

    int limit;
    vector<int> out;
    
    void showNext(int n)
    {
        out.push_back(n);
        int p = n*10;
        for(int i = 0;i<10;i++)
        {
            int t = p+i;
            if(t<=limit)
            {
                showNext(t);
            }
            else
            {
                break;
            }
        }
    }
    
    vector<int> lexicalOrder(int n) 
    {
        limit = n;
        for(int i = 1;i<10&&i<=n;i++)
        {
            showNext(i);
        }
        return out;
    }
};