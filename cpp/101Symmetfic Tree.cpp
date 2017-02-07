101. Symmetric Tree  QuestionEditorial Solution  My Submissions
Total Accepted: 126746
Total Submissions: 357033
Difficulty: Easy
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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

    bool isSym(TreeNode* left,TreeNode* right)
    {
        if(left == NULL && right == NULL){return true;}
        if(left == NULL || right == NULL){return false;}
        
        if(left->val == right ->val)
        {
            if(isSym(left->left,right->right))
            {
                if(isSym(left->right,right->left))
                {
                    return true;
                }
            }
            
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL){return true;}
        return isSym(root->left,root->right);
    }
};