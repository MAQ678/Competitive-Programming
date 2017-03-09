//Bismillahir Rahmanir Rahim
//Opu-1204026
//first make spanning tree
//then for each connected components we choose greedy way that if edge is >=airport
//then we will replace this with airport.
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

vector<pair<int,ii> >p;
vector<ii>g[10005];
int par[10005],w,air,n;
bool vis[10005];

void initialize()
{
    int i;
    fr1(i,n)par[i]=i,g[i].clear();
}
int root(int u)
{
    while(par[u]!=u)par[u]=par[par[u]],u=par[u];
    return u;
}

int dfs(int u)
{
    vis[u]=1;
    int k,v,an=0;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(!vis[v])
        {
            if(air<=g[u][k].sd)
            {
                an+=dfs(v)+1;
            }
            else
            {
                w+=g[u][k].sd;
                an+=dfs(v);
            }
        }
    }
    return an;
}

int main()
{
    int t,z,i,j,an,m,u,v,c;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d%d",&n,&m,&air);
        p.clear();
        initialize();
        fr(i,m)
        {
            sf("%d%d%d",&u,&v,&c);
            p.pb(mp(c,mp(u,v)));
        }
        sort(all(p));
        fr(i,m)
        {
            u=p[i].sd.ft;v=p[i].sd.sd;c=p[i].ft;
            if(root(u)!=root(v))
            {
                par[root(u)]=par[root(v)];
                g[u].pb(mp(v,c));g[v].pb(mp(u,c));
            }
        }

        ms(vis,0);
        an=0;w=0;
        fr1(i,n)
        {
            if(!vis[i])
            {
                an+=dfs(i)+1;
            }
        }
        w+=(an*air);
        pf("Case %d: %d %d\n",z,w,an);
    }
    return 0;
}

