class Solution {
public:
    void solve(vector<int>& candidates,vector<int>& tmp,set<vector<int>>& ans,int start,int end,int target)
    {
        if(target==0){
            ans.insert(tmp);
            return;
        }
        if(start>end or target<0) return;
        solve(candidates,tmp,ans,start+1,end,target);
        tmp.push_back(candidates[start]);
        solve(candidates,tmp,ans,start+1,end,target-candidates[start]);
        tmp.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> v;
        solve(candidates,v,ans,0,n-1,target);
        for(auto it:ans) res.push_back(it);
        return res;
    }
};