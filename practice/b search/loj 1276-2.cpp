//Bismillahir Rahmanir Rahim
//Opu-1204026
//getting help
#include<bits/stdc++.h>
using namespace std;
#define sf      scanf
#define pf      printf
#define pb      push_back
#define _       ios_base::sync_with_stdio(false);
#define ct      cin.tie(NULL);
#define ll      long long
#define eps     1e-10
#define ms(n,i) memset(n,i,sizeof n)
#define pi      2*acos(0)
#define inf     1<<30
#define fr(i,n) for(i=0;i<n;i++)
#define fr1(i,n)for(i=1;i<=n;i++)
#define nl cout<<"\n"
#define abs(x)  ((x<0)?-(x):x)
#define MAX 30005
#define sp(i)      cout<<fixed<<setprecision(i)
//STL
typedef      vector<int> vi;
typedef      vector<ll> vl;
typedef      pair<int,int>ii;
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

vl a;
set<ll>s;
set<ll>::IT it;
ll mx=1e12;
void lucky(ll val)
{
    if(val>mx)return;
    if(val>1)a.pb(val);
    ll z=val*10;
    lucky(z+4);
    lucky(z+7);
}
bool check(ll x,ll y)
{
    ll z=mx/y;
    if(z*y<mx)z++;
    if(x<=z)return 1;
    return 0;
}
void vlucky(int i,ll v)
{
    if(v>1&&v<=mx)
        s.insert(v);
    if(i>=a.size()||v>mx) return;
    int j;
    for(j=i;j<a.size();j++)
    {
        if(!check(v,a[j]))
        {
            break;
        }
        vlucky(j,v*a[j]);
    }

}
void pre()
{
    a.clear(),s.clear();
    lucky(0);
    sort(all(a));
    vlucky(0,1);
   a.clear();
    tr(s,it)a.pb(*it);
}


int main()
{
    pre();
    int t,z;
    ll l,r;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%lld%lld",&l,&r);
        pf("Case %d: %d\n",z,upper_bound(all(a),r)-lower_bound(all(a),l));
    }

    return 0;
}

