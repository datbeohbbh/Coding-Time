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

    const int N = 1e6 + 6;
    int a[N];
    ll f[4][N],sum[N];
    int n,x;
    ll ans = 0;

    struct  FenwickTree{
        vector <int> ft;
        void initFenwickTree(){
            ft.assign(N,0);
        }
        void update_up(int node){
            for(;node < N;node += node & (-node)){
                ft[node] += 1;
            }
        }
        void update_down(int node){
            for(;node > 0;node -= node & (-node)){
                ft[node] += 1;
            }
        }
        int rsq_up(int node){
            int ret = 0;
            for(;node < N;node += node & (-node)){
                ret += ft[node];
            }
            return  ret;
        }
        int rsq_down(int node){
            int ret = 0;
            for(;node > 0;node -= node & (-node)){
                ret += ft[node];
            }
            return ret;
        }
    };
    FenwickTree fen;

    ll coef(int val){
        return 1LL*(val - 1)*1LL*val / 2LL;
    }

    void solve(){
        cin>>n>>x;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        ans = coef(x) + x;
        fen.initFenwickTree();
        for(int i = n;i >= 1;--i){
            if(a[i] < x){
                f[0][i] += fen.rsq_down(a[i] - 1);
            }
            if(a[i] - 2 > 0) {
                f[2][i] += fen.rsq_down(a[i] - 2);
            }
            fen.update_up(a[i]);
        }
        fen.initFenwickTree();
        for(int i = 1;i <= n;++i){
            if(a[i] > 1){
                f[1][i] += fen.rsq_up(a[i] + 1);
            }
            if(a[i] + 2 <= x) {
                f[3][i] += fen.rsq_up(a[i] + 2);
            }
            fen.update_down(a[i]);
        }
        for(int i = 1;i <= n;++i){
            if(a[i] < x){
                sum[a[i] + 1] += f[0][i];
            }
            if(a[i] > 1){
                sum[a[i]] -= f[1][i];
                sum[1] += f[1][i];
            }
            sum[a[i] + 1] += f[3][i];
            sum[a[i]] -= f[2][i];
        }
        for(int i = 1;i <=x ;++i){
            sum[i] += sum[i - 1];
        }
        for(int l = 1;l <= x;++l){
            if(sum[l]){
                int &r = l;
                int tl = l;
                while(r <= x and sum[r]){
                    ++r;
                }
                ans -= (coef(r - tl) + r - tl);
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