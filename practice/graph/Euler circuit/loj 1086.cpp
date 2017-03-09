//Bismillahir Rahmanir Rahim
//Opu-1204026
//.016 learned
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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


vi nd;

int g[16][16],s,dp[1<<16];

int f(int m)
{
    if(m==(1<<s)-1)return 0;
    if(dp[m]!=-1)return dp[m];
    int i,j,an=inf;
    fr(i,s)
    {
        if((m&(1<<i))==0)
        {
            for(j=i+1;j<s;j++)
            {
                if((m&(1<<j))==0)
                an=min(an,g[nd[i]][nd[j]]+f((m|(1<<i))|(1<<j)));
            }
            break;
        }
    }
    return dp[m]=an;
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);

    int t,z,n,m,u,v,c,i,d[16],an,j,k;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&m);
        ms(d,0);an=0;ms(g,63);
        fr1(i,n)g[i][i]=0;
        fr(i,m)
        {
            sf("%d%d%d",&u,&v,&c);
            an+=c;
            g[u][v]=g[v][u]=min(g[u][v],c);
            d[u]++,d[v]++;
        }

        fr1(k,n)fr1(i,n)fr1(j,n)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

        fr1(i,n)if(d[i]&1)nd.pb(i);

        s=nd.size();ms(dp,-1);//cout<<an<<endl;
       // fr(i,s)cout<<nd[i]<<" ";nl;
        an+=f(0);

        pf("Case %d: %d\n",z,an);


        nd.clear();

    }
    return 0;
}
