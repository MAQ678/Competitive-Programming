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

vector<pair<int,ii> > p;
int par[50005],n,m;
int pa[50005][16],me[50005][16];
bool vis[50005];
int L[50005];//,T[50005];
vector<ii>g[50005];

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
void dsu(int u,int v)
{
    par[root(u)]=par[root(v)];
}

int dfs(int u,int z,int d)
{
    int k,v,mxd=d;
    //T[u]=z;
    L[u]=d;vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(!vis[v])
        {
            mxd=max(mxd,dfs(v,u,d+1));
            pa[v][0]=u;
            me[v][0]=g[u][k].sd;
        }
    }
    return mxd;
}

void process(int d)
{

    int i,j;
  //  fr1(i,n)cout<<pa[i][0]<<" ";
 //       nl;
    for(j=1;(1<<j)<=d;j++)
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

int query(int p,int q)
{
    if(L[p]<L[q])swap(p,q);
    int lg=0,i,j,mx=0;

    while((1<<lg)<L[p])lg++;
    for(i=lg;i>=0;i--)
    {
        if(L[p]-(1<<i)>=L[q])
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
            mx=max(mx,max(me[p][i],me[q][i]));
            p=pa[p][i];
            q=pa[q][i];
        }
    }
    return max(mx,max(me[p][0],me[q][0]));
}

int main()
{
    int t,i,j,u,v,c,z,q;
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
        sort(p.begin(),p.end());

        initialize();
        j=0;
        fr(i,m)
        {
            u=p[i].sd.ft,v=p[i].sd.sd,c=p[i].ft;
            if(root(u)!=root(v))
            {
                dsu(u,v);
                g[u].pb(mp(v,c));
                g[v].pb(mp(u,c));
                j++;
            }
            if(j==n-1)break;
        }

        ms(L,0);ms(vis,0);ms(me,0);ms(pa,-1);
        process(dfs(1,-1,0));


        pf("Case %d:\n",z);
        sf("%d",&q);
        while(q--)
        {
            sf("%d%d",&u,&v);
            pf("%d\n",query(u,v));
        }

    }

    return 0;
}

