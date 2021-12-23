int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    vector<pair<int,int>> p(n);
    for(int i=0; i<n; i++) {
        p[i].first = a[i][1];
        p[i].second = a[i][0];
    }
    sort(p.begin(), p.end());
    int ans = 1;
    int mx = p[0].first;
    for(int i=1; i<n; i++) {
        if(p[i].second >= mx) {
            ans++;
            mx = p[i].first;
        }
    }
    return ans;
}