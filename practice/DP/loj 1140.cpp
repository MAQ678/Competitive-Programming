//Bismillahir Rahmanir Rahim
//Opu-1204026

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
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())



string s;
ll dp[12][2][2][12];
ll fun(int r,int ir,int iz,int tz)
{
    if(r==0)return tz;
    if(dp[r][ir][iz][tz]!=-1)return dp[r][ir][iz][tz];
    int an=0,z;
    if(iz==1)
    {
        an+=fun(r-1,0,0,tz)*9+fun(r-1,0,1,tz);
    }
    else
    {
        if(ir==1)
        {
            z=s[r-1]-'0';
            if(z>0)
            {
                an+=fun(r-1,0,0,tz+1);
                z--;
                an+=fun(r-1,0,0,tz)*z;
                an+=fun(r-1,1,0,tz);
            }
            else an+=fun(r-1,1,0,tz+1);
        }
        else an+=fun(r-1,0,0,tz+1)+fun(r-1,0,0,tz)*9;
    }
    return dp[r][ir][iz][tz]=an;
}

ll solve(ll n)
{
    if(n<0)return 0;
    int len;
    stringstream ss;
    ss<<n;ss>>s;ss.clear();
    reverse(all(s));
    len=s.length();
    ms(dp,-1);
    return fun(len-1,1,0,0)+fun(len-1,0,0,0)*(s[len-1]-'0'-1)+fun(len-1,0,1,0)+1;//range,without range,is zero
}

int main()
{
    ll t,z,n,a,b;
    sf("%lld",&t);
    fr1(z,t)
    {
        sf("%lld%lld",&a,&b);
        pf("Case %lld: %lld\n",z,solve(b)-solve(a-1));
    }
    return 0;
}

