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

    void solve(){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vector <int> ans;
        while(a > 0 and b > 0){
            ans.emp(0);
            ans.emp(1);
            --a;
            --b;
        }
        while(b > 0 and c > 0){
            ans.emp(2);
            ans.emp(1);
            --b;
            --c;
        }
        while(c > 0 and d > 0){
            ans.emp(2);
            ans.emp(3);
            --c;
            --d;
        }
        while(c > 0){
            ans.emp(2);
            --c;
        }
        while(d > 0){
            ans.emp(3);
            --d;
        }
        while(a > 0){
            ans.emp(0);
            --a;
        }
        while(b > 0){
            ans.emp(1);
            --b;
        }
        for(int i = 1;i < sz(ans);++i){
            if(Abs(ans[i] - ans[i - 1]) != 1){
                cout<<"NO",exit(0);
            }
        }
        cout<<"YES";
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