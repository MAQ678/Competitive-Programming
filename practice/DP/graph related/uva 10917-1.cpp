//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back
//


//input output
#define sf      scanf
#define pf      printf

#define sf1(a)  sf("%d",&a)
#define sf2(a,b)  sf("%d%d",&a,&b)
#define sf3(a,b,c)   sf("%d%d%d",&a,&b,&c)

#define nl cout<<"\n"
//eof

//seg tree
#define lc      (s+e)>>1
#define rc      (lc)+1
#define Ln      n<<1
#define Rn      (Ln)|1
//end of seg tree




//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

struct st
{
    int v,c;
    st(int u1,int c1)
    {
        v=u1;c=c1;
    }
     bool operator < (const st& a)const
    {
        return a.c<c;
    }
};

vector<ii>g[1005],wt;
vi pa[1005];
int dp[1005];
int wk[1005][1005];

void dij()
{
    int dis[1005],u,v;
    ms(dis,63);
    priority_queue<st>pq;
    dis[1]=0;
    pq.push(st(1,0));

    while(!pq.empty())
    {
        u=pq.top().v;
        pq.pop();
        for(auto w:g[u])
        {
            v=w.ft;
            if(dis[v]==dis[u]+w.sd)
            {
                pa[v].pb(u);
            }
            if(dis[v]>dis[u]+w.sd)
            {
                dis[v]=dis[u]+w.sd;
                pa[v].clear();
                pa[v].pb(u);
                pq.push(st(v,dis[v]));
            }
        }
    }

}

int get(int u)
{
    if(u==1)return 1;
    if(dp[u]!=-1)return dp[u];
    dp[u]=0;
    for(int v:pa[u])
    {
        dp[u]+=get(v);
    }
    return dp[u];
}


int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);

    int n,m,i,u,v,c;
    while(sf1(n)&&n!=0)
    {
        sf1(m);
        fr1(i,n)g[i].clear(),pa[i].clear();
        ms(wk,63);

        fr(i,m)
        {
            sf3(u,v,c);
            if(wk[u][v]>c)
            {
                if(wk[u][v]==wk[0][0])
                    wt.pb(mp(u,v));
                wk[u][v]=wk[v][u]=c;

            }
            g[u].pb(mp(v,c));
            g[v].pb(mp(u,c));
        }
        cout<<wt.size();nl;
        for(ii zt:wt)
        {
            u=zt.ft;v=zt.sd;
          //  g[u].pb(mp(v,wk[u][v]));
          //  g[v].pb(mp(u,wk[u][v]));
        }

        //take i/p

        dij();
        ms(dp,-1);

       // fr1(i,n)pf("out: %d %d\n",i,pa[i].size());

        pf("%d\n",get(2));

    }
    return 0;
}







