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

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 21;
    int n,m;
    string s;
    int g[N][N];
    int f[N][MASK(N)];
    int dp[MASK(N)];

    int compute(int mask){
        if(__builtin_popcount(mask) == m){
            return 0;
        }
        if(~dp[mask]){
            return dp[mask];
        }
        int ret = numeric_limits <int> :: max();
        int cur_bit = __builtin_popcount(mask);
        for(int c = 0;c < m;++c){
            if(!BIT(mask,c)){
                minimize(ret,compute(mask | MASK(c)) + cur_bit * (f[c][mask] - f[c][(MASK(m) - 1) ^ mask]));
            }
        }
        return dp[mask] = ret;
    }

    void solve(){
        cin>>n>>m>>s;
        for(int i = 0;i < n;++i){
            if(i and s[i] != s[i - 1]){
                ++g[s[i] - 'a'][s[i - 1] - 'a'];
            }
            if(i < n - 1 and s[i] != s[i + 1]){
                ++g[s[i] - 'a'][s[i + 1] - 'a'];
            }
        }
        for(int i = 0;i < m;++i){
            for(int mask = 0;mask < MASK(m);++mask){
                for(int j = 0;j < m;++j){
                    f[i][mask] += BIT(mask,j) * g[i][j];
                }
            }
        }
        for(int mask = 0;mask < MASK(m);++mask){
            dp[mask] = -1;
        }
        cout<<compute(0);
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
