//Bismillahir Rahmanir Rahim
//Opu-1204026
//first disktra problem solved
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
#define eps     1e-10
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct st
{
    int u;
    ll w;
    bool operator < (const st& a)const
    {
        return a.w<(w+eps);
    }
};

vi g[100005];
vl co[100005];
int par[100005];
ll dis[100005];
int disktra(int n)
{
    priority_queue<st>q;
    ms(dis,63);

    dis[1]=0;
    st u,z;
    u.u=1;u.w=0;
    int k,v;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();

        if(u.u==n)return 1;

        fr(k,g[u.u].size())
        {
            v=g[u.u][k];
            if(dis[v]>u.w+co[u.u][k])
            {
                par[v]=u.u;

                dis[v]=u.w+co[u.u][k];

                z.u=v;z.w=dis[v];
                q.push(z);
            }
        }

    }
    return -1;
}

int main()
{
    _;ct;
    vi path;
    int n,i,j,m,u,v;
    ll c;
    cin>>n>>m;
    fr(i,m)
    {
        cin>>u>>v>>c;
        g[u].pb(v);g[v].pb(u);

        co[u].pb(c);co[v].pb(c);
    }
    ms(par,-1);
   u= disktra(n);
   if(u==-1)cout<<u;
   else
   {
       path.pb(n);
        while(par[n]!=-1)
        {
            path.pb(par[n]);
            n=par[n];
        }
       // path.pb(1);
        reverse(path.begin(),path.end());
        fr(i,path.size())
        {
            if(i)cout<<" ";
            cout<<path[i];
        }
   }
   nl;

    return 0;
}
