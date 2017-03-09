
//Bismillahir Rahmanir Rahim
//Opu-1204026
//.248
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
    int l,r,v;
}w[200005];

int a[200005],ma[200005];
int tr[500000];

void init(int n,int s,int e)
{
    if(s==e)
    {
        tr[n]=w[s].v;
        return;
    }
    int mid=(s+e)>>1;
    init(n<<1,s,mid);init((n<<1)|1,mid+1,e);
    tr[n]=max(tr[n<<1],tr[(n<<1)|1]);
}

int get(int n,int s,int e,int l,int r)
{
    if(l>r)return 0;
    if(e<l||s>r)return 0;
    if(s>=l&&e<=r)
    {
        return tr[n];
    }
    int mid=(s+e)>>1;
    return max(get(n<<1,s,mid,l,r),get((n<<1)|1,mid+1,e,l,r));

}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int t,z,n,c,q,cn,l,r,an,v,i;
   sf("%d",&t);
   fr1(z,t)
   {
       sf("%d%d%d",&n,&c,&q);
       fr(i,n)
       {
            sf("%d",&a[i]);
       }
       cn=0;
       w[0].l=0;ms(ma,0);
       ma[a[0]]=0;
       fr1(i,n-1)
       {
           if(a[i-1]==a[i])w[cn].r=i;
           else
           {
               w[cn].r=i-1;
               w[cn].v=w[cn].r-w[cn].l+1;
               cn++;
               ma[a[i]]=cn;
               w[cn].l=i;
           }
       }
       w[cn].r=i-1;
       w[cn].v=w[cn].r-w[cn].l+1;

       init(1,0,cn);
       pf("Case %d:\n",z);
       while(q--)
       {
            sf("%d%d",&l,&r);
            l--;r--;
            if(a[l]==a[r])pf("%d\n",r-l+1);
            else
            {
                v=0;
                v=max((w[ma[a[l]]].r-l+1),(r-w[ma[a[r]]].l+1));
                v=max(v,get(1,0,cn,ma[a[l]]+1,ma[a[r]]-1));
                pf("%d\n",v);
            }
       }


   }

    return 0;
}
