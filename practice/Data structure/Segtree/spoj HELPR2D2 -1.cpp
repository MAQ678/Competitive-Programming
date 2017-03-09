//Bismillahir Rahmanir Rahim
//Opu-1204026
//.31
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
char ch[100];

int k,tr[5000000],an;
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

void up(int n,int s,int e,int v)
{
    if(s==e)
    {
        an=max(an,s);
        tr[n]-=v;
        return;
    }
    int mid=(s+e)>>1;
    if(tr[n<<1]>=v)up(n<<1,s,mid,v);
    else up((n<<1)|1,mid+1,e,v);
    tr[n]=max(tr[n<<1],tr[(n<<1)|1]);
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    int t,n,i,j,b,v,w;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&k,&n);
        init(1,0,n-1);an=0;w=0;
        fr(i,n)
        {
            sf("%s",ch);
            if(ch[0]=='b')
            {
                sf("%d%d",&b,&v);
                while(b--)
                {
                    w+=v;
                    i++;
                    up(1,0,n-1,v);
                }
                i--;
            }
            else
            {
                v=atoi(ch);
                w+=v;
                up(1,0,n-1,v);
            }
        }
        pf("%d %d\n",an+1,(an+1)*k-w);
    }

    return 0;
}

