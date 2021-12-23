class Solution {
public:
    int removeDuplicates(vector<int>& v) 
    {
        int n = v.size();
        int ans = 1;
        int i=0, j=1;
        if(n==0) return 0;
        else if(n==1) return 1;
        while(j<n)
        {
            if(v[i]!=v[j])
            {
                i++;
                v[i] = v[j];
                ans++;
            }
            j++;
        }
        return ans;
    }
};