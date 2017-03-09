//Bismillahir Rahmanir Rahim
//Opu-1204026
//using dp solution print
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

int a[12];
int dp[1000005];
int pr[1000005];

int fun(int v)
{
    if(v<=0)return 0;
    if(dp[v]!=-1)return dp[v];
    int k,an=0,w;
    for(k=8;k>=0;k--)
    {
        if(v-a[k]>=0)
        {
            w=fun(v-a[k])+1;
            if(an<w)
            {
                an=w;
                pr[v]=k+1;
            }
        }

    }
    return dp[v]=an;
}
bool cmp(int c,int d)
{
    return c>d;
}

int main()
{
    vi val;
    int v,f,i,an,pe;
    sf("%d",&v);
    fr(i,9)sf("%d",&a[i]);
    ms(dp,-1);
    ms(pr,0);
    an=fun(v);
    if(an==0)puts("-1");
    else
    {
        pe=v;
      for(i=v;i>0;)
      {
          if(pr[i]==0)break;
          val.pb(pr[i]);
          i-=a[pr[i]-1];
          if(i==pe)break;
          pe=i;
      }
       sort(all(val),cmp);
        fr(i,val.size())pf("%d",val[i]);
        pf("\n");
    }

    return 0;
}

