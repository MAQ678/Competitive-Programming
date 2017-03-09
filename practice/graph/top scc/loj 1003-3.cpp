//Bismillahir Rahmanir Rahim
//Opu-1204026
//.128
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
vi g[20005];
//int in[20005];
bool vis[20005],onStack[20005];

bool dfs(int u)
{
    int k,v;
    vis[u]=1;
    onStack[u]=1;
    fr(k,g[u].size())
    {
        v=g[u][k];
        if(!vis[v]&&dfs(v))
        {
            return 1;
        }
        else if(onStack[v])
        {
            return 1;
        }
    }
    onStack[u]=0;
    return 0;
}

int main()
{
    _;ct;
    string s1,s2;
    int t,z,n,i,cn;
    bool w;
    cin>>t;
    fr1(z,t)
    {
        cin>>n;
        cn=0;
        m.clear();
        fr(i,20001)g[i].clear();//,in[i]=0;
        fr(i,n)
        {
            cin>>s1>>s2;
            if(!pr(m,s1))m[s1]=cn++;
            if(!pr(m,s2))m[s2]=cn++;
            g[m[s1]].pb(m[s2]);
        }
        //check cycle
        ms(vis,0);ms(onStack,0);
        w=0;
        fr(i,cn)
        {
            if(!vis[i]&&dfs(i))
            {
                w=1;
                break;
            }
        }

        cout<<"Case "<<z<<": ";
        if(w)cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
