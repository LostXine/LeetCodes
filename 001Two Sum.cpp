Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        
        //Hash size
        int div = 13;
        double* thre = new double[div];
        vector<vector<int>> hash;
        bool flap = (target<0);
        
        if(target == 0)
        {
            int cc = 0;
            vector<int>low,high,zz;
            for(int w = 0;w<nums.size();w++)
            {
                if(nums[w]==0)
                {
                    cc++;
                    zz.push_back(w);
                }
                else if(nums[w]>0)
                {
                    high.push_back(w);
                }
                else
                {
                    low.push_back(w);
                }
                if(cc==2)
                {
                    return zz;
                }
            }
            
            if(cc<2)
            {
                div = 0;
                hash.push_back(low);
                hash.push_back(high);
                goto FIN;
            }
        }
        
        
        
        if(flap)
        {
            target = -target;
        }
        
        for(int i = 0;i<div;i++)
        {
            thre[i] = (double)target/div*i;
            vector<int> subHash;
            hash.push_back(subHash);
        }
        
        for(int q = 0;q<2;q++)
        {
            vector<int> subHash;
            hash.push_back(subHash);
        }
        //construct hash tabel
        for(int t = 0;t<nums.size();t++)
        {
            if(flap)
            {
                nums[t] = -nums[t];
            }
            
            int val = nums[t];
            
            if(val > target)
            {
                hash[div+1].push_back(t);
                continue;
            }
            
            int level = 0;
            for(int c = 0;c<div;c++)
            {
                if(val >= thre[c])
                {
                    if(val == thre[c])
                    {
                        hash[level].push_back(t);
                    }
                    level ++;
                }
                else
                {
                    break;
                }
            }
            
            hash[level].push_back(t);
        }
FIN:
        //hash level
        for(int s = 0;s<(div+1)/2+1;s++)
        {
            vector<int>a,b;
            a = hash[s];
            b = hash[div+1-s];
            for(int m = 0;m<a.size();m++)
            {
                for(int n = 0;n<b.size();n++)
                {
                    if(s*2 == div+1 && m == n)
                    {
                        continue;
                    }
                    if((nums[a[m]]+nums[b[n]])==target)
                    {
                        result.push_back(a[m]);
                        result.push_back(b[n]);
                        return result;
                    }
                }
            }
        }
        return result;
    }
    
};