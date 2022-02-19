// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool check(string s, vector<string> &wordDict) {
        for(auto it:wordDict) {
            if(it == s) return true;
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        if(sz == 0) return true;
        bool dp[sz+1];
        memset(dp, false, sizeof(dp));
        for(int i=1; i<=sz; i++) {
            if (dp[i] == false and check( s.substr(0, i), wordDict ))
                dp[i] = true;
            if (dp[i] == true)
            {
                if (i == sz)
                    return true;
                for (int j = i+1; j <= sz; j++)
                {
                    if (dp[j] == false and check( s.substr(i, j-i), wordDict ))
                        dp[j] = true;
                    if (j == sz && dp[j] == true)
                        return true;
                }
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    unordered_map<string,int> m;
    
    void solve(string s, int i, vector<string> &ans, string curr)
    {
        if(i == s.size())
        {
            string tmp = curr;
            reverse(tmp.begin(),tmp.end());
            tmp.pop_back();
            reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            return;
        }
        string x;
        for(int j = i ; j < s.size() ; j++)
        {    
            x += s[j];
            if(m.find(x) != m.end())
            {
                solve(s, j+1, ans , curr + " " + x);
            }
        }
        return;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0 ; i < wordDict.size() ; i++) m[wordDict[i]]++;
        vector<string> ans;
        solve(s, 0, ans , "");
        return ans;
    }
};