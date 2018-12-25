//crt
ll crt(vector<ll> v, vector<ll> rem){
	int n=v.size();
	ll M=1;
	for(auto e:rem){
		M*=e;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ans=ans+v[i]*(inv(M/rem[i],rem[i])*M/rem[i])%M;
		ans=ans%M;
	}
	return ans;
}

