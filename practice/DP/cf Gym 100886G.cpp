//digit
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
typedef      pair<ll,string>is;
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

string a,b;
is dp[20][2];
bool vis[20][2];

is fun(int i,int ck)
{
    if(i>=b.length())
    {
        return is(0,"");
    }
    if(vis[i][ck])return dp[i][ck];
    ll j,lm,v;
    string s;
    if(!ck)
    {
        j=1;
        while(i<b.length())
        {
            j*=9;
            j++;
            s+='9';
        }
        return is(j,s);
    }

    is w,m;
    char c;
    m=is(0,"");
    lm=b[i]-'0';
    fr1(j,lm-1)
    {
        w=fun(i+1,0);
        w.ft*=j;
        c=j+'0';
        w.sd=c+w.sd;
        if(w.ft>=m.ft)
        {
            m=w;
        }
    }
    w=fun(i+1,1);
    w.ft*=lm;
    w.sd=b[i]+w.sd;
    if(w.ft>=m.ft)
    {
        m=w;
    }
    return dp[i][ck]=m;
}


int main()
{
    // freopen("D:\\Coding\\in.txt","r",stdin);
    // freopen("D:\\Coding\\out.txt","w",stdout);
    ll i,x,y;
    stringstream ss;
    cin>>x>>y;
    ss<<x;
    ss>>a;
    ss.clear();
    ss<<y;
    ss>>b;
    ss.clear();
    if(a.length()<b.length())
    {

        //now max is 9^(b.length()-1)
        a=1;
        fr1(i,b.length()-1)a+='0';
    }
    ms(vis,0);
    is an1=fun(0,0);
    is an2=fun(0,1);
    if(an1<an2)an1=an2;
    cout<<an2.sd;
    nl;




    return 0;
}

