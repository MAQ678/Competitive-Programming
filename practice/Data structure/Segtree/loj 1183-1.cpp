//Bismillahir Rahmanir Rahim
//Opu-1204026
//.0352
//hack 1: if we want to update value 0 to the node... here we always have to update on lazy, not increment
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
    int v,la;
}tr[1<<20];

void up(int r,int s,int e,int L,int R,int val)
{
    int z=r<<1;
    if(tr[r].la>-1)
    {
        tr[r].v=tr[r].la*(e-s+1);
        if(s!=e)
        {
            tr[z].la=tr[r].la;tr[z+1].la=tr[r].la;
        }
        tr[r].la=-1;
    }
    if(s>R||e<L)return;
    if(s>=L&&e<=R)
    {
        tr[r].v=val*(e-s+1);
        if(s!=e)
        {
            tr[z].la=val;tr[z+1].la=val;
        }
        return;
    }
    int mid=(s+e)>>1;
    up(z,s,mid,L,R,val);up(z+1,mid+1,e,L,R,val);
    tr[r].v=tr[z].v+tr[z+1].v;
}
void init(int r,int s,int e)
{
    int z=r<<1;
    tr[r].v=0,tr[r].la=-1;
    if(s==e)return;
    int mid=(s+e)>>1;
    init(z,s,mid);init(z+1,mid+1,e);
}

int query(int r,int s,int e,int L,int R)
{
    int z=r<<1;
    if(tr[r].la>-1)
    {
        tr[r].v=tr[r].la*(e-s+1);
        if(s!=e)
        {
            tr[z].la=tr[r].la;tr[z+1].la=tr[r].la;
        }
        tr[r].la=-1;
    }
    if(s>R||e<L)return 0;
    if(s>=L&&e<=R)
    {
        return tr[r].v;
    }
    int mid=(s+e)>>1;
    return query(z,s,mid,L,R)+query(z+1,mid+1,e,L,R);
}

int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}

int main()
{
    int t,z,n,v,i,j,q,c,l,r,sm,m,an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&q);
        init(1,0,n-1);
        pf("Case %d:\n",z);
        while(q--)
        {
            sf("%d",&c);
            if(c==1)
            {
                sf("%d%d%d",&l,&r,&v);
                up(1,0,n-1,l,r,v);
            }
            else
            {
                sf("%d%d",&l,&r);
                sm=query(1,0,n-1,l,r);
                m=gcd(sm,r-l+1);
                an=(r-l+1)/m;
                if(an==1)pf("%d\n",sm/m);
                else pf("%d/%d\n",sm/m,an);
            }
        }
    }
    return 0;
}
