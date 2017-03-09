//Bismillahir Rahmanir Rahim
//Opu-1204026
//for learning
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


int n,m;
int par[50005],L[50005],pa[50005][16],me[50005][16];
vector<ii> g[50005];
vector<pair<int,ii> >p;
bool vis[50005];

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
void dsu(int u,int v)
{
    par[root(u)]=par[root(v)];
}

void dfs(int u,int z,int d)
{
    int k,v;
    vis[u]=1;L[u]=d;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(!vis[v])
        {
            dfs(v,u,d+1);
            pa[v][0]=u;
            me[v][0]=g[u][k].sd;
        }
    }
}

void process()
{
    int i,j;
    for(j=1;(1<<j)<n;j++)
    {
        fr1(i,n)
        {
            if(pa[i][j-1]!=-1)
            {
                pa[i][j]=pa[pa[i][j-1]][j-1];
                me[i][j]=max(me[i][j-1],me[pa[i][j-1]][j-1]);
            }
        }
    }
}

int ans(int p,int q)
{
    if(L[p]<L[q])swap(p,q);
    int i,j,lg=0,an=0;
    while((1<<lg)<L[p])lg++;

    for(i=lg;i>=0;i--)
    {
        if(L[p]-(1<<i)>=L[q])
        {
            an=max(an,me[p][i]);
            p=pa[p][i];
        }
    }
    if(p==q)return an;
    for(i=lg;i>=0;i--)
    {
        if(pa[p][i]!=-1&&pa[p][i]!=pa[q][i])
        {
            an=max(an,max(me[p][i],me[q][i]));
            p=pa[p][i],q=pa[q][i];
        }
    }
    return max(an,max(me[p][0],me[q][0]));
}

int main()
{
    int t,u,v,c,i,j,z,q;
    sf("%d",&t);
    fr1(z,t)
    {
        p.clear();
        sf("%d%d",&n,&m);
        fr(i,m)
        {
            sf("%d%d%d",&u,&v,&c);
            p.pb(mp(c,mp(u,v)));
        }
        sort(all(p));
        initialize();
        fr(i,m)
        {
            u=p[i].sd.ft;
            v=p[i].sd.sd;
            c=p[i].ft;
            if(root(u)!=root(v))
            {
                dsu(u,v);
                g[u].pb(mp(v,c));
                g[v].pb(mp(u,c));
            }
        }

        ms(vis,0),ms(pa,-1),ms(me,0);
        dfs(1,-1,0);

        process();
        pf("Case %d:\n",z);
        sf("%d",&q);
        while(q--)
        {
            sf("%d%d",&u,&v);
            pf("%d\n",ans(u,v));
        }
    }
    return 0;
}

