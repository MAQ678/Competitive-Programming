//Bismillahir Rahmanir Rahim
//Opu-1204026
//got tle
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



int a[10005],md=5000000,tr[52][50000],m[10005],m1[52][10005];
bool ck[10005];



map<int,int>M;

void up(int n,int s,int e,int p,int k,int v)
{
    if(s>p||e<p)return;
    if(s==e)
    {
        tr[k][n]=v%md;return;
    }
    int mid=(s+e)>>1;
    up(n<<1,s,mid,p,k,v);
    up((n<<1)|1,mid+1,e,p,k,v);
    tr[k][n]=(tr[k][n<<1]+tr[k][(n<<1)|1])%md;
}

int get1(int n,int s,int e,int p,int k)
{
    if(s>p)return 0;
    if(e<=p)return tr[k][n];
    int mid=(s+e)>>1;
    return (get1(n<<1,s,mid,p,k)+get1((n<<1)|1,mid+1,e,p,k))%md;
}
int get2(int n,int s,int e,int p,int k)
{
    if(s>p||e<p)return 0;
    if(s==e)return tr[k][n];
    int mid=(s+e)>>1;
    return (get2(n<<1,s,mid,p,k)+get2((n<<1)|1,mid+1,e,p,k))%md;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    int n,k,mx,i,j,v1,v2,v;
    sf("%d%d",&n,&k);
    fr(i,n)sf("%d",&a[i]),M[a[i]];
    mx=0;//ms(tr,0);
    for(auto it:M)
    {
        m[it.ft]=mx++;
    }
    ms(ck,0);ms(m1,0);
    fr(i,n)
    {
        if(!ck[m[a[i]]])
        up(1,0,n-1,m[a[i]],1,1),ck[m[a[i]]]=1;

        for(j=2;j<=k;j++)
        {
            v1=get1(1,0,n-1,m[a[i]]-1,j-1);
            if(m1[j][m[a[i]]]>0)v2=m1[j][m[a[i]]];
            else
            v2=get2(1,0,n-1,m[a[i]],j);
            v=(v1-v2+md)%md;
            if(v>0)
            {
                up(1,0,n-1,m[a[i]],j,v1);
                m1[j][m[a[i]]]=v1;
            }
        }
    }
    pf("%d\n",tr[k][1]);

    return 0;
}

