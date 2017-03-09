//Bismillahir Rahmanir Rahim
//Opu-1204026
//.212
//learned a technic
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

int tr[5000000],w,nv;

void init(int n,int s,int e)
{
    if(s==e)
    {
        if((s&1)==0)tr[n]=0;
        else tr[n]=1;
        return;
    }
    int mid=(s+e)>>1;
    init(n*2,s,mid);
    init(n*2+1,mid+1,e);
    tr[n]=tr[n*2]+tr[n*2+1];
}

int get(int n,int s,int e,int v)
{
    if(tr[n]<v)return 0;
    if(tr[n]<0)return 0;
    if(s==e)
    {
        if(tr[n])
        return s;
        else return 0;
    }
    int mid=(s+e)>>1;
    int p=0;
    if(tr[n*2]>=v)
    {
        p|=get(n*2,s,mid,v);
    }
    else
    {
        int val=v-tr[n*2];
        if(val>0&&tr[n*2+1]>=val)
        p|=get(n*2+1,mid+1,e,val);
    }

    return p;
}

void put(int n,int s,int e,int v)
{
    if(s==e)
    {
        tr[n]=0;
        return;
    }
    int mid=(s+e)>>1;
    if(tr[n*2]>=v)put(n*2,s,mid,v);
    else put(n*2+1,mid+1,e,v-tr[n*2]);
    tr[n]=tr[n*2]+tr[n*2+1];
}
vi lk;
void take(int n,int s,int e)
{
    if(s==e)
    {
        lk.pb(s);
        return;
    }
    int mid=(s+e)>>1;
    if(tr[n*2])take(n*2,s,mid);
    if(tr[n*2+1])take(n*2+1,mid+1,e);
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int i,j,n=1429431,v,qq=2,p,t,z;
    w=1;
    init(1,0,n);
  //  cout<<tr[1]<<endl;
    while(1)
    {
        v=get(1,0,n,qq);
        qq++;
        if(v==0)break;
        p=tr[1]/v;
        if(p*v>tr[1])p--;
        for(j=p*v;j>=1;j-=v)
        {
            put(1,0,n,j);
        }
    }
    take(1,0,n);
   // fr(i,lk.size())cout<<lk[i]<<" ";nl;
   // cout<<lk.size()<<endl;
   sf("%d",&t);
   fr1(z,t)
   {
       sf("%d",&n);
       pf("Case %d: %d\n",z,lk[n-1]);
   }


    return 0;
}


