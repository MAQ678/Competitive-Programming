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

vector<int>g[55];
vector<pair<int,ii> >p;
int par[55],n;
bool vis[55];

void initialize()
{
    int i;
    fr1(i,n)par[i]=i,g[i].clear();
}
int root(int u)
{
    while(par[u]!=u)
    {
        par[u]=par[par[u]];
        u=par[u];
    }
    return u;
}

void dfs(int u)
{
    int k,v;vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])dfs(v);
    }
}

int main()
{
    int t,z,i,j,v,w,u,c,sm;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        p.clear();sm=0;
        initialize();
        fr1(i,n)fr1(j,n)
            {
                sf("%d",&v);
                sm+=v;
                if(v)p.pb(mp(v,mp(i,j)));
            }
        sort(all(p));

        w=p.size();
        fr(i,w)
        {
            u=p[i].sd.ft,v=p[i].sd.sd,c=p[i].ft;
            if(root(u)!=root(v))
            {
                par[root(u)]=par[root(v)];//make union
                sm-=c;
                g[u].pb(v);
                g[v].pb(u);
            }
        }
        ms(vis,0);
        dfs(1);w=0;
        pf("Case %d: ",z);
        fr1(i,n)if(!vis[i])w=1;
        if(w)sm=-1;
        pf("%d\n",sm);
    }
    return 0;
}

