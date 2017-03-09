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

struct sst
{
    int l,r,ck;
}v[100005];
int a[100005];
struct st
{
    int va,vm,lv,lm,rv,rm,;
}tr[400005];

void init(int n,int s,int e)
{
    if(s==e)
    {
        va=a[s];vm=1;
        lm=rm=lv=rv=0;
        return;
    }
    int mid=(s+e)>>1;
    int l=n*2,r=l+1,v1,v2,v3;
    init(l,s,mid);init(r,mid+1,e);

    if(tr[l].vm==tr[r].vm)
    {
        tr[n]=tr[l].va+tr[r].va;
        tr[n].vm=tr[l].vm;
    }
    else
    {
        v1=0;v2=0;
        if(tr[l].vm==tr[r].lm)
        {
            v1=tr[l].va+tr[r].lv;
            v2=tr[l].vm;
        }


    }
}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int t,z,n,i,j,l,r,c,w,u;
   sf("%d",&t);
   fr1(z,t)
   {
       sf("%d%d%d",&n,&c,&q);
       fr1(i,c)v[i].ck=0;
       fr(i,n)
       {
           sf("%d",&w);a[i]=w;
           if(w!=u&&i)v[w].r=i-1;
           if(v[w].ck==0)
           {
               v[w].ck=1;
               v[w].l=i;
               u=w;
           }
       }
       v[w].r=i-1;

       init(1,0,n);

       fr(i,q)
       {
           sf("%d%d",&l,&r);
       }
   }

    return 0;
}

