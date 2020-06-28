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

    const int N = 2e5 + 5;
    const int lg = 30;
    vector <int> a;
    int par[N];
    vector <int> cnt[N];
    int n,cntEdges = 0;
    ll ans = 0;

    class Trie{
    public:
        Trie *child[2];
        int has;
        Trie(){
            has = 0;
            child[0] = child[1] = nullptr;
        }
    public:
        void add(int val,Trie *root){
            for(int j = lg;~j;--j){
                if(root -> child[BIT(val,j)] == nullptr){
                    root -> child[BIT(val,j)] = new Trie;
                }
                root = root -> child[BIT(val,j)];
                ++(root -> has);
            }
        }
        void del(int val,Trie *root){
            for(int j = lg;~j;--j){
                root = root -> child[BIT(val,j)];
                --(root -> has);
            }
        }
        int minXor(int val,Trie *root){
            int ret = 0;
            for(int j = lg;~j;--j){
                int b = BIT(val,j);
                if(root -> child[b] and root -> child[b] -> has){
                    root = root -> child[b];
                } else {
                    ret += MASK(j);
                    if(root -> child[b ^ 1] and root -> child[b ^ 1] -> has){
                        root = root -> child[b ^ 1];
                    }
                }
            }
            return ret;
        }
    };
    Trie *trie = new Trie;

    int findp(int u){
        return par[u] == u ? u : par[u] = findp(par[u]);
    }

    void join(int u,int v){
        u = findp(u),v = findp(v);
        if(u == v){
            return ;
        }
        if(cnt[u].size() < cnt[v].size()){
            swap(u,v);
        }
        par[v] = u;
        for(;cnt[v].size();cnt[v].pop_back()){
            cnt[u].emplace_back(cnt[v].back());
        }
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            int val;
            cin>>val;
            a.emplace_back(val);
        }
        sort(all(a));
        a.erase(unique(all(a)),a.end());
        map <int,int> f;
        for(int i = 0;i < a.size();++i){
            trie -> add(a[i],trie);
            cnt[i].emplace_back(i);
            par[i] = i;
            f[a[i]] = i;
        }
        while(cntEdges < a.size() - 1){
            vector <int> r;
            for(int u = 0;u < a.size();++u){
                r.emplace_back(findp(u));
            }
            sort(all(r));
            r.erase(unique(all(r)),r.end());
            vector <pii> g;
            for(int u : r){
                int minEdges = numeric_limits <int> :: max();
                int cur = -1;
                for(int v : cnt[u]){
                    trie -> del(a[v],trie);
                }
                for(int v : cnt[u]){
                    int mi = trie -> minXor(a[v],trie);
                    if(mi < minEdges){
                        minEdges = mi;
                        cur = v;
                    }
                }
                for(int v : cnt[u]){
                    trie -> add(a[v],trie);
                }
                if(~cur){
                    g.emplace_back(make_pair(cur,f[a[cur] ^ minEdges]));
                }
            }
            for(pii p : g){
                int u = p.first;
                int v = p.second;
                if(findp(u) != findp(v)){
                    join(u,v);
                    ++cntEdges;
                    ans += 1LL * (a[u] ^ a[v]);
                }
            }
        }
        cout<<ans;
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