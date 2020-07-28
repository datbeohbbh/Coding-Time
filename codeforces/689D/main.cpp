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

    const  int N = 2e5 + 5;
    const  int lg = 19;
    int rmq[2][N][lg + 1];
    int a[N],b[N];
    int n;
    ll ans = 0;

    int queryMax(int l,int r){
        int x = log2(r - l + 1);
        return max(rmq[0][l][x],rmq[0][r - MASK(x) + 1][x]);
    }

    int queryMin(int l,int r){
        int x = log2(r - l + 1);
        return  min(rmq[1][l][x],rmq[1][r - MASK(x) + 1][x]);
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int i = 1;i <= n;++i){
            cin>>b[i];
        }
        for(int i = 1;i <= n;++i){
            rmq[0][i][0] = a[i];
            rmq[1][i][0] = b[i];
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 1;i + MASK(j) - 1 <= n;++i){
                rmq[0][i][j] = max(rmq[0][i][j - 1],rmq[0][i + MASK(j - 1)][j - 1]);
                rmq[1][i][j] = min(rmq[1][i][j - 1],rmq[1][i + MASK(j - 1)][j - 1]);
            }
        }
        for(int i = 1;i <= n;++i){
            if(queryMax(i,i) <= queryMin(i,i)){
                int l = i - 1,r = i;
                for(int j = lg;j >= 0;--j){
                    if(l + MASK(j) <= n and queryMax(i,l + MASK(j)) < queryMin(i,l + MASK(j))){
                        l += MASK(j);
                    }
                    if(r + MASK(j) <= n and queryMax(i,r + MASK(j)) <= queryMin(i,r + MASK(j))){
                        r += MASK(j);
                    }
                }
                ans += 1LL*(r - l);
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