vector<pair<ll,ll> >v[100003];
ll dist[100003];
int main(){
    ios::sync_with_stdio(0);
    ll n,e,a[1000003];
    cin>>n>>e;
    for(ll i=0;i<e;i++){
        ll p,q,w;
        cin>>p>>q>>w;
        v[p].pb(mp(w,q));
        v[q].pb(mp(w,p));
    }
    for(ll i=0;i<=n;i++){
        dist[i]=100000;
    }
    ll so;
    cin>>so;
    set<pair<ll,ll> >s;
    dist[so]=0;
    s.insert(mp(0,so));
    while(!s.empty()){
        pair<ll,ll>p=*(s.begin());
        s.erase(p);
        for(ll i=0;i<v[p.se].size();i++){
            if(dist[v[p.se][i].se]>dist[p.se]+v[p.se][i].fi){
                if(dist[v[p.se][i].se]!=100000){
                    s.erase(v[p.se][i]);
                }
                dist[v[p.se][i].se]=dist[p.se]+v[p.se][i].fi;
                s.insert(mp(dist[v[p.se][i].se],v[p.se][i].se));
            }
        }
    }
}
