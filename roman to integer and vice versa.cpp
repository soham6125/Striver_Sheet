// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int n = s.length();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(mp[s[i]] >= mp[s[i+1]]) ans += mp[s[i]];
            else ans-=mp[s[i]];
        }
        ans += mp[s[n-1]];
        return ans;
    }
};

// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int n) 
    {
        string ans;
        while(n>0) {
            if(n>=1000) {
                ans+="M"; 
                n-=1000;
            }
            else if(n>=900) {
                ans+="CM";
                n-=900;
            }
            else if(n>=500) {
                ans+="D";
                n-=500;
            }
            else if(n>=400) {
                ans+="CD";
                n-=400;
            }
            else if(n>=100) { 
                ans+="C"; 
                n-=100; 
            }
            else if(n>=90) { 
                ans+="XC"; 
                n-=90; 
            }
            else if(n>=50) { 
                ans+="L"; 
                n-=50; 
            }
            else if(n>=40) { 
                ans+="XL"; 
                n-=40; 
            }
            else if(n>=10) { 
                ans+="X"; 
                n-=10; 
            }
            else if(n>=9) { 
                ans+="IX"; 
                n-=9; 
            }
            else if(n>=5) { 
                ans+="V"; 
                n-=5; 
            }
            else if(n>=4) { ans+="IV"; n-=4; }
            else { ans+="I"; n-=1; }
        }
        return ans;
    }
};