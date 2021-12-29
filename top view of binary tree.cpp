class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        map<int,int> v;
        vector<int> a;
        if(!root) return a;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.size()) {
            Node *t = q.front().first;
            int vh = q.front().second;
            q.pop();
			// if this column index already has a 
		    //node we dont need to change it 
            if(v[vh] == 0) v[vh] = t->data;   
            if(t->left) q.push({t->left,vh-1});
            if(t->right) q.push({t->right,vh+1});

        }
      // all the nodes in the map are the nodes which are 
	  // encountered first in the verical traversal so  gives us the top view of the tree
        for(auto x:v) a.push_back(x.second);    
        return a;
 
    }

};