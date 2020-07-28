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
#define pb emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int lg = 19;
const int N = 1e5 + 5;
vector <int> adj[N];
vector <int> root;
vector <vector <int> > szt,dad,d;
int cnt[N],idx[N],f[N];
int n,m;

struct MergeSortTree{
    vector < vector <int> > tree;
    void init_size(int ns){
        tree.resize((ns<<2) + 1);
    }
    void build(int l,int r,int node,int tree_index){
        if(l > r)return;
        if(l == r){
            return (void) (tree[node].pb(d[tree_index][l]));
        }
        int mid = (l + r)>>1;
        build(l,mid,node<<1,tree_index);
        build(mid + 1,r,node<<1|1,tree_index);
        tree[node].resize(sz(tree[node<<1]) + sz(tree[node<<1|1]));
        merge(all(tree[node<<1]),all(tree[node<<1|1]),tree[node].begin());
    }
    int query(int tl,int tr,int l,int r,int node,int val){
        if(tr < l or r < tl or tl > tr)return 0;
        if(l <= tl and tr <= r){
            vector <int> :: iterator lo,hi;
            lo = lower_bound(all(tree[node]),val);
            hi = upper_bound(all(tree[node]),val);
            if(lo == tree[node].end() or *lo != val){
                return 0;
            }
            return hi - lo;
        }
        int mid = (tl + tr)>>1;
        return query(tl,mid,l,r,node<<1,val)
             + query(mid + 1,tr,l,r,node<<1|1,val);
    }
};
vector <MergeSortTree> mseg;

struct LowestCommonAncestor{
    vector <int> dp[lg + 1];
    void init_size(int ns){
        for(int i = 0;i <= lg;++i){
            dp[i].resize(ns + 1);
        }
    }
    void build(int tree_index){
        for(int i = 1;i <= cnt[tree_index];++i){
            dp[0][i] = dad[tree_index][i];
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 1;i <= cnt[tree_index];++i){
                dp[j][i] = dp[j - 1][dp[j - 1][i]];
            }
        }
    }
    int findp(int u,int p,int tree_index){
        int tmp = u;
        for(int j = lg;j >= 0;--j){
            if(d[tree_index][dp[j][u]] >= d[tree_index][tmp] - p){
                u = dp[j][u];
            }
        }
        return u;
    }
};
vector <LowestCommonAncestor> lca;

void countSize(int u,int par,int tree_index){
    idx[u] = ++cnt[tree_index];
    f[u] = tree_index;
    for(int i = 0;i < sz(adj[u]);++i){
        int v = adj[u][i];
        if(v == par)continue;
        countSize(v,u,tree_index);
    }
}

void dfs(int u,int par,int tree_index){
    for(int i = 0;i < sz(adj[u]);++i){
        int v = adj[u][i];
        if(v == par)continue;
        d[tree_index][idx[v]] = d[tree_index][idx[u]] + 1;
        dad[tree_index][idx[v]] = idx[u];
        dfs(v,u,tree_index);
        szt[tree_index][idx[u]] += szt[tree_index][idx[v]];
    }
}

void solve(){
    cin>>n;
    for(int i = 1;i <= n;++i){
        int r;
        cin>>r;
        if(r){
            adj[r].pb(i);
            adj[i].pb(r);
        } else {
            root.pb(i);
        }
    }
    szt.resize(sz(root));
    dad.resize(sz(root));
    d.resize(sz(root));
    for(int i = 0;i < sz(root);++i){
        countSize(root[i],root[i],i);
        szt[i].resize(cnt[i] + 1,1);
        d[i].resize(cnt[i] + 1,0);
        dad[i].resize(cnt[i] + 1,0);
        d[i][1] = dad[i][1] = 1;
        dfs(root[i],root[i],i);
    }
    lca.resize(sz(root));
    for(int i = 0;i < sz(root);++i){
        lca[i].init_size(cnt[i]);
        lca[i].build(i);
    }
    mseg.resize(sz(root));
    for(int i = 0;i < sz(root);++i){
        mseg[i].init_size(cnt[i]);
        mseg[i].build(1,cnt[i],1,i);
    }
    cin>>m;
    while(m--){
        int p,v;
        cin>>v>>p;
        int par = lca[f[v]].findp(idx[v],p,f[v]);
        if(d[f[v]][idx[v]] - d[f[v]][par] != p){
            cout<<0<<' ';
        }
        else {
            int ans = mseg[f[v]].query(1,cnt[f[v]],par,par + szt[f[v]][par] - 1,1,d[f[v]][idx[v]]);
            cout<<ans - 1<<' ';
        }
    }
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
