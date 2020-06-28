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
    int R[N],C[N];
    int n,q;


    void solve(){
        cin>>n>>q;
        for(int i = 1;i <= n;++i){
            cin>>R[i];
            R[i] %= 2;
        }
        for(int i = 1;i <= n;++i){
            cin>>C[i];
            C[i] %= 2;
        }
        for(int i = 2;i <= n;++i){
            R[i] += R[i - 1];
            C[i] += C[i - 1];
        }
        while(q--){
            int ra,ca;
            int rb,cb;
            cin>>ra>>ca>>rb>>cb;
            if(ra > rb){
                swap(ra,rb);
            }
            if(ca > cb){
                swap(ca,cb);
            }
            if(R[rb] - R[ra - 1] == 0 and C[cb] - C[ca - 1] == 0){
                cout<<"YES\n";
            } else if(R[rb] - R[ra - 1] == rb - ra + 1 and C[cb] - C[ca - 1] == cb - ca + 1){
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
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