//Bismillahir Rahmanir Rahim
//Opu-1204026
//.876
//has work to do with mod smartly, cause (16^15)*15 is an overflow
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

string s;
ll dp[1<<17][21];
vl v;
int n;
ll k;
ll b;
ll pow(int cn)
{
    ll z=1;
    while(cn--)
    {
        z=z*b;
    }
    return z;
}

ll fun(int mask,ll val)
{
    if(mask==(1<<n)-1)
    {
        //cout<<val<<" K ";
        if((val+k)%k==0)return 1;
       // cout<<val<<" ";
        return 0;
    }
   // if(cn>=n)return 0;
    if(dp[mask][val]!=-1)return dp[mask][val];
    int i;
    ll an=0,bn;
    int cn=0;
    fr(i,n)if(mask&(1<<i))cn++;
    fr(i,n)
    {
        if(!(mask&(1<<i)))
        {
            bn=pow(cn)%k;
            bn=(bn*v[i]+k)%k;
            an=an+fun((mask|(1<<i)),(bn+val+k)%k);
        }
    }
    return dp[mask][val]=an;
}

int main()
{
   // _;ct;
    int t,z,i;
    cin>>t;
    fr1(z,t)
    {
        cin>>b>>k;
        cin>>s;

        n=s.length();
        v.clear();
        fr(i,n)
        {
            if(s[i]>='0'&&s[i]<='9')v.pb(s[i]-'0');
            else
            {
                v.pb((s[i]-'A')+10);
            }
        }
       // fr(i,n)cout<<v[i]<<" ";
       // nl;
        ms(dp,-1);
        cout<<"Case "<<z<<": ";
        cout<<fun(0,0);nl;

    }
    return 0;
}

