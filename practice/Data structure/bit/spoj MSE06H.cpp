//Bismillahir Rahmanir Rahim
//Opu-1204026
//.10
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
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())


struct st
{
    int u,v;
}a[1005];
bool cmp(st x,st y)
{
    return x.u<y.u;
}
vi g[1005];
ll tr[2005];
void update(int idx,int n)
{
    while(idx<=n)
    {
        tr[idx]++;
        idx+=idx&(-idx);
    }
}

ll query(int idx)
{
    ll z=0;
    while(idx)
    {
        z+=tr[idx];
        idx-=idx&(-idx);
    }
    return z;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int t,z,n,m,k,u,v,i,j;
   ll an=0;
   sf("%d",&t);
   fr1(z,t)
   {
       sf("%d%d%d",&n,&m,&k);
       fr(i,k)
       {
            sf("%d%d",&u,&v);
            g[u].pb(v);
       }
       an=0;
       ms(tr,0);
       fr1(i,n)
       {
           fr(j,g[i].size())
           {
                an+=(1ll*(query(m)-query(g[i][j])));
           }
           fr(j,g[i].size())
           {
               update(g[i][j],m);
           }
           g[i].clear();
       }
       pf("Test case %d: %lld\n",z,an);

   }

    return 0;
}

