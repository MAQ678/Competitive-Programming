//Bismillahir Rahmanir Rahim
//Opu-1204026
//.216
//find connected components,then check for each component
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

int n,co[1005];
vi g[1005];
bool vis[1005],mvis[1005];

void dfs(int u)
{
    int k,v;
    mvis[u]=vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!mvis[v])dfs(v);
    }
}

int main()
{
    int t,z,u,v,m,sm,cn,r,c,i,j;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        sm=0;
        fr1(i,n)g[i].clear();
        fr1(i,n)sf("%d",&co[i]),sm+=co[i];
        fr(i,m)
        {
            sf("%d%d",&u,&v);
            g[u].pb(v);
            g[v].pb(u);
        }
        pf("Case %d: ",z);
        if(sm%n!=0)pf("No\n");
        else
        {
            r=sm/n;c=0;
            ms(mvis,0);
            fr1(i,n)
            {
                if(!mvis[i])
                {
                    sm=0;
                    cn=0;
                    ms(vis,0);
                    dfs(i);
                    fr1(j,n)if(vis[j])sm+=co[j],cn++;
                    if(cn*r!=sm)
                    {
                        pf("No\n");
                        c=1;
                        break;
                    }
                }
            }
            if(!c)pf("Yes\n");
        }
    }
    return 0;
}

