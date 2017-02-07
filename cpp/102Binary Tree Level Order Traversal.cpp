102. Binary Tree Level Order Traversal  QuestionEditorial Solution  My Submissions
Total Accepted: 121734
Total Submissions: 349745
Difficulty: Easy
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


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

    vector<vector<int>> head;
    
    void cruseAndOrder(TreeNode* root,int _l)
    {
        if(root == NULL){return;}
        int level = _l;   
        
        while(head.size()<=level)
        {
            vector<int> tmp;
            head.push_back(tmp);
        }
        
        (head[level]).push_back(root->val);
        
        cruseAndOrder(root->left,level+1);
        cruseAndOrder(root->right,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        cruseAndOrder(root,0);
        return head;
    }
};