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
#define all(c)  c.begin(), c.end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=c.end();i++)
#define vpresent(c,x) (find(all(c),x)!=(c).end())


struct st
{
    int s[3],val;
    st(int a,int b,int c,int val){
        this->s[0]=a;
        this->s[1]=b;
        this->s[2]=c;
        this->val=val;
    }
    bool operator < (const st& w)const
    {
        return w.val<val;
    }
};

int main()
{
    //freopen("F:\\Coding\\in.txt","r",stdin);
   // freopen("F:\\Coding\\out.txt","w",stdout);
    bool vis[201][201][201];
    st w;
   int t,a,b,c,d,i,j;
   sf("%d",&t);
   while(t--)
   {
       sf("%d%d%d",&a,&b,&c,&d);

       priority_queue<st>q;
       q.push(st(0,0,c,0));
       ms(vis,0);
       vis[0][0][c]=1;
       while(!q.empty())
       {
            w=q.top();
            fr(i,3)if(w.s[i]==d)break;
            fr(i,3)
            {
                fr(j,3)
                {
                    if(i!=j)
                    {
                        //if fill possible fill it
                    }
                }
            }

       }


   }

    return 0;
}

