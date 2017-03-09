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
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
vi a;
int tr[2000000];

void update(int r,int s,int e,int pos)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r]=1;
        return;
    }
    int mid=(s+e)>>1;
    update(r*2,s,mid,pos);
    update(r*2+1,mid+1,e,pos);
    tr[r]=tr[r*2]+tr[r*2+1];
}
void init(int r,int s,int e)
{
    if(s==e)
    {
        tr[r]=0;
        return;
    }
    int mid=(s+e)>>1;
    init(r*2,s,mid);
    init(r*2+1,mid+1,e);
    tr[r]=0;
}

int query(int r,int s,int e,int pos)
{
    if(pos<=0||tr[r]<pos)
        return 0;
    if(s==e)
    {
        tr[r]=0;
        return a[s];
    }
    int mid=(s+e)>>1;
    int p,q,z=tr[r*2];
    p=query(r*2,s,mid,pos);
    q=query(r*2+1,mid+1,e,pos-z);
    tr[r]=tr[r*2]+tr[r*2+1];
    return (p|q);
}

int main()
{
   // freopen("F:\\Coding\\in.txt","r",stdin);
    int t,z,n,i,j,q,N,v;
    char ch;
    sf("%d",&t);
    fr1(z,t)
    {
        a.clear();
        sf("%d%d",&n,&q);
       // cout<<q<<endl;
        N=n+q;
        init(1,0,N-1);
        fr(i,n)
        {
            sf("%d",&v);
            a.pb(v);
            update(1,0,N-1,i);
        }
        pf("Case %d:\n",z);
        while(q--)
        {
            sf(" %c%d",&ch,&v);
          // cin>>ch>>v;
            if(ch=='a')
            {
                 a.pb(v);
                update(1,0,N-1,n);
                n++;
            }
            else
            {
                if(tr[1]<v)pf("none\n");
                else
                pf("%d\n",query(1,0,N-1,v));
            }
        }
    }

    return 0;
}
