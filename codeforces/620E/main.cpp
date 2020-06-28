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
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 4e5 + 5;
    vector <int> *adj;
    int n,m,cur = 0;
    int c[N],pos[N],child[N];

    class SegmentTree{
    public:
        vector <int> lazy;
        vector <ll> tree;
    public:
        void resizeTree(int szt){
            lazy.resize((szt << 2) + 2,0);
            tree.resize((szt << 2) + 2,0);
        }
        void pushdown(int l,int r,int node){
            if(!lazy[node])return;
            tree[node] = (1LL << lazy[node]);
            if(l ^ r){
                lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
            }
            lazy[node] = 0;
        }
        void updateRange(int tl,int tr,int col,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(r < tl or l > tr or l > r){
                return ;
            }
            if(tl <= l and r <= tr){
                tree[node] = (1LL << col);
                if(l ^ r){
                    lazy[node << 1] = lazy[node << 1 | 1] = col;
                }
                return ;
            }
            int mid((l + r) >> 1);
            updateRange(tl,tr,col,l,mid,node << 1);
            updateRange(tl,tr,col,mid + 1,r,node << 1 | 1);
            tree[node] = tree[node << 1] | tree[node << 1 | 1];
        }
        ll cnt(int tl,int tr,int l,int r,int node){
            pushdown(l,r,node);
            if(r < tl or l > tr or l > r){
                 return 0;
            }
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid((l + r) >> 1);
            ll le = cnt(tl,tr,l,mid,node << 1);
            ll ri = cnt(tl,tr,mid + 1,r,node << 1 | 1);
            return (le | ri);
        }
        int cnt(int tl,int tr,int l,int r){
            return __builtin_popcountll(cnt(tl,tr,l,r,1));
        }
    };

    void dfs(int u,int par){
        pos[u] = ++cur;
        child[u] = 1;
        for(int v : adj[u]){
            if(v ^ par){
                dfs(v,u);
                child[u] += child[v];
            }
        }
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>c[i];
        }
        adj = new vector <int> [n + 1];
        for(int i = 1;i <= n;++i){
            adj[i].clear();
        }
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1,1);
        SegmentTree *seg = new SegmentTree;
        seg -> resizeTree(n);
        for(int i = 1;i <= n;++i){
            seg -> updateRange(pos[i],pos[i],c[i],1,n);
        }
        while(m--){
            int type,v,c;
            cin>>type;
            if(type == 1){
                cin>>v>>c;
                seg -> updateRange(pos[v],pos[v] + child[v] - 1,c,1,n);
            } else {
                cin>>v;
                cout<<seg -> cnt(pos[v],pos[v] + child[v] - 1,1,n)<<'\n';
            }
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