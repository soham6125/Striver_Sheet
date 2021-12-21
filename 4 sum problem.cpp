class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        int n = v.size();
        sort(v.begin(),v.end());
        if(n<=3) return res;
        for(int i=0; i<=n-4; i++) {
            for(int j=i+1; j<=n-3; j++) {
                int a = j+1, b = n-1;
                int new_target = target - v[i] - v[j];
                while(a < b)
                {
                    if(v[a]+v[b] == new_target)
                    {
                        vector<int> tmp;
                        tmp.push_back(v[i]);
                        tmp.push_back(v[j]);
                        tmp.push_back(v[a]);
                        tmp.push_back(v[b]);
                        a++; b--;
                        ans.insert(tmp);
                    }
                    else if(v[a]+v[b] < new_target) a++;
                    else b--;
                }
            }
        }
        for(auto it:ans) res.push_back(it);
        return res;
    }
};