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

int deg[3005],an[3005],vis[3005];
vi g[3005];


//void dfs(int u)
//{
//    deg[u]--;
//    int k,v;
//    fr(k,g[u].size())
//    {
//        v=g[u][k];
//        if(deg[v]==1||deg[v]==2)dfs(v);
//    }
//}

void dfs1(int u,int d)
{
    vis[u]=1;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            if(an[v]==-1)
            {
                an[v]=d+1;
                dfs1(v,d+1);
            }
            else dfs1(v,d);
        }
    }
}

int main()
{

    int n,i,j,u,v,z;
    ms(deg,0);
    cin>>n;
    fr(i,n)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);

        deg[u]++;
        deg[v]++;
    }
//    fr1(i,n)
//    {
//        if(deg[i]==1)
//            dfs(i);
//    }
queue<int>q;
    fr1(i,n)if(deg[i]==1)q.push(i);

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        deg[u]--;
        fr(i,g[u].size())
        {
            v=g[u][i];
            deg[v]--;
            if(deg[v]==1)
            {
                q.push(v);
            }
        }
    }

    ms(an,-1);
    fr1(i,n)
    {
       // cout<<deg[i]<<" ";
        if(deg[i]>0)an[i]=0,z=i;
    }
   // nl;

    ms(vis,0);
    dfs1(z,0);

    fr1(i,n)
    {
        if(i>1)pf(" ");
        pf("%d",an[i]);
    }


    return 0;
}
