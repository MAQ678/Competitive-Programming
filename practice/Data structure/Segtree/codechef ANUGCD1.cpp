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
int a[1<<20];
struct st
{
    int id,g,x,y;
    bool operator < (const st& b)const
    {
        return y!=b.y?y<b.y:x<b.x;
    }
};
int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349};
//70
int tr[70][1<<19],sm[70][1<<19];

int main()
{
    int n,m,i,s,e,v,j;
    sf("%d%d",&n,&m);
    fr(i,n)sf("%d",&a[i]);
    fr(i,m)sf("%d%d%d",&b[i].g,&b[i].x,&b[i].y),b[i].x--,b[i].y--,b[i].in=i;
    sort(b,b+m);
    s=0;
    fr(i,m)
    {
        while(s<=b[i].y)
        {
            v=a[s];
            fr(j,70)
            {
                if(v>=pr[j])
                {
                    if(v%pr[j]==0)
                    {
                        while(v%pr[j]==0)v/=pr[j];
                    }
                }
                else break;
            }
        }
    }
    return 0;
}

