//Bismillahir Rahmanir Rahim
//Opu-1204026
//.756
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


int a[2001][2001],b[2001][2001];
char ch[2001][2001];

int get(int in,int n)
{
    stack<ii> s;
    int i,j,an,mx=0;
    fr(i,n)
    {

        while(!s.empty()&&s.top().ft>b[in][i])
        {
            j=s.top().sd;
            an=s.top().ft;
            s.pop();
            if(s.size())
            {
                mx=max(mx,an*(i-s.top().sd-1));
            }
            else
            {
                mx=max(mx,an*(i));
            }
        }
        if(!s.empty()&&s.top().ft==b[in][i])s.pop();
        s.push(mp(b[in][i],i));
    }
    if(!s.empty())
    {
        j=n-1;
        an=s.top().ft;
        s.pop();
        while(!s.empty())
        {
            mx=max(mx,an*(j-s.top().sd));
            an=s.top().ft;//,j=s.top().sd;
            s.pop();
        }
        mx=max(mx,an*(j+1));
    }
    return mx;

}


int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
    // freopen("F:\\Coding\\out.txt","w",stdout);
    int i,j,n,m,t,an,sm,z;
//  Reader rr;
    // t=rr.next_u32();
    sf("%d",&t);
    fr1(z,t)
    {
        //  n=rr.next_u32();m=rr.next_u32();
        sf("%d%d",&n,&m);
        fr(i,n)sf("%s",ch[i]);
        ms(b,0);
        //fr(i,n)fr(j,m)a[i][j]=ch[i][j]-'0';
        for(j=m-1; j>=0; j--)
            for(i=n-1; i>=0; i--)
            {
                if((ch[i][j]-'0')==1)b[i][j]=0;
                else
                {
                    if(i<n-1)
                        b[i][j]=b[i+1][j]+1;
                    else b[i][j]=1;
                }
            }
        an=0;
        fr(i,n)
        {
            an=max(an,get(i,m));
        }
        pf("Case %d: %d\n",z,an);
    }

    return 0;
}


