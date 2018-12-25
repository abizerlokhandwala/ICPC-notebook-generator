//points inside convex polygon O(logn)
const ll N = 100009;
struct point {
    ll x,y;
}a[N];
ll n;
double cross(const point& p1,const point& p2,const point& org) {
    return ((p1.x-org.x)*1.0)*(p2.y-org.y)-((p2.x-org.x)*1.0)*(p1.y-org.y);
}
inline bool comp(const point& x,const point& y) {
    return cross(x,y,a[0]) >= 0;
}
bool inside(point& p) {
    if (cross(a[0], a[n-1], p)>=0) return false;
    if (cross(a[0], a[1], p) <=0) return false;
    ll l =1;
    ll r =n-1;
    while(l<r) {
        ll m = l + (r-l)/2;
        if(cross(a[m],p,a[0]) >=0)
            l=m+1;
        else
            r=m;
    }
    if(l == 0)
        return false;
    return cross(a[l-1],a[l],p) >0;
}
sort(a+1,a+n,comp);