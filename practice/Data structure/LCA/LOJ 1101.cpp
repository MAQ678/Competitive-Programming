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
//pair<int,ii>p[100005];
int par[50005];//for mst


int T[50005],pa[50005][16],me[50005][16];//for lca
int dis[50005];
int n,m;
vi g[50005],co[50005];


void initialize()
{
    int i;
    fr1(i,n)par[i]=i;
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

void kruskal()
{
    int i,u,v,c;
    fr(i,m)
    {
        u=p[i].sd.ft;
        v=p[i].sd.sd;
        c=p[i].ft;

        if(root(u)!=root(v))
        {
            dsu(u,v);
            //making tree
                g[u].pb(v);
                g[v].pb(u);
                co[u].pb(c);
                co[v].pb(c);
                T[v]=u;
            //end of this
        }
    }
}

void makeLca()
{
    int i,j,k;
    fr1(i,n)
    {
        pa[i][0]=T[i];
        fr(k,g[i].size())
        {
            if(g[i][k]==T[i])
                {
                    me[i][0]=co[i][k];//get edge between two nodes
                    break;
                }
        }
    }

    for(j=1;(1<<j)<n;j++)fr1(i,n)
    {
        if(pa[i][j-1]!=-1)pa[i][j]=pa[pa[i][j-1]][j-1];//for lca

        if(pa[i][j-1]!=-1)me[i][j]=max(me[i][j-1],me[pa[i][j-1]][j-1]);//for max edge
    }

}

void dfs(int u,int z)
{
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(dis[v]==-1)
        {
            dis[v]=z;
            dfs(v,z+1);
        }
    }
}
/*
int lca(int p,int q)
{
    if(dis[p]<dis[q])swap(p,q);
    int lg=0,i,j;
    while((1<<lg)<dis[p])
        lg++;

    for(i=lg;i>=0;i--)if(dis[p]-(1<<i)>=dis[q])p=pa[p][i];

    if(p==q)return p;
    for(i=lg;i>=0;i--)
    {
        if(pa[p][i]!=-1&&pa[p][i]!=pa[q][i])p=pa[p][i],q=pa[q][i];
    }
    return pa[p][0];
}

int kthAnMax(int u,int k)
{
    int i,lg=0,an=-1;
    while((1<<lg)<k)lg++;
    for(i=lg;i>=0;i--)
    {
        if(!k)break;
        if(k>=(1<<i))
        {
            an=max(an,me[u][i]);
            u=pa[u][i];
            k-=(1<<i);
        }
    }
    return an;
}
*/
int query(int p,int q)
{
    if(dis[p]<dis[q])swap(p,q);
    int lg=0,i,j,mx=0;
    while((1<<lg)<dis[p])lg++;

    for(i=lg;i>=0;i--)
    {
        if(dis[p]-(1<<i)>=dis[q])
        {
            mx=max(mx,me[p][i]);
            p=pa[p][i];
        }
    }
    if(p==q)return mx;

    for(i=lg;i>=0;i--)
    {
        if(pa[p][i]!=-1&&pa[p][i]!=pa[q][i])
        {
            mx=max(mx,me[p][i]);
            mx=max(mx,me[q][i]);
            p=pa[p][i];
            q=pa[q][i];
        }
    }
    return max(mx,max(me[p][0],me[q][0]));
}

int main()
{
   // _;ct;
   pair<int,ii> ww;
    int i,j,u,v,c,t,z,q,d1,d2,l,an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        p.clear();
        fr1(i,n)g[i].clear(),co[i].clear();
        fr(i,m)
        {
            sf("%d%d%d",&u,&v,&c);
            ww=mp(c,mp(u,v));
            p.pb(ww);
        }
        sort(p.begin(),p.end());
        initialize();//initialize DSU

         ms(T,0);
        kruskal();//make tree

        //lca part
        ms(pa,-1);
        ms(me,0);
        makeLca();
        //end of lca

            //getting root of the tree
        u=1;
        fr1(i,n)if(pa[i][0]==-1&&g[i].size())
        {
            u=i;break;
        }
            //end of getting root

            //for finding depth of nodes
        ms(dis,-1);
        dis[u]=0;
        dfs(u,1);
            //end of finding depth

        //now here we go for our main problem

        pf("Case %d:\n",z);
        sf("%d",&q);
        while(q--)
        {
            sf("%d%d",&u,&v);
//            l=lca(u,v);
//            d1=dis[u]-dis[l];
//            d2=dis[v]-dis[l];
//            an=kthAnMax(u,d1);
//            an=max(an,kthAnMax(v,d2));
            an=query(u,v);
            pf("%d\n",an);
        }
    }
    return 0;
}
