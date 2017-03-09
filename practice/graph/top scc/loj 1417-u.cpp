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

struct st
{
    int u,c;
}nv[50002];
vi g[50002],rg[50002],ng[50002];
int fi[50002],w,scc,mn[50002],id[50002],tn[50002],mnv,dp[50002];
bool vis[50002];

void dfs(int u)
{
    w++;
    vis[u]=1;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])dfs(v);
    }
    fi[u]=w++;

}
bool cmp(st a,st b)
{
    return a.c>b.c;
}

int dfs1(int u)
{
    vis[u]=1;
    id[u]=scc;
    mnv=min(mnv,u);
    int k,v,an=1;
    fr(k,rg[u].size())
    {
        v=rg[u][k];
        if(!vis[v])
        {
            an+=dfs1(v);
        }
    }
    return an;

}

int dfs2(int u)
{
    if(vis[u])return dp[u];
    vis[u]=1;
    int k,v,an=tn[u];
    fr(k,ng[u].size())
    {
        v=ng[u][k];
        an+=dfs2(v);
    }
    return dp[u]=an;

}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int n,u,v,t,z,i,an,mx,nd,j;
   sf("%d",&t);
   fr1(z,t)
   {
       sf("%d",&n);
       fr(i,n)
       {
           sf("%d%d",&u,&v);g[u].pb(v),rg[v].pb(u);
       }
       ms(fi,0);
        w=0;ms(vis,0);
        fr1(i,n)
        {
            if(!fi[i])dfs(i);
        }
        fr(i,n)nv[i].u=i+1,nv[i].c=fi[i+1];
        sort(nv,nv+n,cmp);

        ms(vis,0);ms(id,0),ms(mn,0);ms(tn,0);scc=0;
        fr(i,n)
        {
            if(!vis[nv[i].u])
            {
                scc++;
                mnv=inf;
                an=dfs1(nv[i].u);
                mn[scc]=mnv;
                tn[scc]=an;
            }
        }
        fr1(i,n)
        {
            fr(j,g[i].size())
            {
                v=g[i][j];
                if(id[i]!=id[v])ng[id[i]].pb(id[v]);
            }
        }
        ms(vis,0);
        mx=-1;
        fr1(i,scc)
        {
            if(!vis[i])
            {
                an=dfs2(i);
                if(an>mx)mx=an,nd=mn[i];
                else if(an==mx)nd=min(nd,mn[i]);
            }
        }
        fr1(i,n)g[i].clear(),rg[i].clear(),ng[i].clear();
        pf("Case %d: %d\n",z,nd);

   }

    return 0;
}

