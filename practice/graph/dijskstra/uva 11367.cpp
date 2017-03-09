//Bismillahir Rahmanir Rahim
//Opu-1204026
//80
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
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct st
{
    int u,f,c;
    st() {}
    st(int u1,int f1,int c1)
    {
        u=u1,f=f1,c=c1;
    }
    bool operator <(const st& a)const
    {
        return a.c<c;
    }
};

vii g[1001];
int di[1001][101];
int p[1001];

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int n,u,v,d,c,s,e,i,m,q,j;
    bool ok;
    st a;
    while(sf("%d%d",&n,&m)!=EOF)
    {

        fr(i,n)sf("%d",&p[i]);
        while(m--)
        {
            sf("%d%d%d",&u,&v,&d);
            g[u].pb(ii(v,d)),g[v].pb(ii(u,d));
        }

        sf("%d",&q);
        while(q--)
        {
            sf("%d%d%d",&c,&s,&e);
            priority_queue<st>q;
            q.push(st(s,0,0));
            fr(i,n)fr(j,c+1)di[i][j]=inf;
            di[s][0]=0;
            ok=0;
            while(!q.empty())
            {
                a=q.top();
                //st(u,d,v)=q.top();a.f=d;a.c=v;
                //cout<<u<<" "<<d<<" "<<v<<endl;
                q.pop();
                u=a.u;
                if(u==e)
                {
                    ok=1;
                    pf("%d\n",di[u][a.f]);
                    break;
                }
                if(a.f+1<=c&&di[u][a.f+1]>di[u][a.f]+p[u])q.push(st(u,a.f+1,a.c+p[u])),di[u][a.f+1]=di[u][a.f]+p[u];
                fr(i,g[u].size())
                {
                    v=g[u][i].ft;
                    d=g[u][i].sd;
                    if(d<=a.f&&di[v][a.f-d]>di[u][a.f])
                    {
                        di[v][a.f-d]=di[u][a.f];
                        q.push(st(v,a.f-d,a.c));
                    }
                }
            }
            if(!ok)pf("impossible\n");
        }
        fr(i,n)g[i].clear();

    }
    return 0;
}

