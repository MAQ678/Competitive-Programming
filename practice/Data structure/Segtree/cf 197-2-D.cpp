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

ll tr[1<<20];

void update(int n,int s,int e,int pos,ll val,int lv)
{
    if(pos<s||pos>e)return;
    if(s==e)
    {
        tr[n]=val;
        return;
    }
    int mid=(s+e)>>1,l=n<<1,r=l|1;
    update(l,s,mid,pos,val,lv-1);
    update(r,mid+1,e,pos,val,lv-1);
    //cout<<lv<<endl;
    if(lv&1)tr[n]=tr[l]|tr[r];
    else tr[n]=tr[l]^tr[r];
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int n,i,p,d,l,m;
   ll a;
   sf("%d%d",&n,&m);
   l=1<<n;l--;
   ms(tr,0);
   fr(i,l+1)sf("%lld",&a),update(1,0,l,i,a,n);
   while(m--)
   {
       sf("%d%lld",&i,&a);
       update(1,0,l,i-1,a,n);
       pf("%lld\n",tr[1]);
   }

    return 0;
}

