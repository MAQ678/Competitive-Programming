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

vi g[3005];
int vis[3005],par[3005],x,y,cn,an[3005];

void dfs(int u,int p)
{

    if(vis[u]==1)//running
    {
        cout<<"cov: "<<u<<" "<<p<<endl;
        if(cn==0)
        x=u,y=p,cn=1;
        return;
    }
    cout<<u<<" "<<p<<endl;
    vis[u]=1;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            par[v]=u;
            dfs(v,u);//child,parent
        }
    }

    vis[u]=2;
}

int dfs1(int u)
{
    if(an[u]!=-1)return an[u];
    int k,v,mn=inf;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[u])
            mn=min(mn,1+dfs1(v)) ;
    }
    return mn;

}

int main()
{
    int n,i,j,k,u,v;
    cin>>n;
    fr(i,n)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ms(vis,0);
    ms(par,-1);

    cn=0;x=-1,y=-1;
    dfs(1,0);

    cout<<x<<" "<<y<<endl;

    //make the cycle as 0
        ms(an,-1);
        u=y;

        if(x<0)x=1;
        an[x]=0;
        while(x>0&&y>0&&par[u]!=x)
        {
            an[u]=0;
            u=par[u];
        }
    //make finished for cycle if any

    fr1(i,n)
    {
        if(an[i]==-1)
        {
            ms(vis,0);
            an[i]=dfs1(i);//get the minimum distance
        }
    }

    //at last get the output

    fr1(i,n)
    {
        if(i>1)pf(" ");
        pf("%d",an[i]);
    }

    return 0;
}
