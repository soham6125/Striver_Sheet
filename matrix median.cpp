int Solution::findMedian(vector<vector<int> > &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i=0; i<n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }
    int req = (n*m + 1)/2;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        int res = 0;
        for(int i=0; i<n; i++) {
            res += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        if(res < req) {
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
