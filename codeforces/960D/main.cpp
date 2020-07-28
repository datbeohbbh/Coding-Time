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

    const int lg = 61;
    ll shift[lg + 2];

    int getHeight(ll val){
        for(int h = 0;h <= lg;++h){
            if(MASK(h) <= val and val <= MASK(h + 1) - 1){
                return h;
            }
        }
    }

    void f(int from,int to,ll k){
        int g = from;
        while(from <= to){
            shift[from] += MASK(from - g) * k;
            ++from;
        }
    }

    void solve(){
        int q;
        cin>>q;
        while(q--){
            int type;
            ll x,k;
            cin>>type;
            if(type < 3){
                cin>>x>>k;
                ll h = getHeight(x);
                if(type == 1){
                    f(h,h,k);
                } else {
                    f(h,lg,k);
                }
            } else {
                cin>>x;
                ll h = getHeight(x);
                ll pos = x - MASK(h);
                ll cur = (pos + shift[h] % MASK(h) + MASK(h)) % MASK(h);
                cout<<x<<' ';
                for(--h;h >= 0;--h){
                    cur = (cur - (cur & 1)) >> 1LL;
                    x = MASK(h) + (cur - shift[h] % MASK(h) + MASK(h)) % MASK(h);
                    cout<<x<<' ';
                }
                cout<<'\n';
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