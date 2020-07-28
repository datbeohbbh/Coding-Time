#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

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
template <class T,class U,class V>
T add_mod(T x,U k,V MOD){
    return (x % MOD + k % MOD) % MOD;
}
template <class T,class U,class V>
T sub_mod(T x,U k,V MOD){
    return (x % MOD - k % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul_mod(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

modular

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const ll base = 1e9 + 7;

    ll fastExp(ll x,ll h){
        ll res = 1;
        for(;h > 0;h /= 2,x = mul_mod(x,x,base)){
            if(h & 1){
                res = mul_mod(res,x,base);
            }
        }
        return res;
    }

    void solve(){
        ll x,y;
        int type;
        cin>>type>>x>>y;
        switch(type){
            case 0 : cout<<(x == y ? "yes" : "no");
                break;
            case 1 : cout<<(x != y ? "yes" : "no");
                break;
            case 2 : cout<<(x < y ? "yes" : "no");
                break;
            case 3 : cout<<(x > y ? "yes" : "no");
                break;
            case 4 : cout<<(x <= y ? "yes" : "no");
                break;
            case 5 : cout<<(x >= y ? "yes" : "no");
                break;
            case 6 : cout<<add_mod(x,y,base);
                break;
            case 7 : cout<<sub_mod(x,y,base);
                break;
            case 8 : cout<<mul_mod(x,y,base);
                break;
            case 9 : ll h;
                cin>>h;
                cout<<fastExp(x,h);
                break;
            case 10 : cout<<mul_mod(x,fastExp(y,base - 2),base);
                break;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
#endif // ONLINE_JUDGE
    task::solve();
}
