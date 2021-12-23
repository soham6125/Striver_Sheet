bool cmp(pair<int,int> s1, pair<int,int> s2)  { 
    return (s1.second < s2.second); 
} 

void solve(vector<vector<int>> &a) 
{ 
    int n = a.size();
    vector<pair<int,int>> p(n)
    for(int i=0; i<n; i++) {
        p[i].first = a[i][0];
        p[i].second = a[i][1];
    }
	sort(p.begin(), p.end(), cmp); 
    int i = 0; 
	cout << p[i].first << " " << p[i].second << endl; 
    for (int j = 1; j < n; j++) 
    { 
      	if (p[j].first >= p[i].second) 
      	{	 
			cout << p[j].first << " " << p[j].second << endl; 
			i = j; 
      	} 
    } 
} 