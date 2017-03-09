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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

set<pair<ii,int> >s[50005];
set<pair<ii,int> >::IT it,it1;
int n,t;

bool check(int z)
{
    queue<ii>q;
    bool vis[50005];
    ms(vis,0);
    vis[1]=1;
    q.push(mp(1,0));
    ii u;
    pair<ii,int>v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(u.ft==n)
        {
            if(u.sd<=t)return 1;
            //return 0;
           continue;
        }
        it=s[u.ft].lower_bound(mp(mp(u.sd,0),0));

        for(;it!=s[u.ft].end();it++)
        {
            v=*it;
            if(v.ft.ft>=u.sd&&v.ft.ft<=z+u.sd&&!vis[v.sd]&&v.ft.sd<=t)
            {
                vis[v.sd]=1;
                q.push(mp(v.sd,v.ft.sd));
            }
            if(v.ft.ft>z+u.sd)break;
        }
    }
    return 0;
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("F:\\Coding\\out.txt","w",stdout);

    int m,u,v,q,e,i,j,lo,hi,mid,an;
    sf("%d%d%d",&n,&t,&m);
    fr(i,m)
    {
        sf("%d%d%d%d",&u,&v,&q,&e);
        s[u].insert(mp(mp(q,e),v));
    }
   // fr1(i,n)cout<<s[i].size()<<endl;
    lo=0;hi=t;an=0;
    while(lo<=hi)
    {
        mid=(lo+hi)>>1;
        if(check(mid))
        {
            an=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    pf("%d\n",an);


    return 0;
}

