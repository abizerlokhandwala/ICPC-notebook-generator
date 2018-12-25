//divisors in cube root n, pr is sieve
inline ll randll(){
  return  ( (ll)rand() << 30 ) + ( rand() << 15 ) + rand();
} 
inline ll mult(ll a, ll b, ll n){ 
  ll res = 0ll;
  a %= n, b %= n;
  while(b)
  {
    if(b&1) res = ( res + a ) % n;
    a = ( a + a ) % n;
    b >>= 1ll;
  }
  return res;
}
long long power(long long x,long long p,long long mod){
    long long s=1,m=x;
    while(p) {
        if(p&1) s=mult(s,m,mod);
        p>>=1;
        m=mult(m,m,mod);
    }
    return s;
}
bool witness(long long a,long long n,long long u,int t){
    long long x=power(a,u,n);
    for(int i=0;i<t;i++) {
        long long nx=mult(x,x,n);
        if(nx==1&&x!=1&&x!=n-1) return 1;
        x=nx;
    }
    return x!=1;
}
bool millerRabin(long long n,int s=100) {
    if(n<2) return 0;
    if(!(n&1)) return n==2;
    long long u=n-1;
    int t=0;
    while(u&1) {
        u>>=1;
        t++;
    }
    while(s--) {
        long long a=randll()%(n-1)+1;
        if(witness(a,n,u,t)) return 0;
    }
    return 1;
}
inline bool isPr(ll n){
  return millerRabin( n , 1000 );
}
#define K 1000010
ll ans=1;
ll count_div_in_cube_root_n(ll n){
  for( ll i=2;i<K&&i<=n;i++)if(!pr[ i ])
    if(n%i==0){
      	ll tcnt = 0;
      	while( n % i == 0 )
        	tcnt++,n/=i;
      	ans*=(tcnt+1ll);
	}
  	if(n!=1){
    	ll tmp=sqrt( n );
    	if( isPr( n ) ) ans*=2ll;
    	else if( tmp * tmp == n ) ans*=3ll;
    	else ans*=4ll;
  	}	
  	return ans;
}