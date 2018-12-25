#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define bolt ios::sync_with_stdio(0)
#define light cin.tie(0);cout.tie(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define MAXN 1000003
typedef int ll;
using namespace std;
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
ll inv_euclid(ll a, ll m = MOD){ll m0 = m;ll y = 0, x = 1;if (m == 1)return 0;while (a > 1){ll q = a / m;ll t = m;m = a % m, a = t;t = y;y = x - q * y;x = t;}if (x < 0)x += m0;return x;}
//https://www.youtube.com/watch?v=40TRPnvs4JE