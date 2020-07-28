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
    const ll inf = 1e15;
    int n,m;
    map <ll,bool> ma;
    ll x[N];
    set <pll> human;

    int find_l(ll pos){
        int l = 1,r = n;
        int p = -1;
        for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(x[mid] <= pos){
                p = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return p;
    }

    int find_r(ll pos){
        int l = 1,r = n;
        int p = -1;
        for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(x[mid] >= pos){
                p = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return p;
    }

    void add(ll pos){
        if(ma[pos])return ;
        int l = find_l(pos);
        int r = find_r(pos);
        ll f1 = inf,f2 = inf;
        if(~l){
            f1 = Abs(pos - x[l]);
        }
        if(~r){
            f2 = Abs(pos - x[r]);
        }
        human.insert(make_pair(min(f1,f2),pos));
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>x[i];
            ma[x[i]] = true;
        }
        sort(x + 1,x + 1 + n);
        for(int i = 1;i <= n;++i){
            if(!ma[x[i] - 1]){
                human.insert(make_pair(1,x[i] - 1));
            }
            if(!ma[x[i] + 1]){
                human.insert(make_pair(1,x[i] + 1));
            }
        }
        ll ans = 0;
        vector <ll> vec;
        for(int i = 1;i <= m;++i){
            while(!human.empty() and ma[human.begin() -> second]){
                human.erase(human.begin());
            }
            pll top = *human.begin();
            ll pos = top.second;
            ll dist = top.first;
            ans += dist;
            vec.emplace_back(pos);
            ma[pos] = true;
            add(pos - 1);
            add(pos + 1);
        }
        cout<<ans<<'\n';
        for(ll val : vec){
            cout<<val<<' ';
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