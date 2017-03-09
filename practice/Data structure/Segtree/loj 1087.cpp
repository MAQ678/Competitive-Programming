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
    int mn,mx,add,val;
}tr[2000000];

void update(int r,int s,int e,int pos,int v)
{
    if(tr[r].add!=0)//lazy
    {
        tr[r].mx+=tr[r].add;
        tr[r].mn+=tr[r].add;
        if(tr[r].mx<tr[r].mn)
        {
            tr[r].mn=tr[r].mx=0;//
            //return 0;
        }
        if(s!=e)tr[r*2].add+=tr[r].add,tr[r*2+1].add+=tr[r].add;
        tr[r].add=0;
    }

    if(s>pos||e<pos)return;
    //lazy
    if(s==e)
    {
        tr[r].val=v;
        tr[r].add=0;
        tr[r].mn=tr[r].mx=tr[1].mx+1;
        return;
    }
    int mid=(s+e)>>1,x;
    update(r*2,s,mid,pos,v);
    update(r*2+1,mid+1,e,pos,v);

    //update to parent
    x=min(tr[r*2].mn,tr[r*2+1].mn);
    if(x)tr[r].mn=x;
    else tr[r].mn=max(tr[r*2].mn,tr[r*2+1].mn);

    tr[r].mx=max(tr[r*2].mx,tr[r*2+1].mx);
}

int query(int r,int s,int e,int val)
{
    if(tr[r].add!=0)//lazy
    {
        tr[r].mx+=tr[r].add;
        tr[r].mn+=tr[r].add;
        if(tr[r].mx<tr[r].mn)
        {
            tr[r].mn=tr[r].mx=0;//
            return 0;
        }
        if(s!=e)tr[r*2].add+=tr[r].add,tr[r*2+1].add+=tr[r].add;
        tr[r].add=0;
    }
    if(tr[r].mn>val||tr[r].mx<val)return 0;
    if(s==e)
    {
        tr[r].mn=tr[r].mx=tr[r].add=0;
      //  if(s&1)tr[r+1].mx-=1,tr[r+1].mn-=1;
        return tr[r].val;
    }

    int mid=(s+e)>>1;
    int p=query(r*2,s,mid,val);
    int q=query(r*2+1,mid+1,e,val);

    if(p)
    {
       if(tr[r*2].mn!=0)tr[r].mn=tr[r*2].mn;
       else tr[r].mn=tr[r*2+1].mn-1;

       if(tr[r].mx>=tr[r].mn)
       {
           if(tr[r*2+1].mn)
           tr[r*2+1].add-=1;
       }
    }
    if(p||q)
    {
        tr[r].mx-=1;///
       if(tr[r].mx<tr[r].mn)tr[r].mx=tr[r].mn=0;
    }
//    if(p)
//    {
//        tr[r*2+1].add-=1;
//    }
//    if(p||q)
//    {
//        tr[r].mx--;
//        if(tr[r].mx<tr[r].mn)tr[r].mx=tr[r].mn=0;
//    }
    return (p|q);

}

int main()
{
    char ch;
    int t,z,n,i,N,q,v,w;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&q);
        N=n+q;
        fr(i,n)
        {
            sf("%d",&v);
            update(1,0,N-1,i,v);
        }
        w=n;
        pf("Case %d:\n",z);
        while(q--)
        {
//            cin>>ch>>v;
            sf(" %c%d",&ch,&v);
            if(ch=='c')
            {
                if(tr[1].mx<v)pf("none\n");
                else
                {
                    pf("%d\n",query(1,0,N-1,v));
                }
            }
            else
            {
                update(1,0,N-1,w,v);
                w++;
            }
        }
        if(z!=t)
        fr1(i,2*N+1)tr[i].mn=tr[i].mx=tr[i].add=tr[i].val=0;
    }
    return 0;
}

