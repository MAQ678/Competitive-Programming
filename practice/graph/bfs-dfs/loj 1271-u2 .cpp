//Bismillahir Rahmanir Rahim
//Opu-1204026
//dijkstra marte hole distance and node duitar ascending lagbe. Cause node er korle length beshi hote pare, ar dis er korle beshi node er hote pare.
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

vi g[50005],nd;
int dis[50005],par[50005];
bool vis[50005];

void bfs(int u,int te)
{
    int v,k;
    priority_queue<int>q;
    q.push(-u);
    vis[u]=1;
    while(!q.empty())
    {
        u=-q.top();
        q.pop();
        if(u==te)return;
        fr(k,g[u].size())
        {
            v=g[u][k];
            if(!vis[v])
            {
                vis[v]=1;
                par[v]=u;
                q.push(-v);
            }
        }
    }
}

int main()
{

    int t,z,n,u,v,te,s,i;
    sf("%d",&t);
    fr1(z,t)
    {
        fr1(i,50000)g[i].clear();
        sf("%d",&n);
        fr(i,n)
        {
            sf("%d",&u);
            if(!i)s=u;
            if(i==n-1)te=u;
            if(i)g[u].pb(v),g[v].pb(u);
            v=u;
        }
        ms(dis,63);
        bfs(s,te);

        nd.clear();
        nd.pb(te);
        u=te;
        while(u!=s)
        {
            nd.pb(par[u]);
            u=par[u];
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


