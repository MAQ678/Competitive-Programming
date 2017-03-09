//Bismillahir Rahmanir Rahim
//Opu-1204026
//help
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

string s;
int n,p[2000000];
void pref()
{
    int i,j;
    j=0,p[0]=0;
    fr1(i,n-1)
    {
        while(j>0&&s[i]!=s[j])j=p[j-1];
        if(s[i]==s[j])
            j++;
        p[i]=j;
    }
}
int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
   _;ct;
int i,j,b,q,an;
   while(cin>>s)
   {
       if(s==".")break;
       n=s.length();
       pref();
        an=n/(n-p[n-1]);
        if(an*((n-p[n-1]))!=n)an=1;
        cout<<an;nl;
   }

    return 0;
}

