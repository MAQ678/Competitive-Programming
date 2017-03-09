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
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

int n,m,p[1005],st[10005];
string s,s1;

void pref()
{
    int i,j;
    j=0;p[0]=0;
    fr1(i,m-1)
    {
        while(j>0&&s1[i]!=s1[j])j=p[j-1];
        if(s1[i]==s1[j])j++;
        p[i]=j;
    }
}

void kmp()
{
    pref();
    int i,j=0,be;
    ms(st,0);
    fr(i,n)
    {
        while(j>0&&s[i]!=s1[j])j=p[j-1];
        if(s[i]==s1[j])j++;
        if(j==m)
        {
            st[i]=2;
            be=i-j;
            if(st[be]==2)st[be]=3;
            else st[be]=1;

            j=p[j-1];
        }
    }
}

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);

   while(cin>>s>>s1)
   {
        n=s.length();m=s1.length();
        kmp();
   }

    return 0;
}

