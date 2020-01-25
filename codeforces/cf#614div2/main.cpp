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
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    ll dist(pll x,pll y){
        return Abs(x.first - y.first) + Abs(x.second - y.second);
    }

    void solve(){
        ll x0,y0,ax,bx,ay,by,xs,ys,t;
        cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
        ll tmp_x = x0;
        ll tmp_y = y0;
        vector <pll> ve;
        while(tmp_x <= 1e18 and tmp_y <= 1e18){
            ve.emplace_back(make_pair(tmp_x,tmp_y));
            if(ax <= (1e18 - bx) / tmp_x){
                tmp_x = ax * tmp_x + bx;
            } else {
                break;
            }
            if(ay <= (1e18 - by) / tmp_y) {
                tmp_y = ay * tmp_y + by;
            } else {
                break;
            }
        }
        int ans = 0;
        sort(all(ve));
        for(int i = 0;i < ve.size();++i){
            ll cur_dist = dist(make_pair(xs,ys),ve[i]);
            if(cur_dist <= t){
                for(int j = 0;j <= i;++j){
                    for(int k = i;k < ve.size();++k){
                        if(cur_dist + min(dist(ve[i],ve[j]),dist(ve[i],ve[k])) + dist(ve[j],ve[k]) <= t){
                            maximize(ans,k - j + 1);
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}