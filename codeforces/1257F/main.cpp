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

    const int N = 1e2 + 2;
    const int lg = 15;
    const ll base[] = {1000000007,1000000087};
    const ll p[] = {29,31};
    int n;
    ll a[N];
    map <pair <ll,ll>,pair <ll,bool> > ma[2];

    pair <ll,ll> getHash(const vector <int> &ve){
        ll hs[2];
        hs[0] = hs[1] = ve[0];
        for(int j = 0;j < 2;++j){
            for(int i = 1;i < sz(ve);++i){
                hs[j] = (hs[j] * p[j] + (ll)ve[i] + base[j]) % base[j];
            }
        }
        return mp(hs[0],hs[1]);
    }

    void solve(){
        cin>>n;
        for(int i = 0;i < n;++i){
            cin>>a[i];
        }
        for(int j = 0;j < 2;++j) {
            for (int mask = 0; mask < MASK(lg); ++mask) {
                vector<int> ve;
                ll t = (!j ? MASK(lg) - 1 : ((MASK(lg) - 1) << lg));
                ll msk = (!j ? mask : mask << lg);
                for (int i = 1; i < n; ++i) {
                    ll u = (a[i] & t) ^ msk;
                    ll v = (a[i - 1] & t) ^ msk;
                    u = __builtin_popcountll(u);
                    v = __builtin_popcountll(v);
                    if(j){
                        swap(u,v);
                    }
                    ve.emp(u - v);
                }
                pair <ll,ll> h = getHash(ve);
                if(ma[j][h].sec == false){
                    ma[j][h] = mp(msk,true);
                }
            }
        }
        for(auto val : ma[0]){
            pair <ll,ll> t = val.fir;
            if(ma[1][t].sec == true){
                cout<<(val.sec.fir | ma[1][t].fir);
                return;
            }
        }
        cout<<-1;
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