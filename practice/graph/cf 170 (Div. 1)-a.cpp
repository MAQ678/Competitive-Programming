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

vi e[110];
vi g[110];
int vis[110];

void dfs(int u,int l)
{
    vis[u]=l;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])dfs(v,l);
    }
}

int main()
{
    _;ct;
    int n,m,i,j,u,v,t,cn,an,w;
    cin>>n>>m;
    fr1(i,n)
    {
        cin>>t;
        fr(j,t)
        {

            cin>>u;
            e[i].pb(u);
             if(j)
             {
                 g[u].pb(v);g[v].pb(u);
             }
            v=u;
        }
    }
    ms(vis,0);
    cn=1;
    fr1(i,m)
    {
        if(!vis[i])
        {
            dfs(i,cn);
            cn++;
        }
    }
    set<int>s;
    w=0;
    fr1(i,n)
    {
        if(e[i].size())
            s.insert(vis[e[i][0]]),w=1;
        else s.insert(cn++);
    }
    an=s.size();
    if(w)
    cout<<an-1;
    else cout<<an;
    nl;
    return 0;
}
