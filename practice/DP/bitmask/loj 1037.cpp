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

int l[20],n;
char ch[20][20];
vector<ii> v[20];
int dp[1<<16];

int fun(int mask)
{
    if(mask==(1<<n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int an=inf,i,j,c,va;
    bool b=0;
    fr(i,n)
    {
        if(!(mask&(1<<i)))
        {
            b=0;
            fr(j,v[i].size())
            {
                va=v[i][j].sd;
                if(mask&(1<<va))
                {
                    b=1;
                    c=(v[i][j].ft*(-1));
                    c=l[i]/(v[i][j].ft*(-1));
                    if(c*(v[i][j].ft*(-1))<l[i])c++;
                    an=min(an,c+fun(mask|(1<<i)));
                    break;
                }
            }
            if(!b)
                an=min(an,l[i]+fun(mask|(1<<i)));
        }
    }
    return dp[mask]=an;
}

int main()
{
    int t,z,i,j;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr(i,n)v[i].clear();
        fr(i,n)sf("%d",&l[i]);
        fr(i,n)sf("%s",ch[i]);
        fr(i,n)fr(j,n)if(ch[i][j]!='0')
        {
            v[j].pb(mp(-1*(ch[i][j]-'0'),i));
        }
        fr(i,n)sort(all(v[i]));
        ms(dp,-1);
        pf("Case %d: %d\n",z,fun(0));
    }
    return 0;
}
