/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL){return result;}
        result = binaryTreePaths(root->left);
        vector<string> B = binaryTreePaths(root->right);
        result.insert(result.end(),B.begin(),B.end());
        bool nul = true;
        stringstream ss;
        for(int i = 0;i<result.size();i++)
        {
            string np;
            ss<<root->val<<"->";
            result[i] =ss.str()+ result[i];
            ss.str("");
            nul = false;
        }
        if(nul){ss<<root->val;result.push_back(ss.str());}
        return result;
    }
};