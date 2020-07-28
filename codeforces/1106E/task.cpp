#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

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
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD)
{
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD)
{
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD)
{
    return (long long)x*y%MOD;
}

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
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=1e5+5;
const int inf = -2e9;
pii cost[N];
int n,m,k;
ll dp[N][202];

struct SegmentTree{
    vector <pii> tree,lazy;
    SegmentTree(){
        tree.resize(4*N + 4,mp(inf,inf));
        lazy.resize(4*N + 4,mp(inf,inf));
    }
    void pushdown(int l,int r,int node){
        if(lazy[node] == mp(inf,inf))return ;
        maximize(tree[node],lazy[node]);
        if(l ^ r){
            maximize(lazy[node<<1],lazy[node]);
            maximize(lazy[node<<1|1],lazy[node]);
        }
        lazy[node] = mp(inf,inf);
    }
    void updateRange(int l,int r,int d,int w,int tl = 1,int tr = n,int node = 1){
        pushdown(tl,tr,node);
        if(tr < l or tl > r)return ;
        if(l <= tl and tr <= r){
            maximize(tree[node],mp(w,d));
            if(tl ^ tr){
                maximize(lazy[node<<1],mp(w,d));
                maximize(lazy[node<<1|1],mp(w,d));
            }
            return ;
        }
        int mid = (tl + tr)>>1;
        updateRange(l,r,d,w,tl,mid,node<<1);
        updateRange(l,r,d,w,mid + 1,tr,node<<1|1);
        maximize(tree[node],tree[node<<1]);
        maximize(tree[node],tree[node<<1|1]);
    }
    pii rmq(int pos,int l = 1,int r = n,int node = 1){
        pushdown(l,r,node);
        if(l > pos or r < pos)return mp(inf,inf);
        if(l == r)return tree[node];
        int mid = (l + r)>>1;
        if(pos <= mid)
            return rmq(pos,l,mid,node<<1);
        else
            return rmq(pos,mid + 1,r,node<<1|1);
    }
};
SegmentTree seg;

ll f(int i,int j){
    if(i > n)
        return 0LL;
    if(~dp[i][j])
        return dp[i][j];
    ll res = 1LL*inf*1LL*inf;
    res = min(res,min(1LL*cost[i].fir + f(cost[i].sec + 1,j),(j < m ? f(i + 1,j + 1) : 1LL*inf*1LL*inf)));
    return dp[i][j] = res;
}

void solve(){

    cin>>n>>m>>k;
    for(int i = 1;i <= k;++i){
        int l,r,d,w;
        cin>>l>>r>>d>>w;
        seg.updateRange(l,r,d,w);
    }
    for(int i = 1;i <= n;++i){
        cost[i] = seg.rmq(i);
        if(cost[i] == mp(inf,inf))
            cost[i] = mp(0,i);
    }
    memset(dp,-1LL,sizeof(dp));
    cout<<f(1,0);
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
