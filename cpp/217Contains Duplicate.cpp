 /*
 Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int hash = nums.size()/3+1;
        
        vector<int>* table = new vector<int>[hash];
        //inititalize hash table 
        
        for(int j = 0;j<nums.size();j++)
        {
            int val = nums[j];
            int h_val = abs(val)%hash;
            for(int l = 0;l<table[h_val].size();l++){
                if(table[h_val][l]==val){return true;}
            }
            table[h_val].push_back(val);
        }
        
        delete [] table;
        
        return false;
    }
};