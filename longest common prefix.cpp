// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& v)
    {
        int mn = INT_MAX;
        int n = v.size();
        if(n==0) return "";
        if(n==1) return v[0];
        string ans="";
        for(int i=0;i<n;i++)
        {
            int sz = v[i].size();
            mn = min(mn,sz);
        }
        for(int ind=0;ind<mn;ind++)
        {
            int cnt = 1;
            char x = v[0][ind];
            for(int i=1;i<n;i++)
            {
                if(v[i][ind]==x) cnt++;
            }
            if(cnt==n) ans+=x;
            else break;
        }
        return ans;
    }
};

/* Longest common prefix using binary search */

bool allContainsPrefix(vector<string> arr, int n, string str, int start, int end)
{
    for (int i=0; i<=n-1; i++)
        for (int j=start; j<=end; j++)
            if (arr[i][j] != str[j])
                return false;
    return true;
}
  
string commonPrefix(vector<string> arr, int n)
{
    int index = INT_MAX;
    for(auto it: arr) index = min(index, it.size());
    string prefix; 
    int low = 0, high = index;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (allContainsPrefix (arr, n, arr[0], low, mid))
        {
            prefix = prefix + arr[0].substr(low, mid-low+1);
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return prefix;
}

