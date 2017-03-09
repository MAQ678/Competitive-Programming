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

int Mod;

struct Mat
{
    int a[6][6];
    void clear()
    {
        ms(a,0);
    }
    void one()
    {
        int i;
        ms(a,0);
        fr(i,6)a[i][i]=1;
    }
    Mat operator *(const Mat &b)const
    {
        Mat tmp;
        tmp.clear();
        int i,j,k;
        fr(i,6)fr(j,6)fr(k,6)
        {
            tmp.a[i][j]+=(ll)(a[i][k]*b.a[k][j])%Mod;
           // if(tmp.a[i][j]>=Mod)tmp.a[i][j]-=Mod;
        }
        return tmp;
    }
    Mat pow(int x)
    {
        Mat ans,num=*this;
        ans.one();
        while(x)
        {
            if(x&1)ans=ans*num;
            num=num*num;
            x>>=1;
        }
        return ans;
    }


};
int p[3],q[3],g[3],f[3];
Mat m,id;
Mat mPow(Mat wm,int n)
    {
        if(n==0)return id;
        Mat ha=mPow(wm,n/2);
        Mat out=ha*ha;
        if(n&1)out=out*wm;
        return out;
    }
void init()
{
    m.clear();
    id.one();
    int i;
    fr(i,3)m.a[0][i]=p[i];
    fr(i,3)m.a[1][i+3]=q[i];
    m.a[2][0]=m.a[3][1]=m.a[4][3]=m.a[5][4]=1;
}

int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int i,t,z,n,d;
    ll an1,an2;

    sf1(t);
    fr1(z,t)
    {
        fr(i,3)sf1(p[i]);
        fr(i,3)sf1(q[i]);
        fr(i,3)sf1(f[i]);
        fr(i,3)sf1(g[i]);
        sf1(Mod);
        sf1(d);
        while(d--)
        {
            sf1(n);
            if(n<3)pf("%d %d\n",f[n]%Mod,g[n]%Mod);
            else
            {
                init();
                m=mPow(m,n-2);
                fr(i,6)
                {
                    fr(an1,6)
                    {
                        pf("%d ",m.a[i][an1]);
                    }
                    nl;
                }
                an1=f[2]*m.a[0][0]+f[1]*m.a[0][1]+g[0]*m.a[0][2];
                an2=g[2]*m.a[1][3]+g[1]*m.a[1][4]+f[0]*m.a[1][5];
                pf("%lld %lld\n",an1%Mod,an2%Mod);
            }
        }
    }

    return 0;
}

