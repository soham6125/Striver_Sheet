// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        if(n < m) return ans;
        vector<int> v1(26,0), v2(26,0);
        for(auto it: p) v1[it-'a']++;
        for(int i=0; i<m; i++) v2[s[i]-'a']++;
        if(v1 == v2) ans.push_back(0);
        for(int i=m; i<n; i++){
            v2[s[i]-'a']++;
            v2[s[i-m]-'a']--;
            if(v1 == v2) ans.push_back(i-m+1);
        }
        return ans;
    }
};