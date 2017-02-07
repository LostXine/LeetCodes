/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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

    TreeNode* LCA;
    int maxdep;
    bool pf,qf;
    void inTree(TreeNode* root, TreeNode* p, TreeNode* q,int dp,bool first){
        if(root == NULL){return;}
        if(root == p){pf = true;}
        if(root == q){qf = true;}
        if((pf||qf) && !(pf&&qf)){
            if(dp<maxdep||maxdep<0){LCA = root;maxdep = dp;}
        }
        if(first){
            inTree(root->left,p,q,dp+1,true);
            inTree(root,p,q,dp,false);
            inTree(root->right,p,q,dp+1,true);
        }
        

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pf = false;
        qf = false;
        LCA = root;
        maxdep = -1;
        inTree(root,p,q,0,true);
        return LCA;
        
    }

};