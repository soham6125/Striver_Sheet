// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int mx = 1;
        int n = s.length();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i) dp[i][i] = 1;
        int start = 0;
        for(int i = 0; i < n - 1; ++i) 
        {
            if (s[i] == s[i + 1]) 
            {
                dp[i][i + 1] = true;
                start = i;
                mx = 2;
            }
        }
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int end = i + len - 1;
                if(dp[i+1][end-1] && s[i] == s[end])
                {
                    dp[i][end] = true;
                    if(len > mx)
                    {
                        start = i;
                        mx = len;
                    }
                }
            }
        }
        // cout << mx;
        ans = s.substr(start,mx);
        return ans;
    }
};