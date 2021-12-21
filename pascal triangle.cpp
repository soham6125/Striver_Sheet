class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            vector<int> v(i,0);
            if(i == 1) {
                v[0] = 1;
                ans.push_back(v);
            } else {
                for(int j=0; j<i; j++) {
                    if(j>=0 and j<i-1)v[j] += ans[i-2][j];
                    if(j-1>=0 and j-1<i-1) v[j] += ans[i-2][j-1];
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};