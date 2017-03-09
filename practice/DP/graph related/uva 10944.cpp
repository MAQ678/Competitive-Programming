//Bismillahir Rahmanir Rahim
//.020
//simple bfs to get dis from any i to j th node, then bit-mask
#include<bits/stdc++.h>
using namespace std;
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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back
//


//input output
#define sf      scanf
#define pf      printf

#define sf1(a)  sf("%d",&a)
#define sf2(a,b)  sf("%d%d",&a,&b)
#define sf3(a,b,c)   sf("%d%d%d",&a,&b,&c)

#define nl cout<<"\n"
//eof

//seg tree
#define lc      (s+e)>>1
#define rc      (lc)+1
#define Ln      n<<1
#define Rn      (Ln)|1
//end of seg tree




//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

ii e[20];

char s[25][25];
int w[25][25],x,y,cn;

void bfs(int id)
{
    int dis[25][25],k,now,i,j;
    ii u,v;
    ms(dis,63);
    dis[e[id].ft][e[id].sd]=0;
    queue<ii>q;
    q.push(e[id]);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        fr(k,8)
        {
            v.ft=u.ft+dx[k];
            v.sd=u.sd+dy[k];
            if(v.ft>=0&&v.sd>=0&&v.ft<x&&v.sd<y)
            if(dis[v.ft][v.sd]>dis[u.ft][u.sd]+1)
            {
                dis[v.ft][v.sd]=dis[u.ft][u.sd]+1;
                q.push(v);
            }
        }
    }

    fr(i,x)
    {
        fr(j,y)
        {
            if(s[i][j]!='.')
            {
                now=s[i][j]-'0';
                if(now!=id)
                {
                    w[id][now]=dis[i][j];
                }
            }
        }
    }
}

int dp[1<<15][17];

int get(int mask,int p)
{
    if(mask==((1<<cn)-1))return w[p][0];
    if(dp[mask][p]!=-1)return dp[mask][p];

    int an=inf,i;
    fr(i,cn)
    {
        if(!(mask&(1<<i)))//i+1 th pos not taken
        {
            an=min(an,get(mask|(1<<i),i+1)+w[p][i+1]);
        }
    }
    return dp[mask][p]=an;
}

int main()
{
    // freopen("D:\\Coding\\in.txt","r",stdin);
    // freopen("D:\\Coding\\out.txt","w",stdout);

    int i,j;

    while(sf2(x,y)!=EOF)
    {

    fr(i,x)sf("%s",s[i]);
    cn=1;
    fr(i,x)
    {
        fr(j,y)
        {
            if(s[i][j]=='L')e[0].ft=i,e[0].sd=j,s[i][j]='0';
            if(s[i][j]=='#')s[i][j]='0'+cn,e[cn].ft=i,e[cn++].sd=j;
        }
    }

    fr(i,cn)
    {
        ms(w[i],0);
        bfs(i);
    }
//    fr(i,cn)
//    {
//        fr(j,cn)pf("%d ",w[i][j]);///all weight
//        nl;
//    }
cn--;
ms(dp,-1);
    pf("%d\n",get(0,0));//now he is on 0 pos

    }
    return 0;
}
