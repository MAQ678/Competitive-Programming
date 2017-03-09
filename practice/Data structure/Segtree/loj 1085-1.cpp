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
int md=1000000007;
int a[1<<20],b[1<<20];
struct st
{
    int val,mn,cnt;
}tr[1<<20];

void up(int r,int s,int e,int pos,int tcn)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r].val=tr[r].mn=a[pos];tr[r].cnt=tcn;
        return;
    }
    int mid=(s+e)>>1;
    up(r*2,s,mid,pos,tcn);up(r*2+1,mid+1,e,pos,tcn);
    tr[r].cnt=tr[r*2].cnt+tr[r*2+1].cnt;
    tr[r].val=max(tr[r*2].val,tr[r*2+1].val);
    tr[r].mn=min(tr[r*2].mn,tr[r*2+1].mn);
    if(tr[r].mn==0)
    {
        tr[r].mn=max(tr[r*2].mn,tr[r*2+1].mn);//
    }
}

int query(int r,int s,int e,int val)//ekhane problem ase may be O(nlogn)
{
    if(tr[r].mn>val||tr[r].mn==0||tr[r].val==0)return 0;
    if(tr[r].val<=val)return tr[r].cnt;
    if(s==e)
    {
        return 0;
    }
    int mid=(s+e)>>1,p=0;
    return (query(r*2,s,mid,val)%md+query(r*2+1,mid+1,e,val)%md)%md;
}
void init(ll r,ll s,ll e)
{
    if(s==e)
    {
        tr[r].val=tr[r].cnt=tr[r].mn=0;
        return;
    }
    int mid=(s+e)>>1;
    init(r*2,s,mid);init(r*2+1,mid+1,e);
    tr[r].val=tr[r].cnt=tr[r].mn=0;//tr[r].an=0;
}

int main()
{
    int t,z,n,i,cn,mx;
    map<int,int>mp;
    sf("%d",&t);
    fr1(z,t)
    {
        mp.clear();
        sf("%d",&n);
        fr(i,n)sf("%d",&a[i]),b[i]=a[i];
        sort(b,b+n);
        cn=1;
        fr(i,n)if(!pr(mp,b[i]))mp[b[i]]=cn,cn++;
        fr(i,n)a[i]=mp[a[i]];//compress the values, where min is 1

        init(1,0,n-1);
        fr(i,n)
        {

            mx=query(1,0,n-1,a[i]-1);
            up(1,0,n-1,i,mx+1);
            //cout<<tr[1].mn<<" "<<tr[1].val<<" "<<tr[1].cnt;nl;
        }
        pf("Case %d: %d\n",z,tr[1].cnt);

    }
    return 0;
}

