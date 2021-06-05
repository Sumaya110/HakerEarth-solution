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


string s;
ll a[100005], mx=100000, tree[400005], t[100005];
void power()
{
    a[0]=1;
    for(int i=1; i<=mx; i++)
    {
        a[i]=(a[i-1]*2)%3;
    }
}

void build(ll node, ll b, ll e)
{
    if(b==e)
    {
        tree[node]=t[b];return;
    }

    ll mid=(b+e)/2;
    ll lf=node*2;
    ll rt=lf+1;

    build(lf, b, mid);
    build(rt, mid+1, e);

    tree[node]= ((tree[lf]*a[e-mid])+ tree[rt])%3;
}

ll query(ll node, ll b, ll e, ll l, ll r)
{
    if(b>r || e<l) return 0;

    if(b>=l && e<=r) return tree[node]*a[r-e];

    ll mid=(b+e)/2;
    ll lf=node*2;
    ll rt=lf+1;

    ll p=query(lf, b, mid, l, r);
    ll q=query(rt, mid+1, e, l, r);

    return (p+q)%3;
}

void update(ll node, ll b, ll e, ll ind)
{
    if(b>ind || e<ind) return;
    if(ind==b && ind==e) {tree[node]=1; return;}

    ll mid=(b+e)/2;
    ll lf=node*2;
    ll rt=lf+1;

    update(lf, b, mid, ind);
    update(rt, mid+1, e, ind);

    tree[node]= ((tree[lf]*a[e-mid])+ tree[rt])%3;
}
int main()
{
   ll n,q,op,l,r;
   sl(n);
   cin>>s;

   for(int i=1; i<=n; i++)
    t[i]=s[i-1]-'0';

   power();
   build(1LL, 1LL, n);
    sl(q);
    while(q--)
    {
        sl(op);
        if(op==0)
        {
            sl2(l,r);
            l++,r++;
            ll ans=query(1LL, 1LL, n, l, r);
            printf("%lld\n", ans);
        }
        else
        {
            sl(l); l++;
            update(1LL, 1LL, n, l);
        }
    }
}
