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

vector<pair<int,ii> >p;
vector<ii>g[505];
bool vis[505];
int an[505],par[505];
int n;

void initialize()
{
    int i;
    fr(i,n)par[i]=i,g[i].clear();
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
    int k,v;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(!vis[v])
        {
            an[v]=max(an[u],g[u][k].sd);
            dfs(v);
        }
    }
}

int main()
{
  //  freopen("F:\\Coding\\in.txt","r",stdin);
    int t,m,u,v,w,d,i,j,z;
    sf("%d",&t);
    fr1(z,t)
    {
        p.clear();
        sf("%d%d",&n,&m);
        fr(i,m)
        {
            sf("%d%d%d",&u,&v,&w);
            p.pb(mp(w,mp(u,v)));
        }
        sort(all(p));

        initialize();

        fr(i,m)
        {
            u=p[i].sd.ft,v=p[i].sd.sd,w=p[i].ft;
            if(root(u)!=root(v))
            {
                par[root(u)]=par[root(v)];
                g[u].pb(mp(v,w));
                g[v].pb(mp(u,w));
            }
        }
        sf("%d",&d);
        pf("Case %d:\n",z);
        ms(vis,0);ms(an,-1);
        an[d]=0;
        dfs(d);
        fr(i,n)
        {
            if(an[i]==-1)pf("Impossible\n");
            else pf("%d\n",an[i]);
        }
    }
    return 0;
}

