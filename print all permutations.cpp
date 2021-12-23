void permutes(string a,ll l,ll r)  
{   
    if(l==r) {
        cout << a << endl;  
    }
    else
    {    
        for(int i=l; i<=r; i++)   {    
            swap(a[l],a[i]);    
            permutes(a,l+1,r);  
            swap(a[l],a[i]);  
        }  
    }  
}

void solve(string s) {
    int n = s.length();
    permutes(s, 0, n-1);
}