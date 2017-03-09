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

ll a[1000000];
ll tr[1000000],la[1000000];

void init(int n,int s,int e)
{
    if(s==e)
    {
        tr[n]=a[s];
        if(a[s]>1)la[n]=1;
        else la[n]=0;
        return;
    }
    int mid=(s+e)>>1;
    init(n<<1,s,mid);init((n<<1)|1,mid+1,e);
    tr[n]=tr[n<<1]+tr[(n<<1)|1];
    la[n]=la[n<<1]+la[(n<<1)|1];
}

void up(int n,int s,int e,int l,int r)
{
    if(s>r||e<l)return;
    if(s==e)
    {
        tr[n]=floor(sqrt(tr[n]));
        if(tr[n]==0)tr[n]=1;
        if(tr[n]<=1)la[n]=0;
        return ;
    }
    int mid=(s+e)>>1;
    if(la[n<<1])
    up(n<<1,s,mid,l,r);
    if(la[(n<<1)|1])
    up((n<<1)|1,mid+1,e,l,r);
    tr[n]=tr[n<<1]+tr[(n<<1)|1];
    la[n]=la[n<<1]+la[(n<<1)|1];
}

ll get(int n,int s,int e,int l,int r)
{
    if(s>r||e<l)return 0;
    if(s>=l&&e<=r)return tr[n];
     int mid=(s+e)>>1;
     return  get(n<<1,s,mid,l,r)+get((n<<1)|1,mid+1,e,l,r);
}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int n,m,x,y,q;
    int t=1,i;
    while(sf("%d",&n)!=EOF)
    {
        fr(i,n)sf("%lld",&a[i]);
        init(1,0,n-1);
        sf("%d",&m);
        pf("Case #%d:\n",t++);

        while(m--)
        {
            sf("%d%d%d",&q,&x,&y);
            x--;y--;
            if(x>y)swap(x,y);
            if(!q) up(1,0,n-1,x,y);//update
            else pf("%lld\n",get(1,0,n-1,x,y));
        }
        puts("");
    }
    return 0;
}

