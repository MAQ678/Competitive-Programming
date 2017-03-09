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
ll M=100000007;
inline ll pow(ll n,ll m)
{
    ll z=1;
    while(m--)z*=n;
    return z;
}

inline ll bigmod(ll b,ll p)
{
    ll res=1;
    for(; p; p>>=1,b=b*b%M)if(p&1)res=res*b%M;
    return res;
}
inline ll InverseM(ll n)
{
    return bigmod(n,M-2);
}




//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction



#define MAX_N 50005
string T; // the input string,
int n; // length of input string
int RA[20][MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N]; // for counting/radix sort
int stp;
void countingSort(int k)   // O(n)
{
    int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c); // clear frequency table
    for (i = 0; i < n; i++) // count the frequency of each integer rank
        c[i + k < n ? RA[stp-1][i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++)
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++) // shuffle the suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[stp-1][SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++) // update the suffix array SA
        SA[i] = tempSA[i];
}


void suf()
{
    int i, k, r;
    for (i = 0; i < n; i++) RA[0][i] = T[i]; // initial rankings
    for (i = 0; i < n; i++) SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}
    for (stp=1,k = 1; k < n; stp++,k <<= 1)   // repeat sorting process log n times
    {
        countingSort(k); // actually radix sort: sort based on the second item
        countingSort(0); // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++) // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
                (RA[stp-1][SA[i]] == RA[stp-1][SA[i-1]] && RA[stp-1][SA[i]+k] == RA[stp-1][SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++) // update the rank array RA
            RA[stp][i] = tempRA[i];
        if (RA[stp][SA[n-1]] == n-1) break; // nice optimization trick
    }
}



int lcp(int x,int y)
{
    if (x == y) return n-x;
    int i,an=0;
    for(i=stp-1; x<n&&y<n&&i>=0; i--)
        if(RA[i][x]==RA[i][y])
            an+=(1<<i),x+=(1<<i),y+=(1<<i);
    return an;
}






int main()
{
    // freopen("D:\\Coding\\in.txt","r",stdin);
    // freopen("D:\\Coding\\out.txt","w",stdout);
    int t,i,j,x,ly,ry,w,z;
    string a,b;
    int ans;
    cin>>t;
    fr1(z,t)
    {
        cin>>a>>b;
        T=a+'{'+b+'$';
        n = T.length();
        suf();

        for ( i = 0; i < n; i++) printf("%2d\t\n", SA[i]);

        ans=0;
        ly=-1;
        x=-1;
        //cout<<T<<endl;
        cout<<n<<endl;
i=n-2;
cout<<i<<endl;
        for(; i>=1; i--)
        {
            if(ly==-1||ly<=SA[i])
            {
                w=ly;
                j=i;
                while(1)
                {
                    if((j&&SA[j]<=a.length())||i==j)
                        j--;
                    else
                    {
                        w=SA[j];
                        break;
                    }
                }
                ry=ly;
                if(ly==-1)ry=w;
                ly=w;
            }
            //  if(SA[i]>a.length())y=SA[i];
            if(SA[i]<a.length())
            {
                ans+=(((n-SA[i]-1)/*current length*/-max(lcp(SA[i],SA[i-1]),max(lcp(SA[i],ly),lcp(SA[i],ry))))-(b.length()+1));
            }
        }
        pf("%d\n",ans);
         cout<<"Case "<<z<<": "<<ans;nl;
    }

    return 0;
}




