
//Bismillahir Rahmanir Rahim
//unfinished
#include<bits/stdc++.h>
using namespace std;
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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back
//


//input output
#define sf      scanf
#define pf      printf

#define sf1(a)  sf("%d",&a)
#define sf2(a,b)  sf("%d%d",&a,&b)
#define sf3(a,b,c)   sf("%d%d%d",&a,&b,&c)

#define nl cout<<"\n"
//eof

//seg tree
#define lc      (s+e)>>1
#define rc      (lc)+1
#define Ln      n<<1
#define Rn      (Ln)|1
//end of seg tree




//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

struct st
{
    int l,r,id;
} w[100005];

int b[100005],cn[100005];
int bs;
ll an[100005],ans;

bool cmp(st x,st y)
{
    int p=x.l/bs,q=y.l/bs;
    if(p<q)return 1;
    else if(p==q)return x.r<y.r;
    return 0;
}

ll get(int v)
{
    v--;
    if(v<0)return 0;
    ll a=v;a*=(v-1);
    return a/2;
}

void add(int p)
{
    int &v=cn[b[p]];
    if(v)ans-=get(v);
    v++;
    if(v)ans+=get(v);
}

void del(int p)
{
    int &v=cn[b[p]];
    if(v)ans-=get(v);
    v--;
    if(v)ans+=get(v);
}

void debug(int n,int k)
{
    int i;
    fr(i,n)sf1(b[i]),b[i]^=k;
    nl;nl;
    fr(i,n)cout<<b[i]<<" ";
    nl;
    fr1(i,n-1)b[i]^=b[i-1];
    fr(i,n)cout<<b[i]<<" ";
    nl;
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);


    int n,m,k,i,l,r,z;
    cout<<get(100000)<<endl;
    sf3(n,m,k);
    bs=sqrt(n)+1;

    debug(n,k);

//    sf1(b[0]);b[0]^=k;
//    fr1(i,n-1)sf1(b[i]),b[i]=b[i-1]^(b[i]^k);

    fr(i,m)
    {
        sf2(w[i].l,w[i].r);
        w[i].l--;w[i].r--;
        w[i].id=i;
    }

    sort(w,w+m,cmp);
     l=0,r=-1;
     ans=0;ms(cn,0);
    fr(z,m)
    {
        while(l<w[z].l)
        {
            del(l);
            l++;
        }
        while(l>w[z].l)
        {
            add(l-1);
            l--;
        }
        while(r+1<=w[z].r)
        {
            add(r+1);
            r++;
        }
        while(r>w[z].r)
        {
            del(r);
            r--;
        }
        an[w[z].id]=ans;
    }
    fr(i,m)pf("%I64d\n",an[i]);
     return 0;
}

