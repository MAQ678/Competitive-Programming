//Bismillahir Rahmanir Rahim
//Opu-1204026
//ac : but taking much help
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

vi g[10005],co[10005];
int pa[10005][20],T[10005];
int dis[10005],cst[10005];
bool vis[10005];

void makeLca(int n)
{
    int i,j;
    fr1(i,n)
    {
        pa[i][0]=T[i];
    }
    for(j=1;(1<<j)<n;j++)
    {
        fr1(i,n)
        {
            if(pa[i][j-1]!=-1)
            pa[i][j]=pa[pa[i][j-1]][j-1];
        }
    }


}

void dfs(int u,int z)
{
    vis[u]=1;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])
        {
            dis[v]=z;
            cst[v]=co[u][k]+cst[u];
            dfs(v,z+1);
        }
    }
}


int lca(int n,int p,int q)
{
    if(dis[p]<dis[q])swap(p,q);
    int lg=0,i,j;
    while((1<<lg)<dis[p])
    {
        lg++;
    }
    for(i=lg;i>=0;i--)
    {
        if(dis[p]-(1<<i)>=dis[q])
            p=pa[p][i];
    }
    if(p==q)return p;

    for(i=lg;i>=0;i--)
    {
        if(pa[p][i]!=-1&&pa[p][i]!=pa[q][i])
            p=pa[p][i],q=pa[q][i];
    }
    return pa[p][0];
}



int kthAn(int u,int k)
{
    int i;
    //if(k==0)return u;

    int lg=0;
    while((1<<lg)<k)lg++;

    for(i=lg;i>=0;i--)
    {
        if(!k)break;
        if(k>=(1<<i))
        {
            u=pa[u][i];
            k-=(1<<i);
        }
    }
    return u;
}


int main()
{
    string s;
    int t,n,i,j,u,v,k,c,d,q,sm,to;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ms(pa,-1);
        ms(T,0);

        fr1(i,n)
        {
            g[i].clear();co[i].clear();
        }

        fr(i,n-1)
        {
            cin>>u>>v>>c;
           // if(!i)d=u;
            g[u].pb(v);
            g[v].pb(u);

            co[u].pb(c);
            co[v].pb(c);

            T[v]=u;

        }

        makeLca(n);

        fr1(i,n)
        {
            if(!T[i]&&g[i].size())
            {
                d=i;break;//get root
            }
        }

        ms(vis,0);

        dis[d]=0;cst[d]=0;//dis for depth and cst for cost
        dfs(d,1);

        while(cin>>s)
        {
            if(s=="DONE")break;
            if(s=="DIST")
            {
                cin>>u>>v;
                d=lca(n,u,v);
                sm=cst[u]+cst[v]-2*cst[d];
              //  cout<<cst[u]<<" dd "<<cst[v]<<" dd "<<cst[d]<<" "<<d<<endl;
                cout<<sm;nl;
            }
            else
            {
                cin>>u>>v>>k;
                d=lca(n,u,v);
                if(k<(dis[u]-dis[d]+1))
                {
                    //u to lca
                    sm=kthAn(u,k-1);
                }
                else if(k==(dis[u]-dis[d]+1))
                {
                    sm=d;
                }
                else
                {
                    //v to lca
                    to=dis[u]+dis[v]+1-2*dis[d];
                    sm=to-k;//v to sm th ancestor
                    sm=kthAn(v,sm);
                }
                cout<<sm;nl;
            }
        }

        nl;
    }


    return 0;
}
