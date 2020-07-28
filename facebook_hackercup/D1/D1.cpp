#include <bits/stdc++.h>

using namespace std;

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

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

// ================================= DEBUG =================================

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

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

// ================================= DEBUG =================================
namespace task{

    const llong inf = 1e18;
    class Solver{
        public:
            
           vector < llong > dp;
           deque < int > dque;
           int n,m;
           vector < llong > c;
            
           void solve() {
               cin>>n>>m;
               c.resize(n + 2,0);
               for(int i = 1;i <= n;++i){
                   cin>>c[i];
               }
               if(m >= n - 1){
                   cout<<0<<'\n';
                   return;
               }
               dp.resize(n + 2,inf);
               dp[1] = 0;
               for(int i = 1;i <= n;++i){
                   //debug(dque);
                   minimize(dp[i],(dque.empty() ? 0 : dp[dque.front()]) + (i == n ? 0 : c[i] > 0 ? c[i] : inf));
                   while(!dque.empty() and dp[dque.back()] >= dp[i]){
                       dque.pop_back();
                   }
                   while(!dque.empty() and dque.front() + m - 1 < i){
                       dque.pop_front();
                   }
                   dque.emplace_back(i);
                   //debug(dque);
               }
               cout<<(dp[n] == inf ? -1 : dp[n])<<'\n';
           }
    };
    
    void solve(){
        int T;
        cin>>T;
        for(int tests = 1;tests <= T;++tests){
            cout<<"Case #"<<tests<<": ";
            (new Solver) -> solve();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".txt","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}

