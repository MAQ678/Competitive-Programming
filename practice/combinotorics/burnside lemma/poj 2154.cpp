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

int p[10000005],md;
bool ip[100000];
vector<int> pr,f;
void phi(int n)
{
    int i,j;
    fr1(i,n)p[i]=i;
    for(i=2;i<=n;i++)
    {
        if(p[i]==i)
        for(j=i;j<=n;j+=i)
            p[j]-=p[j]/i;
    }

}

void sieve(int n)
{
    int i,j;
    fr(i,n+1)ip[i]=1;
    for(i=2;i*i<=n;i++)
    {
        if(ip[i])
        {

            for(j=i;j*i<=n;j++)
            {
                ip[i*j]=0;
            }
        }
    }
    pr.clear();
    for(i=2;i<=n;i++)
    {
        if(ip[i])pr.pb(i);
    }
}
void factor(int n)
{
    int i;
    f.pb(n);
    if(n!=1)f.pb(1);
    for(i=0;pr[i]*pr[i]<=n;i++)
    {
        if(n%pr[i]==0)
        {
            f.pb(pr[i]);
            while(n%pr[i]==0)
            {
                if(n/pr[i]!=pr[i]&&n/pr[i]>1)f.pb(n/pr[i]);
                n/=pr[i];
            }
        }

    }
    if(n>1&&n!=f[0])f.pb(n);
}

int get(int n)
{
    if(n<=10000000)return p[n];
    int an=n,i;
    for(i=0;pr[i]*pr[i]<=n;i++)
    {
        if(n%pr[i]==0)
        {
            while(n%pr[i]==0)n/=pr[i];
            an-=an/pr[i];
            if(n<=1)return an;
        }
    }
    if(n>1)an-=an/n;
    return an;
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
    //freopen("F:\\Coding\\in.txt","r",stdin);
        //freopen("F:\\Coding\\out.txt","w",stdout);
    phi(10000000);
    sieve(32000);
   // cout<<pr.size()<<endl;
        int x,n,an,i,w;
      //  fr(i,pr.size())cout<<pr[i]<<" ";nl;
    sf("%d",&x);
    while(x--)
    {
        sf("%d%d",&n,&md);
        an=0;
        f.clear();
        factor(n);

        fr(i,f.size())
        {
         //   cout<<f[i]<<" ";
           // cout<<get(f[i])<<" "<<bigmod(n,(n/f[i])-1);nl;
            an=(an+get(f[i])*bigmod(n,(n/f[i])-1))%md;
        }
       // nl;
        pf("%d\n",an);
    }
    return 0;
}

