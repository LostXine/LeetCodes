107. Binary Tree Level Order Traversal II  QuestionEditorial Solution  My Submissions
Total Accepted: 95113
Total Submissions: 264686
Difficulty: Easy
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>>head,out;
    
    void levelOrder(TreeNode* root,int level = 0)
    {
        if(root == NULL){return;}
        if(head.size()<=level)
        {
            head.resize(level+1);
        }
        
        head[level].push_back(root->val);
        
        levelOrder(root->left,level+1);
        levelOrder(root->right,level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        levelOrder(root);
        vector<vector<int>>::iterator tp = head.end();
        while(tp!=head.begin())
        {
            tp--;
            out.push_back(*tp);
        }
        return out;
    }
};