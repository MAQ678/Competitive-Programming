//Bismillahir Rahmanir Rahim
//Opu-1204026
//here sequence start from 0 based index
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
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

struct matrix
{
    int v[3][3],row,col;
};
int mod=1000007;
matrix mul(matrix a,matrix b)
{
    matrix r;r.row=a.row;r.col=b.col;
    int i,j,sm,k;
    fr(i,r.row)
        fr(j,r.col)
        {
            sm=0;
            fr(k,a.col)sm+=a.v[i][k]*b.v[k][j],sm%=mod;
            r.v[i][j]=sm;
        }
    return r;
}

matrix power(matrix T,int p)
{
    if(p==1)return T;
    if(p%2==1)return mul(T,power(T,p-1));
    matrix ret=power(T,p/2);ret=mul(ret,ret);
    return ret;
}

int main()
{
    matrix T;
    T.row=T.col=2;
    T.v[0][0]=0,T.v[0][1]=T.v[1][0]=T.v[1][1]=1;
    matrix f;
    f.v[0][0]=1,f.v[1][0]=1;f.row=2,f.col=1;
    int n;sf("%d",&n);
    T=power(T,n-1);f=mul(T,f);
    pf("%d\n",f.v[1][0]);
}

