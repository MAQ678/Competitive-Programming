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
vi primes;
bool flag[5000005];
ll f[5000005],sm[5000005];
//sieve
void sieve(int ub)
{
    int i,val,j;
    fr(i,ub+1)flag[i]=1;
    val=sqrt(ub)+1;
    for(i=2;i<val;i++)
        if(flag[i])
        for(j=i;j*i<=ub;j++)
            flag[j*i]=0;
    for(i=2;i<ub;i++)
        if(flag[i])
            primes.pb(i);
}

void calcuPF()
{
    int i,j;f[0]=f[0]=0;
    ms(sm,0);
    bool b;
    for(i=2;i<=5000000;i++)
    {
        f[i]=0;
        for(j=0;j<primes.size()&&primes[j]*primes[j]<=i;j++)
        {
            if(i%primes[j]==0)
            {
                f[i]=f[i/primes[j]]+1;
                break;
            }
        }
        if(!f[i])f[i]=1;
        sm[i]=f[i]+sm[i-1];
    }
}

int main()
{
    sieve(5000004);
    //cout<<primes[0]<<endl;
    calcuPF();
    int t,a,b,l;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&a,&b);
        pf("%I64d\n",sm[a]-sm[b]);
    }
    return 0;
}

