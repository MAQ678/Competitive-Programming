//Bismillahir Rahmanir Rahim
//Opu-1204026
//.228
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
#define tr(c,i) for( i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())


vector<ll> a,w;
ll b[15],mx;
set<ll>s;
set<ll>::IT it1;

void fun(int i)
{
    if(i>12)return;
    //make value
    ll j,sm=0;
    fr(j,i)sm=sm*10+b[j];
    if(sm)a.pb(sm);
    //end of
    b[i]=4;
    fun(i+1);
    b[i]=7;
    fun(i+1);
}

void fun2(int i,ll v)
{
    if(i==a.size()||v>mx)
    {
        if(v<=mx)s.insert(v);
        return;
    }
    if(v>1)s.insert(v);
    int j;
    for(j=i; j<a.size(); j++)
    {
        if(v>(mx/a[j]))break;//if we use v*a[j] then there will be overflow
        fun2(j,a[j]*v);
    }
}

int main()
{
    int i,t,z,an,w,mode,an1,an2;
    ll l,r;
    mx=1e12;
    fun(0);//make all possible lucky number
    sort(all(a));
    fun2(0,1);
    a.clear();
    tr(s,it1)
    {
        a.pb(*it1);
    }
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%lld%lld",&l,&r);
        pf("Case %d: ",z);
        an=upper_bound(all(a),r)-lower_bound(all(a),l);
        pf("%d\n",an);

    }
    return 0;
}



