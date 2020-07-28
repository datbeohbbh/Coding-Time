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

    void solve(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            vector <int> b(n + 2,0);
            vector <int> has((n << 1) + 2,0);
            for(int i = 1;i <= n;++i){
                cin>>b[i];
                has[b[i]] = true;
            }
            vector <int> c;
            for(int i = 1;i <= (n << 1);++i){
                if(!has[i]){
                    c.emplace_back(i);
                }
            }
            vector <int> ans((n << 1) + 2,0);
            for(int i = 1;i <= n;++i){
                bool ok = true;
                for(int j = 0;j < c.size();++j){
                    if(c[j] < b[i])continue;
                    vector <int> x,y;
                    for(int k = i + 1;k <= n;++k){
                        x.emplace_back(b[k]);
                    }
                    for(int k = 0;k < c.size();++k){
                        if(k != j){
                            y.emplace_back(c[k]);
                        }
                    }
                    sort(all(x));
                    sort(all(y));
                    for(int k = 0;k < x.size();++k){
                        if(x[k] > y[k]){
                            ok = false;
                        }
                    }
                    if(ok){
                        ans[(i << 1) - 1] = b[i];
                        ans[i << 1] = c[j];
                        c.clear();
                        c = y;
                        break;
                    }
                }
            }
            bool ok = true;
            for(int i = 1;i <= n;++i){
                if(min(ans[i << 1],ans[(i << 1) - 1]) != b[i]){
                    ok = false;
                }
            }
            if(!ok){
                cout<<-1<<'\n';
            } else {
                for(int i = 1;i <= (n << 1);++i){
                    cout<<ans[i]<<' ';
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
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
