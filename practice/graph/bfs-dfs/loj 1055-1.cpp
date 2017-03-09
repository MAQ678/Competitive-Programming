//Bismillahir Rahmanir Rahim
//Opu-1204026
//.096
//normal bfs but complex implementation
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
//    bool operator =(const P& a)const
//    {
//        return (a.x==x&&a.y==y);
//    }
};

struct st
{
    P a,b,c;

};

char ch[12][12];
int dis[11][11][11][11][11][11],n;
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};

void makeDis(st u,int val)
{
    dis[u.a.x][u.a.y][u.b.x][u.b.y][u.c.x][u.c.y]=val;
    dis[u.a.x][u.a.y][u.c.x][u.c.y][u.b.x][u.b.y]=val;
    dis[u.b.x][u.b.y][u.a.x][u.a.y][u.c.x][u.c.y]=val;
    dis[u.b.x][u.b.y][u.c.x][u.c.y][u.a.x][u.a.y]=val;
    dis[u.c.x][u.c.y][u.a.x][u.a.y][u.b.x][u.b.y]=val;
    dis[u.c.x][u.c.y][u.b.x][u.b.y][u.a.x][u.a.y]=val;
}

bool checkBound(P a)
{
    if(a.x>=0&&a.x<n&&a.y>=0&&a.y<n&&ch[a.x][a.y]!='#')return 1;
    return 0;
}

st makeInc(st u,int k)
{
    st v;
    v=u;
    v.a.x+=dx[k];v.a.y+=dy[k];v.b.x+=dx[k];v.b.y+=dy[k];v.c.x+=dx[k];v.c.y+=dy[k];
    if(!checkBound(v.a))v.a=u.a;
    if(!checkBound(v.b))v.b=u.b;
    if(!checkBound(v.c))v.c=u.c;
    //if(v.a==v.b||v.a==v.c||v.b==v.c)return v;//this move is pure
    if((v.a.x==v.b.x&&v.a.y==v.b.y)||(v.a.x==v.c.x&&v.a.y==v.c.y)||(v.b.x==v.c.x&&v.b.y==v.c.y))//this move is pure
    {
        if(v.a.x==v.b.x&&v.a.y==v.b.y)
        {
            if(u.a.x==v.a.x&&u.a.y==v.a.y)//a could not make a move
            {
                if(u.b.x==v.c.x&&u.b.y==v.c.y)
                {
                    v.c=u.c;
                }
                v.b=u.b;
            }
            else//u.b==v.b
            {
                if(u.a.x==v.c.x&&u.a.y==v.c.y)v.c=u.c;
                v.a=u.a;
            }
        }
        else if(v.a.x==v.c.x&&v.a.y==v.c.y)
        {
            if(u.a.x==v.a.x&&u.a.y==v.a.y)//a could not make a move
            {
                if(u.c.x==v.b.x&&u.c.y==v.b.y)
                {
                    v.b=u.b;
                }
                v.c=u.c;
            }
            else//u.c==v.c
            {
                if(u.a.x==v.b.x&&u.a.y==v.b.y)v.b=u.b;
                v.a=u.a;
            }
        }
        else
        {
             if(u.b.x==v.b.x&&u.b.y==v.b.y)//a could not make a move
            {
                if(u.c.x==v.a.x&&u.c.y==v.a.y)
                {
                    v.a=u.a;
                }
                v.c=u.c;
            }
            else
            {
                if(u.b.x==v.a.x&&u.b.y==v.a.y)v.a=u.a;
                v.b=u.b;
            }
        }
       // return v;
    }
    return v;
}

int bfs(st u)
{
    st v;
    int k;
    queue<st>q;
    q.push(u);
    makeDis(u,0);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
       // A=u.a,B=u.b,C=u.c;
        if(ch[u.a.x][u.a.y]=='X'&&ch[u.b.x][u.b.y]=='X'&&ch[u.c.x][u.c.y]=='X')return dis[u.a.x][u.a.y][u.b.x][u.b.y][u.c.x][u.c.y];
        fr(k,4)
        {
            v=makeInc(u,k);
            if(dis[v.a.x][v.a.y][v.b.x][v.b.y][v.c.x][v.c.y]>dis[u.a.x][u.a.y][u.b.x][u.b.y][u.c.x][u.c.y]+1)
            {
                //cout<<k<<" ";
                makeDis(v,dis[u.a.x][u.a.y][u.b.x][u.b.y][u.c.x][u.c.y]+1);
                q.push(v);
            }
        }
       // nl;
    }
    return -1;

}



int main()
{
    int i,j,t,z,cn=0,an;
    st w;
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

         ms(dis,63);
       an= bfs(w);
       pf("Case %d: ",z);
       if(an==-1)pf("trapped\n");
       else pf("%d\n",an);
    }
    return 0;
}

