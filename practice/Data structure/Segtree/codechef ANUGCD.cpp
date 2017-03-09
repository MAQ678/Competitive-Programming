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

map<int,int>ma;
int a[100005],n,pos[100005],in;
vi f[100005];

void calc()
{
    int i,v,val,j;
    fr(j,n)
    {
        val=a[j];
        for(i=2; i*i<=a[j];i++)
        {
            if(val%i==0)
            {
                f[i].pb(i);
                if(!pr(ma,i))ma[i]=1,pos[in++]=i;
                while(val%i==0)
                {
                    val/=i;
                }
            }
        }
        if(val>1)
        {
            f[i].pb(val);
            if(!pr(ma,val))ma[val]=1,pos[in++]=val;
        }
    }
  // fr(i,in)cout<<pos[i]<<" ";
   // nl;cout<<"dd"<<endl;
}

bool ase(int i,int v)
{
    if(binary_search(all(f[i]),v))return 1;
    return 0;
}

int tr[400][100005],sm[400][100005];//one is for max in range,another is total no of occuring

void update(int n,int s,int e,int ps,int no)
{
    if(s>ps||e<ps)return;
    if(s==e)
    {
        tr[no][n]=a[ps];
        sm[no][n]=1;
        return;
    }
    int mid=(s+e)>>1,le=n*2,ri=n*2+1;
    update(le,s,mid,ps,no);
    update(ri,mid+1,e,ps,no);


    if(tr[no][le]>tr[no][ri])
    {
        tr[no][n]=tr[no][le];
        sm[no][n]=sm[no][le];
    }
    else if(tr[no][le]<tr[no][ri])
    {
        tr[no][n]=tr[no][ri];
        sm[no][n]=sm[no][ri];
    }
    else tr[no][n]=tr[no][ri],sm[no][n]=sm[no][le]+sm[no][ri];
}

void process()
{
    int i,l,j;
    l=in;
    fr(i,in)
    {
        //init(1,0,n-1,i);
        ms(tr[i],0);
        fr(j,n)
        {
            if(ase(j,pos[i]))update(1,0,n-1,j,i);
            //else update(1,0,n-1,j,0,i);
        }
    }
}

ii query(int n,int s,int e,int l,int r,int no)
{
    if(s>r||e<l)return mp(0,0);
    if(s>=l&&e<=r)
        return mp(tr[no][n],sm[no][n]);
    int mid=(s+e)>>1;
    ii p,q;
    p=query(n*2,s,mid,l,r,no);
    q=query(n*2+1,mid+1,e,l,r,no);
    if(p.ft>q.ft)return p;
    else if(p.ft<q.ft)return q;
    else
    {
        return mp(p.ft,p.sd+q.sd);
    }
}

int main()
{
    int m,i,g,x,y,val,mx,to,q;
    ii an;
    sf("%d%d",&n,&m);
    fr(i,n)
    {
        sf("%d",&a[i]);
    }
        in=0;
        ma.clear();
        calc();//calculate all prime factors

        process();//calculate on segment tree

        while(q--)
        {
            sf("%d%d%d",&g,&x,&y);
            mx=-1,to=-1;
            //process g
            fr(i,in)
            {
                if(g>pos[i])break;
                else
                {
                    if(g%pos[i]==0)
                    {
                        an=query(1,0,n-1,x-1,y-1,i);
                        if(an.ft>mx&&an.ft!=0)mx=an.ft,to=an.sd;
                    }
                }
            }
            pf("%d %d\n",mx,to);

        }

        fr(i,n)f[i].clear();


    return 0;
}

