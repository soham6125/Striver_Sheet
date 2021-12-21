#include<bits/stdc++.h>

int solve(vector<int> a, int b) {
    int n = a.size();
    int ans = 0;
    int x = 0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++) {
        x ^= a[i];
        if(x == b) ans++;
        if(m.find(x^b) != m.end()) ans += m[x^b];
        m[x]++;
    }
    return ans;
}
