#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[809][8009],ind[809][8009],c[8009],a[8009];
ll cost(int i,int j){
	if(i>j)return 0;
	ll sum=(c[j]-c[i-1])*(j-i+1);
	return sum;
}
void go(int g,int l,int r,int start_ind,int end_ind){
	if(l>r)return ;
	int mid=(l+r)/2;
	dp[g][mid]=LLONG_MAX;
	for(int i=start_ind;i<=end_ind;i++){
		ll cur=dp[g-1][i]+cost(i+1,mid);
		if(cur<dp[g][mid]){
			dp[g][mid]=cur;
			ind[g][mid]=i;
		}
	}
	go(g,l,mid-1,start_ind,ind[g][mid]);
	go(g,mid+1,r,ind[g][mid],end_ind);
}
int main(){
	int n,G;cin>>n>>G;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i]+c[i-1];
	}
	for(ll i=1;i<=n;i++){
		dp[1][i]=c[i]*i;
	}
	for(int i=2;i<=G;i++){
		go(i,0,n,0,n);
	}
	cout<<dp[G][n];
}


