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

int a[2001][2001],b[2001][2001],tr[20000],trr[20000];
char ch[2001][2001];

void init(int n,int s,int e,int p)
{
    if(s==e)
    {
        tr[n]=trr[n]=b[p][s];
        return;
    }
     int mid=(s+e)>>1;
    init(n<<1,s,mid,p);init((n<<1)|1,mid+1,e,p);
    tr[n]=min(tr[n<<1],tr[(n<<1)|1]);
    trr[n]=max(trr[n<<1],trr[(n<<1)|1]);
}

int get(int n,int s,int e,int l,int r,int d,int val)
{
    if(s>r||e<l)return 0;
    if(s>=l&&e<=r)
    {
        if(tr[n]>=val)return (e-s+1);
        if(trr[n]<val||s==e)return 0;
    }
    int mid=(s+e)>>1,p=0;
    if(d==1)
    {
        p=get((n<<1)|1,mid+1,e,l,r,d,val);
        if(p==min(e,r)-mid||(min(e,r)-mid)<0)
            p+=get(n<<1,s,mid,l,r,d,val);
    }
    else
    {
        p=get(n<<1,s,mid,l,r,d,val);
        if(p==mid-max(s,l)+1||(mid-max(s,l)+1)<0)
            p+=get((n<<1)|1,mid+1,e,l,r,d,val);
    }
    return p;
}
int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int i,j,n,m,t,an,sm,z;
 //  Reader rr;
  // t=rr.next_u32();
   sf("%d",&t);
   fr1(z,t)
   {
     //  n=rr.next_u32();m=rr.next_u32();
       sf("%d%d",&n,&m);
       fr(i,n)sf("%s",ch[i]);
       //fr(i,n)fr(j,m)a[i][j]=ch[i][j]-'0';
       for(j=m-1;j>=0;j--)
       for(i=n-1;i>=0;i--)
       {
           if((ch[i][j]-'0')==1)b[i][j]=0;
           else
           {
               if(i<n-1)
            b[i][j]=b[i+1][j]+1;
            else b[i][j]=1;
           }
       }
        an=0;
       fr(i,n)
       {
           init(1,0,m-1,i);
           fr(j,m)
           {
               sm=0;
               if(j)sm=get(1,0,m-1,0,j-1,1,b[i][j]);
               if(j+1<n)sm+=get(1,0,m-1,j+1,m-1,2,b[i][j]);
               sm++;
               an=max(an,sm*b[i][j]);
           }
       }
       pf("Case %d: %d\n",z,an);
   }

    return 0;
}

