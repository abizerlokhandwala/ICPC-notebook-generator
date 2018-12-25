//lis NLOGN
int lis(int a[],int n){
	ll dp[n+3];
	//int lis[n+3];
	//ms(lis,0,sz lis);
	dp[0]=-LLONG_MAX;
	for(int i=1;i<=n;i++){
		dp[i]=LLONG_MAX;
	}
	int anss=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=n,ans;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]<=dp[mid]){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		dp[ans]=a[i];
	//	lis[i]=max(lis[i],ans);
		anss=max(anss,ans);
	}
	return anss;
}

