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

vi g[1002];
int dp[1002][1002][2];
bool vis[1002];

int f(int u,int c,int pa)
{
    if(dp[u][pa][c]!=-1)return dp[u][pa][c];
    int an=0;
    int k,v;
    if(c)an=1;
    vis[u]=1;

    fr(k,g[u].size())
    {
        v=g[u][k];
        if(v==pa)continue;
        if(c==0)an+=max(f(v,0,u),f(v,1,u));
        else an+=f(v,0,u);
    }
    return dp[u][pa][c]=an;
}
int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);

    int t,z,n,m,u,v,i,an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)
        {
            sf("%d%d",&u,&v);
            g[u].pb(v);g[v].pb(u);
        }
        ms(dp,-1);ms(vis,0);
        an=0;
        fr1(i,n)
        {
            if(!vis[i])
            {
                an+=max(f(i,0,i),f(i,1,i));
            }
        }
        pf("Case %d: %d\n",z,an);
        fr1(i,n)g[i].clear();
    }

    return 0;
}

