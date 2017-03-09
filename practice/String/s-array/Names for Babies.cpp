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





//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

struct st
{
    int p,ra[2];
} L[10005];

string s;
int sa[15][10005],la[10005],stp,n;

bool cmp(st x,st y)
{
    if(x.ra[0]<y.ra[0])return 1;
    if(x.ra[0]==y.ra[0])return x.ra[1]<y.ra[1];
    return 0;
}


void suf()
{
    int i,j,cnt;
    n=s.length();
    fr(i,n)sa[0][i]=s[i]-'a';

    for(stp=1,cnt=1; cnt>>1 <n; stp++,cnt<<=1)
    {
        fr(i,n)
        {
            L[i].p=i;
            L[i].ra[0]=sa[stp-1][i];
            L[i].ra[1]=(i+cnt<n)?sa[stp-1][i+cnt]:-1;
        }
        sort(L,L+n,cmp);
        fr(i,n)
        {
            sa[stp][L[i].p]=i;
            if(i&&L[i].ra[0]==L[i-1].ra[0]&&L[i].ra[1]==L[i-1].ra[1])
                sa[stp][L[i].p]=sa[stp][L[i-1].p];
        }
    }
}

int lcp(int x,int y)
{
    int i,an=0;
    for(i=stp-1; x<n&&y<n&&i>=0; i--)
        if(sa[i][x]==sa[i][y])
            an+=(1<<i),x+=(1<<i),y+=(1<<i);
    return an;
}

//void lcpa()
//{
//    int i;
//    fr(i,n)
//    la[i]=lcp(i,i+1);
//
//}


int main()
{
    // freopen("D:\\Coding\\in.txt","r",stdin);
    // freopen("D:\\Coding\\out.txt","w",stdout);
      _;ct;
    int t,z,p,q,i,ans,lc,w;

    cin>>t;
    fr1(z,t)
    {
        cin>>s>>p>>q;
        suf();
//        lcpa();
//        fr(i,n)cout<<L[i].p<<" ";
//        nl;//suffix array
//        fr(i,n)cout<<la[i]<<" ";nl;
     /*   while(cin>>p>>q)
        {
            cout<<lcp(L[p].p,L[q].p)<<endl;
            cout<<lcp(p,q)<<endl;nl;
        }

        nl;*/
        ans=max(0,min(q,n-L[0].p)-(p-1));
        fr1(i,n-1)
        {
            lc=lcp(L[i-1].p,L[i].p);
            ans+=max(0,min(q,n-L[i].p)-max(p-1,lc));
        }
        cout<<"Case "<<z<<": "<<ans;
        nl;
    }

    return 0;
}

