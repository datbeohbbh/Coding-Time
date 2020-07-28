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
    const int lg = 18;
    vector <pii> adj[N];
    int n,m,k,q;

    struct Edges{
        int u,v,w;
        Edges(int u,int v,int w){
            this -> u = u;
            this -> v = v;
            this -> w = w;
        }
        bool operator < (const Edges &other){
            return w < other.w;
        }
    };
    vector <Edges> edgesList;

    typedef struct DisjointSetUnion{
        int par[N];
        DisjointSetUnion(){
            for(int i = 0;i < N;++i){
                par[i] = i;
            }
        }
        int findp(int u){
            return (u == par[u] ? u : par[u] = findp(par[u]));
        }
        bool join(int u,int v){
            u = findp(u);
            v = findp(v);
            if(u == v){
                return true;
            }
            par[u] = v;
            return false;
        }
    }Dsu;
    Dsu dsu = DisjointSetUnion();

    ll c[N];
    int h[N];
    pair <int,ll> ord[N];
    vector <int> ve;
    ll rmq[lg + 2][N];
    int f[lg + 2][N];
    int lca[lg + 2][N];

    void dfs(int u,int p,int cur){
        f[0][u] = cur;
        lca[0][u] = p;
        for(pii e : adj[u]){
            int v = e.fir;
            int w = e.sec;
            if(v == p)continue;
            c[v] = c[u] + (ll)w;
            h[v] = h[u] + 1;
            dfs(v,u,(v <= k ? v : cur));
        }
        if(u <= k) {
            ord[u] = mp(ve.size(), c[u] - c[cur]);
            ve.emp(u);
        }
    }

    int getLca(int u,int v){
        if(h[u] < h[v])swap(u,v);
        for(int j = lg;~j;--j){
            if(h[lca[j][u]] >= h[v]){
                u = lca[j][u];
            }
        }
        if(u == v){
            return u;
        }
        for(int j = lg;~j;--j){
            if(lca[j][u] ^ lca[j][v]){
                u = lca[j][u];
                v = lca[j][v];
            }
        }
        return lca[0][u];
    }

    int lift(int u,int p){
        for(int j = lg;~j;--j){
            if(h[f[j][u]] < h[p]){
                u = f[j][u];
            }
        }
        return u;
    }

    ll getMax(int l,int r){
        int x = (int)log2(r - l + 1);
        return max(rmq[x][l],rmq[x][r - MASK(x) + 1]);
    }

    void solve(){
        cin>>n>>m>>k>>q;
        for(int i = 0;i < m;++i){
            int u,v,w;
            cin>>u>>v>>w;
            edgesList.emp(Edges(u,v,w));
        }
        sort(all(edgesList));
        for(int i = 0;i < sz(edgesList);++i){
            int u = edgesList[i].u;
            int v = edgesList[i].v;
            int w = edgesList[i].w;
            if(!dsu.join(u,v)){
                adj[u].emp(mp(v,w));
                adj[v].emp(mp(u,w));
            }
        }
        dfs(1,1,1);
        for(int j = 1;j <= lg;++j){
            for(int i = 1;i <= n;++i){
                f[j][i] = f[j - 1][f[j - 1][i]];
                lca[j][i] = lca[j - 1][lca[j - 1][i]];
            }
        }
        for(int i = 0;i < sz(ve);++i){
            rmq[0][i] = ord[ve[i]].sec;
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 0;i + MASK(j) - 1 < sz(ve);++i){
                rmq[j][i] = max(rmq[j - 1][i],rmq[j - 1][i + MASK(j - 1)]);
            }
        }
        while(q--){
            int u,v,ord_u,ord_v;
            cin>>u>>v;
            int p = getLca(u,v);
            ord_u = lift(u,p);
            ord_v = lift(v,p);
            ll ans = -1;
            if(ord[u].fir <= ord[ord_u].fir - 1){
                maximize(ans,getMax(ord[u].fir,ord[ord_u].fir - 1));
            }
            if(ord[v].fir <= ord[ord_v].fir - 1){
                maximize(ans,getMax(ord[v].fir,ord[ord_v].fir - 1));
            }
            if(p <= k){
                maximize(ans,c[ord_u] - c[p]);
                maximize(ans,c[ord_v] - c[p]);
            } else {
                maximize(ans,c[ord_u] + c[ord_v] - (c[p]<<1LL));
            }
            cout<<ans<<'\n';
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