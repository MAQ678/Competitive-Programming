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
#define sp      cout<<fixed<<setprecision(10)
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

ll a[100005];
stack<ll>s;
int main()
{
    ll n,t,i,mx,pvt,z,sm,zz;
    sf("%lld",&t);
    fr1(z,t)
    {
        sf("%lld",&n);
        fr(i,n)sf("%lld",&a[i]);

        mx=0;
        fr(i,n)
        {
            if(!s.size()||a[s.top()]<=a[i])s.push(i);
            else
            {
                pvt=s.top();
                while(s.size()&&a[s.top()]>a[i])
                {
                    sm=a[s.top()]*(pvt-s.top()+1);

                    zz=s.top();
                    s.pop();
                    if(s.size())sm+=a[zz]*(zz-s.top()-1);
                    else
                    {
                        if(zz>0)sm+=a[zz]*zz;
                    }
                    mx=max(mx,sm);
                }
                s.push(i);
            }
        }
        if(s.size())
        pvt=s.top();
        while(s.size())
        {
            sm=a[s.top()]*(pvt-s.top()+1);

            zz=s.top();
            s.pop();
            if(s.size())sm+=a[zz]*(zz-s.top()-1);
            else
            {
                if(zz>0)sm+=a[zz]*zz;
            }
            mx=max(mx,sm);
        }
        pf("Case %lld: %lld\n",z,mx);
    }
}

