// rec relation: Ai=c1*Ai-1+c2*Ai-2+...ck*Ai-k
//A0=a0 A1=a1 ... Ak-1=ak-1
void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);
ll ini[2];
ll fib(ll n){
  ll F[2][2] = {{0,-1},{1,(2*f)%MOD}};
  // F= (0 0 0 ..   ck)
  //    (1 0 0 ...ck-1)
  // 	  (0 1 0 ...ck-2)
  //    (.............)
  //	  (0 0 0 ..1  c1)
  if (n == 1)return (ini[1]*I)%MOD;  	//ini is [a0,a1...,ak]
  power(F,n-1); 					 	//n-1 => n-k+1
  ll ans=(ini[1]%MOD*F[1][1]%MOD)%MOD+(ini[0]%MOD*F[0][1]%MOD)%MOD;
  if(ans<0)ans=(ans+MOD)%MOD;
  ans=(ans*I)%MOD;
  return ans;
}
void power(ll F[2][2], ll n){
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{0,-1},{1,(2*f)%MOD}};
  power(F, n/2);
  multiply(F, F);
  if (n%2 != 0) multiply(F, M);
}
void multiply(ll F[2][2], ll M[2][2]){
  ll x =  (F[0][0]%MOD*M[0][0]%MOD + F[0][1]%MOD*M[1][0]%MOD)%MOD;
  ll y =  (F[0][0]%MOD*M[0][1]%MOD + F[0][1]%MOD*M[1][1]%MOD)%MOD;
  ll z =  (F[1][0]%MOD*M[0][0]%MOD + F[1][1]%MOD*M[1][0]%MOD)%MOD;
  ll w =  (F[1][0]%MOD*M[0][1]%MOD + F[1][1]%MOD*M[1][1]%MOD)%MOD;
  if(x<0)x=(x+MOD)%MOD;
  if(y<0)y=(y+MOD)%MOD;
  if(z<0)z=(z+MOD)%MOD;
  if(w<0)w=(w+MOD)%MOD;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
