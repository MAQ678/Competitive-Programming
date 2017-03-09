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
typedef      vector<ii> vii;
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())


vii g[10002];
bool vis[10002],ck[20002],ok;
int d[10002],low[10002],ti,cn,id[10002];


void dfs(int u,int par)
{
    vis[u]=1;
    low[u]=d[u]=ti++;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(v!=par)
        {
            if(!vis[v])
            {
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(d[u]<low[v])
                {
                    ck[g[u][k].sd]=1;
                }
            }
            else low[u]=min(low[u],d[v]);
        }
    }
}


void dfs1(int u,int c)
{
    int k,v;
    vis[u]=1;
    id[u]=c;
    cn++;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(ck[g[u][k].sd])continue;
        if(!vis[v])
        {
            dfs1(v,(c+1)&1);

        }
        else
        {
            if(id[v]==c)ok=1;
        }
    }
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,z,n,m,u,v,i,an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)
        {
            sf("%d%d",&u,&v);
            g[u].pb(mp(v,i));g[v].pb(mp(u,i));
        }
        ms(vis,0);ms(d,0),ms(low,0);
        ti=1;
        dfs(0,-1);
        ms(vis,0);
        an=0;ms(id,-1);
        fr(i,n)
        {
            if(!vis[i])
            {
                cn=0;ok=0;
                dfs1(i,0);
                if(ok)
                {
                    an+=cn;
                }
            }
        }
        pf("Case %d: %d\n",z,an);
    }
    return 0;
}

