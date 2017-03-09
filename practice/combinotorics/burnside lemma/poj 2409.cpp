//Bismillahir Rahmanir Rahim
//Opu-1204026
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
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


ll ppow(ll n,ll m)
{
    ll z=1;
    while(m--)
    {
        z*=n;
    }
    return z;
}
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    ll n,m,sm,i,c;
    while(sf("%lld%lld",&c,&n)!=EOF)
    {
        if(!n&&!c)break;
        sm=0;
        fr1(i,n)
        {
            sm+=ppow(c,gcd(i,n));
        }
        if(n&1)sm+=n*ppow(c,n/2+1);
        else sm+=(n/2)*ppow(c,n/2+1)+(n/2)*ppow(c,n/2);
        sm/=2*n;
        pf("%lld\n",sm);
    }
    return 0;
}

