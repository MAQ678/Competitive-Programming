//Bismillahir Rahmanir Rahim
//Opu-1204026
#include<bits/stdc++.h>
#include<time.h>
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
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct node
{
    int key,cnt,priority;
    node *left, *right;
    node(){cnt=0,priority=0,left=right=NULL;}
    node(int _key){cnt=1,key=_key,priority=rand(),left=right=NULL;}
    node(int _key,int pr){cnt=1,key=_key,priority=pr,left=right=NULL;}
};

struct treap
{
    node* root;
    treap() {root=NULL; srand(time(NULL));}

    int treeSize(node* T)//extra
    {
        if(T==NULL)return 0;
        return T->cnt;
    }

    void upcnt(node* &T)//extra
    {
        if(T)T->cnt=1+treeSize(T->left)+treeSize(T->right);
    }

    void leftRotate(node* &T)
    {
        node* tmp=T->left;
        T->left=tmp->right;
        tmp->right=T;
        T=tmp;

        upcnt(T->right);
        upcnt(T);
    }
    void rightRotate(node* &T)
    {
        node* tmp=T->right;
        T->right=tmp->left;
        tmp->left=T;
        T=tmp;

        upcnt(T->left);
        upcnt(T);

    }

    void balance(node* &T)//do the heap operation
    {
        if(T->priority < T->left->priority)leftRotate(T);
        else if(T->priority < T->right->priority)rightRotate(T);
    }

    void  insert(node* &T,int _key)//bst operation
    {
        if(T==NULL)
        {
            T=new node(_key);
            return;
        }
        if(T->key > _key)
        {
            insert(T->left,_key);
            if(T->priority < T->left->priority)leftRotate(T);
        }
        else if(T->key < _key)
        {
            insert(T->right,_key);
           if(T->priority < T->right->priority)rightRotate(T);
        }
     //   balance(T);
        upcnt(T);
    }

    void Delete(node* &T,int _key)
    {
        if(T==NULL)return;

        if(T->key >_key)
            Delete(T->left,_key);
        else if(T->key <_key)Delete(T->right,_key);
        else
        {
            if(T->left&&T->right)//if it's not child
            {
                if(T->left->priority > T->right->priority)leftRotate(T);
                else rightRotate(T);
                Delete(T,_key);
            }
            else
            {
                node* tmp=T;
                if(T->left)T=T->left;
                else T=T->right;
                delete tmp;
            }
        }
        upcnt(T);
    }

    void insert(int _key)
    {
        insert(root,_key);
    }
    void Delete(int _key)
    {
        Delete(root,_key);
    }


    int Count(node* &T,int _key)
    {
        if(T==NULL)return 0;
        if(T->key < _key)
            return 1+treeSize(T->left)+Count(T->right,_key);//1 for the T th node
        else return Count(T->left,_key);
    }
    int Count(int _key)
    {
        return Count(root,_key);
    }

    int kth(node* &T,int k)
    {
        if(treeSize(T)<k)return -inf;
        int v=1+treeSize(T->left);
        if(v==k)return T->key;
        else if(v>k)return kth(T->left,k);
        else return kth(T->right,k-v);

    }
    int kth(int k)
    {
        return kth(root,k);
    }
};


int main()
{
    freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    int n,w,an;
    cin>>n;
    string s;
    treap t;//=new treap();
    while(n--)
    {
        cin>>s>>w;
        if(s=="I")t.insert(w);
        else if(s=="D")t.Delete(w);
        else if(s=="C")an=t.Count(w);
        else an=t.kth(w);
        if(s=="C"||s=="K")
        {
            //print
            if(an<=-inf)cout<<"invalid\n";//pf("invalid\n");
            else cout<<an,nl;//pf("%d\n",an);
        }
    }
    return 0;
}

