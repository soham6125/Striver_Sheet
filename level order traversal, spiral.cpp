// https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++)
        {
            TreeNode* node=q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}  
};

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) 
        {
            int sz = q.size();
            vector<int> res;
            for(int i=0; i<sz; i++) 
            {
                TreeNode* t = q.front();
                q.pop();
                res.push_back(t->val);
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            if(level % 2 == 0) {
                ans.push_back(res);
            }
            else {
                reverse(res.begin(), res.end());
                ans.push_back(res);
            }
            level++;
        }
        return ans;
    }
};