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

int c[100005],te[100005];
vi g[100005];
bool vis[100005];

/*
void dfs(int u)
{
    int k,v;
    vis[u]=1;
    t[u]++;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis(v))
        {
            t[]
        }
    }
}
*/
int main()
{
    _;ct;
    int n,m,i,j,u,v,mx,an,z;
    cin>>n>>m;

    fr(i,n)cin>>c[i];

    fr(i,m)
    {
        cin>>u>>v;
        if(c[u-1]!=c[v-1])
        {
            g[c[u-1]].pb(c[v-1]);
            g[c[v-1]].pb(c[u-1]);
        }

    }
  /*  ms(vis,0);ms(te,0);
    fr1(i,n)
    {
        if(!vis(c[i]))
            dfs(c[i]);
    }
    */
    ms(vis,0);
    set<int>s;
    sort(c,c+n);
    mx=-1;
    fr(i,n)
    {
        if(!vis[c[i]])
        {
            s.clear();
            vis[c[i]]=1;
            fr(j,g[c[i]].size())s.insert(g[c[i]][j]);
            z=s.size();
            if(z>mx)
            {
                mx=z;
                an=c[i];
            }

        }
    }
    cout<<an;nl;

    return 0;
}
