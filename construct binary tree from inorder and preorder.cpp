// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    int curr_ind;
    
    TreeNode* solve(vector<int>& inorder,vector<int>& preorder,int l,int r)
    {
        if(l > r) return NULL;
        int ind = find(inorder.begin(), inorder.end(), preorder[curr_ind]) - inorder.begin();
        curr_ind++;
        TreeNode *head = new TreeNode(inorder[ind]); 
        head->left = solve(inorder, preorder, l, ind-1);
        head->right = solve(inorder, preorder, ind+1, r);
        return head;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        curr_ind = 0;
        return solve(inorder, preorder, 0, n-1);
    }
};