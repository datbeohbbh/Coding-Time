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
void maximize(T &x,U y) {
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y) {
    if(x > y)x=y;
}
template <class T>
T Abs(T x) {
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x) {
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD) {
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD) {
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD) {
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

namespace task {

const int N = 23;
const ll base = 1e9 + 9;
int f[N];
int n,c;
ll m;

struct matrix{
    ll val[N][N];
    matrix(){
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                val[i][j] = 0;
            }
        }
    }
    matrix operator * (const matrix &other){
        matrix res;
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                for(int k = 0;k < N;++k){
                    res.val[i][j] = addmod(res.val[i][j],mul(val[i][k],other.val[k][j],base),base);
                }
            }
        }
        return res;
    }
};

matrix fastExp(matrix x,ll h){
    matrix res;
    for(int i = 0;i < N;++i){
        res.val[i][i] = 1;
    }
    for(;h > 0;h /= 2,x = x * x){
        if(h & 1){
            res = x * res;
        }
    }
    return res;
}

void solve() {
    while(cin>>n>>m>>c){
        matrix a,b;
        for(int i = 0;i < n;++i){
            cin>>f[i];
            b.val[n - 1 - i][0] = f[i];
        }
        for(int i = 0;i < c;++i){
            int k;
            cin>>k;
            a.val[0][k - 1] = 1;
        }
        for(int i = 1;i < c;++i){
            a.val[i][i - 1] = 1;
        }
        if(m <= n){
            cout<<f[m - 1]<<'\n';
            continue;
        }
        a = fastExp(a,m - n);
        b = a*b;
        cout<<b.val[0][0]<<'\n';
    }

}}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
#endif // ONLINE_JUDGE
    task::solve();
}
