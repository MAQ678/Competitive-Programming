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

vector<pair<int,ii> >g[5001];
struct st
{
    int u,c;
    bool operator < (const st& a)const
    {
        return a.c<c;
    }
};

int dis[5002],mdis[5002];
vector<ii>path,par[5002];
int main()
{
    int n,t,u,v,vv,z,c,k,man,an,in,w,wn,i,r,bn;
    bool qq,qb;
    st p,x;
    priority_queue<st>q;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&r);
        fr(i,r)
        {
            sf("%d%d%d",&u,&v,&c);
            g[u].pb(mp(v,mp(c,i)));
            g[v].pb(mp(u,mp(c,i)));
        }
        ms(dis,63);
        dis[1]=0;p.u=1,p.c=0;
        q.push(p);
        while(!q.empty())
        {
            p=q.top();
            q.pop();
            if(p.u==n)break;
            u=p.u;
            fr(k,g[u].size())
            {
                v=g[u][k].ft;
                if(dis[v]>dis[u]+g[u][k].sd.ft)
                {
                    dis[v]=dis[u]+g[u][k].sd.ft;
                    if(par[v].size())par[v].clear();
                    par[v].pb(mp(u,g[u][k].sd.sd));
                    x.u=v;
                    x.c=dis[v];
                    q.push(x);
                }
            }
        }
        man=dis[n];
        v=n;
        path.pb(mp(n,-1));
        while(par[v].size())
        {
            path.pb(par[v][0]);
            v=par[v][0].ft;
            if(v==1)break;
        }
        reverse(all(path));
        an=man;qq=0;
        fr1(i,path.size()-1)
        {
            //for each edge we will cut it and calculate another shortest path
            ms(mdis,63);
            while(!q.empty())q.pop();

            u=path[i-1].ft;
            vv=path[i].ft;
            in=path[i-1].sd;

            bn=(dis[n]+2*(dis[vv]-dis[u]));
            if(an==man&&bn>an)an=bn,qq=1;
            else an=min(an,bn);

            fr(k,g[u].size())
            {
                v=g[u][k].ft;
                if(g[u][k].sd.sd!=in)an=min(an,g[u][k].sd.ft*2+man);
            }
            mdis[u]=0;
            p.u=u,p.c=0;
            q.push(p);
            qb=0;
            while(!q.empty())
            {
                p=q.top();
                q.pop();
                if(p.u==vv)
                {
                    qb=1;
                    break;
                }
                u=p.u;
                fr(k,g[u].size())
                {
                    if(g[u][k].sd.sd==in)continue;
                    v=g[u][k].ft;
                    if(mdis[v]>mdis[u]+g[u][k].sd.ft&&(mdis[u]+g[u][k].sd.ft!=(dis[vv]-dis[path[i-1].ft])))
                    {
                        mdis[v]=mdis[u]+g[u][k].sd.ft;
                        x.u=v;x.c=mdis[v];
                        q.push(x);
                    }
                }
            }
            if(!qb)continue;
            w=mdis[vv];
            wn=(dis[n]-(dis[vv]-dis[path[i-1].ft]))+w;
            if(wn>man)
            {
                if(qq)
                an=min(an,wn);
                else an=wn;
                qq=1;
            }
        }
        pf("Case %d: %d\n",z,an);
        fr1(i,n)g[i].clear(),par[i].clear();
        path.clear();
    }
    return 0;
}
