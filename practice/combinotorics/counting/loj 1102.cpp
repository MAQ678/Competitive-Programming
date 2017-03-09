//Bismillahir Rahmanir Rahim
//Opu-1204026
//star & bar problem
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

ll f[2000002],md=1000000007;

ll bigmod(ll b,ll p)
{
    if(!p)return 1;
    if(p&1)return (b*bigmod(b,p-1))%md;
    ll an=bigmod(b,p/2);
    return (an*an)%md;
}

ll inv(ll n)
{
    return bigmod(n,md-2);
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int z,t;
    ll n,k,i,an;
    f[0]=1;
    fr1(i,2000001)f[i]=(i*f[i-1])%md;

    sf("%d",&t);
    fr1(z,t)
    {
        sf("%lld%lld",&n,&k);
        k--;
        an=(inv(f[k])*inv(f[n]))%md;
        an=(f[n+k]*an)%md;
        pf("Case %d: %lld\n",z,an);
    }


    return 0;
}

