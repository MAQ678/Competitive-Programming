//Bismillahir Rahmanir Rahim
//Opu-1204026
//good problem
//dp+segment tree
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
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct st
{
    int v,in;
}a[10005];
int tr[52][50000],md=5000000;
bool cmp(st x,st y)
{
    if(x.v<y.v)return 1;
    else if(x.v==y.v)return x.in>y.in;
    return 0;
}

void up(int n,int s,int e,int p,int k,int v)
{
    if(s>p||e<p)return;
    if(s==e)
    {
        tr[k][n]=v%md;
        return;
    }
    int mid=(s+e)>>1;
    up(n<<1,s,mid,p,k,v);
    up((n<<1)|1,mid+1,e,p,k,v);
    tr[k][n]=(tr[k][n<<1]+tr[k][(n<<1)|1])%md;
}

int get(int n,int s,int e,int p,int k)
{
    if(s>p)return 0;
    if(e<=p)
        return tr[k][n];
    int mid=(s+e)>>1;
    return (get(n<<1,s,mid,p,k)+get((n<<1)|1,mid+1,e,p,k))%md;
}



int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int n,k,i,j,v;
   sf("%d%d",&n,&k);
   fr(i,n)sf("%d",&a[i].v),a[i].in=i;
   sort(a,a+n,cmp);
   ms(tr,0);
   fr(i,n)
   {
       up(1,0,n-1,a[i].in,1,1);
       for(j=2;j<=k;j++)
       {
            v=get(1,0,n-1,a[i].in-1,j-1);
            up(1,0,n-1,a[i].in,j,v);
       }
   }
   pf("%d\n",tr[k][1]);

    return 0;
}

