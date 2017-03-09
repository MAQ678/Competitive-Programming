//Bismillahir Rahmanir Rahim
//Opu-1204026
//.372
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

int tr[1002][1002],ck[1002][1002];

void up(int x1,int y1)
{
    int y;
    while(x1<=1001)
    {
        y=y1;
        while(y<=1001)
        {
            tr[x1][y]++;
            y+=y&(-y);
        }
        x1+=x1&(-x1);
    }
}

int query(int x1,int y1)
{
    int y,z=0;
    while(x1)
    {
        y=y1;
        while(y)
        {
            z+=tr[x1][y];
            y-=y&(-y);
        }
        x1-=x1&(-x1);
    }
    return z;
}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int t,z,i,j,an,q,x1,x2,y1,y2,p;
    sf("%d",&t);
    fr1(z,t)
    {
        ms(tr,0);ms(ck,0);
        sf("%d",&p);
        pf("Case %d:\n",z);
        while(p--)
        {
            sf("%d",&q);
            if(q)
            {
                sf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++,x2++,y1++,y2++;
                an=0;
               // cout<<query(x2,y2)<<" d "<<query(x1-1,y2)<<" "<<query(x2,y1-1)<<" "<<query(x1-1,y1-1);
              //  nl;
                an+=query(x2,y2);
                an-=query(x1-1,y2);an-=query(x2,y1-1);
                an+=query(x1-1,y1-1);
                pf("%d\n",an);
            }
            else
            {
                sf("%d%d",&x1,&y1);x1++,y1++;
                if(!ck[x1][y1])
                up(x1,y1),ck[x1][y1]=1;
            }
        }
    }
    return 0;
}

