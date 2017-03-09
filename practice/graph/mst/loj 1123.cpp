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

int e[205][205],n,par[205];
vector<pair<int,ii> >p;
vector<ii>g[205];


void initialize()
{
    int i;
    fr1(i,n)par[i]=i,g[i].clear();
}

int main()
{
    int t,z,i,j,w,u,v,c,to,q;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&w);
        ms(e,0);p.clear();
        initialize();
        to=0;q=0;
        fr(i,w)
        {
            sf("%d%d%d",&u,&v,&c);
            if(!e[u][v])to++;
            e[u][v]=min(e[u][v],c);
            e[v][u]=c;
            p.pb(mp(c,mp(u,v)));
            if(to==n-1)//there can be possible
            {
                if(!q)//first time
                {
                    sort(all(p));
                    fr(j,p.size())
                    {

                    }
                }
            }
            else pf("-1\n");
        }
    }
    return 0;
}

