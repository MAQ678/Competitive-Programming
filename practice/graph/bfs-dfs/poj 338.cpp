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



int d[22][22],cn;
bool vis[22][22];
int dx[]= {0,1,1};
int dy[]= {1,0,1};

void dfs(int x1,int y1,int x2,int y2,int v)
{
    vis[x1][y1]=1;
    int x3,y3,i;
    fr(i,3)
    {
        x3=x1+dx[i];y3=y1+dy[i];
        if(x3<=x2&&y3<=y2&&!vis[x3][y3])
        {
            if(d[x1][y1]==d[x3][y3])
            {
                dfs(x3,y3,x2,y2,v);
            }
            else
            {
                cn++;
                dfs(x3,y3,x2,y2,cn);
            }
        }
    }
    d[x1][y1]=v;
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int n,x1,y1,x2,y2,i,w,h;
   pair<ii,ii>p;
   sf("%d%d%d",&w,&h,&n);
   ms(d,0);
   cn=1;
   fr(i,n)
   {
        sf("%d%d%d%d",&x1,&y1,&x2,&y2);
       // if(y1<y2)p=make(x1,y1,x2,y2);
       // else p=make(x2,y2,x1,y1);
       if(y1>y2)swap(y1,y2),swap(x1,x2);
       if(x1>x2)swap(x1,x2);
       ms(vis,0);
        dfs(x1,y1,x2,y2,cn);
        cn++;

   }
   cout<<"hhh"<<endl;


    return 0;
}

