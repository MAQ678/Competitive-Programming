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

int d;
int s[31],e[31];
int possible(int i,int sm)
{
    if(sm==0&&i==d)return 1;
    if(sm<0||i==d)return 0;
    int an=0;
    for(int k=s[i];k<=e[i];k++)
    {
        an=an|possible(i+1,sm-k);
    }
    return an;
}

int main()
{
    int sm;
    int i,j;
    sf("%d%d",&d,&sm);
    fr(i,d)sf("%d%d",&s[i],&e[i]);
    if(possible(0,sm))
    {
        pf("YES\n");
    }
    else pf("NO\n");
    return 0;
}

