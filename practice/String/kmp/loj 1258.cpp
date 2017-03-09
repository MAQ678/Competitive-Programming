//Bismillahir Rahmanir Rahim
//Opu-1204026
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
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

string s,s1;
int n,pp[1000005];
void pref()
{
  //  cout<<s1<<endl;
    int i,j;j=0;pp[0]=0;
    fr1(i,n-1)
    {
        while(j>0&&s1[i]!=s1[j])j=pp[j-1];
        if(s1[i]==s1[j])j++;
        pp[i]=j;
    }
}

int kmp()
{
    int i,j,mx=0;pref();j=0;
    fr(i,n)
    {
        while(j>0&&s[i]!=s1[j])j=pp[j-1];
        if(s[i]==s1[j])j++;
    }
    return j;
}

int main()
{
   _;ct;
   int t,z,an,i;
    cin>>t;
    fr1(z,t)
    {
        cin>>s;s1=s;
        reverse(all(s1));
        n=s.length();an=kmp();
        an=an+(n-an)*2;
        cout<<"Case "<<z<<": "<<an;nl;
    }

    return 0;
}

