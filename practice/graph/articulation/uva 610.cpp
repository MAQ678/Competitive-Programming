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

struct st
{
    int u,v;
    st(int u,int v)
    {
        this->u=u;
        this->v=v;
    }
    bool operator <(const st& a)const
    {
        if(a.u>u)return 1;
        else if(a.u==u)return a.v>v;
        return 0;
    }
};
vector<st>pa;
vii g[1002];
bool vis[1002],ck[1000000];
int d[1002],low[1002],ti;


void dfs(int u,int par)
{
    int k,v;
    vis[u]=1;
    d[u]=low[u]=ti++;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(v!=par)
        {
            if(!vis[v])
            {
                ck[g[u][k].sd]=1;
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(d[u]<low[v])
                {
                   // cout<<"ff"<<endl;
                    pa.pb(st(u,v));
                    pa.pb(st(v,u));
                }
                else
                {
                    pa.pb(st(u,v));
                }
            }
            else
            {
                low[u]=min(low[u],d[v]);
                if(!ck[g[u][k].sd])
                pa.pb(st(u,v)),ck[g[u][k].sd]=1;
            }
        }
    }
}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

   int n,m,i,u,v,an,z=1;
    while(sf("%d%d",&n,&m)&&(n||m))
    {
        fr(i,m)
        {
            sf("%d%d",&u,&v);
            g[u].pb(mp(v,i));g[v].pb(mp(u,i));
        }
        ms(vis,0),ms(d,0),ms(low,0);ti=1;
        pa.clear();ms(ck,0);
        dfs(1,-1);
        sort(all(pa));
        pf("%d\n\n",z++);
        fr(i,pa.size())
        {
            pf("%d %d\n",pa[i].u,pa[i].v);
        }
        puts("#");
        fr1(i,n)g[i].clear();

    }
    return 0;
}

