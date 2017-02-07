/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    int m,n;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        if(m<1){return false;}
        n = matrix[0].size();
        if(n<1){return false;}
        int ilim = matrix[0][0];
        int alim = matrix[m-1][n-1];
        if(target<ilim||target>alim){return false;}
        else if(target==ilim||target==alim){return true;}
        int lind = 0;
        int rind = m-1;
        while(rind-lind>1){
            int mind = (lind+rind)/2;
            int mval = matrix[mind][0];
            if(target==mval){return true;}
            else if(target>mval){lind = mind;}
            else{rind = mind;}
            }
        if(rind == m-1){
            int mval = matrix[rind][0];
            if(target==mval){return true;}
            else if(target>mval){lind = rind;}
        }
        int index = lind;
        lind = 0;
        rind = n;
        while(rind-lind>1){
            int mind = (lind+rind)/2;
            int mval = matrix[index][mind];
            if(target==mval){return true;}
            else if(target>mval){lind = mind;}
            else{rind = mind;}
        }
        return false;
    }

    
};