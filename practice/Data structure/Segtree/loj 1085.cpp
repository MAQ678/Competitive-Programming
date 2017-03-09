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
#define inf     1<<34
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
ll md=1000000007;


struct st
{
    ll val,cnt,mn;//,an;
}tr[1<<20];
bool u;
void init(ll r,ll s,ll e)
{
    if(s==e)
    {
        tr[r].val=-inf;tr[r].cnt=0;//tr[r].an=0;
        return;
    }
    ll mid=(s+e)>>1;
    init(r*2,s,mid);init(r*2+1,mid+1,e);
    tr[r].val=-inf;tr[r].cnt=0;//tr[r].an=0;
}

void update(ll r,ll s,ll e,ll pos,ll tc,ll val)
{
    if(s>pos||e<pos)return;
    if(s==e)
    {
        tr[r].val=val;tr[r].cnt=tc;//
        return;
    }
    ll mid=(s+e)>>1;
    update(r*2,s,mid,pos,tc,val);
    update(r*2+1,mid+1,e,pos,tc,val);
    tr[r].val=max(tr[r*2].val,tr[r*2+1].val);
    tr[r].cnt=(tr[r*2].cnt%md+tr[r*2+1].cnt%md)%md;
}

/*ll query1(ll r,ll s,ll e,ll val)
{
    if(s==e)
    {
        if(tr[r].val<=val)
        {
            u=1;
            return tr[r].val;
        }
        else return -inf;
    }
    if(tr[r].val<=val)
    {
        u=1;
        return tr[r].val;
    }
    ll mid=(s+e)>>1;
    return max(query1(r*2,s,mid,val),query1(r*2+1,mid+1,e,val));
}

ll query2(ll r,ll s,ll e,ll val)
{
    if(s==e)
    {
        if(tr[r].val==val)return tr[r].cnt;
        else return 0;
    }
    ll mid=(s+e)>>1,p=0;
    if(tr[r*2].val>=val)p+=query2(r*2,s,mid,val);
    if(tr[r*2+1].val>=val)p+=query2(r*2+1,mid+1,e,val);
    return p;
}
*/
ll query3(ll r,ll s,ll e,ll val)
{
    if(s==e)
    {
        if(tr[r].val<val)return tr[r].cnt;
        return 0;
    }
    if(tr[r].val<val)return tr[r].cnt;
    ll mid=(s+e)>>1;
    return (query3(r*2,s,mid,val)%md+query3(r*2+1,mid+1,e,val)%md)%md;
}

int main()
{
    ll t,z,n,i,v,w,mx,tot;
    sf("%lld",&t);
    fr1(z,t)
    {
        sf("%lld",&n);
        init(1,0,n-1);
        fr(i,n)
        {
            sf("%lld",&v);
            u=0;
           /* mx=query1(1,0,n-1,v-1);//get max value that is less than or equal to v-1
            cout<<mx<<" ff";nl;
            if(u==0)
                 update(1,0,n-1,i,1,v);
            else
            {
                tot=query2(1,0,n-1,mx);//get total cnt of the value of mx
                cout<<tot<<" fdf";nl;
                update(1,0,n-1,i,tot+1,v);
            }
            */
            mx=query3(1,0,n-1,v);
            update(1,0,n-1,i,(mx+1)%md,v);
        }
        pf("Case %lld: %lld\n",z,tr[1].cnt);
    }


    return 0;
}

