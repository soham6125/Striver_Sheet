#include <bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define loopr(a,b,i)     for(long long int i=a;i>=b;i--)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
#define endl             "\n"
#define lb               lower_bound
#define ub               upper_bound
#define f                first
#define se               second
#define vll              vector<ll>
#define pll              pair<ll,ll>
#define vpll             vector< pair<ll,ll> >
#define all(x)           x.begin(),x.end()
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll MAX  = 8000000000000000064LL;
const ll MIN  = -8000000000000000064LL;
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std; 

const ll dx[] = {-1,1,0,0,1,1,-1,-1};
const ll dy[] = {0,0,1,-1,-1,1,-1,1};

ll merge(ll a[],ll temp[],ll left,ll mid,ll right)
{
    ll i=left, j=mid, k=left;
    ll inv_count = 0;
    while((i<=mid-1) and (j<=right))
    {
        if(a[i] <= a[j]){
            temp[k] = a[i];
            k++; i++;
        }
        else{
            temp[k] = a[j];
            k++; j++;
            inv_count += (mid-1);
        }
    }
    while(i <= mid-1)
    {
        temp[k++] = a[i++];
    }
    while(j <= right)
    {
        temp[k++] = a[j++];
    }
    for(i=left;i<=right;i++)
    {
        a[i] = temp[i];
    }
    return inv_count;
}

ll mergesort(ll a[],ll temp[],ll left,ll right)
{
    ll mid=0, inv_count=0;
    if(right > left)
    {
        mid = (left+right) / 2;
        inv_count += mergesort(a,temp,left,mid);
        inv_count += mergesort(a,temp,mid+1,right);
        inv_count += merge(a,temp,left,mid+1,right);
    }
    return inv_count;
}

signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
        
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        ll n; cin>>n;
        ll a[n] , temp[n];
        loop(0,n,i) cin>>a[i];
        ll ans = mergesort(a,temp,0,n-1);
        cout << ans << endl;
    }

 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
