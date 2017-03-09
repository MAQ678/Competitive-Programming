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

int a[101][101],dp[101][101],pr[101][101],n,m;

int fun(int i,int j)
{
    if(i==n-1&&j==m-1)return dp[i][j]=a[i][j];
    if(i>=n||j>=m)return -inf;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=a[i][j]+max(fun(i+1,j),fun(i,j+1));
}

int fun1(int i,int j)
{
    if(i==0&&j==0)return 0;

    if(i<0||j<0||a[i][j]<0)return -inf;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=a[i][j]+max(fun1(i-1,j),fun1(i,j-1));
}

int main()
{
    int t,z,i,j,an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,n)fr(j,m)sf("%d",&a[i][j]);
        ms(dp,-1);
        an=fun(0,0);
      //  cout<<an;nl;
        i=0,j=0;
        while(1)
        {
            if(dp[i][j]-a[i][j]==dp[i+1][j]&&i!=n-1)
            {
                if((i==0&&j==0)||(i==n-1&&j==m-1))
                {
                    a[i][j]=0;
                }
                else
                a[i][j]=-1;
                i++;
            }
            else
            {
                if((i==0&&j==0)||(i==n-1&&j==m-1))
                {
                     a[i][j]=0;
                }
                else
                a[i][j]=-1;
                j++;
            }
            if(i==n-1&&j==m-1)
            {
                a[i][j]=0;
                break;
            }
        }

        fr(i,n)
        {
            fr(j,m)
            {
                cout<<a[i][j]<<" ";
            }
            nl;
        }

        ms(dp,-1);
        an+=fun1(n-1,m-1);
        cout<<an;nl;
        fr(i,n)
        {
            fr(j,m)
            {
                cout<<dp[i][j]<<" ";
            }
            nl;
        }

    }
    return 0;
}
