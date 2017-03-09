//Bismillahir Rahmanir Rahim
//Opu-1204026
//63ms
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<sstream>
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


ll get(ll n)
{
    ll sm=0,v,w;
    sm=n*(n+1)/2;
        v=n/10;w=10;
        while(v)
        {
            sm+=((n-w+1)*(n-w+2))/2;
            w*=10;
            v=v/10;
        }
    return sm;
}

ll fun(ll n)
{
    ll lo,hi,mid,v,w;
    w=n;
    lo=1;hi=32000;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            v=get(mid);
            if(v>n)hi=mid-1;
            else lo=mid+1;
        }
        while(get(mid+1)<=n)mid++;
        if(get(mid)>n)mid--;
        return mid;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    int t;
    stringstream ss;
    string s;
    ll n,w,v,i;
    sf("%d",&t);
    while(t--)
    {
        sf("%lld",&n);
        w=fun(n);
        v=n-get(w);
        if(v>0)
        fr1(i,32000)
        {
            ss<<i;
            ss>>s;
            ss.clear();
            v-=s.length();
            if(v<=0)
            {
                v+=s.length();
                pf("%c\n",s[v-1]);
                break;
            }
        }
        else pf("%lld\n",w%10);
       /* if(v>0)
        {
            w=fun(v);
            v=n-get(w);
        }
        if(v==0)
        {
            pf("%d\n",w%10);
        }
        else
        {
            w++;
            ss<<w;
            ss>>s;
            ss.clear();
            cout<<v<<endl;
            v=s[v-1]-'0';
            pf("%d\n",v);
        }
        */
    }
    return 0;
}

