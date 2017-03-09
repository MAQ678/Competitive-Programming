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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

int d[15][15],v[1<<15],n,dp[1<<15];

int get(int m)
{
    if(m==(1<<n)-1)return 0;
    if(dp[m]!=-1)return dp[m];
    int j,an=inf,w=(1<<n)-1;
    w=w^m;
    for(j=w;j;j=(j-1)&w)
    {
        an=min(an,v[j]+get(m|j));
    }
    return dp[m]=an;
}
int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);

    int t,j,i,z,an,k;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr(i,n)fr(j,n)sf("%d",&d[i][j]);

        for(i=0;i<(1<<n);i++)
        {
            v[i]=0;
            fr(j,n)
            {
                if(i&(1<<j))
                {
                    fr(k,n)
                    if(i&(1<<k))v[i]+=d[j][k];
                }
            }
        }
        ms(dp,-1);
        an=get(0);
        pf("Case %d: %d\n",z,an);
    }

    return 0;
}

