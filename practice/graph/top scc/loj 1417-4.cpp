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

int id[50002],tn[50002],mn[50002];//id means a node is on which scc // tn means total no of node on a scc//min node on a scc which will represent node no of new graph

vi g[50002],rg[50002],nn,ng[50002];
bool vis[50002];
int w,fi[50002],mnd,scc,dp[50002];


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
    mnd=min(mnd,u);
    id[u]=scc;
    int an=0,k,v;
    vis[u]=1;
    nn.pb(u);
    fr(k,rg[u].size())
    {
        v=rg[u][k];
        if(!vis[v])
        {
            an+=(1+ddfs(v));
        }
    }
    return an;//dp[u]=an;
}

int dffs(int u)
{
    if(vis[u])return dp[u];
    vis[u]=1;
    int k,v,an=tn[u];
    //st x,an;an.c=tn[u],an.u=mn[u];///an=mp(tn[u],mn[u]);
    fr(k,ng[u].size())
    {
        v=ng[u][k];
        an+=dffs(v);
       // x=dffs(v);
      //  an.c+=x.c;an.u=min(an.u,x.u);
    }
    return dp[u]=an;
}

bool cmp(st a,st b)
{
    return a.c>b.c;
}
int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,z,u,v,n,mx,an,nd,i,j,wn;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr(i,n)sf("%d%d",&u,&v),g[u].pb(v),rg[v].pb(u);

        ms(fi,0);
        w=0;ms(vis,0);
        fr1(i,n)
        {

            if(!fi[i])dfs(i);
        }
        fr(i,n)nv[i].c=fi[i+1],nv[i].u=i+1;
        sort(nv,nv+n,cmp);
        scc=0;
        ms(vis,0);ms(id,0),ms(mn,0),ms(tn,0);
        fr(i,n)
        {
            if(!vis[nv[i].u])
            {

                mnd=inf;
                scc++;
                an=ddfs(nv[i].u)+1;
                mn[scc]=mnd;
                tn[scc]=an;

            }
        }
        fr1(i,n)
        {
            fr(j,g[i].size())
            {
                v=g[i][j];
                if(id[i]!=id[v])
                {
                    ng[id[i]].pb(id[v]);
                }
            }
        }
 /*       fr1(i,scc)
        {
            cout<<i<<" has: ";
            fr(j,ng[i].size())
            {
                cout<<ng[i][j]<<" ";
            }
            nl;
        }
*/
        //now we need only to find highest cost of an acyclic graph
        ms(vis,0);mx=-1;
        fr1(i,scc)
        {
            if(!vis[i])
            {
                wn=dffs(i);
                if(wn>mx)
                {
                    mx=wn;
                    nd=mn[i];
                }
                else if(wn==mx)nd=min(nd,mn[i]);

            }
        }
      //  cout<<mx<<endl;

        fr1(i,n)g[i].clear(),rg[i].clear(),ng[i].clear();
        pf("Case %d: %d\n",z,nd);
        //cout<<mx<<" "<<nd;nl;
    }

    return 0;
}



