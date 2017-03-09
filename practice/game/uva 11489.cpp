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
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

vi v;
int n;
bool vis[1002];

int fun(int t)
{
    if(t==0)return 0;
    int k,an=0;
    fr(k,n)
    {
        if(!vis[k]&&(t-v[k])%3==0)
        {
            an=an|fun(t-v[k]);
            break;
        }
    }
    if(an==0)return 1;
    return 0;
}

int main()
{
    string s;
    int t,z,an=0,va,ans=0,i;
    cin>>t;
    fr1(z,t)
    {
        cin>>s;
        v.clear();
        n=s.length();
        an=0;
        fr(i,n)
        {
            va=s[i]-'0';
            v.pb(va);
            an+=va;
        }
        ms(vis,0);
        ans=0;
        fr(i,n)
        {
            if((an-v[i])%3==0)
            {
                //cout<<i;nl;
                vis[i]=1;
                if(!fun(an-v[i]))
                {
                    ans=1;
                    break;
                }
                vis[i]=0;

            }
        }
        if(ans)cout<<"S",nl;
        else cout<<"T",nl;
    }
    return 0;
}

