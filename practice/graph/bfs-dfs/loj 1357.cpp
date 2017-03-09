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

vi g[100005];
int deg[100005];
int vis[100005];

int dfs(int u)
{
    vis[u]=1;
    int k,v,a=0;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            a+=(1+dfs(v));
        }

    }
    return a;
}

int main()
{
    int t,z,u,v,n,an1,an2,pos,i,j,w;
    sf("%d",&t);
    fr1(z,t)
    {


        sf("%d",&n);

        fr(i,n-1)
        {
            sf("%d%d",&u,&v);
            g[u].pb(v);g[v].pb(u);
            deg[u]++;deg[v]++;
        }
        ms(vis,0);
        an1=dfs(1);
        //cout<<an1<<endl;
        fr1(i,n)sort(all(g[i]));
//        fr1(i,n)
//        {
//            fr(j,g[i].size())cout<<g[i][j]<<" wew ";
//            nl;
//        }
        an2=0;
        fr1(i,n)
        {
            pos=lower_bound(all(g[i]),i)-g[i].begin();
            w=n-i;
            an2+=(w-(g[i].size()-pos));
//            cout<<g[i][pos]<<" dd "<<pos<<endl;
//            while((g[i][pos]<i||pos>=g[i].size())&&pos>=0)pos--;
//            if(pos>=0)w=(g[i].size()-pos);
           // an2+=(n-w);
        }
        pf("%d %d\n",an1,an2);
        fr1(i,n)g[i].clear(),deg[i]=0;

    }
    return 0;
}

