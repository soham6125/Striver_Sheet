// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int level = 0;
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) 
        {
            int sz = q.size();
            for(int i=0; i<sz; i++) 
            {
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);
            }
            level++;
        }
        return level;
    }
};