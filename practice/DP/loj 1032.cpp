//0.012
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

ll dp[2][33];
int n=31;

ll fun(int b,int i)
{
    if(i>n-1)return 0;
    if(i>=0&&dp[b][i]!=-1)return dp[b][i];
    ll an=0;
    if(b==0||i<0)an=fun(1,i+1);
    else an=fun(1,i+1)+(1<<(n-i-1));
    an=an+fun(0,i+1);
    return dp[b][i]=an;
}

int main()
{
    int t,z,v,cn,i,b,wn;
    ll an;
    string s;
    ms(dp,-1);
    fun(0,0);
   // cout<<dp[0][0]<<endl;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&v);
        s="";cn=0;
        while(v)
        {
            cn++;
            if(v&1)s+='1';
            else s+='0';
            v>>=1;
        }
       // cout<<s<<endl;
        while(cn<=31)s+='0',cn++;
        reverse(all(s));
       // cout<<s<<endl;
        an=0,wn=0;
        fr1(i,30)
        {
            if(s[i]=='1')
            {
               // cout<<i<<"gg",nl;
                an+=dp[0][i];//cout<<dp[0][i],nl;
                an+=((1<<(n-i))*wn);
                //cout<<((1<<(n-i))*wn)<<" ww ",nl;
            }
            if(i&&s[i]==s[i-1]&&s[i]=='1')
            {
                wn++;
            }
        }
        //nl;
        //cout<<i<<endl;
        if(s[i]=='1')
        {
            an+=wn*2;
            if(s[i]==s[i-1])
            {
                an++;
            }
        }
        else an+=wn;
        //an+=wn;
        pf("Case %d: %lld\n",z,an);
    }
}
