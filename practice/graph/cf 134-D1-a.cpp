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

struct st
{
    int x,y,d;
}e[101];

bool g[1005][1005];
int mx,mn,n;
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
int co[1005][1005];

int bfs(int x,int y)
{
    //cout<<x<<" "<<y;nl;
    queue<st>q;
    st p;
    p.x=x;p.y=y;
    co[x][y]=0;
    int k;
    fr(k,4)
    {
        p.d=k;
        q.push(p);
    }

    st u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        fr(k,4)
        {
            v=u;
                v.x+=dx[k];v.y+=dy[k];
                if(v.x>=mn&&v.x<=mx&&v.y>=mn&&v.y<=mx)
                {
                    if(u.d==k)
                    {
                        if(co[v.x][v.y]>co[u.x][u.y])
                        {
                            v.d=k;
                            co[v.x][v.y]=co[u.x][u.y];
                            q.push(v);
                        }
                    }
                    else
                    {
                        if(co[v.x][v.y]>co[u.x][u.y]+1)
                        {
                            v.d=k;
                            co[v.x][v.y]=co[u.x][u.y]+1;
                            q.push(v);
                        }
                    }

            }
        }
    }
    int mx=0;
    fr(k,n)
    {
        //cout<<co[e[k].x][e[k].y]<<endl;
        mx=max(mx,co[e[k].x][e[k].y]);
    }
    return mx;


}

int main()
{
    int i,j,x,y;
    mn=inf,mx=0;
    sf("%d",&n);
    ms(g,0);
    ms(co,63);
    fr(i,n)
    {
        sf("%d%d",&x,&y);
        g[x][y]=1;
        e[i].x=x;e[i].y=y;
        mx=max(mx,x);
        mx=max(mx,y);
        mn=min(mn,x);
        mn=min(mn,y);
    }

    pf("%d\n",bfs(x,y));

}
