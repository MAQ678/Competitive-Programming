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


vii g[502];
vi w;
bool cc[502];
int n,way[18][18],dis[502],ws;

struct st
{
    int u,c;
    st(int u,int c)
    {
        this.u=u;this.c=c;
    }
    bool operator <(const &st a)const
    {
        return a.c<c;
    }
};

priority_queue<st>q;

void dij(int s)
{
    st u;
    ms(dis,63);
    int i,z=0,v;
    dis[s]=0;q.push(st(s,0));
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        if(cc[u.u])
        {
            way[s][u.u]=u.c;
            z++;
        }
        if(z==ws)
        {
            break;
        }

        fr(i,g[u.u].size())
        {
            v=g[u.u][i].ft;
            if(d[v]>d[u.u]+g[u.u][i].sd)
            {
                d[v]=d[u.u]+g[u.u][i].sd;
                q.push(st(v,d[v]));
            }
        }
    }
}


int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);

    int m,u,s,v,c,i,t,z;
    sf("%d",&t);
    set<int>ss;
    fr1(z,t)
    {

        sf("%d%d%d",&n,&m,&s);
        w.resize(s);ms(cc,0);
        fr(i,s)sf("%d",&w[i]),ss.insert(w[i]),cc[w[i]]=1;

        ws=ss.size();ss.clear();
        if(!cc[0])ws++;if(!cc[n-1])ws++;

        cc[0]=cc[n-1]=1;
        fr(i,m)
        {
            sf("%d%d%d",&u,&v,&c);
            g[u].pb({v,c});
        }
        ms(way,-1);
        fr(i,s)
        {
            if(way[w[i]][0]!=-1)
            dij(w[i]);
        }
        if()

    }
    return 0;
}

