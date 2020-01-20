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

    const  int N = 1e5 + 5;
    vector <int> adj[N];
    int a[N],ord[N],lab[N];
    bool ingraph[N],par[N];
    ll ans = 0;
    int n,m;

    int findp(int u){
        return (lab[u] < 0 ? u : findp(lab[u]));
    }

    void join(int u,int v){
        u = findp(u),v = findp(v);
        if(u == v)return ;
        if(lab[u] > lab[v])swap(u,v);
        lab[u] += lab[v];
        lab[v] = u;
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            ord[i] = i;
            lab[i] = -1;
        }
        for(int i = 1;i <= m;++i){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        sort(ord + 1,ord + 1 + n,[&](const int &i,const int &j){
            return a[i] > a[j];
        });
        for(int i = 1;i <= n;++i){
            vector <pii> f;
            f.pb(mp(ord[i],1));
            ingraph[ord[i]] = true;
            par[ord[i]] = true;
            for(int j = 0;j < sz(adj[ord[i]]);++j){
                int u = adj[ord[i]][j];
                if(!ingraph[u])continue;
                u = findp(u);
                if(!par[u]){
                    par[u] = true;
                    f.pb(mp(u,-lab[u]));
                }
                join(ord[i],u);
            }
            int sum = 0;
            for(int j = 0;j < sz(f);++j){
                sum += f[j].sec;
                par[f[j].fir] = false;
            }
            for(int j = 0;j < sz(f);++j){
                ans += 1LL*(sum - f[j].sec)*1LL*f[j].sec*1LL*a[ord[i]];
            }
        }
        cout<<setprecision(10)<<fixed;
        cout<<(double)ans / ((double)n*(double)(n - 1));
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