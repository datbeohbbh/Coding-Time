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
    const int inf = numeric_limits <int> :: max();
    vector <int> compress;
    int n,k,ans = inf;
    int w[N],cp_w[N],cnt[2][N],freq[N];

    struct  FenwickTree{
        vector <int> ft;

        void clr(){
            ft.resize(N + 1,0);
        }

        void upd(int node,int val){
            for(;node <= N;node += node & (-node)){
                ft[node] += val;
            }
        }

        int rsq(int node){
            int ret = 0;
            for(;node > 0;node -= node & (-node)){
                ret += ft[node];
            }
            return ret;
        }
    }fen;

    void solve(){
        cin>>n>>k;
        for(int i = 1;i <= n;++i){
            cin>>w[i];
            compress.emp(w[i]);
        }
        sort(all(compress));
        compress.erase(unique(all(compress)),compress.end());

        fen.clr;
        for(int i = 1;i <= n;++i){
            int node = lower_bound(all(compress),w[i]) - compress.begin() + 1;
            cnt[0][i] += fen.rsq(node - 1);
            fen.upd(node,1);
        }

        fen.clr();
        for(int i = n;i >= 1;--i){
            int node = lower_bound(all(compress),w[i]) - compress.begin() + 1;
            cnt[1][i] += fen.rsq(node - 1);
            fen.upd(node,1);
        }

        for(int i = n;i >= 0;--i){
            freq[i] = inf;
        }
        for(int i = n;i >= 0;--i){
            minimize(freq[cnt[1][i]],w[i]);
        }
        for(int i = n - 1;i >= 1;--i){
            minimize(freq[i],freq[i + 1]);
        }

        for(int i = 1;i <= n;++i){
            if(freq[])
            if(freq[])
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