//Bismillahir Rahmanir Rahim
//Opu-1204026
//check datatype
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

ll chi[100005],n;
ll an2;
bool vis[100005];
vi g[100005];
int dfs(int u,ll lev)
{
    vis[u]=1;
    int k,v,a=0;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            chi[u]++;
            a+=(1+dfs(v,lev+1));
            chi[u]+=chi[v];
        }
    }
    an2+=(n-lev-1-chi[u]);
    return a;
}


int main()
{
    int t,z,u,v,i,an1;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr1(i,n)g[i].clear();
        fr(i,n-1)
        {
            sf("%d%d",&u,&v);
            g[u].pb(v);
        }
        ms(vis,0);ms(chi,0);an2=0;
        an1=dfs(1,0);
        pf("Case %d: %d %lld\n",z,an1,an2/2);
    }
    return 0;
}
