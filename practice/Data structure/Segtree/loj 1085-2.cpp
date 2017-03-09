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
int md=1000000007;
struct st
{
    int val,in;
}a[1<<20];

bool cmp(st x,st y)
{
    if(x.val<y.val)return true;
    else if(x.val==y.val)return x.in>y.in;
    return false;
}
int tr[1<<20];
void init(int r,int s,int e)
{
    if(s==e)
    {
        tr[r]=0;
        return;
    }
    int mid=(s+e)>>1;
    init(r*2,s,mid);init(r*2+1,mid+1,e);
    tr[r]=0;
}
void up(int r,int s,int e,int val,int pos)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r]=val;
        return;
    }
    int mid=(s+e)>>1;
    up(r*2,s,mid,val,pos);up(r*2+1,mid+1,e,val,pos);
    tr[r]=(tr[r*2]%md+tr[r*2+1]%md)%md;
}

int query(int r,int s,int e,int pos)
{
    if(s>pos)return 0;
    if(e<=pos)return tr[r];
    int mid=(s+e)>>1;
    return (query(r*2,s,mid,pos)%md+query(r*2+1,mid+1,e,pos)%md)%md;
}

int main()
{
    int t,z,i,j,n,mx;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr(i,n)sf("%d",&a[i].val),a[i].in=i;
        sort(a,a+n,cmp);
        init(1,0,n-1);
        fr(i,n)
        {
            mx=query(1,0,n-1,a[i].in-1);
            up(1,0,n-1,(mx+1)%md,a[i].in);
        }
        pf("Case %d: %d\n",z,tr[1]);
    }
}
