//Bismillahir Rahmanir Rahim
//Opu-1204026
// hack is : if m==0 then w=1, cause there must have a country
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

vi g[1005],te;//te means total edges
int a[1005][1005],vis[1005][1005];//a for check which edge in which position of m for output last .

void dfs(int s,int u)
{
    vis[s][u]=1;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[s][v])dfs(s,v);
    }
}

int main()
{
    _;ct;
    int n,m,i,j,k,mx,cn,u,v;
    ms(vis,0);ms(a,0);
    cin>>n>>m;
    fr1(i,m)
    {
        cin>>u>>v;
        g[u].pb(v);

        a[u][v]=i;
    }
    // now we have to check from a node where can we reach
    fr1(i,n)dfs(i,i);//source:destination

    //now we will check by making a edge bidirectional how many degree can we get
    mx=1;
    fr1(i,n)
    {
        fr1(j,n)
        {
            cn=0;
            if(a[i][j])
            {
                fr1(k,n)
                {
                    if((vis[i][k]&&vis[k][j]))//||(vis[j][k]&&vis[k][i]))//
                       {
                           cn++;
                       }
                }
                if(cn>mx)
                {
                    mx=cn;
                    te.clear();
                }
                if(cn==mx)
                    te.pb(a[i][j]);
            }
        }
    }
    cout<<mx;
    nl;
    cout<<te.size();
    nl;
    sort(te.begin(),te.end());
    fr(i,te.size())
    {
        if(i)cout<<" ";
        cout<<te[i];
    }
    if(te.size())
    nl;
    return 0;


}
