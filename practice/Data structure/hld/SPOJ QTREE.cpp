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

vector<pair<int,ii> > g[10001];
int p[14][10001],d[10001],subsz[10001],otend[10001];

int chainHead[10001],chainPos[10001],chainInd[10001],chainSize[10001],chainNo,ptr,posInBase[10001],baseArray[10001],othend[10001];
void dfs(int pa,int u,int t)
{
    p[0][u]=pa;
    d[u]=t;
    subsz[u]=1;
    int k,v;
    fr(k,g[u].size())
    {
        v=g[u][k].ft;
        if(v!=pa)
        {
            othend[g[u][k].sd.sd]=v;
            dfs(u,v,t+1);
            subsz[u]+=subsz[v];
        }
    }
}

void hld(int u,int pa,int cost)
{
    if(chainHead[chainNo]==-1)chainHead[chainNo]=u;
    chainInd[u]=chainNo;//chainPos[u]=chainSize[chainNo];
    //chainSize[chainNo]++;
    posInBase[u]=ptr;
    baseArray[ptr++]=cost;
    int sc=-1,ncost,i,v;
    fr(i,g[u].size())
    {
        v=g[u][i].ft;
        if(v!=pa)
        {
            if(sc==-1||subsz[sc]<subsz[v])
            {
                sc=v;ncost=g[u][i].sd.ft;
                //cout<<ncost<<endl;
            }
        }
    }
    if(sc!=-1)hld(sc,u,ncost);
    fr(i,g[u].size())
    {
        v=g[u][i].ft;
        if(v!=pa&&sc!=v)
        {
            chainNo++;
            hld(v,u,g[u][i].sd.ft);
        }
    }
}
int lca(int u,int v)
{
    if(d[u]<d[v])swap(u,v);
    int dif=d[u]-d[v],i;
    fr(i,14)if((dif>>i)&1)u=p[i][u];
    if(u==v)return u;
    for(i=14-1;i>=0;i--)
    {
        if(p[i][u]!=p[i][v])
            u=p[i][u],v=p[i][v];
    }
    return p[0][u];
}

int tr[1<<20];
void init(int n,int s,int e)
{
    if(s==e)
    {
        tr[n]=baseArray[s];return;
    }
    int mid=(s+e)>>1;
    init(n*2,s,mid);init(n*2+1,mid+1,e);
    tr[n]=max(tr[n*2],tr[n*2+1]);
}

void update(int n,int s,int e,int pos,int va)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[n]=va;
        return;
    }
    int mid=(s+e)>>1,l=n<<1,r=l+1;
    update(l,s,mid,pos,va);update(r,mid+1,e,pos,va);
    tr[n]=max(tr[l],tr[r]);
}

int query(int n,int s,int e,int le,int ri)
{
    if(s>ri||e<le)return 0;
    if(s>=le&&e<=ri)return tr[n];
    int mid=(s+e)>>1,l=n<<1,r=l+1;
    return max(query(l,s,mid,le,ri),query(r,mid+1,e,le,ri));
}

void change(int i,int val)
{
    int u=othend[i];
    update(1,0,ptr-1,posInBase[u],val);
}

int getQuery(int u,int v)
{
    if(u==v)return 0;
    int an=0,l,r,uchain,vchain=chainInd[v];
    while(1)
    {
        uchain=chainInd[u];
        if(uchain==vchain)
        {
            if(u==v)break;
            an=max(an,query(1,0,ptr-1,posInBase[v],posInBase[u]));
            cout<<an<<" dd"<<endl;
            break;
        }
        an=max(an,query(1,0,ptr-1,posInBase[chainHead[uchain]],posInBase[u]));
        u=chainHead[uchain];
        u=p[0][u];
    }
   // cout<<an<<" dd"<<endl;
    return an;
}

int fun(int u,int v)
{
    int w=lca(u,v);
    return max(getQuery(u,w),getQuery(v,w));
}


int main()
{
    int t,n,u,v,cc,i,j;
    char q[10];
    sf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        fr(i,n)
        {
            g[i].clear();
            chainHead[i]=-1;
            fr(j,14)p[j][i]=-1;
        }
        fr(i,n-1)
        {
            sf("%d%d%d",&u,&v,&cc);
            g[u-1].pb(mp(v-1,mp(cc,i)));
            g[v-1].pb(mp(u-1,mp(cc,i)));
        }
        ms(d,-1);ms(p,-1);
        chainNo=0;ptr=0;
        dfs(-1,0,0);
       // ms(chainHead,-1);ms(chainInd,-1),ms(chainPos,-1),ms(chainSize,0);
        hld(0,-1,-1);//0==root
        ms(tr,0);
       // fr(i,n)cout<<baseArray[i]<<" ";nl;

        init(1,0,ptr-1);

        fr1(i,14-1)
        {
            fr(j,n)
            {
                if(p[i-1][j]!=-1)p[i][j]=p[i-1][p[i-1][j]];
            }
        }

        while(1)
        {
            sf("%s",q);
            if(q[0]=='D')break;
            if(q[0]=='Q')
            {
                sf("%d%d",&u,&v);
                pf("%d\n",fun(u-1,v-1));
            }
            else
            {
                sf("%d%d",&i,&u);
                change(i-1,u);
            }
        }

    }
    return 0;
}

