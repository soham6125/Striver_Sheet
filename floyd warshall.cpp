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

const ll N = 5e2+5;
const ll inf = 1e15;
ll dp[N][N];
 
void Floyd_Warshall(ll n)
{
    for(ll i=1;i<=n;i++) dp[i][i] = 0;
 
    for(ll i=1 ; i<=n ;i++ )
        for(ll j=1; j<=n ; j++ )
            for(ll k=1; k<=n ; k++ )
                dp[j][k] = min( dp[j][k] , dp[j][i] + dp[i][k] );
    return;
 
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
        ll n,m,q; 
        cin >> n >> m >> q;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dp[i][j] = inf;
        for(ll i=0;i<m;i++)
        {
            ll u,v,w;
            cin >> u >> v >> w;
            dp[u][v] = min(dp[u][v],w);
            dp[v][u] = min(dp[v][u],w);
        }
        Floyd_Warshall(n);
        while(q--)
        {
            ll a,b;
            cin >> a >> b;
            if(dp[a][b] != inf) cout << dp[a][b] << endl;
            else cout << -1 << endl;
        }
    }

 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
