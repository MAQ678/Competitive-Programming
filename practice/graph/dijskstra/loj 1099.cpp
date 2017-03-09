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

struct st
{
    int w,u;
    bool operator <(const st& a)const
    {
        return a.w<w;
    }
};
int dis[5005][2];
priority_queue<st>p;
vector<ii>g[5005];

int disktra()
{
    int i,j;
    st x,y;
    dis[1][0]=0;
    x.u=1,x.w=0;
    p.push(x);//aro duibar dibo naki
    while(!p.empty())
    {
        x=p.top();
        p.pop();
        fr(k,)
    }
}

int main()
{
    int t,u,v,c,i,j,z;
    st r;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,m)
        {
            sf("%d%d%d",&u,&v,&c);
            g[u].pb(mp(v,c));
            g[v].pb(mp(u,c));
        }
        ms(dis,63);
        pf("%d\n",disktra());
    }
    return 0;
}

