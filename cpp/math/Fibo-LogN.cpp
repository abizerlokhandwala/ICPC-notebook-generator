ll fib(ll n,ll mod){
	ll i,h,j,k,t;i=h=1;j=k=0;
	while(n>0) {
		if(n%2==1)
		t=(j*h)%mod,j=(i*h + j*k +t)%mod,i=(i*k + t)%mod;
		t=(h*h)%mod; h=(2*k*h + t)%mod;
		k=(k*k + t)%mod;n= n/2;
	}
	return j;
}