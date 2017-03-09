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


map<string,int>m;
vi g[20005],r[20005],va,nd;
int in[20005];//,st[20005],fi[20005];
bool vis[20005],w;


void dfs1(int u)
{
    int k,v;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v])dfs1(v);
    }
    va.pb(u);
}
void dfs2(int u)
{
    int k,v;
    vis[u]=1;
    fr(k,r[u].size())
    {
        v=r[u][k];
        if(!vis[v])dfs2(v);
    }
}

void dfs(int u)
{
    int k,v;
    vis[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        in[v]--;
        if(!vis[v])dfs1(v);
    }
}

int main()
{
    _;ct;
    string s1,s2;
    int t,z,n,i,cn;
    bool w;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        cn=0;
        m.clear();nd.clear();va.clear();
        fr(i,20002)g[i].clear(),r[i].clear();
        fr(i,n)
        {
            cin>>s1>>s2;
            if(!pr(m,s1))m[s1]=cn++,nd.pb(m[s1]);
            if(!pr(m,s2))m[s2]=cn++,nd.pb(m[s2]);
            g[m[s1]].pb(m[s2]);
            r[m[s2]].pb(m[s1]);

            in[m[s2]]++;
        }
        //check cycle
        ms(vis,0);
        fr(i,nd.size())
        {
            if(!vis[nd[i]])
            {
                dfs1(nd[i]);
            }
        }
        reverse(all(va));
        cn=0;
        ms(vis,0);
        fr(i,va.size())
        {
            if(!vis[va[i]])
            {
                cn++;
                dfs2(va[i]);
            }
        }
        ms(vis,0);w=0;
        if(cn==nd.size())
        {
            fr(i,nd.size())
            {
                if(in[nd[i]]==0)
                {
                    dfs(nd[i]);
                }
            }
            w=1;
            fr(i,nd.size())if(in[nd[i]]>0)
            {
                w=0;
                break;
            }
        }
        cout<<"Case "<<z<<": ";
        if(w)cout<<"Yes\n";
        else cout<<"No\n";



       /* cout<<"Case "<<z<<": ";
        if(w)cout<<"No\n";
        else cout<<"Yes\n";*/
    }
    return 0;
}

