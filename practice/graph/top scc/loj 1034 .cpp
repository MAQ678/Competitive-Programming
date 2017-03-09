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

vi g[10005],rg[10005];
bool vis[10005];
//struct st
//{
//    int in,nd;
//}w[10005];
//bool cmp(st a,st b)
//{
//    return a.in<b.in;
//}

void dfs(int u,int md)
{
    int k,v;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            dfs(v,0);
        }
    }
    if(md==1)
    fr(k,rg[u].size())
    {
        v=rg[u][k];
        if(!vis[v])
        {
            dfs(v,1);
            break;
        }
    }
}


int main()
{
    int t,z,n,m,i,j,a,b,cn;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr1(i,n)g[i].clear(),rg[i].clear();
//w[i].in=0,w[i].nd=i,
        fr(i,m)
        {
            sf("%d%d",&a,&b);
            g[a].pb(b);
            rg[b].pb(a);
           // w[b].in++;
        }
        //sort(w+1,w+n+1,cmp);
        ms(vis,0);cn=0;
        fr1(i,n)
        {
            if(!vis[i])
            {
                cn++;
                dfs(i,1);
            }
        }
        pf("Case %d: %d\n",z,cn);
    }
    return 0;
}

