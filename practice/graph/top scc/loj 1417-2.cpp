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
} nv[50002];
vi g[50002],rg[50002],nn;
bool vis[50002];
int w,fi[50002],dp[50002];

void dfs(int u)
{
    vis[u]=1;
    w++;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            dfs(v);
        }
    }
    fi[u]=w++;
}

int ddfs(int u)
{
    if(dp[u]!=-1)return dp[u];
    int an=0,k,v;
    vis[u]=1;
    nn.pb(u);
    fr(k,rg[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            an+=(1+ddfs(v));
        }
    }
    return an;//dp[u]=an;
}

bool cmp(st a,st b)
{
    return a.c>b.c;
}
int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,z,u,v,n,mx,an,nd,i,j;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr(i,n)sf("%d%d",&u,&v),g[u].pb(v),rg[v].pb(u);

        ms(fi,0);
        w=0;
        fr1(i,n)
        {
            ms(vis,0);
            if(!fi[i])dfs(i);
        }
        fr1(i,n)nv[i].c=fi[i],nv[i].u=i;
        sort(nv+1,nv+n+1,cmp);
        mx=-1;
        ms(dp,-1);
        fr1(i,n)
        {
            if(dp[nv[i].u]==-1)
            {
                nn.clear();
                ms(vis,0);
                an=ddfs(nv[i].u)+1;
                cout<<an<<"  d "<<nv[i].u;nl;
                if(an>mx)
                {
                    mx=an,nd=nv[i].u;
                }
                fr(j,nn.size())
                {
                    dp[nn[j]]=an;

                    if(an==mx)nd=min(nd,nn[j]);
                }
            }
        }
        fr1(i,n)g[i].clear(),rg[i].clear();
        pf("Case %d: %d\n",z,nd);
        //cout<<mx<<" "<<nd;nl;
    }

    return 0;
}


