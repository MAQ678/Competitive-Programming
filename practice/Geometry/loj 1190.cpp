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

struct P
{
    int x,y;
    P(int x=0,int y=0)
    {
        this->x=x;this->y;
    }

};



//2D Start
P MV(P aa,P bb){ return P(bb.x-aa.x,bb.y-aa.y);}//Make Vector
int DP(P aa,P bb){ return (aa.x*bb.x+aa.y*bb.y);}//Dot Product
int CP(P aa,P bb){ return (aa.x*bb.y-aa.y*bb.x);}//Cross Product
///double V(P aa){return (aa.x*aa.x+aa.y*aa.y);}//Value of Vector
double VA(P aa){return (sqrt(DP(aa,aa)));}//Value of Vector
P VL(P aa,double l){ double m=VA(aa); return P((aa.x/m)*l,(aa.y/m)*l);}// Make Vector of 'l' length
int TRIANGLE(P aa,P bb){ return (CP(aa,bb));}//Area of Triangle
P ROT(P aa,double rad){return P(aa.x*cos(rad)-aa.y*sin(rad),aa.x*sin(rad)+aa.y*cos(rad));} //rotation with an angle(on radian)
//2D End
double dis(P aa,P bb){return (((aa.x-bb.x)*(aa.x-bb.x))+((aa.y-bb.y)*(aa.y-bb.y)));}







//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

vector<P>p;

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int t,i,z,x,y,n,q,tn,pre;
    P r,a,b,u;
    r=P(0,0);
    sf1(t);
    fr1(z,t)
    {
        p.clear();
        sf1(n);
        fr(i,n)sf2(x,y),p.pb(P(x,y));
        tn=0;
        fr1(i,n-1)
        {
            a=MV(r,p[i-1]);
            b=MV(r,p[i]);
            tn+=TRIANGLE(a,b);//divide by 2 is missing
        }
        pre=0;
        sf1(q);
        while(q--)
        {
            sf2(x,y);
            u=P(x,y);
            pre=0;
            fr1(i,n-1)
            {
                a=MV(u,p[i-1]);
                b=MV(u,p[i]);
                pre+=TRIANGLE(a,b);
            }
            if(pre==tn)
            {
                pf("Yes\n");
            }
            else pf("No\n");
        }
    }

    return 0;
}
