//Bismillahir Rahmanir Rahim
//Opu-1204026
//.288
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
int n;
vector<ii>g[5002];
struct st
{
    int u,c1,c2;
    bool operator < (const st& a)const
    {
        if(a.c1<c1)return true;
        else if(a.c1==c1)return a.c2<c2;
        return false;
    }
};
int dis[5002][2];

int fun()
{
    int u,v,k,w1,w2;
    st a,b;
    priority_queue<st>q;
    set<int>s;
    set<int>::IT it;
    a.u=1,a.c1=0,a.c2=inf;
    q.push(a);dis[1][0]=0;
    while(!q.empty())
    {
        a=q.top();
        q.pop();
        fr(k,g[a.u].size())
        {
            v=g[a.u][k].ft;
            s.clear();
            s.insert(min(dis[a.u][0]+g[a.u][k].sd,inf));
            s.insert(dis[v][0]);s.insert(dis[v][1]);
            s.insert(min(inf,dis[a.u][1]+g[a.u][k].sd));
            it=s.begin();
            w1=*it;it++;
            w2=*it;
            if(w1<dis[v][0]||w2<dis[v][1])
            {
                dis[v][0]=w1;dis[v][1]=w2;
                b.u=v;b.c1=w1,b.c2=w2;
                q.push(b);
            }
        }
    }
    return dis[n][1];

}

int main()
{
    int t,z,r,u,v,c,i;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&r);
        fr(i,r)
        {
            sf("%d%d%d",&u,&v,&c);
            g[u].pb(mp(v,c));
            g[v].pb(mp(u,c));
        }
        ms(dis,63);
        pf("Case %d: %d\n",z,fun());
        fr1(i,n)g[i].clear();
    }
    return 0;
}
