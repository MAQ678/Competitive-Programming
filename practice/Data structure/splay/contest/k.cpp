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

struct node
{
    node *par,*l,*r;
    int v;
};

node *tree;

void rightRot(node *p)
{
    node *x=p->l;
    node *B=x->r;

    if(p->par)
    {
        if(p->par->l==p)p->par->l=x;
        else p->par->r=x;
    }
    if(B) B->par=p;
    x->par=p->par;
    x->r=p;

    p->par=x;
    p->l=B;
}

void leftRot(node *p)
{
    node *x=p->r;
    node *B=x->l;

    if(p->par)
    {
        if(p->par->l==p)p->par->l=x;
        else p->par->r=x;
    }
    if(B) B->par=p;

    x->par=p->par;
    x->l=p;

    p->par=x;
    p->r=B;

}

void splay(node *x)
{
    while(1)
    {
        node *p=x->par;
        if(!p)break;
        node *g=p->par;
        if(!g)
        {
            if(p->l==x)rightRot(p);
            else leftRot(p);
            break;
        }
        if(g->l==p)
        {
            if(p->l==x)//zigzig
            {
                rightRot(g);rightRot(p);
            }
            else//zigzag
            {
                leftRot(p);rightRot(g);
            }
        }
        else
        {
            if(p->r==x)//zigzig
            {
                leftRot(g);leftRot(p);
            }
            else
            {
                rightRot(p);leftRot(g);
            }
        }
    }
    tree=x;
}

/////////////////////////////////////////////////
void make(node *tr,int v)
{
    tr=(node *)malloc(sizeof(node));

    tr->l=tr->r=NULL;
    tr->v=v;
}

void insert(int v)
{
    if(!tree)
    {
      //  make(tree,v);
        tree=(node *)malloc(sizeof(node));
        tree->l=NULL;tree->r=NULL;
        tree->par=NULL;

        tree->v=v;
        return;
    }
    node *tr=tree;
    while(1)
    {
        if(tr->v==v)break;///function like multiset

        if(tr->v >v)
        {
            if(tr->l)tr=tr->l;
            else
            {
                tr->l=(node *)malloc(sizeof(node));
                tr->l->l=tr->l->r=NULL;

                tr->l->v=v;

                tr->l->par=tr;
                tr=tr->l;
                break;
            }
        }
        else
        {
            if(tr->r)tr=tr->r;
            else
            {
                tr->r=(node *)malloc(sizeof(node));
                tr->r->l=tr->r->r=NULL;

                tr->r->v=v;

                tr->r->par=tr;
                tr=tr->r;
                break;
            }
        }
    }
   // pf("ddd\n");
    splay(tr);
}

node* find(int v)
{
    if(!tree)return NULL;
    node *p=tree;
    while(p)
    {
        if(p->v==v)break;
        if(p->v <v)
            {
                if(p->r)
                p=p->r;
                else break;
            }
        else
        {
            if(p->l)
            p=p->l;
            else break;
        }
    }
    splay(p);
    if(p->v==v)return p;
    else return NULL;
}


bool del(int v)
{
    node *N=find(v);

    if(!N)return 0;
    splay(N);

    node *p=N->l;

    if(!p)
    {
        tree=N->r;
        tree->par=NULL;
        free(N);
        return 1;
    }
    while(p&&p->r)p=p->r;

    if(N->r)
    {
        p->r=N;
        N->par=p;
    }

    tree=N->l;
    tree->par=NULL;
    free(N);

    return 1;
}


void inorder(node *N)
{
    if(!N)return;
    inorder(N->l);
    pf("v: %d ",N->v);
    if(N->l)pf("l: %d ",N->l->v);
    if(N->r)pf("r: %d",N->r->v);
    puts("");
    inorder(N->r);
}
///////////////
int a[1000000];

void build(int l,int r,node *tr)
{

    int mid=(l+r)>>1;
    tr->v=mid;
    tr->c=a[mid];
    if(l==r)return;


    node *lh,*rh;

    build(l,mid,lh);
    build(mid+1,r,rh);

    tr->l=lh;tr->r=rh;

    update(tr);
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int n,q,i;
    sf2(n,q);
    fr(i,n)sf1(a[i]);
    build(0,n-1,tree);

    return 0;
}

