#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

typedef complex<double> base;

const double PI = 4*atan(1);
const int N=2e5+5;
const int MOD=13313;

int FFT_N=0;
vector<base> omega;

void init_fft(int n)
{
	FFT_N = n;
	omega.resize(n);
	double angle = 2*PI/n;
	for(int i=0;i<n;i++)
	{
		omega[i]=base(cos(i*angle), sin(i*angle));
	}
}

void fft(vector<base> &a)
{
	int n=a.size();
	if(n==1)
		return;
	int half=n>>1;
	vector<base> even(half), odd(half);
	for(int i=0, j=0; i<n; i+=2, j++)
	{
		even[j]=a[i];
		odd[j]=a[i+1];
	}
	fft(even);
	fft(odd);
	int denominator=FFT_N/n;
	for(int i=0;i<half;i++)
	{
		base cur=odd[i] * omega[i*denominator];
		a[i]=even[i] + cur;
		a[i+half]=even[i] - cur;
	}
}

void multiply(vector<int> &a, vector<int> &b, vector<int> &res)
{
	vector<base> fa(a.begin(), a.end());
	vector<base> fb(b.begin(), b.end());
	int n=1;
	while(n<2*max(a.size(), b.size()))
		n<<=1;
	fa.resize(n);
	fb.resize(n);
	init_fft(n);
	fft(fa);
	fft(fb);
	for(int i=0;i<n;i++)
		fa[i] = conj(fa[i] *  fb[i]);
	fft(fa);
	res.resize(n);
	for(int i=0;i<n;i++)
	{
		res[i]=(long long)(fa[i].real()/n + 0.5);
		res[i]%=MOD;
	}
}

int n, k, q, curlen, idx=0;
int a[N], f[N];
vector<int> res;
vector<vector<int> > ans[40];

vector<int> divide(int lo, int hi)
{
	vector<int> ret;
	if(lo==hi)
	{
		ret.resize(f[lo]+1);
		for(int i=0;i<=f[lo];i++)
			ret[i]=1;
		return ret;
	}
	int mid=(lo+hi)>>1;
	vector<int> v1=divide(lo, mid);
	vector<int> v2=divide(mid+1, hi);
	multiply(v1, v2, ret);
	ret.resize((int)v1.size()+(int)v2.size()-1);
	return ret;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	vector<int> ans=divide(1, 2e5);
	cout<<ans[k]<<endl;
	return 0;
} 
