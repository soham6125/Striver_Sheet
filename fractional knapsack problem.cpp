bool cmp(pair<int,int> p1, pair<int,int> p2) {
    double r1 = (double)p1.first / (double)p1.second;
    double r2 = (double)p2.first / (double)p2.second;
    return r1 > r2;
} 

double fractional_knapsack(vector<vector<int>> &a, int W) {
    int n = a.size();
    vector<pair<int,int>> v(n);
    // v[i].first represent value
    // v[i].second represent weight
    for(int i=0; i<n; i++) {
        v[i].first = a[i][0];
        v[i].second = a[i][1];
    }
    sort(v.begin(), v.end(), cmp);
    int curWeight = 0; 
    double finalvalue = 0.0; 
    for (int i = 0; i < n; i++) {
        if (curWeight + v[i].second <= W) {
            curWeight += v[i].second;
            finalvalue += v[i].first;
        }
        else {
            int remain = W - curWeight;
            finalvalue += v[i].first * ((double)remain / (double)v[i].second);
            break;
        }
    }
    return finalvalue;
}