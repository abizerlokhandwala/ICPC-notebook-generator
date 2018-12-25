void build(ll node,ll a, ll b){//1,0,n-1
    if(a>b)
        return;
    if(a==b){
        tree[node]=arr[a];//something
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);
    tree[node] = tree[node*2]+tree[node*2+1]//something
}

ll query(ll node, ll a, ll b, ll i, ll j){//a=0,b=n-1,i=l,j=r
    if(a > b || a > j || b < i)
        return 0;
    if(a >= i && b <= j){
        return 0;//something
    }
    ll q1 = query(node*2, a, (a+b)/2, i, j);
    ll q2 = query(1+node*2, 1+(a+b)/2, b, i, j);
    return 0;//something
}

ll update(ll node, ll a, ll b, ll i, ll val){
    if(a==b){
        arr[i]=val;
        tree[node];//something
    }
    else{
        ll mid=(a+b)/2;
        if(a<=i&&i<=mid){
            update(2*node,a,mid,i,val);
        }
        else{
            update(2*node+1,mid+1,b,i,val);
        }
        tree[node]=(tree[2*node]+tree[2*node+1])%mod;// something
    }
}
