//Bismillahir Rahmanir Rahim
//Opu-1204026
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
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
    int l,w;
}a[5005];
bool ck[10005];
int mx[10005];
vi v;
bool cmp(st x,st y)
{
    return x.l>y.l;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int t,i,j,n,an,cn;
   bool ok;
   sf("%d",&t);
   while(t--)
   {
       sf("%d",&n);
       ms(ck,0);
       ms(mx,0);
       fr(i,n)
       {
           sf("%d%d",&a[i].l,&a[i].w);
           mx[a[i].w]=max(mx[a[i].w],a[i].l);
           if(!ck[a[i].w])ck[a[i].w]=1,v.pb(a[i].w);
       }
       sort(a,a+n,cmp);
       sort(all(v));
       reverse(all(v));
       ms(ck,0);an=0;cn=0;
       fr(i,v.size())
       {
           ok=0;
            fr(j,n)
            {
                if(!ck[j])
                {
                    if(a[j].w<=v[i]&&a[j].l<=mx[v[i]])
                    {
                        cn++;
                        ck[j]=1;
                        ok=1;
                    }
                }
            }
            if(ok)an++;
            if(cn==n)break;
       }
       pf("%d\n",an);
       v.clear();
   }

    return 0;
}

