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

    const int N = 2e5 + 5;
    vector <int> child[N];
    int r[N],g[N];
    int par[N];
    int f[N];
    int n;

    int findp(int u){
        return (u == par[u] ? u : par[u] = findp(par[u]));
    }

    void join(int u,int v){
        par[u] = par[findp(v)];
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            par[i] = i;
        }
        for(int i = 1;i <= n;++i){
            cin>>f[i];
            if(!f[i])continue;
            join(i,f[i]);
            ++g[i];
            ++r[f[i]];
        }
        vector <int> vec;
        for(int i = 1;i <= n;++i){
            if(i == findp(i)){
                vec.emplace_back(i);
            }
        }
        for(int i = 1;i <= n;++i){
            child[findp(i)].emplace_back(i);
        }
        vector <int> tmp;
        for(int i = 0;i < sz(vec);++i){
            int u = vec[i];
            int x = 0,y = 0;
            for(auto v : child[u]){
                if(!g[v]){
                    x = v;
                }
                if(!r[v]){
                    y = v;
                }
            }
            if(x and y) {
                tmp.emplace_back(u);
                child[u] . clear();
                child[u] . emplace_back(x);
                child[u] . emplace_back(y);
            }
        }
        for(int i = 0;i < sz(tmp);++i){
            int u = tmp[i];
            int v = tmp[(i + 1) % (sz(tmp))];
            f[child[u][0]] = child[v][1];
        }
        for(int i = 1;i <= n;++i){
            cout<<f[i]<<' ';
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