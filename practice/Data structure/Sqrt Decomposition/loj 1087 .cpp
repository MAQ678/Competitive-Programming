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


int b[400],s;
int a[1<<20];

int main()
{
    int t,z,i,j,n,q,v,N,w;
    char ch;
    sf("%d",&t);
    fr1(z,t)
    {
        sf("%d%d",&n,&q);
        w=n;
        N=n+q;
        s=sqrt(N)+1;
        ms(a,0);ms(b,0);
        fr(i,n)
        {
            sf("%d",&a[i]);
            b[i/s]++;
        }
        while(q--)
        {
            sf(" %c%d",&ch,&v);
            if(ch=='a')
            {
                w++;
                a[n]=v;
                b[n/s]++;
                n++;
            }
            else
            {
                if(v>w)pf("none\n");
                else
                {
                    i=0;
                    while(b[i]<v)
                    {
                        v-=b[i];
                        i++;
                    }
                    for(j=i*s;;j++)
                    {
                        if(a[i]!=0)
                        {
                            if(v==1)
                                {
                                    pf("%d\n",a[i]);
                                    a[i]=0;
                                    break;
                                }
                            v--;
                        }
                    }
                    w--;
                }
            }
        }
    }
    return 0;
}

