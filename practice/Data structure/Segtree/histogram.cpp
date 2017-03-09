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
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct st
{
    int v,in;
}a[100000];

bool cmp(st x,st y)
{
    return x.v>y.v;
}
struct sst
{
    int v,mv,lv,rv;
};

void up(int n,int s,int e,int p,int v)
{
    if(s>p||e<p)return;
    if(s==e)
    {
        tr[n].v=tr[n].mv=tr[n].lv=tr[n].rv=v;
        return;
    }
    int mid=(s+e)>>1,l=n*2,r=l+1;
    up(l,s,mid,p,v);up(r,mid+1,e,p,v);
    int v1=min(tr[l].mv,tr[r].mv),v2=v1*(e-s+1);
    if(v2>tr[l].v&&v2>tr[r].v)
    {
        tr[n].v=v2;tr[n].mv=v1;
        tr[n].lv=tr[l].lv;tr[n].rv=tr[r].rv;
    }
    else
    {
        if(tr[l].v>tr[r].v)
        {
            tr
        }
    }



}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int n,i;
   cin>>n;
   fr(i,n)cin>>a[i].v,a[i].in=i;
   sort(a,a+n,cmp);

    fr(i,n)
    {
        up(1,0,n-1,a[i].in,a[i].v);
    }


    return 0;
}

