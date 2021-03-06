//tangent of lines is m=dx/dy, by calculating for each pair and counting equal ones ,we can get the answer.

#include<bits/stdc++.h>
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


vector<ii>v;
map<ii,int>m;
int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int t,n,i,a,b,z,w,mx,j;
    sf1(t);
    fr1(z,t)
    {
        mx=0;
        v.clear();
        sf1(n);
        fr(i,n)sf2(a,b),v.pb(ii(a,b));
        fr(i,n)
        {
            m.clear();
            fr(j,n)
            {
                if(i!=j)
                {
                    a=(v[i].sd-v[j].sd);
                    b=(v[i].ft-v[j].ft);
                    if(a*b>=0)a=abs(a),b=abs(b);
                    if(b<0)a=-a,b=abs(b);
                    if(a==0&&b!=0)b=1;
                    else if(a!=0&&b==0)a=1;
                    else if(a!=0&&b!=0)
                    {
                        w=__gcd(abs(a),b);
                        a/=w;b/=w;
                    }
                    m[ii(a,b)]++;
                    mx=max(mx,m[ii(a,b)]);

                }
            }
        }
        pf("Case %d: %d\n",z,mx+1);
    }
    return 0;
}

