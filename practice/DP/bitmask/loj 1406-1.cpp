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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

vi g[16];
bool vis[16];
int f[1<<16],dp[1<<16],n;

int dfs(int u,int m)
{
    int k,v,w=m;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
            {
                w|=dfs(v,m|(1<<v));
            }
    }
    f[w]=1;
    return m;
}

int fn(int m)
{
    if(m==((1<<n)-1))return 0;
    if(dp[m]!=-1)return dp[m];

    int i,w,an=inf;
    w=m^((1<<n)-1);
    for(i=w;i>0;i=(i-1)&w)
        if(f[i]!=-1)
        an=min(an,fn(m|i)+f[m]);

    return dp[m]=an;
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int t,z,m,u,v,i;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)sf("%d%d",&u,&v),g[u-1].pb(v-1),g[v-1].pb(u-1);
        ms(f,-1);
        fr(i,n)
        {
            ms(vis,0);
            dfs(i,1<<i);
        }
        f[0]=0;
        ms(dp,-1);
        pf("Case %d: %d\n",z,fn(0));
    }

    return 0;
}

