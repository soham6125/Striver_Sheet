class Solution {
public:
    vector<int> next_permutation(vector<int> a,int n)
    {
        int k = -1, l = -1;
        for(int i=n-1; i>0; i--)
        {
            if(a[i-1] < a[i])
            {
                k = i; 
                break;
            }
        }
        if(k == -1)
        {
            sort(a.begin(), a.end());
            return a;
        }
        for(int i=n-1; i>0; i--)
        {
            if(a[k-1] < a[i])
            {
                l = i; 
                break;
            }
        }
        swap(a[k-1],a[l]);
        reverse(a.begin()+k,a.end());
        return a;
    }
};