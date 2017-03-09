//Bismillahir Rahmanir Rahim
//Opu-1204026
//O(nlog n)//update version of loj 1076
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

int n,k,a[1005];

bool isPossible(int val)
{
    int i,cn=0,sm=0;
    fr(i,n)
    {
        if(cn+a[i]>=val)
        {
            sm++;
            if(cn+a[i]==val)
            {
                cn=0;
                if(sm+(n-i)<=k)return 1;
            }
            else
            {
                cn=a[i];
                if(sm+(n-i)+1<=k)return 1;
            }
        }
        else cn+=a[i];
    }
    if(cn)sm++;
    if(sm<=k)return 1;
    else return 0;
}

int main()
{
    int t,z,i,j,lo,hi,mid,an,cn,sm;
    bool w;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&k);
        n++;
        k++;
        lo=0;
        hi=0;
        fr(i,n)sf("%d",&a[i]),lo=max(lo,a[i]),hi+=a[i];
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            if(isPossible(mid))
            {
                an=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        pf("Case %d: %d\n",z,an);
        //print solution
        cn=0;w=0;sm=0;
        fr(i,n)
        {
            if(w==1)
            {
                pf("%d\n",a[i]);
                continue;
            }
            if(cn+a[i]>=an)
            {
                sm++;
                if(cn+a[i]==an)
                {
                    pf("%d\n",cn+a[i]);
                    cn=0;
                }
                else
                {
                    pf("%d\n",cn);
                    cn=a[i];
                }
            }
            else cn+=a[i];
            if(sm+(n-i)==k)
            {
                if(cn)pf("%d\n",cn);
                w=1;
                continue;
            }
        }
        if(!w&&cn)pf("%d\n",cn);
    }
    return 0;
}

