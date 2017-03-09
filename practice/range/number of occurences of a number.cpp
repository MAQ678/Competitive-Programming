//Bismillahir Rahmanir Rahim
//Opu-1204026
//O(nlogn)
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
    int v,in;
} a[1<<20];


bool cmp(st x,st y)
{
    if(x.v<y.v) return true;
    else if(x.v==y.v)return x.in<y.in;
    return false;
}

/*
8
1 1 1 2 3 5 1 2
6
1 3 1
1 8 1
4 8 2
4 5 2
1 3 2
5 7 2
*/

int main()
{
    int n,i,j,an,lo,hi,mid,q,l,r,v;
    cin>>n;
    map<int,int>s,e;
    fr(i,n)cin>>a[i].v,a[i].in=i+1;
    sort(a,a+n,cmp);
    s.clear(),e.clear();
    fr(i,n)
    {
        if(!i||a[i].v!=a[i-1].v)s[a[i].v]=i;
        if(i&&(a[i].v!=a[i-1].v||i==n-1))e[a[i-1].v]=i-1;

    }
    cin>>q;
    while(q--)
    {
        cin>>l>>r>>v;
        if(!pr(s,v))
        {
            cout<<0;
            nl;
            continue;
        }
        lo=s[v],hi=e[v];
        while(lo<=hi)//lower bound search
        {
            mid=(lo+hi)>>1;
            if(a[mid].in>=l)hi=mid-1;
            else lo=mid+1;
        }
        an=mid;
        if(a[mid].in>=l&&a[mid].in<=r)
        {
            //cout<<mid<<" qqqq "<<a[mid].in<<endl;
            lo=s[v],hi=e[v];
            while(lo<=hi)//lower bound search
            {
                mid=(lo+hi)>>1;
                if(a[mid].in>=r)hi=mid-1;
                else lo=mid+1;
            }
            //cout<<mid<<" dddd "<<a[mid].in<<endl;
            if(a[mid].in>r)mid--;
            an=mid-an;
            if(a[mid].v==v)an++;

        }
        else an=0;

        pf("%d\n",an);

    }

    return 0;
}
