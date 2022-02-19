// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p) return p;
        if(root == q) return q;
        TreeNode *left, *right;
        left = lca(root->left,p,q);
        right = lca(root->right,p,q);
        if(left == NULL) return right;
        else if(right == NULL) return left; 
        else return root;
    }
};