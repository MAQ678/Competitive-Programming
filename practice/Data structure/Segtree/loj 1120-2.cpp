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

struct st
{
   ll x1,x2,y1,y2;
}a[30005];
struct sst
{
    ll y1,y2,ck,x;
    void init(ll x1,ll y11,ll y12,ll c)
    {
        x1=x;y1=y11;y2=y12;ck=c;
    }
};
map<ll,ll>m1,m2;
vi v1,v2;
vector<sst>g[30005];
map<ll,ll>::IT it;
ll tr[200000],la[200000];

void up(ll n,ll s,ll e,ll l,ll r,ll va)
{
    if(s>r||e<l)return;
    if(s>=l&&e<=r)
    {
        la[n]+=(1ll*va);
        if(la[n]>0)
        {

            tr[n]=1ll*(v2[e]-v2[s]);
        }
        else
        {
            tr[n]=tr[n*2]+tr[n*2+1];//as its child may be colored
        }
        return;
    }
    if(s+1>=e)return;
    ll mid=(s+e)>>1;
    up(n*2,s,mid,l,r,va);up(n*2+1,mid,e,l,r,va);

    if(la[n]>0)tr[n]=1ll*(v2[e]-v2[s]);
    else
    {
        tr[n]=tr[n*2]+tr[n*2+1];//as its child may be colored
    }
}

int main()
{
    ll n,t,z,mx,my,u,j,l,r,i;
    ll an;
    sf("%lld",&t);
    fr1(z,t)
    {
        sf("%lld",&n);m1.clear();m2.clear();v1.clear(),v2.clear();
        fr(i,n)
        {
            sf("%lld%lld%lld%lld",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
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
        fr(i,n)
        {
            u=m1[a[i].x1];
            g[u].pb(sst(m2[a[i].y1],m2[a[i].y2],1));//start
            u=m1[a[i].x2];
            g[u].pb(sst(m2[a[i].y1],m2[a[i].y2],-1));//end
        }
        an=0;
        ms(tr,0);ms(la,0);
       // fr(i,v1.size())cout<<v1[i]<<" ";nl;
       // fr(i,v2.size())cout<<v2[i]<<" ";nl;
        fr(i,mx)
        {
            fr(j,g[i].size())
            {
                l=g[i][j].y1;
                r=g[i][j].y2;
                up(1,0,my-1,l,r,g[i][j].ck);
            }
            if(i<mx)
                {
                    an+=1ll*tr[1]*(1ll*(v1[i+1]-v1[i]));
                 //   cout<<tr[1]<<" ";
                }
        }
        nl;
        pf("Case %lld: %lld\n",z,an);
        fr(i,mx)g[i].clear();


    }
}
