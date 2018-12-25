//mobius
int mobius(ll n){
	prime.clear(); //primes till n
	pf(n);
	int c[1000000]={0};
	for(int i=0;i<prime.size();i++){
		c[prime[i]]++;
	}
	for(int i=1;i<1000000;i++){
		if(c[i]>=2)return 0;
	}
	if(prime.size()&1)return -1;
	return 1;
}

