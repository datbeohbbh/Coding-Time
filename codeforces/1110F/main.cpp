#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x + k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x - k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 5e5 + 5;
    const ll inf = 1e18;
    vector <pii> adj[N];
    vector <int> queries[N];
    int que_l[N],que_r[N];
    int pos[N],child[N];
    ll dst[N];
    ll ans[N];
    bool isLeaf[N];
    int n,q,next_id = 0;

    class SegmentTree{
    public:
        vector <ll> tree;
        vector <ll> lazy;
    public:
        void initTree(int sizeTree){
            tree.resize((sizeTree << 2) + 2,0);
            lazy.resize((sizeTree << 2) + 2,0);
        }

        void pushdown(int l,int r,int node){
            if(lazy[node] != 0){
                tree[node] += lazy[node];
                if(l ^ r){
                    lazy[node << 1] += lazy[node];
                    lazy[node << 1 | 1] += lazy[node];
                }
                lazy[node] = 0;
            }
        }

        void buildTree(int pos,ll val,int l,int r,int node = 1){
            if(l > r or r < pos or l > pos){
                return ;
            }
            if(l == r){
                tree[node] = val;
                return;;
            }
            int mid = (l + r) >> 1;
            if(pos <= mid){
                buildTree(pos,val,l,mid,node << 1);
            } else {
                buildTree(pos,val,mid + 1,r,node << 1 | 1);
            }
            tree[node] = min(tree[node << 1],tree[node << 1 | 1]);
        }

        void updateRange(int tl,int tr,ll val,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return ;
            }
            if(tl <= l and r <= tr){
                tree[node] += val;
                if(l ^ r){
                    lazy[node << 1] += val;
                    lazy[node << 1 | 1] += val;
                }
                return ;
            }
            int mid = (l + r) >> 1;
            updateRange(tl,tr,val,l,mid,node << 1);
            updateRange(tl,tr,val,mid + 1,r,node << 1 | 1);
            tree[node] = min(tree[node << 1],tree[node << 1 | 1]);
        }

        ll rmq(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return inf;
            }
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            return min(rmq(tl,tr,l,mid,node << 1),rmq(tl,tr,mid + 1,r,node << 1 | 1));
        }
    };
    SegmentTree *seg = new SegmentTree;

    void dfs(int u,int par){
        pos[u] = ++next_id;
        child[u] = 1;
        isLeaf[u] = true;
        for(pii E : adj[u]){
            int v = E.first;
            int w = E.second;
            if(v ^ par){
                dst[v] = dst[u] + 1LL * w;
                isLeaf[u] = false;
                dfs(v,u);
                child[u] += child[v];
            }
        }
    }

    void calc(int u,int p){
        for(int j : queries[u]){
            int l = que_l[j];
            int r = que_r[j];
            ans[j] = seg -> rmq(l,r,1,n);
        }
        for(pii E : adj[u]){
            int v = E.first;
            int cur_w = E.second;
            if(v != p){
                seg -> updateRange(1,n,cur_w,1,n);
                seg -> updateRange(pos[v],pos[v] + child[v] - 1,-2LL * cur_w,1,n);
                calc(v,u);
                seg -> updateRange(pos[v],pos[v] + child[v] - 1,2LL * cur_w,1,n);
                seg -> updateRange(1,n,-cur_w,1,n);
            }
        }
    }

    void solve(){
        cin>>n>>q;
        for(int i = 2;i <= n;++i){
            int p,w;
            cin>>p>>w;
            adj[p].emplace_back(make_pair(i,w));
            adj[i].emplace_back(make_pair(p,w));
        }
        dfs(1,1);
        seg -> initTree(n);
        for(int u = 1;u <= n;++u){
            seg -> buildTree(pos[u],isLeaf[u] ? dst[u] : inf,1,n);
        }
        for(int i = 1;i <= q;++i){
            int v,l,r;
            cin>>v>>que_l[i]>>que_r[i];
            queries[v].emplace_back(i);
        }
        calc(1,1);
        for(int i = 1;i <= q;++i){
            cout<<ans[i]<<'\n';
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}