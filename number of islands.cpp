/* Number of Islands in graph */

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj[N+1];
vector<bool> vis(N,false);

void dfs(int node)
{
	vis[node]=true;
	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			dfs(it);
		}
	}
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	int n,edge; cin >> n >> edge;
	while(edge--)
	{
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int ans=0;
	for(int i=0; i<n; i++) {
		if(vis[i]==false) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}

/* Number of Islands in grid */

class Solution {
public:
    int ans = 0;
    
    void dfs(vector<vector<char>>& mat,vector<vector<bool>>& vis,int n,int m,int i,int j)
    {
        if(i<0 or i>=n or j<0 or j>=m) return;
        if(vis[i][j]) return;
        if(mat[i][j]=='0') return;
        vis[i][j] = true;
        dfs(mat,vis,n,m,i+1,j);
        dfs(mat,vis,n,m,i-1,j);
        dfs(mat,vis,n,m,i,j+1);
        dfs(mat,vis,n,m,i,j-1);
    }
    
    int numIslands(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and mat[i][j]=='1')
                {
                    dfs(mat,vis,n,m,i,j); 
                    ans++;
                }
            }
        }
        return ans;
    }
};