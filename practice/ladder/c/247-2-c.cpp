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

int k,d,n;
int md=1000000007 ;
int dp[110][2];

int fun(int t,int c)
{
    if(t==n&&c)return 1;
    if(t>=n)return 0;
    if(dp[t][c]!=-1)return dp[t][c];
    int i,an=0;
    fr1(i,k)
    {
        if(i>=d)an=(an+fun(t+i,1)%md)%md;
        else an=(an+fun(t+i,c)%md)%md;
    }
    return dp[t][c]=an;
}

int main()
{
    sf("%d%d%d",&n,&k,&d);
    ms(dp,-1);
    pf("%d\n",fun(0,0));

    return 0;
}

