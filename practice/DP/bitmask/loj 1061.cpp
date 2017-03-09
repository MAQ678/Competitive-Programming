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

int cn;
struct st
{
    int y[8];
} w[500];
int c[9],mk[9];
bool dr[8][8];

bool ck(int x,int y)
{
    int k=min(x+y,7),z;
    x=x+y-k;
    y=k;
    if(dr[x][y])return 0;
    k=max(x-y,0);
    y=y-(x-k);
    x=k;
    if(dr[x][y])return 0;
    return 1;
}
void check(int x,int y)
{
    int k=min(x+y,7),z,xx,yy;
    xx=x+y-k;
    yy=k;
    dr[xx][yy]=1;
    k=max(x-y,0);
    yy=y-(x-k);
    xx=k;
    dr[xx][yy]=1;
}
void get(int k)
{
    int i;
    if(k>=8)
    {
        fr(i,8)w[cn].y[i]=c[i],cout<<c[i]+1<<" ";
        nl;

        cn++;
        return;
    }
    int kk,x1,y1,x2,y2;

    fr(i,8)
    {
        kk=min(k+i,7);
        x1=(k+i)-kk;
        y1=kk;
        kk=max(k-i,0);
        y2=i-(k-kk);
        x2=kk;
        if(!mk[i]&&!dr[x2][y2]&&!dr[x1][y1])
        {
            c[k]=i;
            mk[i]=1;
            dr[x2][y2]=1;
            dr[x1][y1]=1;
            get(k+1);
            dr[x2][y2]=0;
            dr[x1][y1]=0;
            mk[i]=0;
        }
    }
}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    cn=0;
    ms(mk,0);
    ms(dr,0);
    get(0);
    cout<<cn<<endl;

    return 0;
}
