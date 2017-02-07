/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0;i<numRows;i++){
            vector<int> tp;
            tp.push_back(1);
            res.push_back(tp);
        }
        for(int j = 1;j<numRows;j++){
            for(int t = 1;t<j;t++){
                res[j].push_back(res[j-1][t]+res[j-1][t-1]);
            }
            res[j].push_back(1);
        }
        return res;
    }
};