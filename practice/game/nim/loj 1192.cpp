//Bismillahir Rahmanir Rahim
//Opu-1204026
//.004
//simple, only check that the game is now strategy or not by xor;
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




int main()
{
    int t,z,an,x,y,k;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&k);
        an=0;
        while(k--)
        {
            sf("%d%d",&x,&y);
            an=an^(y-x-1);
        }
        if(an)pf("Case %d: Alice\n",z);
        else pf("Case %d: Bob\n",z);

    }

    return 0;
}

