//Bismillahir Rahmanir Rahim
//Opu-1204026
//.464
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

struct st
{
    int x,y;
}p[100005];
int tr[1<<20],ck[1<<20],cn;

void init(int r,int s,int e)
{
    tr[r]=0;
    if(s==e)return;
    int mid=(s+e)>>1;
    init(r*2,s,mid);init(r*2+1,mid+1,e);
}

void up(int r,int s,int e,int L,int R,int val)
{
    if(tr[r])
    {
        if(s!=e)tr[r*2]=tr[r],tr[r*2+1]=tr[r],tr[r]=0;
    }
    if(s>R||e<L)return;
    if(s>=L&&e<=R)
    {
        if(s!=e)tr[r*2]=val,tr[r*2+1]=val;
        else tr[r]=val;
        return;
    }
    int mid=(s+e)>>1;
    up(r*2,s,mid,L,R,val);up(r*2+1,mid+1,e,L,R,val);
}

void query(int r,int s,int e)
{
    if(tr[r])
    {
        if(!ck[tr[r]])
        {
            ck[tr[r]]=1;
            cn++;
        }
        return;
    }
    if(s==e)return;
    int mid=(s+e)>>1;
    query(r*2,s,mid);query(r*2+1,mid+1,e);
}

int main()
{
    int t,z,n,i,j,mx;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        mx=0;
        fr(i,n)
        {
            sf("%d%d",&p[i].x,&p[i].y);
            mx=max(mx,p[i].y);
        }
        init(1,0,mx);
        fr(i,n)
        {
            up(1,0,mx,p[i].x,p[i].y,i+1);
        }
        ms(ck,0);
        cn=0;query(1,0,mx);
        pf("Case %d: %d\n",z,cn);
    }
    return 0;
}

