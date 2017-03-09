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
    int r,d;
    bool operator <(const st& a)const
    {
        if(a.d!=d)return a.d<d;
        return a.r<r;
    }
};

vi g[50005],nd;
int dis[50005],n,par[50005];

void bfs(int u,int te)
{
    int k,v;
    st x,y;
    priority_queue<st>q;
    x.r=u;x.d=0;

    q.push(x);
    dis[u]=0;
    while(!q.empty())
    {
        x=q.top();
        q.pop();
        u=x.r;
      //  if(u==te)continue;
        fr(k,g[u].size())
        {
            v=g[u][k];
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                y.r=v;y.d=dis[v];
                par[v]=u;
                q.push(y);
            }
        }
    }
}

int main()
{
    int t,z,i,j,u,v,s,te;
    sf("%d",&te);
    fr1(z,te)
    {
        sf("%d",&n);
        ms(dis,0);ms(par,-1);
        fr(i,n)
        {
            sf("%d",&v);
            if(!i)s=v;
            if(i==n-1)t=v;
            if(i)
            {
                if(!dis[u])g[u].clear(),dis[u]=1;//par[u].clear(),
                if(!dis[v])g[v].clear(),dis[v]=1;//,par[v].clear()
                g[u].pb(v);g[v].pb(u);
            }
            u=v;
        }
        ms(dis,63);
        bfs(s,t);
        nd.clear();
        nd.pb(t);
        while(par[t]!=-1)
        {
            t=par[t];
            nd.pb(t);
        }
        reverse(all(nd));
        pf("Case %d:\n",z);
        fr(i,nd.size())
        {
            if(i)pf(" ");
            pf("%d",nd[i]);
        }
        pf("\n");

    }
    return 0;
}

