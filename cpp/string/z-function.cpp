//z-function
vector<ll>z(100001,0);
void calculatez(string &s){ // z[i] is the length of the longest substring starting from s[i] which is also a prefix of s
    ll n=s.size();
    z[0]=n;
    for(ll i=1, l=0, r=0; i<n; i++) {
        if(i<=r)
            z[i]=min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            z[i]++;
        if(i+z[i]-1>r) {
            l=i;
            r=i+z[i]-1;
        }
    }
}