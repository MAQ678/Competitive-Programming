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

struct st
{
    int x,y,p;
}a[100005];
struct ss
{
    int x1,y1,x2,y2,va;
}b[100005];
struct sst
{
    int y,id,t;
    sst(int y,int id,int t)
    {
        this->y=y;
        this->id=id;
        this->t=t;
    }
};

map<int,int>m1,m2;
int v1[1000000],v2[1000000];
vector<sst>v[1000000];
bool cmp(sst x,sst y)
{
    return x.y<y.y;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

   int t,z,n,r,t,i,cn,an,mx,my;

   sf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        fr(i,n)sf("%d%d%d",&a[i].x,&a[i].y,&a[i].p),m1[a[i].x],m2[a[i].y];
        mx=1,my=1;
        sf("%d",&r);
        fr(i,r)sf("%d%d%d%d",&b[i].x1,&b[i].y1,&b[i].x2,&b[i].y2),m1[b[i].x1],m2[b[i].y1],m1[b[i].x2],m2[b[i].y2];

        for(auto it: m1)
        {
            m1[it->ft]=mx;
            v1[mx]=it->ft;
            mx++;
        }
        for(auto it: m2)
        {
            m2[it->ft]=my;
            v2[my]=it->ft;
            my++;
        }
        fr(i,n)
        {
            v[m1[a[i].x]].pb(sst(m2[a[i].y],i,1));
        }
        fr(i,r)
        {
            v[m1[b[i].x1]].pb(sst(m2[b[i].y1],i,2));
            v[m1[b[i].x2]].pb(sst(m2[b[i].y2],i,3));
        }
        //compression complete
        fr1(i,mx-1)
        {
            sort(all(v[i]),cmp);
            fr(k,v[i].size())
            {
                if(v[i].t==1)
                {
                    up(v[i].y,a[v[i].id].p);
                }
                else if(v[i].t==2)
                {
                    //take values before start
                }
                else
                {
                    //get the value of the position and remove the existing
                }
            }
        }




    }

    return 0;
}

