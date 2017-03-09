//Bismillahir Rahmanir Rahim
//Opu-1204026
//.556
//taking idea from http://codeforces.com/blog/entry/9817
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
    int x,y,an,in;
}p[50005];

int a[100005],b[100005],tr[1<<20];

void up(int r,int s,int e,int pos,int val)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r]+=val;
        return;
    }
    int mid=(s+e)>>1;
    up(r*2,s,mid,pos,val);up(r*2+1,mid+1,e,pos,val);
    tr[r]=tr[r*2]+tr[r*2+1];
}

bool cmp(st a, st b)
{
    return a.y<b.y;
}

bool cmp1(st a,st b)
{
    return a.in<b.in;
}

int query(int r,int s,int e,int L,int R)
{
    if(s>R||e<L)return 0;
    if(s>=L&&e<=R)return tr[r];
    int mid=(s+e)>>1;
    return query(r*2,s,mid,L,R)+query(r*2+1,mid+1,e,L,R);
}

int main()
{
    int t,z,n,q,i,j,ck;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&q);
        ms(b,-1);
        ms(tr,0);
        fr(i,n)
        {
            sf("%d",&a[i]);
            if(b[a[i]]==-1)
            {
                up(1,0,n-1,i,1);
                b[a[i]]=i;
            }
        }
        fr(i,q)sf("%d%d",&p[i].x,&p[i].y),p[i].in=i;
        sort(p,p+q,cmp);
        j=0;ck=0;
        fr(i,n)
        {
            if(b[a[i]]!=i)
            {
                up(1,0,n-1,b[a[i]],-1);
                up(1,0,n-1,i,1);
                b[a[i]]=i;
            }
            while(j<q&&p[j].y-1==i)
            {
                p[j].an=query(1,0,n-1,p[j].x-1,p[j].y-1);
                j++;
            }
            if(j==q)break;
        }
        sort(p,p+q,cmp1);
        pf("Case %d:\n",z);
        fr(i,q)pf("%d\n",p[i].an);
    }
    return 0;
}

