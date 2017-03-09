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


vi g[100005],rg[100005];
bool vis[100005];
int f[100005],z;

void dfs(int u)
{
    vis[u]=1;
    int k;
    fr(k,sz(g[u]))
    {
        if(!vis[g[u][k]])
            dfs(g[u][k]);
    }
    f[u]=z++;
}
vii va;
int main()
{
  //  freopen("F:\\Coding\\in.txt","r",stdin);
       // freopen("F:\\Coding\\out.txt","w",stdout);
    int t;
    int n,m,i,u,v,an;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&n,&m);
        while(m--)
        {
            sf("%d%d",&u,&v);u--,v--;
            g[u].pb(v);//rg[v].pb(u);
        }
        ms(vis,0);z=0;ms(f,0);
        fr(i,n)
        {
            if(!vis[i])dfs(i);
        }
        fr(i,n)va.pb(mp(f[i],i));
        sort(all(va));reverse(all(va));
        ms(vis,0);an=0;
        fr(i,n)
        {
            u=va[i].sd;
            if(!vis[u])
            {
                an++;
                dfs(u);
            }
        }
        pf("%d\n",an);
        fr(i,n)g[i].clear();
        va.clear();

    }
    return 0;
}

