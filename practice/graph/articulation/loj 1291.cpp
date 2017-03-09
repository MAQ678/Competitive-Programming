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

bool vis[10002],ck[20005];
int low[10002],d[10002],to,ti;
vii g[10002];


int dfs(int u,int par)
{
    vis[u]=1;
    d[u]=low[u]=ti++;
    int k,v,an=0;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;

        if(par!=v)
        {
            if(!vis[v])
            {
                an+=dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(d[u]<low[v])an++;
            }
            else
                low[u]=min(low[u],d[v]);
        }
    }
    return an;

}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,z,i,an,u,v,n,m;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)sf("%d%d",&u,&v),g[u].pb(mp(v,i)),g[v].pb(mp(u,i));
        ms(vis,0);
        ms(low,0),ms(d,0);
        to=0;
        ti=1;ms(ck,0);
        an=dfs(0,-1);
        pf("Case %d: %d\n",z,(an+1)/2);
        fr(i,n)g[i].clear();


    }
    return 0;
}
