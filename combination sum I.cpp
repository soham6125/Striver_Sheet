class Solution {
private:
    vector<vector<int>> ans;
public:
    void solve(int ind,int target, vector<int>& temp, vector<int>& v, int n)
    {
        if(target < 0)  return;
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(ind > n-1) return;
        temp.push_back(v[ind]);
        solve(ind, target-v[ind], temp, v, n);
        temp.pop_back();
        solve(ind+1, target, temp, v, n);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n = candidates.size();
        vector<int> t;
        solve(0, target, t, candidates, n);
        return ans;
    }
};