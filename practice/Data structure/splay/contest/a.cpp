
//Bismillahir Rahmanir Rahim
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdio.h>
#include<map>

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
    int v,id;
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
                rightRot(g);
                rightRot(p);
            }
            else//zigzag
            {
                leftRot(p);
                rightRot(g);
            }
        }
        else
        {
            if(p->r==x)//zigzig
            {
                leftRot(g);
                leftRot(p);
            }
            else
            {
                rightRot(p);
                leftRot(g);
            }
        }
    }
    tree=x;
    tree->par = NULL;
}


///////////////////////////

void insert(int v,int id)
{
    if(!tree)
    {
        tree=(node *)malloc(sizeof(node));
        tree->l=NULL;
        tree->r=NULL;
        tree->par=NULL;

        tree->v=v;
        tree->id=id;
        return;
    }
    node *tr=tree;
    while(1)
    {
        if(tr->v==v)break;
        if(tr->v >v)
        {
            if(tr->l)tr=tr->l;
            else
            {
                tr->l=(node *)malloc(sizeof(node));
                tr->l->l=tr->l->r=NULL;

                tr->l->v=v;
                tr->l->id=id;

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
                tr->r->id=id;

                tr->r->par=tr;
                tr=tr->r;
                break;
            }
        }

    }
    splay(tr);

}

node* findH(node *tr)
{
    if(!tr->r)return tr;
    return findH(tr->r);
}
node* findL(node *tr)
{
    if(!tr->l)
        return tr;
    return findH(tr->l);
}

int del(int q)
{
    node *N;
    if(q==2)
        N=findH(tree);
    else
        N=findL(tree);
    if(!N)return 0;
    int ans=N->id;
    splay(N);
    node *p=N->l;

    if(p)
    {
        while(p&&p->r)p=p->r;
        if(N->r)
        {
            p->r=N;
            N->par=p;
        }
        tree=N->l;

        if(tree)
        {
            tree->par=NULL;

        }
        free(N);

        return ans;
    }
    tree=N->r;


    if(tree)
    {
         tree->par=NULL;

    }
    free(N);

    return ans;

}

void dell(node* tr)
{
    if(tr->l)
        dell(tr->l);
    if(tr->r)
        dell(tr->r);
    free(tr);

    return;
}
int main()
{
    int q,k,p;
    while(sf1(q)&&q)
    {
        tree=NULL;
        if(q==1)
        {
            sf2(k,p);
            insert(p,k);
        }
        else
        {
            if(tree==NULL)pf("0\n");
            else
            {
                pf("%d\n",del(q));
            }
        }

    }

    dell(tree);

    return 0;
}
