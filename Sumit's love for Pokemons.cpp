#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define endl        "\n"
#define si(a)       scanf("%d",&a)
#define si2(a,b)    scanf("%d%d",&a,&b)
#define sl(a)       scanf("%lld",&a)
#define sl2(a,b)    scanf("%lld%lld",&a,&b)
#define pb          push_back
#define mk          make_pair
#define loop(n)     for(int i=0; i<n; i++)
#define FOR(a,b)    for(int i=a; i<=b; i++)
#define sz          size()
#define ff          first
#define ss          second
#define mem(a,val)  memset(a, val, sizeof(a))
#define md          1000000007
#define pi          acos(-1.0)

string s; int mx;
void solve(string& s, int k, char c)
{
    int cnt=0, l=0;
    for(int i=0; i<s.sz; i++)
    {
        if(s[i]!=c)
            cnt++;
       while(cnt>k)
        {
            if(s[l]!=c)
                cnt--;
            l++;
        }
        mx=max(mx, i-l+1);
    }
}
int main()
{
   int t,n,k;
   si(t);
   while(t--)
   {
       si2(n,k);
       cin>>s;

       mx=0;
       for(int i=0; i<26; i++)
       {
           solve(s, k, i+'a');
           solve(s, k, i+'A');
       }
       cout<<mx<<endl;
   }
}


