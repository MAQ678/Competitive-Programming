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
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())



int a[10005],md=5000000,tr[52][10005],m1[52][10005],n,mx;
bool ck[10005];
map<int,int>M;

void up(int p,int k,int v)
{
    while(p<=mx)
    {
        tr[k][p]=(v+tr[k][p])%md;
        p+=p&(-p);
    }
}
int get(int p,int k)
{
    int z=0;
    while(p)
    {
        z=(z+tr[k][p])%md;
        p-=p&(-p);
    }
    return z;
}

int main()
{
 //   freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    int k,i,j,v1,v2,v,m;
    sf("%d%d",&n,&k);
    fr(i,n)sf("%d",&a[i]),M[a[i]];
    mx=1;ms(tr,0);
    for(auto it:M)
    {
        M[it.ft]=mx++;
    }
    mx--;
    ms(ck,0);ms(m1,0);
    fr(i,n)
    {
        m=M[a[i]];
        if(!ck[m])
            up(m,1,1),ck[m]=1;

        for(j=2;j<=k;j++)
        {
            v2=0;
            v1=get(m-1,j-1);
            if(m1[j][m]>0)v2=m1[j][m];
            v=(v1-v2+md)%md;
            if(v>0)
            {
              up(m,j,v);
                m1[j][m]=v1;
            }
        }
    }
    pf("%d\n",get(mx,k));

    return 0;
}


