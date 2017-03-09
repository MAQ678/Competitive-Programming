//Bismillahir Rahmanir Rahim
//Opu-1204026
//O(nlog n)
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


int a[1005],n,m;

bool isPossible(int val)
{
    int i,cn=0,sm=0;
    fr(i,n)
    {
        if(cn+a[i]>=val)
        {

            if(cn+a[i]==val)cn=0;
            else
            {
                cn=a[i];
            }
            sm++;
        }
        else cn+=a[i];
    }
    if(cn!=0)sm++;
    if(sm>m)return 0;
    return 1;
}

int main()
{
    int t,z,i,j,cn,lo,hi,mid,mx,an;
    sf("%d",&t);
    fr1(z,t)
    {
        cn=0,mx=0;
        sf("%d%d",&n,&m);
        fr(i,n)sf("%d",&a[i]),cn+=a[i],mx=max(mx,a[i]);

        lo=cn/mx;
        if(lo*mx<cn)lo++;
        mx=max(mx,lo);
        lo=mx,hi=cn;an=0;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            if(isPossible(mid))
            {
                an=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        pf("Case %d: %d\n",z,an);
    }
    return 0;
}

