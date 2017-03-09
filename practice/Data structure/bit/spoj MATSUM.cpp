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
    int x1,x2,y1,y2,sm,t;
}a[1025];
char ch[5];
map<int,int>m1,m2;
int xm[1025],ym[1025],mx,my;
int tr[1025][1025];

void up(int x1,int y1,int sm)
{
    int y;
    while(x1<=mx)
    {
        y=y1;
        while(y<=my)
        {
            tr[x1][y]+=sm;
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
    int t,i,j,an,q,w,x1,y1,x2,y2;
    sf("%d",&t);
    while(t--)
    {
        mx=1;my=1;
        ms(tr,0);
        sf("%d",&q);
        i=0;
        while(1)
        {
            sf("%s",ch);
            if(!strcmp(ch,"SET"))
            {
                sf("%d%d%d",&a[i].x1,&a[i].y1,&a[i].sm);
                a[i].t=1;
                m1[a[i].x1],m2[a[i].y1];
            }
            else if(!strcmp(ch,"SUM"))
            {
                sf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
                a[i].t=0;
                m1[a[i].x1],m2[a[i].y1];m1[a[i].x2],m2[a[i].y2];
            }
            else break;
            i++;
        }
        w=i;
        for(auto it: m1)
        {
            m1[it.ft]=mx;
            xm[mx]=it.ft;
            mx++;
        }
        for(auto it: m2)
        {
            m2[it.ft]=my;
            ym[my]=it.ft;
            my++;
        }
        //fr1(i,mx)pf("%d ",xm[i]);nl;
        //fr1(i,my)pf("%d ",ym[i]);nl;
        fr(i,w)
        {
            if(a[i].t)
            {
                up(m1[a[i].x1],m2[a[i].y1],a[i].sm);
            }
            else
            {
                x1=m1[a[i].x1];x2=m1[a[i].x2];y1=m2[a[i].y1];y2=m2[a[i].y2];
                an=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
                pf("%d\n",an);
            }
        }
    }

    return 0;
}

