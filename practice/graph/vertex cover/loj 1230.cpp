//Bismillahir Rahmanir Rahim
//Opu-1204026
//.040
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
typedef      vector<ii> vii;
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

vi g[1005];
ii dp[1005][1005][2];
bool vis[1005][1005][2],is[1005];
ii f(int u,int pa,int c)
{
    if(vis[u][pa][c])return dp[u][pa][c];
    vis[u][pa][c]=1;
    is[u]=1;
    ii an,w,x;
    an=w=x=ii(0,0);
    int k,v;
    if(c)an.ft=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(v==pa)continue;
        if(!c)
        {
            w=f(v,u,1);
            an.ft+=w.ft;an.sd+=w.sd;
        }
        else
        {
            w=f(v,u,1);x=f(v,u,0);
            w.sd++;
            if(w.ft==x.ft)w.sd=max(w.sd,x.sd),an.ft+=w.ft,an.sd+=w.sd;
            else if(w.ft>x.ft)an.ft+=x.ft,an.sd+=x.sd;
            else an.ft+=w.ft,an.sd+=w.sd;
        }

    }

    return dp[u][pa][c]=an;
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);

    int n,m,t,u,v,i,z;
    ii an1,an2,an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)sf("%d%d",&u,&v),g[u].pb(v),g[v].pb(u);
        ms(vis,0);ms(is,0);
        an=ii(0,0);
        fr(i,n)
        {
            if(!is[i])
            {
                if(g[i].size())
                {
                    an1=f(i,i,1);an2=f(i,i,0);
                    if(an1.ft==an2.ft)an1.sd=max(an1.sd,an2.sd);
                    else if(an1.ft>an2.ft)swap(an1,an2);
                    an.ft+=an1.ft,an.sd+=an1.sd;
                }
            }
        }


        pf("Case %d: %d %d %d\n",z,an.ft,an.sd,m-an.sd);
        fr(i,n)g[i].clear();
    }


    return 0;
}

