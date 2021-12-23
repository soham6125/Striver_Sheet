int min_coins(vector<int> &coins, int x) {
    int n = coins.size();
    sort(coins.begin(), coins.end());
    int ans = 0;
    for(int i=n-1; i>=0; i--) {
        if(x >= coins[i]) {
            ans += x/coins[i];
            x %= coins[i];
        }
    }
    return ans;
}