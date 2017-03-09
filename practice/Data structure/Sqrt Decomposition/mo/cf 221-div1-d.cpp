
//Bismillahir Rahmanir Rahim

//670 ms
///at first get the range for a node on rooted tree such that it will show the vertices that is on a subtree
//after this sqrt decomposition
//in each step I will see that when a color I find , I will how many times a color came in the specific range
//then besides this I will save on another array w that for k ,if there is a color which is exactly k times in the subtree
//then for a query as we need to now how many color are at-least kj times,
//so for this we to get sum value of w array from (kj->max time a color present).. so bit will do this...
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

struct st
{
    int l,r,k,id;
}e[100005];



ii rn[100005];

vi g[100005],vc;
int c[100005],vk[100005],an[100005],wn[100005],zn[100005];
int ck,bs;

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=wn[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

void update(int idx,int x)
{
    while(idx<=100005)
    {
        wn[idx]+=x;
        idx+=idx&(-idx);
    }
}


bool cmp(st x,st y)
{
    int p=x.l/bs,q=y.l/bs;
    if(p<q)return 1;
    else if(p==q)return x.r<y.r;
    return 0;
}

void dfs(int u,int pr)
{
    vc.pb(c[u]);
    rn[u].ft=ck++;
    for(int v:g[u])
    {
        if(v!=pr)
        {
            dfs(v,u);
        }
    }
    rn[u].sd=ck-1;
}

int ans;

void add(int p,int z)
{
    int v=vc[p];

    if(vk[v]>0)//wn[vk[v]]--;
    {
        update(vk[v],-1);
       // zn[vk[v]]--;
    }
    vk[v]++;
    if(vk[v]>0)//wn[vk[v]]++;
    {
        update(vk[v],1);
       // zn[vk[v]]++;
    }
    if(vk[v]==e[z].k)
        ans++;
}

void del(int p,int z)
{
    int v=vc[p];
    if(vk[v]==e[z].k)
        ans--;

    if(vk[v]>0)//wn[vk[v]]--;
    {
        update(vk[v],-1);
     //   zn[vk[v]]--;
    }
    vk[v]--;
    if(vk[v]>0)//wn[vk[v]]++;
    {
        update(vk[v],1);
      //  zn[vk[v]]++;
    }

}

void solve(int m)
{
    int l,r,z;
    l=0,r=-1;
     ans=0;
    ms(vk,0);ms(wn,0);ms(zn,0);
    fr(z,m)
    {
        while(l<e[z].l)
        {
            del(l,z);
            l++;
        }
        while(l>e[z].l)
        {
            add(l-1,z);
            l--;
        }
        while(r+1<=e[z].r)
        {
            add(r+1,z);
            r++;
        }
        while(r>e[z].r)
        {
            del(r,z);
            r--;
        }
        an[e[z].id]=query(100000)-query(e[z].k-1);//wn[e[z].k];
    }
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int n,m,i,u,v,k;
    sf2(n,m);
    fr1(i,n)
    {
        sf1(c[i]);
    }
    fr(i,n-1)
    {
        sf2(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    ck=0;
    dfs(1,1);

//    fr(i,vc.size())
//    {
//        cout<<vc[i]<<" ";
//    }
//    nl;


    fr(i,m)
    {
        sf2(v,e[i].k);
        e[i].l=rn[v].ft;e[i].r=rn[v].sd;
        e[i].id=i;
    }

    //mo's
    bs=sqrt(m)+1;
    sort(e,e+m,cmp);

    ms(wn,0);

    solve(m);

    fr(i,m)pf("%d\n",an[i]);

    return 0;
}



