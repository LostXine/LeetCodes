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