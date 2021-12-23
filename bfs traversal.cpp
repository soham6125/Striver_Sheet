#include<bits/stdc++.h>
using namespace std;

int main()
{ quick;
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
#endif
	
	int n; cin >> n;
	int start; cin >> start;
	vector<int> adj[n];
	vector<int> dis[n]={0};
	queue<int> q;
	vector<bool> vis(n,false);
	for(int i=0; i<n-1; i++)
	{
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
	q.push(start);
	dis[start] = 0;
	vis[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		cout << x << " ";
		q.pop();
		for(auto it:adj[x])
		{
			if(!vis[it])
			{
				q.push(it);
				dis[it] = dis[x] + 1;
				vis[it] = true;
			}
		}
	}
	return 0;	
}


