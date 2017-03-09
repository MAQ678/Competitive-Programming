//Bismillahir Rahmanir Rahim
//Opu-1204026
//1.052
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
    int x,y;
}p[50005];
int qr[50005];
int tr[1<<20],la[1<<20];

void init(int r,int s,int e)
{
    tr[r]=0,la[r]=0;
    if(s==e)return;
    int mid=(s+e)>>1;
    init(r*2,s,mid);init(r*2+1,mid+1,e);
}

void up(int r,int s,int e,int L,int R)
{
    if(la[r])
    {
        if(s==e)
        tr[r]+=la[r];
        if(s!=e)la[r*2]+=la[r],la[r*2+1]+=la[r];
        la[r]=0;
    }
    if(s>R||e<L)return;
    if(s>=L&&e<=R)
    {
        if(s==e)
        tr[r]++;
        if(s!=e)la[r*2]++,la[r*2+1]++;
        return;
    }
    int mid=(s+e)>>1;
    up(r*2,s,mid,L,R);up(r*2+1,mid+1,e,L,R);
    //tr[r]=tr[r*2]+tr[r*2+1];
}

int query(int r,int s,int e,int pos)
{
    if(la[r])
    {
        if(s==e)
        tr[r]+=la[r];
        if(s!=e)la[r*2]+=la[r],la[r*2+1]+=la[r];
        la[r]=0;
    }
    if(s>pos||e<pos)return 0;
    if(s==e) return tr[r];
    int mid=(s+e)>>1;
    return query(r*2,s,mid,pos)+query(r*2+1,mid+1,e,pos);
}

int main()
{
    int t,z,n,q,i,j,l,r,cn;
    vi v;
    map<int,int>mp;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&q);
        v.clear();
        mp.clear();
      // s.clear();
        cn=0;
        fr(i,n)
        {
            sf("%d%d",&p[i].x,&p[i].y);
            if(!pr(mp,p[i].x))mp[p[i].x]=1,v.pb(p[i].x);
            if(!pr(mp,p[i].y))mp[p[i].y]=1,v.pb(p[i].y);
        }
        fr(i,q)
        {
            sf("%d",&qr[i]);
            if(!pr(mp,qr[i]))mp[qr[i]]=1,v.pb(qr[i]);
        }
        sort(all(v));
        mp.clear();
        fr(i,v.size())mp[v[i]]=i+1;

        //compression complete

        cn=v.size();
        init(1,0,cn);
        fr(i,n) up(1,0,cn,mp[p[i].x],mp[p[i].y]);
        pf("Case %d:\n",z);
        fr(i,q) pf("%d\n",query(1,0,cn,mp[qr[i]]));
    }
    return 0;
}

