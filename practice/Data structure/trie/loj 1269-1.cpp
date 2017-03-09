//Bismillahir Rahmanir Rahim
//Opu-1204026
//.612
//learn
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

int a[50002];
int len;
struct st
{
    int nxt[2];
    st()
    {
        nxt[0]=nxt[1]=0;
    }
}tr[1<<20];
int cnt;
void insert(string& s)
{
    int i,l=s.length(),p=0,x;
    fr(i,l)
    {
        x=s[i]-'0';
        if(!tr[p].nxt[x])tr[p].nxt[x]=cnt++;
        p=tr[p].nxt[x];
    }
}

int pow(int cn)
{
    int z=1;
    while(cn--)z*=2;
    return z;
}

ii query(string& s)
{
    int i,l=s.length(),p=0,mx=0,mn=0,x,y;
    fr(i,l)//max
    {
        x=s[i]-'0';
        y=(x+1)&1;
        if(tr[p].nxt[y])
        {
            p=tr[p].nxt[y];
            mx+=pow(l-i-1);
        }
        else
            p=tr[p].nxt[x];
    }
    p=0;
    fr(i,l)//min
    {
        x=s[i]-'0';
        y=(x+1)&1;
        if(tr[p].nxt[x])
        {
            p=tr[p].nxt[x];

        }
        else {
                mn+=pow(l-i-1);
                p=tr[p].nxt[y];

            }
    }
    return mp(mx,mn);
}

ii fun(int v)
{
    int i,w=0,z=v;ii an;
    string s="";
    while(v)
    {
        s+=((v&1)+'0');
        w++;
        v>>=1;
    }
    while(w<len)w++,s+='0';
    reverse(all(s));
    an=query(s);
    insert(s);
    return mp(max(an.ft,z),min(an.sd,z));
}
int main()
{
    int t,z,n,i,w,mx,d,mn;
    ii an;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d",&n);
        cnt=1;
        d=0,mx=0;len=0;
        fr(i,n)sf("%d",&a[i]),d=d^a[i],mx=max(d,mx);
        while(mx)
        {
            mx>>=1;
            len++;
        }
        d=0;mx=0,mn=inf;
        fr(i,n)
        {
            d=d^a[i];
            an=fun(d);
            mx=max(mx,an.ft);
            mn=min(mn,an.sd);
        }
        fr(i,cnt+2)ms(tr[i].nxt,0);
        pf("Case %d: %d %d\n",z,mx,mn);
    }
    return 0;
}
