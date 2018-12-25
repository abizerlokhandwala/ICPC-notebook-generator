vector<int> dig; // contains digits of number
ll dp[24][204][2];
ll get(int pos,int sum,int flag){ //flag checking length of prefix
	if(pos==dig.size()){
		if(!pr[sum]){ // end condition
			return 1;
		}
		else return 0;
	}
	if(dp[pos][sum][flag]!=-1){
		return dp[pos][sum][flag];
	}
	int lmt;
	ll ans=0;
	if(!flag){
		lmt=dig[pos];
	}else{
		lmt=9;
	}
	for(int i=0;i<=lmt;i++){
		int nf=flag;
		if(!flag&&i<lmt){
			nf=1;   
		}
		ans+=get(pos+1,sum+i,nf);
	}
	return (dp[pos][sum][flag]=ans);
}

