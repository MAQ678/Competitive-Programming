//Bismillahir Rahmanir Rahim
//Opu-1204026
//using fast I/O
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

typedef unsigned int u32;
#define BUF 65536
struct Reader {
    char buf[BUF]; char b; int bi, bz;
    Reader() { bi=bz=0; read(); }
    void read() {
        if (bi==bz) { bi=0; bz = fread(buf, 1, BUF, stdin); }
        b = bz ? buf[bi++] : 0; }
    void skip() { while (b > 0 && b <= 32) read(); }
    u32 next_u32() {
        u32 v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
};

struct st
{
    int l,r,v,in,an;
} p[200005];
struct zt
{
    int v,in;
} a[30005];
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

int tr[1<<20]={0};
void up(int r,int s,int e,int pos)
{
    //if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r]=1;
        return;
    }
    int mid=(s+e)>>1,z=r<<1;
    if(mid>=pos)
    up(z,s,mid,pos);
    if(mid+1<=pos)
    up(z+1,mid+1,e,pos);
    tr[r]=tr[z]+tr[z+1];
}

int query(int r,int s,int e,int L,int R)
{
    //if(s>R||e<L)return 0;
    if(s>=L&&e<=R)return tr[r];
    int mid=(s+e)>>1,an=0,z=r<<1;;
    if(mid>=L)an=query(z,s,mid,L,R);
    if(mid+1<=R)an+=query(z+1,mid+1,e,L,R);
    return an;
    //return query(r*2,s,mid,L,R)+query(r*2+1,mid+1,e,L,R);
}
int main()
{
    Reader rr;
    int n,i,j,q,v;
   // sf("%d",&n);
   n=rr.next_u32();
    fr(i,n)
    {
        v=rr.next_u32();
       // sf("%d",&v);
        a[i].v=v;
        a[i].in=i;
    }
    q=rr.next_u32();
   // sf("%d",&q);
    fr(i,q)
    {
        //sf("%d%d%d",&p[i].l,&p[i].r,&p[i].v);
        p[i].l=rr.next_u32();
        p[i].r=rr.next_u32();
        p[i].v=rr.next_u32();

        p[i].in=i;
    }
    sort(p,p+q,cmp);
    sort(a,a+n,cmp1);
    j=0;
   // init(1,0,n-1);
    fr(i,q)
    {
        while(j<n&&a[j].v>p[i].v)
        {
            up(1,0,n-1,a[j].in);
            j++;
        }
        p[i].an=query(1,0,n-1,p[i].l-1,p[i].r-1);
    }
    sort(p,p+q,cmp2);
    fr(i,q)pf("%d\n",p[i].an);
    return 0;
}


