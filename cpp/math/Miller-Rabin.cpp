bool miller_rabin_primality(ll N){
	static const int p[12]={2,3,5,7,11,13,17,19,23,29,31,37};
	if(N<=1)return false;
	for(int i=0;i<12;++i){
		if(p[i]==N)return true;
		if(N%p[i]==0)return false;
	}
	ll c =N-1,g=0;
	while(!(c&1))c>>=1,++g;
	for(int i=0;i<12;++i){
		ll k=fpow(p[i],c,N);
		for(int j=0;j<g;++j){
			ll kk=mult(k,k,N);
			if(kk==1&&k!=1&&k!=N-1)
				return false;
			k=kk;
		}
		if(k!=1)
			return false;
	}
	return true;
}
