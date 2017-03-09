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
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct st
{
    ll v;int in;
}a[100005];

bool cmp(st x,st y)
{
    return x.v<y.v;
}
ll tr[100005];
int n;
vi g[1000005];
bool ck[1000005];

ll get(int in)
{
    ll z=0;
    while(in)
    {
        z+=tr[in];
        in-=in&(-in);
    }
    return z;
}
void up(int in,ll v)
{
    while(in<=n)
    {
        tr[in]+=v;
        in+=in&(-in);
    }
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int t,i,j;
   ll an,v;
   sf("%d",&t);
   while(t--)
   {
       sf("%d",&n);
       fr1(i,n)sf("%lld",&v),g[v].pb(i);
       sort(a,a+n,cmp);
       ms(ck,0);
       an=0;
       ms(tr,0);
       fr(i,n)
       {
           an+=get(a[i].in)-get(a[i].in-1);
           up(a[i].in,a[i].v);
       }
       pf("%lld\n",an);
   }

    return 0;
}

