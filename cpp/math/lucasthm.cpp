//lucas thm
ll fact[14258+2];
ll ncr(ll n,ll r, ll MOD){
	if(r>n)return 0;
	ll num=fact[n]%MOD;
	ll den=fact[r]%MOD*fact[n-r]%MOD;
	den=den%MOD;
	return (num*inv(den,MOD))%MOD;
}
ll lucas(ll n, ll r,ll MOD){
	if(r>n)return 0;
	/*
	precompute in main
	ms(fact,0,sz fact);
	fact[0]=fact[1]=1;
	for(int i=2;i<=MOD;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=MOD;
	}*/
	vector<ll> nn,rr;
	ll tn=n,tr=r,rem=0;
	while(tn){
		rem=tn%MOD;
		nn.pb(rem);
		tn=tn/MOD;
	}
	rem=0;
	while(tr){
		rem=tr%MOD;
		rr.pb(rem);
		tr=tr/MOD;
	}
	ll ans=1;
	for(int i=0;i<rr.size();i++){
		ans=ans*ncr(nn[i],rr[i],MOD)%MOD;
		ans=ans%MOD;
	}
	return ans;
}

