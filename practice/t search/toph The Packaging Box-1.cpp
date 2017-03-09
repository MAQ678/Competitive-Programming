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

int main()
{
    _; ct;
    int t,i;
    double p,q,r,v,an1,an2,lo,hi,m1,m2,w=2.0/3.0,w1=1.0/3.0;
    cin>>t;
    while(t--)
    {

        cin>>p>>q>>r>>v;
        sp(9);
        lo=0.00001;
        hi=1000000000000000000;
        fr(i,5000)
        {
            m1=lo+(hi-lo)*w1;
            m2=lo+(hi-lo)*w;

            an1=m1*(p+r)+((4*q*v*sqrt(m1))/m1);
            an2=m2*(p+r)+((4*q*v*sqrt(m2))/m2);
            if(an1>an2+eps)lo=m1;
            else hi=m2;
        }
        cout<<an1;
        nl;

    }
    return 0;
}

