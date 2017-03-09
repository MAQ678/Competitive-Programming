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

ll make(ll a)
{
    ll sm1,la1,z1,cn,ra1,w;
     sm1=0;
        la1=1;cn=0;
        ra1=0;
        if(a>=0)sm1=1;
        while(a>0)
        {
            z1=a%10;
            a=a/10;
            sm1+=a*la1;
           // cout<<sm1<<" dd";nl;

            //exclusion part
            if(z1==0&&cn)
            {
                sm1-=(la1-ra1-1);
                //cout<<(la1-ra1-1)<<" ff";nl;
            }
            cn++;
            la1*=10;
            ra1=ra1*10+z1;
        }
        return sm1;
}


int main()
{
    //cout<<make(200)<<endl;
    ll t,z,a,b;
    sf("%lld",&t);
    fr1(z,t)
    {
        sf("%lld%lld",&a,&b);
        a--;
        a=make(a);
       // cout<<a<<endl;
        b=make(b);
       // cout<<b<<endl;
        pf("Case %lld: %lld\n",z,b-a);



    }
    return 0;
}

