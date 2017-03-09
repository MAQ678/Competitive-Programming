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
#define lft n<<1,s,mid
#define rft (n<<1)|1,mid+1,e

int a[100005];
struct st
{
    int lv,rv,rm,lm,m;
}tr[400000];

void init(int n,int s,int e)
{
    if(s==e)
    {
        tr[n].lv=tr[n].rv=a[s];
        tr[n].rm=tr[n].lm=tr[n].m=1;
        return;
    }
    int mid=(s+e)>>1;
    init(lft);init(rft);
    int l=n*2,r=n*2+1;
    tr[n].lv=tr[l].lv;tr[n].rv=tr[r].rv;

    if(tr[l].lv==tr[r].lv)tr[n].lm=tr[l].lm+tr[r].lm;
    else tr[n].lm=tr[l].lm;

    if(tr[l].rv==tr[r].rv)tr[n].rm=tr[l].rm+tr[r].rm;
    else tr[n].rm=tr[r].rm;

    tr[n].m=max(tr[l].m,tr[r].m);
    if(tr[l].rv==tr[r].lv)tr[n].m=max(tr[n].m,tr[l].rm+tr[r].lm);



    /*tr[n].m=0;
    if(tr[n].lv==tr[n].rv)
    {
        tr[n].lm=tr[l].m;
        tr[n].rm=tr[r].m;
        tr[n].m=tr[l].m+tr[r].m;
    }
    else if(tr[n].lv==tr[r].lv)
    {
        tr[n].lm=tr[l].m+tr[r].lm;
        tr[n].rm=tr[r].rm;
    }
    else if(tr[l].rv==tr[n].rv)
    {
        tr[n].rm=tr[r].m+tr[l].rm;
        tr[n].lm=tr[l].lm;
    }
    else
    {
        tr[n].lm=tr[l].lm;tr[n].rm=tr[r].rm;
    }
    tr[n].m=max(tr[l].m,tr[r].m);
    */

}



int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

    int t,z,n,c,q,i,j,l,r;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d%d",&n,&c,&q);
        fr(i,n)sf("%d",&a[i]);
        init(1,0,n-1);
        fr(i,q)
        {

        }
    }
    return 0;
}

