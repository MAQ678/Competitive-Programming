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


map<string,int>ma;
map<int,string>mq;
vii g[1000000];
bool vis[1000000];
int n;

int dfs(int u,int l)
{
    if(l>n)return 0;

    int k,v,t,an=0;
    bool b=0;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        t=g[u][k].sd;
        if(!vis[t])
        {
            vis[t]=1;
            b=1;
            an|=dfs(v,l+1);
        }
    }
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   int i,cn=0,u,v;
   string s,s1,s2;
   sf("%d",&n);
   fr(i,n)
   {
        cin>>s;
        s1=s[0]+s[1];
        s2=s[1]+s[2];
        if(!pr(ma,s1))mq[cn]=s1,ma[s1]=cn++;
        if(!pr(ma,s2))mq[cn]=s2,ma[s2]=cn++;
        g[ma[s1]].pb(mp(ma[s2],i));
   }
   ms(vis,0);
   fr(i,cn)
   {
       l=dfs(i);
       if(zn==n&&l==n+2)//total edge taken
       {
           //print
       }

   }


    return 0;
}

