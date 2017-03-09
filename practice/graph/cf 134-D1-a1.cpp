//Bismillahir Rahmanir Rahim
//Opu-1204026
//used dfs as limit is 100, if it was 1e5 or higher , then we need to use dsu
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
    int x,y;
}a[105];

bool vis[105];
vi xx[1005],yy[1005];

void dfs(int p)
{
    vis[p]=1;
    int k,v;
    fr(k,xx[a[p].x].size())
    {
        v=xx[a[p].x][k];
        if(!vis[v])dfs(v);
    }
    fr(k,yy[a[p].y].size())
    {
        v=yy[a[p].y][k];
        if(!vis[v])dfs(v);
    }
}


int main()
{
    int n,i,j,x,y,cn=0;
    sf("%d",&n);
    fr(i,n)
    {
        sf("%d%d",&a[i].x,&a[i].y);
        xx[a[i].x].pb(i);
        yy[a[i].y].pb(i);
    }
    ms(vis,0);
    fr(i,n)
    {
        if(!vis[i])
        {
            cn++;//no of connected components
            dfs(i);
        }
    }
    pf("%d\n",cn-1);
}
