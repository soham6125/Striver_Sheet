int solve(string columnTitle) {
    int sum = 0;
    int n = columnTitle.size();
    int val = n;
    while(val >= 0) {
        sum += (columnTitle[i]-'A'+1) * pow(26,val);
        val--;
    }
    return sum;
}