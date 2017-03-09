//Bismillahir Rahmanir Rahim
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


//otosporin




int son[N][2],pre[N],key[N],val[N];

int nd;

void new_node(int &x,int fa,int v,int va)
{
    x=nd++;

    pre[x]=fa;key[x]=v;val[x]=va;
    ms(son[x],0);
}


void _rotate(int x,int dir)
{
    int y=pre[x];
//pd
    son[y][!dir]=son[x][dir]; pre[son[x][dir]]=y;
    if(pre[y])son[pre[y]][son[pre[y][1]==y]]=x;

    pre[x]=pre[y];

    son[x][dir]=y, pre[y]=x;
    //pu
}

void splay(int x,int goal)
{
    //pd
    while(pre[x]!=goal)
    {
        int y=pre[x];
        if(pre[y]==goal)_rotate(x,son[y][0]==x);
        else
        {
            int dir=son[pre[y]][0]==y;
            if(son[y][dir]==x)_rotate(x,!dir),_rotate(x,dir);
            else _rotate(y,dir),_rotate(x,dir);
        }
    }
//pu
    if(goal==0)root=x;
}

void _insert(int v,int va)
{
    if(!root)new_node(root,0,v,va);
    else
    {
        while(son[x][key[x]<v])
        {
            x=son[x][key[x]<v];
        }
        new_node(son[x][key[x]<v],x,v,va);
        splay(son[x][key[x]<v],0);
    }
}


int _find(int v)
{
    int x=root;
    while(1)
    {
        if(key[x]<v)x=son[x][1];
        else if(key[x]>v)x=son[x][0];
        else if(key[x]==v||!x)break;
    }
    return x;
}

int get_prec(int x)
{
    int t=son[x][0];
    while(son[t][1])t=son[t][1];
    return t;
}
int get_suc(int x)
{
    int t=son[x][1];
    while(son[t][0])t=son[t][0];
    return t;
}

void del(int v)
{
    int x=_find(v);
    if(!x)return;
    splay(x,0);
    if(!son[root][0]||!son[root][1])
            root=son[root][0]+son[root][1],pre[root]=0;
    else
    {
        int t=get_suc(root);
        splay(t,root);
        son[son[]
    }

}


int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);


    return 0;
}

