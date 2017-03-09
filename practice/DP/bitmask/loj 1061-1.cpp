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
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
struct st
{
    int y[8];
}w[500];

int c[10],cn;

bool check(int x,int y)
{
    int j;
    fr(j,y)
    {
        if(c[j]==x||abs(c[j]-x)==abs(j-y))return 0;
    }
    return 1;
}

void get(int k)
{
    int i;
    if(k>=8)
    {
        fr(i,8)w[cn].y[i]=c[i];
        cn++;
        return;
    }
    fr(i,8)
    {
        if(check(i,k))
        {
            c[k]=i;
            get(k+1);
            c[k]=0;
        }
    }
}
char ch[10][10];
int x[8],y[8];

int dis(int i,int j,int k)
{
    int x1=j,y1=w[i].y[j];
    return abs(j-x[k])+abs(w[i].y[j]-y[k]);
}
int dp[1<<8];
int fun(int i,int mask)
{
    if(mask==(1<<8)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int j,an=inf,k=0;
    fr(j,8)if(mask&(1<<j))k++;
    fr(j,8)
    {
        if(!(mask&(1<<j)))
        {
            an=min(an,fun(i,mask|(1<<j))+dis(i,j,k));
        }
    }
    return dp[mask]=an;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   cn=0;ms(c,0);
   get(0);
   cout<<cn<<endl;
   int i,t,z,j,wn,an;
    sf("%d",&t);
    fr1(z,t)
    {
        fr(i,8)sf("%s",ch[i]);
        wn=0;
        fr(i,8)
        {
            fr(j,8)
            {
                if(ch[i][j]=='q')x[wn]=i,y[wn]=j,wn++;
            }
        }
        an=inf;
        fr(i,cn)
        {
            ms(dp,-1);
            an=min(an,fun(i,0));
        }
        cout<<an<<endl;
    }


    return 0;
}

