//.10
//learn we need to give power (n-d)
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
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
#define eb      emplace_back

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

struct mat
{
    int v[16][16],r,c;
}I;
int md,w[17];

mat mul(mat a,mat b)
{
    mat r;r.r=a.r,r.c=b.c;
    int i,j,sm,k;
    fr(i,r.r)
    {
        fr(j,r.c)
        {
            sm=0;
            fr(k,a.c)sm+=(a.v[i][k]*b.v[k][j])%md,sm%=md;
            r.v[i][j]=sm;
        }
    }
    return r;
}

mat power(mat T,int p)
{
    if(p==0)return I;
    if(p==1)return T;
    if(p%2==1)return mul(T,power(T,p-1));
    mat ret=power(T,p/2);
    return mul(ret,ret);
}
int main()
{
       // freopen("F:\\Coding\\in.txt","r",stdin);
       // freopen("F:\\Coding\\out.txt","w",stdout);
        int n,d,i,j;
        mat T,f;
        while(sf("%d%d%d",&d,&n,&md)&&(n||d||md))
        {
            T.r=T.c=d;
            ms(I.v,0);I.r=I.c=d;
            fr(i,d)I.v[i][i]=1;
            ms(T.v,0);
            fr(i,d)sf("%d",&T.v[0][i]),T.v[0][i]%=md;
            j=0;
            for(i=1;i<d;i++)T.v[i][j]=1,j++;
            f.r=d;f.c=1;
            //fr(i,d)sf("%d",&f.v[i][0]),f.v[i][0]%=md;
           // fr(i,d)sf("%d",&w[i]);
            for(i=d-1;i>=0;i--)sf("%d",&f.v[i][0]),f.v[i][0]%=md;//f.v[i][0]=w[d-1-i]%md;
            if(n<=d)pf("%d\n",f.v[d-n][0]%md);
            else
            {
                T=power(T,n-d);f=mul(T,f);
                pf("%d\n",f.v[0][0]);
            }
        }


    return 0;
}

