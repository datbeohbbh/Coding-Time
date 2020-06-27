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

    const int N = 1e2 + 2;
    const int inf = 1e9;
    const int lg = 16;
    const int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
    int n;
    int a[N];
    int index[N];
    int msk[N];
    int f[N][1 << (lg + 1)];
    pii tr[N][1 << (lg + 1)];

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int j = 0;j < 17;++j){
            index[prime[j]] = j;
        }
        for(int i = 2;i < 60;++i){
            int tmp = i;
            for(int j = 2;j * j <= tmp;++j){
                if(tmp % j == 0){
                    while(tmp % j == 0){
                        tmp /= j;
                    }
                    msk[i] |= MASK(index[j]);
                }
            }
            if(tmp > 1) {
                msk[i] |= MASK(index[tmp]);
            }
        }
        for(int i = 0;i <= n;++i){
            for(int mask = 0;mask < MASK(lg);++mask){
                f[i][mask] = inf;
            }
        }
        f[0][0] = 0;
        pii res(inf,inf);
        for(int mask = 0;mask < MASK(lg);++mask){
            for(int i = 0;i < n;++i){
                for(int j = 1;j < (a[i + 1] << 1);++j){
                    if(!(mask & msk[j])){
                        if(f[i + 1][mask | msk[j]] > f[i][mask] + Abs(a[i + 1] - j)){
                            f[i + 1][mask | msk[j]] = f[i][mask] + Abs(a[i + 1] - j);
                            tr[i + 1][mask | msk[j]] = make_pair(mask,j);
                            if(i == n - 1){
                                minimize(res,make_pair(f[i + 1][mask | msk[j]],mask | msk[j]));
                            }
                        }
                    }
                }
            }
        }
        vector <int> ans;
        for(int i = n;i >= 1;--i){
            ans.emplace_back(tr[i][res.second].second);
            res.second = tr[i][res.second].first;
        }
        reverse(all(ans));
        for(int val : ans){
            cout<<val<<' ';
        }
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
