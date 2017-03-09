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
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())
int mn[200][40];
int lg(int n)
{
    int mxlen;
    mxlen=0;
    while((1<<mxlen)<n)
        mxlen++;
    return mxlen;
}

int main()
{

    int n,i,mxlen,j;
    cin>>n;
    fr(i,n)cin>>mn[i][0];

    mxlen=lg(n);

    fr1(j,mxlen)
    {
        fr(i,n)
        {
            if(i+(1<<j)>=n)break;
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<j)][j-1]);
        }
    }

    int x,y,l,v;
    cout<<"Give range: ";nl;
    while(cin>>x>>y)
    {

        l=lg(y-x+1);//0- based indexing
        cout<<l<<endl;

        v=inf;
        v=min(v,mn[x][l]);
        x+=(1<<l);
        for(i=l;i>=0;i--)
        {
            if((x+(1<<i))<=y)//check range
            v=min(v,mn[x][i]),
            x+=(1<<i);
        }
        cout<<v;nl;

    }



    return 0;
}
