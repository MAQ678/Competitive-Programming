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
int tr[100010],trr[100010],n;

void up(int id,int v,int t)
{
    while(id<=n)
    {
        if(t)
        tr[id]+=v;
        else trr[id]+=v;
        id+=id&(-id);
    }
}
int query(int t,int id)
{
    int z=0;
    while(id)
    {
        if(t)z+=tr[id];
        else z+=trr[id];
        id-=id&(-id);
    }
    return z;
}

int sum(int id)
{
    return query(1,id)*id-query(0,id);
}

int main()
{
    int c,i,p,q,u,v,t;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&n,&c);
        ms(tr,0);ms(trr,0);
        while(c--)
        {
            sf("%d%d%d",&u,&p,&q);
            if(u)
            {
                //query
                pf("%d\n",sum(q)-sum(p-1));
            }
            else
            {
                sf("%d",&v);
                up(p,v,1);up(q+1,-v,1);
                up(p,v*(p-1),0);up(q+1,-v*q,0);
            }
        }
    }
}
