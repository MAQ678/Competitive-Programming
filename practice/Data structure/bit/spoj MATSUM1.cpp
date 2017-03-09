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

char ch[5];
ll tr[1030][1030],ww[1030][1030];
bool ck[1030][1030];

void up(int x1,int y1,ll sm)
{
    int y;
    while(x1<=1025)
    {
        y=y1;
        while(y<=1025)
        {
            tr[x1][y]+=sm;
            y+=y&(-y);
        }
        x1+=x1&(-x1);
    }
}

int query(int x1,int y1)
{
    int y;
    ll z=0;
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
   // freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,i,j,q,w,x1,y1,x2,y2;
     ll an,sm;
    sf("%d",&t);
    while(t--)
    {
        ms(tr,0);ms(ck,0);
        sf("%d",&q);
        while(1)
        {
            sf("%s",ch);
            if(!strcmp(ch,"SET"))
            {
                sf("%d%d%lld",&x1,&y1,&sm);
                x1++;y1++;
                if(ck[x1][y1])
                {
                    an=ww[x1][y1];
                    up(x1,y1,-an);
                }
                else ck[x1][y1]=1;

                up(x1,y1,sm);
                ww[x1][y1]=sm;
            }
            else if(!strcmp(ch,"SUM"))
            {
                sf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++;y1++;x2++;y2++;
                an=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
                pf("%lld\n",an);
            }
            else break;
        }
        puts("");
    }

    return 0;
}

