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
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct P
{
    int x,y;
};

struct st
{
    P a,b,c;
};

char ch[12][12];
int dis[11][11][11][11][11][11];

void makeDis(st u,int val)
{
    dis[u.a.x][u.a.y][u.b.x][u.b.y][u.c.x][u.c.y]=val;
    dis[u.a.x][u.a.y][u.c.x][u.c.y][u.b.x][u.b.y]=val;
    dis[u.b.x][u.b.y][u.a.x][u.a.y][u.c.x][u.c.y]=val;
    dis[u.b.x][u.b.y][u.c.x][u.c.y][u.a.x][u.a.y]=val;
    dis[u.c.x][u.c.y][u.a.x][u.a.y][u.b.x][u.b.y]=val;
    dis[u.c.x][u.c.y][u.b.x][u.b.y][u.a.x][u.a.y]=val;
}

int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};

int bfs(st u)
{
    st v;
    makeDis(u,0);
    P A,B,C;

    queue<st>q;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        fr(k,4)
        {
            A=u.a;B=u.b;C=u.c;
            A.x+=dx[k],A.y+=dy[k];B.x+=dx[k],B.y+=dy[k];C.x+=dx[k],C.y+=dy[k];

        }
    }
}

int main()
{
    st w;
    int t,z,n,i,j,k,cn;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        fr(i,n)sf("%s",ch[i]);
        cn=0;
        fr(i,n)
        {
            fr(j,n)
            {
                if(ch[i][j]=='A'||ch[i][j]=='B'||ch[i][j]=='C')
                {
                    if(cn==0)w.a.x=i,w.a.y=j;
                    if(cn==1)w.b.x=i,w.b.y=j;
                    if(cn==2)w.c.x=i,w.c.y=j;
                    cn++;
                }
            }
        }

        // all nodes are on w;
        ms(dis,63);
        bfs(w);
    }
    return 0;
}

