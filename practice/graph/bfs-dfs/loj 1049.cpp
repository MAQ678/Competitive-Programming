//Bismillahir Rahmanir Rahim
//Opu-1204026
//simple as it should always be ring
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

vector<ii>g[101];
bool vis[101];

int dfs(int u,int n)
{
    int k,v,an=0,w;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;//w=g[u][k].sd;
        if(!vis[v])
        {
            if(v==1)
            {
                if(n==1)
                {
                    vis[v]=1;
                    an+=g[u][k].sd;
                }
            }
            else
                an+=g[u][k].sd+dfs(g[u][k].ft,n-1);
        }
    }
    return an;
}

int main()
{
    int t,z,u,v,c,n,an,i;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr1(i,n)g[i].clear();
        fr(i,n)
        {
            sf("%d%d%d",&u,&v,&c);
            g[u].pb(mp(v,0));
            g[v].pb(mp(u,c));
        }
        ms(vis,0);
        an=dfs(g[1][0].ft,n-1)+g[1][0].sd;
        ms(vis,0);
        an=min(an,dfs(g[1][1].ft,n-1)+g[1][1].sd);
        pf("Case %d: %d\n",z,an);
    }
    return 0;
}

