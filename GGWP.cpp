
#include <bits/stdc++.h>
#include <random>
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define f first
#define s second
#define ll long long
using namespace std;
ll n,q,val,x,l,r,d,dem,k;
ll a[6000000],f[6000000];
string s,v;
const ll MOD=1e9+7;
int main() 
{
    //freopen("GGWP.inp","r",stdin);
    //freopen("GGWP.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    FOR(i,1,n) {cin>>a[i];}
    dem=0;
    sort(a+1,a+1+n);
    FORD(i,n,1)
    {
        dem+=a[i];
        if(dem>=k) {cout<<n-i+1; return 0;}
    }
    cout<<"15GG";
    return 0;
}