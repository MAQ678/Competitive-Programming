//Bismillahir Rahmanir Rahim
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
#define sf2(a,b)  sf("%lld%lld",&a,&b)
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




struct P
{
    double x;
    double y;

    P(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};

P MV(P aa,P bb){ return P(bb.x-aa.x,bb.y-aa.y);}//Make Vector
double CP(P aa,P bb){ return (aa.x*bb.y-aa.y*bb.x);}//Cross Product
double DP(P aa,P bb){ return (aa.x*bb.x+aa.y*bb.y);}
double VA(P aa){return (sqrt(DP(aa,aa)*1.0));}
double dis(P aa,P bb){return (((aa.x-bb.x)*(aa.x-bb.x))+((aa.y-bb.y)*(aa.y-bb.y)));}

P ROT(P aa,double rad){return P(aa.x*cos(rad)-aa.y*sin(rad),aa.x*sin(rad)+aa.y*cos(rad));}

double angle(P aa,P bb)
{
    return acos((DP(aa,bb)*1.0)/(VA(aa)*VA(bb)));
}

vector<P>s;

bool cmp(P a,P b)
{
    if(a.y<b.y)return 1;
    else if(a.y==b.y)return a.x<b.x;
    return 0;
}
P h[100005];
int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    P down,up,w1,w2;
    double x,y;
    int c,st,k=0;,i,j;
    double mx;
    double an1,an2;
    sf1(c);
    fr(i,c)sf2(x,y),s.pb(P(x,y));
    sort(all(s),cmp);

    fr(i,c)
    {
        while(k>=2&&CP(MV(h[k-2],s[i]),MV(h[k-1],s[i]))<0)k--;
        h[k++]=s[i];
    }
    st=k;
    for(i=c-2;i>=0;i--)
    {
        while(k>st&&CP(MV(h[k-2],s[i]),MV(h[k-1],s[i]))<0)k--;
        h[k++]=s[i];
    }
    k--;
    cout<<st<<endl;
    fr(i,k)pf("%llf %llf\n",h[i].x,h[i].y);


    w1=P(inf,h[0].y);
    w2=P(-inf,h[st-1].y);
    down=MV(h[0],w1);
    up=MV(h[st-1],w2);
    i=1;
    j=st;
    mx=dis(h[0],h[st-1]);
    while(i<st&&j<k)
    {
        w1=MV(h[i-1],h[i]);
        w2=MV(h[j-1],h[j]);

        an1=angle(down,w1);
        an2=angle(up,w2);

        down=ROT(down,an1);

        if(fabs(an1-an2)<=eps)
        {

            down=ROT(down,an1);
            up=ROT(up,an1);
            mx=max(mx,dis(h[i-1],h[j]));
            mx=max(mx,dis(h[i],h[j]));
            mx=max(mx,dis(h[i],h[j-1]));//extra
            i++;j++;
        }
        else if(an1<an2+eps)
        {
            //take i
            down=ROT(down,an1);
            up=ROT(up,an1);
            mx=max(mx,dis(h[i],h[j-1]));
            i++;
        }
        else
        {
            down=ROT(down,an2);
            up=ROT(up,an2);
            mx=max(mx,dis(h[i-1],h[j]));
            j++;
        }
    }

    //now rotate

    return 0;
}
