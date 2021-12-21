class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0, j = 0;
        int n = s.length();
        unordered_set<char> ch;
        while(i<n and j<n)
        {
            if(ch.find(s[j]) == ch.end())
            {
                ch.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
            else
            {
                ch.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};