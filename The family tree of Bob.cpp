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

ll p[25][500005];
vector<ll>g[500005];

void dfs(ll rt, ll pa)
{
    for(auto x: g[rt])
    {
        if(x!=pa)
        {
            dfs(x, rt);
            p[0][x]=rt;
        }
    }
}
ll solve(ll node, ll k)
{
    for(int i=0; i<=20; i++)
    {
        if(k & (1<<i))
            {
                if(node!=-1)
                {
                    node=p[i][node];
                }
            }
    }
    return node;
}
int main()
{
   ll t,q,u,v,n,i,j,k,l,mn=0, mx=0, node;
   sl2(n,q);
   for(int i=1; i<n; i++)
   {
       sl2(u,v);
       g[u].pb(v);
       g[v].pb(u);
   }
   memset(p, -1, sizeof(p));
   p[0][1]=-1;
   dfs(1, -1);

   for(int i=1; i<=20; i++)
   {
       for(int node=1; node<=n; node++)
       {
           int parent_node=p[i-1][node];
           if(parent_node!=-1)
           {
               p[i][node]=p[i-1][parent_node];
           }
       }
   }


   while(q--)
   {
       sl2(node,k);

       ll kk=solve(node, k);
       printf("%lld\n", kk);
   }

}


