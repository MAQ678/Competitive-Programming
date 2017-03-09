//Bismillahir Rahmanir Rahim
//Opu-1204026
//0.004
//think a bit that actual move needs only the path between two pawn
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


int a[2][102];

int main()
{
    int t,z,n,i,an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr(i,n)sf("%d",&a[0][i]);
        fr(i,n)sf("%d",&a[1][i]);
        an=0;
        fr(i,n)
        {
            an=an^(a[1][i]-a[0][i]-1);
        }
        if(an)pf("Case %d: white wins\n",z);
        else pf("Case %d: black wins\n",z);
    }
    return 0;
}

