#include <bits/stdc++.h>
#include <random>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define f first
#define s second
#define ll long long
using namespace std;
ll n,q,val,x,l,r,d;
ll a[6000000],f[6000000];
string s,v;
const ll MOD=1e9+7;
void build(ll l, ll r, ll id)
{
    if(l==r) {f[id]=a[l]; return;}
    if(l>r) return;
    ll mid=(l+r)/2;
    //cout<<l<<' '<<r<<' '<<id<<'\n';
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    f[id]=f[id*2]+f[id*2+1];
}
void update(ll l, ll r, ll id, ll x, ll val)
{
    if(r<x||x<l) return;
    if(l==r&&l==x)  {f[id]=val; return;}
    ll mid=(l+r)/2;
    update(l,mid,id*2,x,val);
    update(mid+1,r,id*2+1,x,val);
    f[id]=f[id*2]+f[id*2+1];
}
ll query(ll l,ll r, ll id, ll i, ll j)
{
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return f[id];
    ll mid=(l+r)/2;
    return( query(l,mid,id*2,i,j)+query(mid+1,r,id*2+1,i,j) );
}
int main() 
{
    freopen("SUMSET.inp","r",stdin);
    freopen("SUMSET.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    build(1,n,1);
    FOR(i,1,q)
    {
        cin>>d;
        if(d==1)
            {
                cin>>x>>val;
                update(1,n,1,x,val);
            }
        else {cin>>l>>r; cout<<query(1,n,1,l,r)<<'\n';}
    }
    return 0;
}