//Bismillahir Rahmanir Rahim
//Opu-1204026
// learned using query type mst. using priority queue
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
    int w,u,v;
    bool operator <(const st& a)const
    {
        return a.w<w;
    }
};
priority_queue<st>p,q;
int n,par[205];


void initialize()
{
    int i;
    fr1(i,n)par[i]=i;
}

int root(int u)
{
    while(par[u]!=u)par[u]=par[par[u]],u=par[u];
    return u;
}

int main()
{
    int t,z,i,j,w,u,v,c,to,sm;
    st r;
    sf("%d",&t);
    fr1(z,t)
    {
        pf("Case %d:\n",z);
        sf("%d%d",&n,&w);
       while(!p.empty())p.pop();
        fr(i,w)
        {

            sf("%d%d%d",&u,&v,&c);
            r.w=c,r.u=u,r.v=v;
            p.push(r);//already sorted
        sm=0;
        initialize();
            while(!p.empty())
            {
                r=p.top();
                p.pop();
                u=r.u,v=r.v,c=r.w;
                if(root(u)!=root(v))
                {
                    par[root(u)]=par[root(v)];
                    sm+=c;
                    q.push(r);
                }
            }
            p=q;
            while(!q.empty())q.pop();
            if(p.size()<n-1)pf("-1\n");
            else pf("%d\n",sm);

        }
    }
    return 0;
}


