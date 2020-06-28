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
    int par[N];
    int n,m;
    pair <ll,int> a[N];
    set <pair <ll,pii> > heap;

    int findp(int u){
        return (u == par[u] ? u : par[u] = findp(par[u]));
    }

    void join(int u,int v){
        par[findp(u)] = findp(v);
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>a[i].first;
            a[i].second = i;
            par[i] = i;
        }
        for(int i = 1;i <= m;++i){
            int x,y;
            ll w;
            cin>>x>>y>>w;
            heap.insert(make_pair(w,make_pair(x,y)));
        }
        sort(a + 1,a + 1 + n);
        for(int i = 2;i <= n;++i){
            heap.insert(make_pair(a[1].first + a[i].first,make_pair(a[1].second,a[i].second)));
        }
        int E = 0;
        ll ans = 0;
        while(E < n - 1 and !heap.empty()){
            pair <ll,pii> top = *heap.begin();
            heap.erase(heap.begin());
            int u = top.second.first;
            int v = top.second.second;
            if(findp(u) == findp(v))continue;
            join(u,v);
            ++E;
            ans += top.first;
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