//Bismillahir Rahmanir Rahim
//Opu-1204026
//.036
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

vi g[10005];
int d[10005],low[10005],w;
bool vis[10005];
set<int>ap;

void dfs(int u,int par)
{
    int k,v,nc=0;
    w++;
    low[u]=d[u]=w;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(v==par)continue;
        if(vis[v])//back edge
            low[u]=min(low[u],d[v]);
        if(!vis[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(d[u]<=low[v]&&u!=1)//u is not root
                ap.insert(u);
            nc++;
        }
    }
    if(nc>1&&u==1)ap.insert(u);
}

int main()
{
    int t,z,u,v,n,m,i;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)
        {
            sf("%d%d",&u,&v);
            g[u].pb(v);
            g[v].pb(u);
        }
        w=0;
        ms(low,0);ms(d,0);ms(vis,0);
        ap.clear();
        dfs(1,-1);
        fr1(i,n)g[i].clear();
        pf("Case %d: %d\n",z,ap.size());
    }
    return 0;
}
