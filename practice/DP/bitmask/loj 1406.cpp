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

int n,dp[1<<16][16];
vi g[16];
vector<int>w[16];
bool vis[20];


void dfs(int u, int mask,int r)
{
    int k,v;
     int tmp;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            tmp=mask;
            tmp=tmp|(1<<(v));
            w[r].pb(tmp);
            dfs(v,tmp,r);
        }
    }
}

int fun(int mask,int cn)
{
    if(mask==((1<<n)-1))return 0;
    if(dp[mask][cn]!=-1)
    {
        return dp[mask][cn];
    }
    int i,an=inf,j,b=0;
    int v,q;
   // if(mask==7)cout<<"ss"<<endl;
    fr(i,n)
    {
        if((mask&(1<<i))==0)
        {
            fr(j,w[i].size())
            {
              //  if(mask==7&&i==4)cout<<"eee"<<endl;
                v=w[i][j];
                v=mask^v;
                v=v&mask;
                //v=~(mask^v);
                if(v==mask)
                {

                    q=mask|w[i][j];
                    an=min(an,1+fun((q|(1<<i)),cn+1));
                }
            }
            an=min(an,1+fun(mask|(1<<i),cn+1));//na pele
        }
    }
    return dp[mask][cn]=an;
}

int main()
{
    freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

    int m,u,v,t,z,i;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)sf("%d%d",&u,&v),g[u-1].pb(v-1);

        fr(i,n)
        {
            ms(vis,0);
            dfs(i,0,i);
        }
       /* fr(i,n)
        {
            cout<<i<<" has: ";
            fr(u,w[i].size())
            cout<<w[i][u]<<" ";
            nl;
        }
        */
        ms(dp,-1);
        pf("Case %d: %d\n",z,fun(0,0));
        fr(i,n)g[i].clear(),w[i].clear();
    }

    return 0;
}

