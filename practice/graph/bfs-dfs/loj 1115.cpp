//Bismillahir Rahmanir Rahim
//0.040

//at first when a color has been seen, we will process this color if it is not been processed yet
//the in a function for every point i will check that by coloring if it will be under that colored region
//the trick i used here is , if a point is in under a region. We cant come out from the map ,if we consider all points except the region color

//the after confirmed ,,simply fill the region with the color
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
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction

char s[55][55];
bool vis[55][55];
int n,m,ok[30];

int check(int i,int j,char c)
{
    int x,y,k;
    vis[i][j]=1;
    int a=1;
    fr(k,4)
    {
        x=i+dx[k];y=j+dy[k];
        if(x<0||y<0||x>=m||y>=n)
        {
            a=0;continue;
        }
        if(!vis[x][y]&&s[x][y]!=c)
            a&=check(x,y,c);
    }
    return a;
}

void color(int i,int j,char c)
{

    s[i][j]=c;
    int k,x,y;
    fr(k,4)
    {
        x=i+dx[k];y=j+dy[k];
        if(s[x][y]!=c)
        color(x,y,c);
    }
}

void make(char c)
{
    //check(3,3,'B');
    //cout<<"ff";nl;
    int i,j;
    ms(vis,0);
    fr(i,m)
    {
        fr(j,n)
        {
            if(!vis[i][j]&&s[i][j]!=c&&check(i,j,c))
            {
                color(i,j,c);
            }
        }
    }

}



int main()
{
       // freopen("D:\\Coding\\in.txt","r",stdin);
       // freopen("D:\\Coding\\out.txt","w",stdout);
    int t,z,i,j;
    sf1(t);
    fr1(z,t)
    {
        sf2(m,n);
        fr(i,m)sf("%s",s[i]);
        ms(ok,0);
    ///ms(cover,0);//0 amount of work done
        fr(i,m)
        {
            fr(j,n)
            {
                if(s[i][j]!='.'&&!ok[s[i][j]-'A'])
                {
                    ok[s[i][j]-'A']=1;
                    make(s[i][j]);
                }
            }
        }
        pf("Case %d:\n",z);
        fr(i,m)pf("%s\n",s[i]);
    }

    return 0;
}


