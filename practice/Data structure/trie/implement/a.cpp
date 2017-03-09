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
    int data;
    int next[26];
    st()
    {
        data=0;
        int i;
        fr(i,26)next[i]=0;
    }

}tr[1<<17];

int Node=1;

void insert(string& s)
{
    int p=0;
    int i,x,l=s.length();
    fr(i,l)
    {
        //for making end point,we can edit there
        int x=s[i]-'a';
        if(tr[p].next[x]==0)
        {
            tr[p].next[x]=Node++;
        }
        p=tr[p].next[x];
    }
    tr[p].data++;//number of string end in this node
}

bool search(string& s)
{
    int i,x,l=s.length();
    int p=0;
    fr(i,l)
    {
        x=s[i]-'a';
        if(!tr[p].next[x])return 0;
        p=tr[p].next[x];
    }
    if(tr[p].data)return 1;
    return 0;
}

void del(string& s)
{
    int i,x,l=s.length();
    vi v;
    int p=0;
    bool b=0;
    fr(i,l)
    {
        x=s[i]-'a';
        p=tr[p].next[x];
        v.pb(p);
    }
    reverse(all(v));
    tr[p].data=0;
    fr(i,26)if(tr[p].next[i])b=1;
    if(b==0)
    {
        p=0;
        fr(i,v.size())
        {
            if(tr[v[i]].data)break;
            tr[v[i]].next[s[l-i-1]-'a']=0;
        }
    }
    v.clear();
}


int main()
{
    string s;
    int n,i,b;
    cin>>n;
    fr(i,n)
    {
        cin>>s;
        insert(s);
    }
    //cout<<Node<<endl;
    cout<<"Search"<<endl;
    while(cin>>b)
    {
        if(b==0)break;
        cin>>s;
        if(b==1)
        {
            if(search(s))cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
        else
        {
            if(search(s))
            {
                del(s);
            }
        }
    }
    return 0;
}

