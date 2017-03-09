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


set<pair<ii,int> >block;
set<pair<ii,int> >::IT it;
struct st
{
    int x,y;
}p[50005];

bool cmp(st a,st b)
{
    return (a.y-a.x)>(b.y-b.x);
    //if((a.y-a.x)>(b.y-b.x))return true;

}
vector<pair<ii,int> >g;

int main()
{
    int t,z,n,q,i,j,l,r;
    bool h;
    pair<ii,int>w,e;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&q);
        fr(i,n)
        {
            sf("%d%d",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmp);
        block.insert(mp(mp(-1,-1),-1));
        block.insert(mp(mp(inf,inf),-1));
        fr(i,n)
        {
            g.clear();
            while(1)
            {
                it=block.lower_bound(mp(mp(p[i].x,-1),-1));
                w=*it;
                if(w.ft.ft>p[i].y)
                    break;
                block.erase(it);
                g.pb(w);
            }
            it=block.lower_bound(mp(mp(p[i].x,-1),-1));
            --it;
            g.pb(*it);
            w=*it;
            block.erase(it);

            h=0;
            fr(j,g.size())
            {
                w=g[j];
                if(g[j].ft.ft<=p[i].x&&g[j].ft.sd>=p[i].x&&g[j].ft.sd<=p[i].y)
                {
                    w=mp(mp(g[j].ft.ft,p[i].x-1),g[j].sd);
                    if(w.ft.ft<=w.ft.sd)
                    {
                        block.insert(w);
                    }
                    w=mp(mp(p[i].x,g[j].ft.sd),g[j].sd+1);
                    block.insert(w);
                }
                else if(g[j].ft.ft>=p[i].x&&g[j].ft.sd<=p[i].y)
                {
                    w=mp(mp(g[j].ft.ft,g[j].ft.sd),g[j].sd+1);
                    block.insert(w);
                }
                else if(g[j].ft.ft>=p[i].x&&g[j].ft.sd>=p[i].y&&g[j].ft.ft<=p[i].y)
                {
                     w=mp(mp(p[i].y+1,g[j].ft.sd),g[j].sd);
                     if(w.ft.ft<=w.ft.sd)
                        {
                            block.insert(w);
                        }
                     w=mp(mp(g[j].ft.ft,p[i].y),g[j].sd+1);
                    block.insert(w);
                }
                else if(g[j].ft.ft<=p[i].x&&g[j].ft.sd>=p[i].y)
                {
                    w=mp(mp(g[j].ft.ft,p[i].x-1),g[j].sd);
                    if(w.ft.ft<=w.ft.sd)
                    {
                        block.insert(w);
                    }
                     w=mp(mp(p[i].y+1,g[j].ft.sd),g[j].sd);
                     if(w.ft.ft<=w.ft.sd)
                        {
                            block.insert(w);
                        }
                    w=mp(mp(p[i].x,p[i].y),g[j].sd+1);
                    block.insert(w);
                }
                else block.insert(g[i]);
            }
            //last check if (l,r) not inserted
            it=block.lower_bound(mp(mp(p[i].x,p[i].x),-1));
            w=*it;
            if(w.ft.ft!=p[i].x)block.insert(mp(mp(p[i].x,p[i].y),1));

       // cout<<block.size()<<endl;nl;nl;
            //now query part

        }
        pf("Case %d:\n",z);
        while(q--)
            {
                sf("%d",&l);
                it=block.lower_bound(mp(mp(l,l),-1));
                w=*it;
                if(w.ft.ft>l)
                {
                    it--;
                    w=*it;
                }
                if(w.sd==-1||(w.ft.sd<l||w.ft.ft>l))pf("0\n");
                else pf("%d\n",w.sd);
            }
    }
    return 0;
}
