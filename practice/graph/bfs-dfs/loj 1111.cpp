//Bismillahir Rahmanir Rahim
//Opu-1204026
//0.016
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

int n;
vi g[1005];
bool vis[1005];
int p[101];
int a[1005];

void dfs(int u)
{
    vis[u]=1;
    a[u]++;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])dfs(v);
    }
}

int main()
{
    int k,m,u,v,i,t,z,j,sm;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d%d",&k,&n,&m);
        fr1(i,n)g[i].clear();

        fr(i,k)sf("%d",&p[i]);
        fr(i,m)
        {
            sf("%d%d",&u,&v);
            g[u].pb(v);
        }
        ms(a,0);
        fr(i,k)
        {
            ms(vis,0);
            dfs(p[i]);
        }
        sm=0;
        fr1(i,n)
        {
            if(a[i]==k)sm++;
        }
        pf("Case %d: %d\n",z,sm);
    }
    return 0;
}

