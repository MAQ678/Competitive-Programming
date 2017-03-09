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

struct st
{
    int l,r,v,in,an;
} p[200005];
struct zt
{
    int v,in;
} a[30005];
//vector<ii>a;
//vi nd;
bool cmp(st x,st y)
{
    return x.v>y.v;
}
bool cmp1(zt x,zt y)
{
    return x.v>y.v;
}
bool cmp2(st x,st y)
{
    return x.in<y.in;
}

int tr[1<<20];
void up(int r,int s,int e,int pos)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r]=1;
        return;
    }
    int mid=(s+e)>>1;
    up(r*2,s,mid,pos);
    up(r*2+1,mid+1,e,pos);
    tr[r]=tr[r*2]+tr[r*2+1];
}

int query(int r,int s,int e,int L,int R)
{
    if(s>R||e<L)return 0;
    if(s>=L&&e<=R)return tr[r];
    int mid=(s+e)>>1;
    return query(r*2,s,mid,L,R)+query(r*2+1,mid+1,e,L,R);
}
int main()
{
    int n,i,j,q,N,v,lo,hi,mid,r;
   // map<int,int>m;
   // nd.clear();
    sf("%d",&n);
    fr(i,n)
    {
        sf("%d",&v);
//        if(!pr(m,v))
//        {
//            m[v]=1;
//            nd.pb(v);
//        }
        a[i].v=v;
        a[i].in=i;
    }
    sf("%d",&q);
    fr(i,q)
    {
        sf("%d%d%d",&p[i].l,&p[i].r,&p[i].v);
//        if(!pr(m,p[i].v))
//        {
//            m[p[i].v]=1;
//            nd.pb(p[i].v);
//        }
        p[i].in=i;
    }
/*
    sort(all(nd));
    m.clear();
    fr(i,nd.size())m[nd[i]]=i;
    N=nd.size()-1;
    fr(i,n)a[i].v=m[a[i].v];
    fr(i,q)p[i].v=m[p[i].v];
*/
    //compression complete and tree size will be N
    sort(p,p+q,cmp);
    sort(a,a+n,cmp1);
    j=0;
    fr(i,q)
    {
        while(j<n&&a[j].v>p[i].v)
        {
            up(1,0,n-1,a[j].in);
            j++;
        }
        p[i].an=query(1,0,n-1,p[i].l-1,p[i].r-1);
    }

    /*
    sort(a,a+n,cmp1);//ascending
    r=n-1;
    ms(tr,0);
    fr(i,q)
    {
        lo=0,hi=r,
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            if(a[mid].v>=p[i].v+1)hi=mid-1;
            else lo=mid+1;
        }
        if(a[mid].v<=p[i].v)
        {
            mid++;
        }
        for(j=mid; j<=r; j++)
        {
            up(1,0,N,a[j].in);
        }
        p[i].an=query(1,0,N,p[i].l-1,p[i].r-1);
    }
    */
    sort(p,p+q,cmp2);
    fr(i,q)pf("%d\n",p[i].an);
    return 0;
}

