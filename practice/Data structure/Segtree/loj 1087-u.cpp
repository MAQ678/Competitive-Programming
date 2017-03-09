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

//int MAX=1<<20;
int tr[1<<20],a[1<<20];

void in(int r,int s,int e)
{
    if(s==e)
    {
        tr[r]=0;
        return;
    }
    int mid=(s+e)>>1;
    in(r*2,s,mid);in(r*2+1,mid+1,e);
    tr[r]=0;
}
void up(int r,int s,int e,int pos)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r]=1;
        return;
    }
    int mid=(s+e)>>1;
    up(r*2,s,mid,pos);up(r*2+1,mid+1,e,pos);
    tr[r]=tr[r*2]+tr[r*2+1];
}

int query(int r,int s,int e,int pos)
{
    if(pos<=0||tr[r]<pos)return 0;
    if(s==e)
    {
        tr[r]=0;
        return a[s];
    }
     int mid=(s+e)>>1,p,q,z=tr[r*2];
    p=query(r*2,s,mid,pos);
    q=query(r*2+1,mid+1,e,pos-z);
    tr[r]=tr[r*2]+tr[r*2+1];
    return p|q;

}

int main()
{
    int t,z,i,j,q,n,N,v;
    char ch;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&q);
        N=n+q;
        in(1,0,N-1);
        fr(i,n)sf("%d",&a[i]),up(1,0,N-1,i);
         pf("Case %d:\n",z);
        while(q--)
        {
            sf(" %c%d",&ch,&v);
            if(ch=='c')
            {
                if(tr[1]<v)pf("none\n");
                else
                    pf("%d\n",query(1,0,N-1,v));
            }
            else
            {
                a[n]=v;
                up(1,0,N-1,n);
                n++;
            }
        }
    }
    return 0;
}

