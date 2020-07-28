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
    const int lg = 18;
    int l[N],w[N];
    int rmq[N << 1][lg + 2];
    int nxt[N << 1];
    int vis[N << 1];
    vector <pair <pii,int> > vec;
    int n;
    ll ans = 0,tans = 0;
    int rm = 0;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>l[i]>>w[i];
            if(tans < ((ll)l[i] * (ll)w[i]) / 2ll){
                tans = ((ll)l[i] * (ll)w[i]) / 2ll;
                rm = ((ll)l[i] * (ll)w[i]) % 2ll;
            } else if(tans == ((ll)l[i] * (ll)w[i]) / 2ll){
                maximize(rm,((ll)l[i] * (ll)w[i]) % 2ll);
            }
            vec.emp(mp(mp(l[i],w[i]),i));
            vec.emp(mp(mp(w[i],l[i]),i));
        }
        sort(all(vec));
        int m = sz(vec) - 1;
        for(int i = m;~i;--i){
            if(!vis[vec[i].sec]){
                vis[vec[i].sec] = i;
                nxt[i] = m + 1;
            } else {
                nxt[i] = vis[vec[i].sec];
            }
        }
        for(int i = 0;i <= m;++i){
            rmq[i][0] = vec[i].fir.sec;
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 0;i <= m - MASK(j) + 1;++i){
                rmq[i][j] = max(rmq[i][j - 1],rmq[i + MASK(j - 1)][j - 1]);
            }
        }
        auto getMax = [&](const int le,const int ri) -> int{
            int x = (int)log2(ri - le + 1);
            return max(rmq[le][x],rmq[ri - MASK(x) + 1][x]);
        };
        for(int i = 0;i <= m;++i){
            int l,r;
            l = i + 1;
            r = nxt[i] - 1;
            if(l <= r){
                maximize(ans,(ll)vec[i].fir.fir * min((ll)vec[i].fir.sec,(ll)getMax(l,r)));
            }
            l = nxt[i] + 1;
            r = m;
            if(l <= r){
                maximize(ans,(ll)vec[i].fir.fir * min((ll)vec[i].fir.sec,(ll)getMax(l,r)));
            }
        }
        if(ans <= tans){
            cout<<tans<<(rm ? ".5" : ".0");
        } else {
            cout<<ans<<".0";
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