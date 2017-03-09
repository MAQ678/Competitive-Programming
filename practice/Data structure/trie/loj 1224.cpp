//Bismillahir Rahmanir Rahim
//Opu-1204026
//.192
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


struct st
{
    int data,nxt[4];
    st()
    {
        data=0;
        int i;
        fr(i,4)nxt[i]=0;
    }
}tr[1<<20];
int cnt;
int sm;
string ss="ACGT";
void insert(string& s)
{
    int i,l=s.length(),x,p=0,j;
    fr(i,l)
    {
        fr(j,4)if(s[i]==ss[j])
        {
            x=j;
            break;
        }
        if(tr[p].nxt[x]==0)
        {
            tr[p].nxt[x]=cnt++;
        }
        p=tr[p].nxt[x];
        tr[p].data++;
        sm=max(sm,tr[p].data*(i+1));
    }

}

int main()
{
    _;ct;
    string s;
    int t,z,n,i,mx,l,j;
    cin>>t;
    fr1(z,t)
    {
        cin>>n;
        cnt=1;
        sm=0;mx=0;
        fr(i,n)
        {
            cin>>s;
            l=s.length();
            mx=max(mx,l);
            insert(s);
        }
        fr(i,cnt+1)
        {
            tr[i].data=0;
            ms(tr[i].nxt,0);
        }
        cout<<"Case "<<z<<": ";
        cout<<sm;nl;
    }
    return 0;
}

