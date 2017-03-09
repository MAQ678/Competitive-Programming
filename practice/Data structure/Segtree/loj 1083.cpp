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

int a[30005],tr[200000],trr[200000];

void init(int n,int s,int e)
{
    if(s==e)
    {
        tr[n]=trr[n]=a[s];return;
    }
    int mid=(s+e)>>1;
    init(n<<1,s,mid);init((n<<1)|1,mid+1,e);
    tr[n]=min(tr[n<<1],tr[(n<<1)|1]);
    trr[n]=max(trr[n<<1],trr[(n<<1)|1]);
}

int get(int n,int s,int e,int l,int r,int d,int va)
{
    if(s>r||e<l)return 0;
    if(s>=l&&e<=r)
    {
        if(tr[n]>=va)
            return (e-s+1);
        if(trr[n]<va)
            return 0;
    }
    int mid=(s+e)>>1,p=0;
    if(d==1)
    {
      //  p=get(n<<1,s,mid,l,r,d,va);
        p=get((n<<1)|1,mid+1,e,l,r,d,va);
        if(p==max(min(e,r)-mid,0))
        {
            p+=get(n<<1,s,mid,l,r,d,va);
        }
    }
    else
    {
        p=get(n<<1,s,mid,l,r,d,va);

        if(p==max(0,mid-max(s,l)+1))
        {
            p+=get((n<<1)|1,mid+1,e,l,r,d,va);
        }
    }
    return p;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

    int n,t,z,i,an,sm;
    sf("%d",&t);
    fr1(z,t)
    {

    sf("%d",&n);
    fr(i,n)sf("%d",&a[i]);
    init(1,0,n-1);
    an=0;
    fr(i,n)
    {
        sm=0;
        if(i)sm=get(1,0,n-1,0,i-1,1,a[i]);
        if(i+1<n)sm+=get(1,0,n-1,i+1,n-1,2,a[i]);
        sm++;
        an=max(an,sm*a[i]);
    }
    pf("Case %d: %d\n",z,an);

    }
    return 0;
}

