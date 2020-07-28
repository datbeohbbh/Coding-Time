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
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
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
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}
 
#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE
 
/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/
 
namespace task{
 
    const int N = 1e5 + 5;
    const int MAGIC = 361;
    vector <int> adj[N];
    int pos[N],child[N],ans[N],t[N],cnt[N];
    int colors[N],freq[N];
    int n,m,p = 0;
 
    struct SquareRootDecomposition {
        int l,r,k,q_id;
        SquareRootDecomposition(){}
        SquareRootDecomposition(int _l,int _r,int _k,int _q_id):l(_l),r(_r),k(_k),q_id(_q_id){}
        bool operator < (const SquareRootDecomposition &other) const {
            int block_x = l / MAGIC;
            int block_y = other.l / MAGIC;
            if(block_x == block_y){
                return (block_x & 1 ? r < other.r : r > other.r);
            }
            return l < other.l;
        }
    };
    vector <SquareRootDecomposition> queries;
 
    void dfs(int u,int par){
        child[u] = 1;
        t[++p] = colors[u];
        pos[u] = p;
        for(int i = 0;i < sz(adj[u]);++i){
            int v = adj[u][i];
            if(v ^ par){
                dfs(v,u);
                child[u] += child[v];
            }
        }
    }
 
    void add(int cur){
        ++cnt[t[cur]];
        ++freq[cnt[t[cur]]];
    }
 
    void del(int cur){
        --freq[cnt[t[cur]]];
        --cnt[t[cur]];
    }
 
    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>colors[i];
        }
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emp(v);
            adj[v].emp(u);
        }
        dfs(1,1);
        for(int i = 1;i <= m;++i){
            int v,k;
            cin>>v>>k;
            queries.emp(SquareRootDecomposition(pos[v],pos[v] + child[v] - 1,k,i));
        }
        sort(all(queries));
        int cur_r = -1,cur_l = 0;
        for(int i = 0;i < sz(queries);++i){
            int l = queries[i].l;
            int r = queries[i].r;
            int k = queries[i].k;
            int q_id = queries[i].q_id;
            while(cur_r < r){
                ++cur_r;
                add(cur_r);
            }
            while(cur_r > r){
                del(cur_r);
                --cur_r;
            }
            while(cur_l < l){
                del(cur_l);
                ++cur_l;
            }
            while(cur_l > l){
                --cur_l;
                add(cur_l);
            }
            ans[q_id] = freq[k];
        }
        for(int i = 1;i <= m;++i){
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