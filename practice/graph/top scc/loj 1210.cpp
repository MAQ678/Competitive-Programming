//Bismillahir Rahmanir Rahim
//Opu-1204026
//.244
//http://codeforces.com/blog/entry/15102
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
}nv[20005];

vi g[20005],rg[20005];
int w,fi[20005];
bool vis[20005];

int id[20005],in[20005],out[20005],scc;//for new graph

void dfs(int u)
{
    vis[u]=1;
    int k,v;
    w++;
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

void dfs1(int u)
{
    vis[u]=1;
    id[u]=scc;
    int k,v;
    fr(k,rg[u].size())
    {
        v=rg[u][k];
        if(!vis[v])dfs1(v);
    }
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

   int t,z,n,m,u,v,ti,to,i,k;
   sf("%d",&t);
   fr1(z,t)
   {
       sf("%d%d",&n,&m);
       fr(i,m)sf("%d%d",&u,&v),g[u].pb(v),rg[v].pb(u);
        ms(fi,0);ms(vis,0);
        w=0;
        fr1(i,n)if(!vis[i])dfs(i);

        fr(i,n)nv[i].u=i+1,nv[i].c=fi[i+1];
        sort(nv,nv+n,cmp);

        ms(vis,0);scc=0;
        fr(i,n)
        {
            if(!vis[nv[i].u])
            {
                scc++;
                dfs1(nv[i].u);

            }
        }
        ms(in,0);ms(out,0);
        fr1(i,n)
        {
            fr(k,g[i].size())
            {
                v=g[i][k];
                if(id[i]!=id[v])
                    out[id[i]]++,in[id[v]]++;
            }
        }
        ti=0,to=0;
        if(scc>1)
        fr1(i,scc)
        {
            if(!in[i])ti++;
            if(!out[i])to++;
        }
        //cout<<scc<<endl;
        pf("Case %d: %d\n",z,max(ti,to));
        // end of part 1(dag's created)


       fr1(i,n)g[i].clear(),rg[i].clear();
   }

    return 0;
}

