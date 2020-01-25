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

    const int N = 2e5 + 5;
    vector <pii> edges;
    vector <int> par;
    vector <int> child;
    int n,m,a,b;

    void clr(){
        edges.clear();
        child.clear();
        par.clear();
    }

    bool chk(int u,int v){
        return ((u != a and u != b) and (v != a and v != b));
    }

    int findp(int u){
        return u == par[u] ? u : par[u] = findp(par[u]);
    }

    void join(int u,int v){
        u = findp(u),v = findp(v);
        if(u == v){
            return ;
        }
        par[u] = v;
        child[v] += child[u];
    }

    void solve(){
        cin>>n>>m>>a>>b;
        par.resize(n + 1);
        child.resize(n + 1,1);
        for(int i = 1;i <= n;++i){
            par[i] = i;
        }
        for(int i = 1;i <= m;++i){
            int u,v;
            cin>>u>>v;
            edges.emp(mp(u,v));
        }
        for(pii E : edges){
            int u = E.fir;
            int v = E.sec;
            if(chk(u,v)){
                join(u,v);
            }
        }
        vector <int> comp[2];
        for(pii E : edges){
            int u = E.fir;
            int v = E.sec;
            if(!chk(u,v) or !chk(v,u)){
                if(u == a and v != a and v != b){
                    comp[0].emp(findp(v));
                }
                if(u == b and v != a and v != b){
                    comp[1].emp(findp(v));
                }
                if(v == a and u != a and u != b){
                    comp[0].emp(findp(u));
                }
                if(v == b and u != a and u != b){
                    comp[1].emp(findp(u));
                }
            }
        }
        int cnt[2] = {0,0};
        for(int i = 0;i < 2;++i){
            sort(all(comp[i]));
            comp[i].erase(unique(all(comp[i])),comp[i].end());
        }
        for(int i = 0;i < 2;++i){
            for(int u : comp[i]){
                auto it = lower_bound(all(comp[i ^ 1]),u);
                if(it == comp[i ^ 1].end() or (*it) != u){
                    cnt[i] += child[u];
                }
            }
        }
        cout<<(1LL * cnt[0] * 1LL * cnt[1])<<'\n';
        clr();
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--) {
        task::solve();
    }
}