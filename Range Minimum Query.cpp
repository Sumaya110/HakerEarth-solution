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

ll a[500010], seg[500010];

void build(ll node, ll b, ll e)
{
    if(b==e)
    {
        seg[node]=a[b]; return;
    }
    ll mid=(b+e)/2;
    ll lf=(2*node);
    ll rt=lf+1;

     build(lf,b,mid);
     build(rt,mid+1,e);
    seg[node]= min(seg[lf], seg[rt]);
}

void update(ll node, ll b, ll e, ll ind, ll val)
{
    if(b>ind || e<ind) return;
    if(b==ind && e==ind) { seg[node]=val; return; }

    ll mid=(b+e)/2;
    ll lf=(2*node);
    ll rt=lf+1;
    update(lf, b, mid, ind, val);
    update(rt, mid+1, e, ind, val);
    seg[node]= min(seg[lf], seg[rt]);
}

ll query(ll node, ll b, ll e, ll l, ll r)
{
    if(b>r || e<l) return 1e18;
    if(l<=b && r>=e) { return seg[node]; }

    ll mid=(b+e)/2;
    ll lf=(2*node);
    ll rt=lf+1;

    ll p=query(lf, b, mid, l, r);
    ll q=query(rt, mid+1, e, l, r);
    return min(p,q);
}
int main()
{
    ll n,k,l,r;
    char c;

    sl2(n,k);
    for(int i=1; i<=n; i++)
    {
        sl(a[i]);
    }
    //for(int i=1; i<=9; i++)
      //seg[i]=1e18;
    build(1LL,1LL,n);
    /*for(int i=1; i<=9; i++)
        cout<<seg[i]<<" ";
    cout<<endl;*/
    for(int i=0; i<k; i++)
    {
        cin>>c;
        sl2(l,r);
        if(c=='q')
        {
            ll ans=query(1LL,1LL, n, l, r);
            printf("%lld\n", ans);
        }
        else
        {
            update(1LL, 1LL, n, l, r);
        }
    }
}

