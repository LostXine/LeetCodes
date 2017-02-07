 /*
 Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root, int& dep){
        if(root==NULL){dep = 0;return true;}
        int dl,dr;
        if(!isBalanced(root->left,dl)||!isBalanced(root->right,dr)){return false;}
        else if(abs(dl-dr)<2){dep = max(dl,dr)+1;return true;}
        else{return false;}
    }
    bool isBalanced(TreeNode* root) {
        int dp = 0;
        return isBalanced(root,dp);
    }
};