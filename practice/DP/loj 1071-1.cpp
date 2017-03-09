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

int n,m;
int a[105][105];
int dp[105][105][105][3];

/*
int fun1(int i,int j,int k,int mode)
{
    if(j>(m-1)||k>m||i>n||j==k)return -inf;
    if(i==n&&j==m-1&&k==m)return a[i][j]+a[i][k];
    if(dp[i][j][k][mode]!=-1)return dp[i][j][k][mode];
    int an=0;
   // an=fun(i+1,j,k);
   an=fun1(i+1,j,k,0)+a[i][j]+a[i][k];
   if(mode!=1)an=max(an,fun1(i,j,k+1,2)+a[i][k]);
   if(mode!=2)an=max(an,fun1(i,j+1,k,1)+a[i][j]);

    return dp[i][j][k][mode]=an;

}
*/
int fun(int i,int j,int k)
{
    if(j>(m-1)||k>m||i>n||j==k)return -inf;
    if(i==n&&j==m-1&&k==m)return a[i][j]+a[i][k];
    int an=0;
    an=fun(i+1,j,k)+a[i][j]+a[i][k];
   // if(i+1>n)an=max(an,max(fun(i,j+1,k),fun(i,j,k+1)));
    //else
    if(i+1<=n)
    {
        if(j+1<m)
            an=max(an,fun(i+1,j+1,k)+a[i][j+1]+a[i][j]);
        if(k+1<=m)
        an=max(an,fun(i+1,j,k+1)+a[i][k+1]+a[i][k]);
       // an=max(an,max(fun(i+1,j+1,k)+a[i][j+1],fun(i+1,j,k+1)+a[i][k+1]));//check j+1 ,k+1
    }
    if(k==m)
        an=max(an,fun(i,j+1,k)+a[i][j]);
    return an;
}

int main()
{
    int t,z,i,j;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr1(i,n)fr1(j,m)sf("%d",&a[i][j]);
        ms(dp,-1);
        pf("%d\n",fun(1,1,2));
    }
    return 0;
}

