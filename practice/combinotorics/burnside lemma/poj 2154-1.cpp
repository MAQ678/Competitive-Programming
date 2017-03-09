//Bismillahir Rahmanir Rahim
//Opu-1204026
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
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

int p[100000],md,w;
vi pr;
void phi(int n)
{
    int i,j;
    w=sqrt(n)+1;
    fr1(i,w)p[i]=i;
    for(i=2;i<=w;i++)
    {
        if(p[i]==i)
        {
            pr.pb(i);
            for(j=i;j<=w;j+=i)
            p[j]-=p[j]/i;
        }

    }

}


int get(int n)
{
    if(n<=w)return p[n]%md;
    int an=n,i;
    for(i=0;i<pr.size()&&pr[i]*pr[i]<=n;i++)
    {
        if(n%pr[i]==0)
        {
            while(n%pr[i]==0)n/=pr[i];
            an-=an/pr[i];
            if(n<=1)return an%md;
        }
    }
    if(n>1)an-=an/n;
    return an%md;
}

int bigmod(int b,int p)
{
    if(p==0)return 1;
    if(p==1)return b%md;
    if(p&1)return (b*bigmod(b,p-1))%md;
    int w=bigmod(b,p/2);
    return (w*w)%md;
}
int main()
{
    phi(1000000000);
    int x,n,an,i;
      //  fr(i,pr.size())cout<<pr[i]<<" ";nl;
    sf("%d",&x);
    while(x--)
    {
        sf("%d%d",&n,&md);
        an=0;
        for(i=1;i*i<n;i++)
        {
            if(n%i==0)
            {
                an=(an+(get(i)*bigmod(n,(n/i)-1))%md+(get(n/i)*bigmod(n,i-1))%md)%md;
            }
        }
        if(i*i==n)an=(an+(get(i)*bigmod(n,(n/i)-1))%md)%md;
        pf("%d\n",an);
    }
    return 0;
}


