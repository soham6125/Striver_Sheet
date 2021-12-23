// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b)
    {
        return (a[1] < b[1]);
    }
        
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v;
        for(int i=0; i<n; i++)
        {
            int st =  startTime[i];
            int end =  endTime[i];
            int pro = profit[i];
            v.push_back({st, end, pro});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> dp(n,0);
        for(int i=0; i<n; i++)
        {
            int st1 = v[i][0];
            int end1 = v[i][1];
            int pr1  = v[i][2];
            dp[i] = pr1;
            int maxx = 0;
            for(int j=i-1; j>=0; j--)
            {
                 int st2 =  v[j][0];
                 int end2 = v[j][1];
                 if(st2<st1 and end2<end1 and st1>=end2 )
                 { 
                       maxx = max(dp[j], maxx);
                         break;
                 }  
            }
            if(i==0) dp[i] = dp[i] + maxx;
            else dp[i] = max(dp[i]+maxx, dp[i-1]);
            
        }
        return dp[n-1];
    }
};