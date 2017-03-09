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
    int x,y;
}nd[16];
char ch[22][22];
int ma[20][20],w[16][16],d[22][22],n,m;
int cn;
int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {1,-1,0,0,1,1,-1,-1};

void dfs(int x,int y)
{
    int k,v1,v2;
    fr(k,8)
    {
        v1=x+dx[k];v2=y+dy[k];
        if(v1>=0&&v2>=0&&v1<n&&v2<m&&d[v1][v2]>d[x][y]+1)
        {
            d[v1][v2]=d[x][y]+1;
            dfs(v1,v2);
        }
    }
}

int fun(int mask, int no)
{
    if(mask==(1<<cn)-1)return 0;
    int an=inf,k;
    fr(k,cn)
    {
        if(!(mask&(1<<k)))
        {
            an=min(an,fun((mask|(1<<k))+w[no][k],k));
        }
    }
    return an;
}

int main()
{
    int t,z,u,an,i,j;

    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        fr(i,n)sf("%s",ch[i]);
        ms(ma,0);
        cn=2;
        fr(i,n)fr(j,m)
        {
            if(ch[i][j]=='x')ma[i][j]=1,nd[0].x=i,nd[0].y=j;
            if(ch[i][j]=='g')nd[cn-1].x=i,nd[cn-1].y=j,ma[i][j]=cn++;
        }
       // cout<<cn<<endl;
       cn--;
        ms(w,0);
        fr(i,cn)
        {
            ms(d,63);
            d[nd[i].x][nd[i].y]=0;
            dfs(nd[i].x,nd[i].y);
            fr(j,cn)
            {
                w[i][j]=d[nd[j].x][nd[j].y];
            }
        }
    fr(i,cn)
    {
        fr(j,cn)cout<<w[i][j]<<" ";
        nl;
    }
//        an=inf;
//        fr(i,cn-1)
//        {
//            an=min(an,fun())
//        }
        cout<<fun(1,0);

    }

    return 0;
}

