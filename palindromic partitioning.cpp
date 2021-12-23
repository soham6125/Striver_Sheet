// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool check(string s, int l, int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    void recur(int ind, string s, vector<string> &v, vector<vector<string>> &ans)
    {
        if(ind==s.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<s.size();i++)
        {
            if(check(s, ind, i))
            {
                v.push_back(s.substr(ind, i-ind+1));
                recur(i+1, s, v, ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> v;
        recur(0, s, v, ans);
        return ans;
    }
};