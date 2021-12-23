int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    vector<int> arr(n), dep(n);
    for(int i=0; i<n; i++) {
        arr[i] = a[i][0];
        dep[i] = a[i][1];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < n and j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
        if (plat_needed > result)
            result = plat_needed;
    }
    return result;
}
