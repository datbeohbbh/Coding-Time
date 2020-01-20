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
    const  ll base = 1e9 + 7;
    const int lg = 18;
    int par[N][lg + 2];
    ll gcd[N][lg + 2];
    int h[N];
    ll x[N];
    vector <int> adj[N];
    int n;
    ll ans = 0;

    void dfs(int u,int dad){
        par[u][0] = dad;
        gcd[u][0] = __gcd(x[u],x[dad]);
        for(int v : adj[u]){
            if(v ^ dad){
                h[v] = h[u] + 1;
                dfs(v,u);
            }
        }
    }

    void buildJumpPointer(){
        for(int j = 1;j <= lg;++j){
            for(int i = 1;i <= n;++i){
                par[i][j] = par[par[i][j - 1]][j - 1];
                gcd[i][j] = __gcd(gcd[i][j - 1],gcd[par[i][j - 1]][j - 1]);
            }
        }
    }

    bool chk(ll u,ll v){
        return (v == 0 ? u == 0 : u % v == 0);
    }

    ll jump(int v){
        int u = v;
        ll cur = x[v];
        ll ret = 0;
        while(true){
            for(int j = lg;~j;--j){
                if(par[u][j] > 0 and chk(gcd[u][j],cur)){
                    u = par[u][j];
                }
            }
            ret = addmod(ret,mul(1LL*(h[v] - h[u] + 1),cur,base),base);
            if(u == 1)break;
            u = par[u][0];
            v = u;
            cur = __gcd(cur,x[v]);
        }
        return ret;
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>x[i];
        }
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emp(v),adj[v].emp(u);
        }
        h[1] = 1;
        dfs(1,0);
        buildJumpPointer();
        for(int v = 1;v <= n;++v){
            ans = addmod(ans,jump(v),base);
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