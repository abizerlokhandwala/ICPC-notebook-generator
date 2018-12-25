//phi
int totient[100008];
void phi(){
	for(int i=1;i<=100000;i++){
		int ans=i;
		set<int> s;
		int temp=i;
		while(temp!=1){
			s.insert(pr[temp]); //pr is spf
			temp/=pr[temp];
		}
		for(auto e:s){
			ans-=ans/e;
		}
		totient[i]=ans;
	}
}

