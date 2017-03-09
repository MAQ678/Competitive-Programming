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

struct st
{
    int data,nxt[2];
    st()
    {
        data=0;nxt[0]=nxt[1]=0;
    }
}tr[1<<17];
int cnt=1;
int pow(int cn)
{
    int z=1;
    while(cn--)
    {
        z=z*2;
    }
    return z;
}
int search(string& s)
{
    int i,l=s.length(),p=0,sm=0,x,y;
    fr(i,l)
    {
        x=s[i]-'0';
        y=(x+1)&1;
        if(tr[p].nxt[y])
        {
            sm+=pow(l-i-1);
            p=tr[p].nxt[y];
        }
        else
        {
            p=tr[p].nxt[x];
        }
    }
    return sm;
}

void insert(string& s)
{
    int i,l=s.length(),x,p=0;
    fr(i,l)
    {
        x=s[i]-'0';
        if(!tr[p].nxt[x])tr[p].nxt[x]=cnt++;
        p=tr[p].nxt[x];
    }
}

int a[100000];

int len;
int fun(int v)
{

int i,w,val;
    string s;
    //fr(i,n)
    {
        s="";w=0;
        while(v>=(1<<w))
        {
            if(v&(1<<w))s+='1';
            else s+='0';
            w++;
        }
        while(w<len)
        {
            s+='0';
            w++;
        }
        reverse(all(s));
       // cout<<s<<"  ll"<<endl;
        val=search(s);
        insert(s);
    }
    return max(v,val);
}

int main()
{
    int n,i,j,v,w,mx=0,as=0,bs=0;;
    cin>>n;
    fr(i,n)sf("%d",&a[i]),bs=bs^a[i],as=max(as,bs);//,as=max(as,a[i]);

    //max length
    w=0;
    while(as>=(1<<w))
        {
            w++;
        }
    len=w;
    //
   // len=32;
    v=0;
    fr(i,n)
    {
        v=v^a[i];
        mx=max(mx,fun(v));
    }


    cout<<mx;nl;
    return 0;
}


