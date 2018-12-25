vector<ll>v[100003];
ll disc[100003];
ll low[100003];
ll vis[100003];
set<ll>ap;
set<pair<ll,ll>>br;
ll par[100003];

void dfs(ll p, ll t){
    vis[p]=1;
    disc[p]=t+1;
    low[p]=t+1;
    ll ch=0;
    for(auto e:v[p]){
        if(vis[e]==0){
            ch++;
            par[e]=p;
            dfs(e,t+1);
            low[p]=min(low[p],low[e]);
            if(low[e]>disc[p]){
                br.insert(mp(min(e,p),max(e,p)));
            }
            if(par[p]==0 && ch>1){
                ap.insert(p);
            }else if(par[p]!=0){
                if(low[e]>=disc[p]){
                    ap.insert(p);
                }
            }
        }else if(e!=par[p]){
            low[p]=min(low[p],disc[e]);
        }
    }
}

int main()
{
        par[1]=0;
        dfs(1,0);
}
