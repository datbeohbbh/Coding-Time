using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()
#define fn "test"    ///FILE_NAME_HERE
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rrep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)

template <class T,class U>
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T,class U,class V>
T addmod(T x,U y,V mod)
{
    return ((x + y)%mod + mod)%mod;
}
template <class T,class U,class V>
T submod(T x,U y,V mod)
{
    return ((x - y)%mod + mod)%mod;
}
template <class T,class U,class V>
T mulmod(T x,U y,V mod)
{
    return (ll)x*y%mod;
}
///---------------------------------------------------------END_TEMPLATE-------------------------------------------------------///

namespace task{

const int N=3e4+33;
int a[N];
int n,q;

struct MergeSortTree
{
   vector < vector <int> > tree;
   MergeSortTree(){tree.resize(4*N + 4,vector <int> ());}
   void buildTree(int l=1,int r=n,int node=1)
   {
       if(l > r)return ;
       if(l==r)return (void)(tree[node].pb(a[l]));
       int mid=(l + r)>>1;
       buildTree(l,mid,node<<1);
       buildTree(mid+1,r,node<<1|1);
       tree[node].resize(sz(tree[node<<1]) + sz(tree[node<<1|1]));
       merge(all(tree[node<<1]),all(tree[node<<1|1]),tree[node].begin());
   }
   int query(int le,int ri,int val,int l=1,int r=n,int node=1)
   {
       if(l > r or r < le or l > ri)return 0;
       if(le <= l and r <= ri)
          return tree[node].end() - upper_bound(all(tree[node]),val);
       int mid=(l + r)>>1;
       return query(le,ri,val,l,mid,node<<1)
             +query(le,ri,val,mid+1,r,node<<1|1);
   }
}seg;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    seg.buildTree();
    cin>>q;
    while(q--)
    {
        int i,j,k;
        cin>>i>>j>>k;
        cout<<seg.query(i,j,k)<<'\n';
    }
}}

int main(void)
{
    cin.sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
