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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

set<int>se;
vector<ii> g[30],stacks;
bool vis[100005];


void dfs(int u)
{
    int v,z;

    for(auto w:g[u])
    {
        v=w.ft;z=w.sd;
        if(!vis[z])
        {
            vis[z]=1;
            dfs(v);
        }
    }
}

int in[30],out[30];

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
       _;ct;
    int t,n,i,u,v,ck,cn;


    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        se.clear();ms(in,0);ms(out,0);
        fr(i,26)g[i].clear();
        fr(i,n)
        {
            cin>>s;
            u=s[0]-'a';v=s[s.length()-1]-'a';
          //  if(u!=v)
            {
                g[u].pb(ii(v,i));
                se.insert(u);
                se.insert(v);
                in[v]++;
                out[u]++;
            }

        }
        ck=0;
        for(int st:se)
        {
            if(in[st]!=out[st])
            {
                if(abs(in[st]-out[st])==1)
                    ck++;
                else
                {
                    ck=-1;break;
                }
            }
        }
        if(ck>2||ck==-1)
        {
            cout<<"The door cannot be opened.";nl;
            //not possible
            continue;
        }
        ms(vis,0);cn=0;
        if(ck==0)
        {
            //cycle
            auto st=se.begin();
           // cout<<*st<<endl;
            dfs(*st);
        }
        else
        {
            fr(i,26)if(in[i]<out[i])
            {
                cn=1;
                dfs(i);
                break;
            }
            if(!cn)cn=-1;
        }
        if(cn!=-1)
        fr(i,n)if(!vis[i])
        {
            cn=-1;break;
        }
        if(cn==-1)
        {
            cout<<"The door cannot be opened.";nl;
        }
        else cout<<"Ordering is possible.\n";



    }

    return 0;
}


