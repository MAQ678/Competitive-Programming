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

int gcd(int a,int b)
{
    return b==0?a :gcd(b,a%b);
}

int makeB(int z,string s)
{
    int an=0;
    int l,i,j,v;
    l=s.length();
    l--;
    i=0;
    while(l--)
    {
        v=s[i]-'0';
        an=(an%z+(v*10)%z)%z;
        i++;
    }
    v=s[i]-'0';
    an=(an%z+v%z)%z;
    return an;

}

int main()
{
    _;ct;

    string b,aa;
    stringstream ss;
    int t,z;
    int a,bb,lb;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ss<<a;
        ss>>aa;
        ss.clear();
        if(aa<b)z=a;
        else
        {
            z=0;
//            ss<<b;
//            ss>>bb;
//            ss.clear();
//            z=a%bb;
        }
        if(z==0)
        {
            cout<<a;
            nl;
            continue;
        }


        lb=makeB(z,b);
        cout<<gcd(z,lb);
        nl;
    }

    return 0;
}
