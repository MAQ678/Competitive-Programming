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
#define tr(c,i) for( i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
//
struct st
{
   int x1,x2,y1,y2;
}a[30005];
int tr[130000],ax[130000],la[130000];
int tre1[130000],ay[130000],la1[130000];
/*
struct tr
{
    int a,ax,la,axl,axr;
}tx[130000],ty[130000];*/
map<int,int>m1,m2;
vi v1,v2;
map<int,int>::IT it;


void init1(int n,int s,int e)
{
    if(s==e)
    {
        tr[n]=1;
        la[n]=0;
        return;
    }
    int mid=(s+e)>>1;
    init1(n*2,s,mid);
    init1(n*2+1,mid+1,e);
    tr[n]=tr[n*2]+tr[n*2+1];

}
void init2(int n,int s,int e)
{
    if(s==e)
    {
        tre1[n]=1,la1[n]=0;
        return;
    }
    int mid=(s+e)>>1;
    init2(n*2,s,mid);
    init2(n*2+1,mid+1,e);
    tre1[n]=tre1[n*2]+tre1[n*2+1];

//    if(s==mid)
//    ay[n]=ay[n*2+1]-ay[n*2];
//    else ay[n]=ay[n*2+1]+ay[n*2];
}

int up1(int n,int s,int e,int l,int r)
{
    if(la[n])
    {
        tr[n]=0;if(s!=e)la[n*2]=la[n*2+1]=1;
    }
    if(s>r||e<l||tr[n]==0)return 0;
    if(s>=l&&e<=r&&tr[n]==(e-s+1))
    {
        if(tr[n]==(e-s+1))
        {
            if(s!=e)la[n*2]=la[n*2+1]=1;
            tr[n]=0;
            int an;
            if(s>0)return v1[e]-v1[s-1];
            else return v1[e]-v1[s];
        }
    }
        int mid=(s+e)>>1;
        return up1(n*2,s,mid,l,r)+up1(n*2+1,mid+1,e,l,r);
}
int up2(int n,int s,int e,int l,int r)
{
    if(la1[n])
    {
        tre1[n]=0;if(s!=e)la1[n*2]=la1[n*2+1]=1;
    }
    if(s>r||e<l||tre1[n]==0)return 0;
    if(s>=l&&e<=r&&tre1[n]==(e-s+1))
    {
        if(tre1[n]==(e-s+1))
        {
            if(s!=e)la1[n*2]=la1[n*2+1]=1;
            tre1[n]=0;
            int an;
            if(s>0)return v2[e]-v2[s-1];
            else return v2[e]-v2[s];
        }
    }
        int mid=(s+e)>>1;
        return up2(n*2,s,mid,l,r)+up2(n*2+1,mid+1,e,l,r);
}
int main()
{
    int n,x1,x2,y1,y2,t,z,i,mx,my,an,x,y;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);m1.clear();m2.clear();v1.clear(),v2.clear();
        fr(i,n)
        {
            sf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
            m1[a[i].x1];m1[a[i].x2];m2[a[i].y1];m2[a[i].y2];
        }
        mx=0,my=0;
        tr(m1,it)
        {
            m1[it->ft]=mx;
            v1.pb(it->ft);mx++;
        }
        tr(m2,it)
        {
            m2[it->ft]=my;
            v2.pb(it->ft);my++;
        }
       // fr(i,v1.size())cout<<v1[i]<<" ";nl;
       // fr(i,v2.size())cout<<v2[i]<<" ";nl;
     //  ms(tr,0);ms(trr,0);ms(la,0);
       init1(1,0,v1.size()-1);//initialize for leaf
       init2(1,0,v2.size()-1);//initialize for leaf
       ms(la,0);ms(la1,0);
       an=0;
       fr(i,n)
       {
            x=up1(1,0,v1.size()-1,m1[a[i].x2],m1[a[i].x1]);
            y=up2(1,0,v2.size()-1,m2[a[i].y2],m2[a[i].y1]);
            an+=(x*y);
            cout<<x<<" "<<y;nl;
       }


    }
}
