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

int k,tr[5000000];
void init(int n,int s,int e)
{
    if(s==e)
    {
        tr[n]=k;
        return;
    }
    int mid=(s+e)>>1;
    init(n<<1,s,mid);
    init((n<<1)|1,mid+1,e);
    tr[n]=max(tr[n<<1],tr[(n<<1)|1]);
}

int get(int n,int s,int e,int p,int v)
{
    if(tr[n]<v)return inf;
    if(p<s)return inf;
    if(s==e)return s;
    int mid=(s+e)>>1;

    return min(get(n<<1,s,mid,p,v),get((n<<1)|1,mid+1,e,p,v));
}

void up(int n,int s,int e,int p,int v)
{
    if(s>p||e<p)return;
    if(s==e)
    {
        tr[n]-=v;
        return;
    }
    int mid=(s+e)>>1;
    up(n<<1,s,mid,p,v);
    up((n<<1)|1,mid+1,e,p,v);
    tr[n]=max(tr[n<<1],tr[(n<<1)|1]);
}

char ch[100];

int main()
{
   // _;ct;
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int n,i,j,t,b,v,l=0,g,an;
    sf("%d",&t);
    while(t--)
    {
    sf("%d%d",&k,&n);
        l=0;
        init(1,0,n-1);an=0;
        fr(i,n)
        {
            sf("%s",ch);
            if(ch[0]=='b')
            {
               sf("%d%d",&b,&v);
                while(b--)
                {
                    an+=v;
                    i++;
                    g=get(1,0,n-1,l,v);
                    if(g>=inf)
                    {
                        l++;
                        up(1,0,n-1,l,v);
                    }
                    else up(1,0,n-1,g,v);

                }
                i--;
            }
            else
            {
                v=atoi(ch);
                g=get(1,0,n-1,l,v);
                an+=v;
                if(g>=inf)
                {

                    l++;
                    up(1,0,n-1,l,v);
                }
                else up(1,0,n-1,g,v);
            }
        }
       // cout<<l+1<<" "<<qu(1,0,n-1,l);nl;
        pf("%d %d\n",l+1,(l+1)*k-an);
    }



    return 0;
}

