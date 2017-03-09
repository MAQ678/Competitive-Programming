//Bismillahir Rahmanir Rahim
//Opu-1204026
//easy problem, but forgot about out degree
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

vi g[1002],rg[1002],ng[1002];
vii nd;
bool vis[1002];
int id[1002],scc,fi[1002],w,wn;
map<int,int>mm,mm1;

void dfs(int u)
{
    vis[u]=1;
    int k,v;
    w++;
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

void dfs1(int u)
{
    int k,v;
    vis[u]=1;
    id[u]=scc;
    if(wn==-1&&mm1[u]==0)wn=scc;
    fr(k,rg[u].size())
    {
        v=rg[u][k];
        if(!vis[v])dfs1(v);
    }
}

void dfs2(int u)
{
    vis[u]=1;
    int k,v;
    fr(k,ng[u].size())
    {
        v=ng[u][k];
        if(!vis[v])
        {
            dfs2(v);
            break;
        }
    }
}
int out[1005];

int main()
{
    // freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,z,u,v,n,cn,k,i,j;
    bool b;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        mm.clear();
        cn=0;
        mm1.clear();
        nd.clear();
        fr(i,n)
        {
            sf("%d",&k);
            fr(j,k)
            {
                sf("%d%d",&u,&v);
                if(!pr(mm,u))mm1[cn]=u,mm[u]=cn++;
                if(!pr(mm,v))mm1[cn]=v,mm[v]=cn++;
                u=mm[u],v=mm[v];
                g[u].pb(v),rg[v].pb(u);
            }
        }
        // fr(i,cn)cout<<mm1[i],nl;
        ms(id,0);
        ms(fi,0);
        ms(vis,0);
        w=0,scc=0;
        fr(i,cn)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        fr(i,cn)
        {
            nd.pb(mp(fi[i],i));
        }
        sort(all(nd));
        reverse(all(nd));
        ms(vis,0);
        wn=-1;
        fr(i,cn)
        {
            v=nd[i].sd;
            if(!vis[v])
            {
                scc++;
                dfs1(v);
            }
        }
        ms(out,0);
        fr(i,cn)
        {
            fr(j,g[i].size())
            {
                v=g[i][j];
                if(id[i]!=id[v])
                    ng[id[i]].pb(id[v]),out[id[i]]++;
            }
        }

        ms(vis,0);
        b=1;
        fr1(i,scc)
        {
            if(out[i]>1)
            {
                b=0;
                break;
            }
        }

        if(b)
        {

            if(wn==-1)b=0;
            else
                dfs2(wn);
            //cout<<wn<<" ssss";nl;
            /* fr(i,scc)
             {
                 cout<<i<<" has: ";
                 fr(j,ng[i].size())cout<<ng[i][j]<<" ";
                 nl;
             }
            */
            fr1(i,scc)if(!vis[i])
            {
                b=0;
                break;
            }

        }
        if(b)pf("Case %d: YES\n",z);
        else pf("Case %d: NO\n",z);
        fr(i,cn)g[i].clear(),rg[i].clear();
        fr(i,scc+1)ng[i].clear();



    }

    return 0;
}

