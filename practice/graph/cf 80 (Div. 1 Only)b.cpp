//Bismillahir Rahmanir Rahim
//Opu-1204026
//hack1: 1 connected component
//hack2: As 1 simple cycle, so after reducing tentacles , deg[i] must be 2
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

vi g[105];
int deg[105];
bool vis[105];
void dfs(int u)
{
    vis[u]=1;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])dfs(v);
    }
}

int main()
{
    _;ct;
    int n,m,u,v,i,cn;
    bool ok=1;
    ms(deg,0);
    cin>>n>>m;
    fr(i,m)
    {
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        g[u].pb(v);
        g[v].pb(u);
    }

    ms(vis,0);cn=0;
    fr1(i,n)
    {
        if(!vis[i])
        {
            dfs(i);
            cn++;
        }
    }
    if(cn>1)
    {
        cout<<"NO";
        return 0;
    }
    cn=0;

    queue<int>q;

    fr1(i,n)if(deg[i]==1)q.push(i);

    //clear all tentacles
        while(!q.empty())
        {
            u=q.front();
            deg[u]--;
            q.pop();
            fr(i,g[u].size())
            {
                v=g[u][i];
                deg[v]--;
                if(deg[v]==1)q.push(v);
            }
        }
    //end of clearing tentacles

        cn=0;
        fr1(i,n)
        {
            if(deg[i]==2)cn++;
            else if(deg[i]>2)
            {
                ok=0;
                break;
            }
        }
        if(!ok||cn<3)cout<<"NO";
        else cout<<"FHTAGN!";
        nl;

    return 0;
}
