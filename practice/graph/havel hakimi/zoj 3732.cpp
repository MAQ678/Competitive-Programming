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
typedef      vector<ii> vii;
#define mp      make_pair
#define ft      first
#define sd      second
#define IT      iterator
#define pr(c,x) ((c).find(x)!=(c).end())
#define sz(a) int((a).size())
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())

vii v1,v2,v3;
vi g[102],ng[102],an1,an2;
int n;


void print(int a)
{
    int i,j,an;
    an1.clear();
    an2.clear();
    if(a==1)
    {
        fr(i,n)
        {
            fr(j,g[i].size())an1.pb(i),an2.pb(g[i][j]);
        }

    }
    pf("%d %d\n",n,an1.size());
    fr(i,an1.size())
    {
        if(i)pf(" ");
        pf("%d",an1[i]);
    }
    pf("\n");
    fr(i,an2.size())
    {
        if(i)pf(" ");
        pf("%d",an2[i]);
    }
    pf("\n");


}

int main()
{
    int i,d,j,prv,u,v;
    bool ok,mul;
    while(sf("%d",&n)!=EOF)
    {
        fr(i,n)
        {
            sf("%d",&d);
            v1.pb(mp(d,i));
        }

        sort(all(v1));
        reverse(all(v1));
        v2=v1;
        ok=1;
        mul=0;
        fr(i,n)
        {
            for(j=i+1; j<n&&v1[i].ft>0; j++)
            {
                v1[i].ft--;
                v1[j].ft--;

                if(v1[j].ft<0)
                {
                    ok=0;
                    break;
                }
                g[v1[i].sd].pb(v1[j].sd);
                if(!mul) ng[v1[i].sd].pb(v1[j].sd);

            }
            if(!ok)break;
            if(j<n&&v1[j].ft==v1[j-1].ft+1&&!mul)
            {
                mul=1;
                v2=v1;
            }
        }
        fr(i,v1.size())
        {
            if(v1[i].ft<0||v1[i].ft>0)
            {
                ok=0;
                break;
            }
        }

        if(ok)
        {

            if(!mul)
            {
                //unique
                pf("UNIQUE\n");
                print(1);
            }
            else
            {


                pf("MULTIPLE\n");

                sort(all(v2));
                reverse(all(v2));
                fr(i,v2.size())
                {
                    if(v2[i].ft==0)break;
                    for(j=i+1; j<v2.size()&&v2[i].ft>0; j++)
                    {
                        v2[i].ft--;
                        v2[j].ft--;
                        ng[v2[i].sd].pb(v2[j].sd);

                    }
                }
                print(1);
                print(2);

            }
        }
        else
        {
            //hobena
            printf("IMPOSSIBLE\n");
        }
        fr(i,n+1)g[i].clear(),ng[i].clear();

    }
}
