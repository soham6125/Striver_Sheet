vector<int> Solution::repeatedNumber( vector<int> &nums) {
    int n = nums.size();
    vector<int> val(n+1,0), ans(2);
    for(auto it: nums) val[it]++;
    for(int i=1; i<=n; i++) {
        if(val[i] == 0) ans[1] = i;
        else if(val[i] == 2) ans[0] = i;    
    }
    return ans;
}