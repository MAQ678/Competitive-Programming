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

vi g[50002];
bool vis[50002];
int dp[50002];

int dfs(int u)
{
    if(dp[u]!=-1)return dp[u];
    vis[u]=1;
    int k,v,an=0;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        an+=(1+dfs(v));
    }
    return dp[u]=an;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int t,z,u,v,n,i,an,mx,nd;
   sf("%d",&t);
   fr1(z,t)
   {
       sf("%d",&n);
       fr(i,n)
       {
           sf("%d%d",&u,&v);
           g[u].pb(v);
       }
       mx=-1;ms(dp,-1);
       nl;
       fr1(i,n)
       {
            ms(vis,0);
            if(dp[i]==-1)
            {
                an=dfs(i);
                cout<<i<<" ";
                cout<<an<<endl;
                if(an>mx)
                {
                    mx=an;
                    nd=i;
                }
            }
       }
       fr1(i,n)g[i].clear();
       pf("Case %d: %d\n",z,nd);

   }

    return 0;
}

