// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    int curr_ind;
    
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int l,int r)
    {
        if(l > r) return NULL;
        int ind = find(inorder.begin(), inorder.end(), postorder[curr_ind]) - inorder.begin();
        curr_ind--;
        TreeNode *head = new TreeNode(inorder[ind]);
        head->right = solve(inorder, postorder, ind+1, r); 
        head->left = solve(inorder, postorder, l, ind-1);
        return head;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size();
        curr_ind = n-1;
        return solve(inorder, postorder, 0, n-1);
    }
};