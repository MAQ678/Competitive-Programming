//Bismillahir Rahmanir Rahim
//Opu-1204026
//needed help
//if there is no bridge then the graph is biconnected graph
//so , first find all bridge ,and then remove all, so left connected components are biconnected
//now if a component is a node and we reconstruct all bridge, then it will be a tree
//now if there is a component then no need extra edge,
//but otherwise , there always need (leaf+1)/2 edge to make ring
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

vii g[10005];

int ti,d[10005],low[10005],id[10005],cm,deg[10005];
bool vis[10005],ck[20005];


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

void dfs1(int u)
{
    int k,v,w;
    id[u]=cm;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        w=g[u][k].sd;
        if(!ck[w]&&!vis[v])
        {
            dfs1(v);
        }
    }
}

void dfs2(int u,int par)
{
    int k,v;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(!vis[v])
        {
            if(id[u]!=id[v])deg[id[u]]++,deg[id[v]]++;
            dfs2(v,u);
        }
    }
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,z,i,u,v,an,n,m;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)
        {
            sf("%d%d",&u,&v);
            g[u].pb(mp(v,i));
            g[v].pb(mp(u,i));
        }
        ms(d,0);ms(vis,0);ms(low,0);
        ti=1;ms(ck,0);
        dfs(0,-1);
        ms(vis,0);ms(id,0);cm=0;
        fr(i,n)
        {
            if(!vis[i])
            {
                cm++;
                dfs1(i);
            }
        }
        ms(deg,0);ms(vis,0);
        dfs2(0,-1);an=0;
        fr1(i,cm)
        {
            if(deg[i]==1)
            {
                an++;
            }
        }
        if(cm==1)an=0;
        else an=(an+1)/2;
        pf("Case %d: %d\n",z,an);
        fr(i,n)g[i].clear();

    }

    return 0;
}

