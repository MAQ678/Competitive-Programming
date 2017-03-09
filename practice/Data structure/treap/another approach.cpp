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
typedef      vector<ii> vii;
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())


typedef struct node
{
    int val,pr,size;
    struct node *l,*r;
}node;

typedef node* pnode;//pnode is pointer to node


int sz(pnode t)
{
    return t?t->size:0;
}
void upd_sz(pnode t)
{
    if(t)t->size=sz(t->l)+sz(t->r)+1;
}

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t)l=r=NULL;
    else if(t->val<=key) split(t->r,t->r,r,key),l=t;
    else split(t->l,l,t->l,key),r=t;
    upd_sz(t);
}

void merge(pnode &t,pnode l,pnode r)
{
    if(!l||!r)t=l?l:r;
    else if(l->pr > r->pr) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),r=t;
    upd_sz(t);
}

pnode init(int val)
{
    pnode tm;
    tm->val=val;tm->pr=rand();tm->size=1;tm->l=tm->r=NULL;
}

void insert(pnode &t,pnode it)
{
    if(!t)t=it;
    else if(it->pr > t->pr)split(t,it->l,it->r,it->val);
    else insert(t->val <= it->val?t->r:t->l,it);
    upd_sz(t);
}

void erase(pnode &t,int key)
{
    if(!t)return;
    else if(t->val==key)
    {
        pnode tmp=t;merge(t,t->l,t->r);free(tmp);
    }
    else erase(t->val<key?t->r:t->l,key);
    upd_sz(t);
}

void unite(pnode &t,pnode l,pnode r)
{
    if(!l||!r)return void(t=l?l:r);
    if(l->pr<r->pr)swap(l,r);
    pnode lt,rt;
    split(r,lt,rt,l->val);
    unite(l->l,l->l,lt);
    unite(l->r,l->r,rt);
    t=l;upd_sz(t);
}




int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

    return 0;
}

