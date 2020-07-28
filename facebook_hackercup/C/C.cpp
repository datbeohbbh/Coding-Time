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
    
    const int inf = 2e9;
    class Solver{
        public:
            void solve(){
                int n;
                cin>>n;
                vector < int > p(n + 2,0);
                vector < int > h(n + 2,0);
                vector < int > ord;
                for(int i = 1;i <= n;++i){
                    cin>>p[i]>>h[i];
                    ord.emplace_back(i);
                }
                sort(ord.begin(),ord.end(),[&](const int &i,const int &j){
                        return p[i] < p[j];
                });
                map < int,int > f;
                for(int i : ord){
                    if(f.count(p[i] + h[i]) == 0){
                        f[p[i] + h[i]] = inf;
                    }
                    if(f.count(p[i]) == 0){
                        f[p[i]] = inf;
                    }
                    minimize(f[p[i] + h[i]],min(f.count(p[i]) > 0 ? f[p[i]] : inf,p[i]));
                    minimize(f[p[i]],min(p[i] - h[i],f.count(p[i] - h[i]) > 0 ? f[p[i] - h[i]] : inf));
                    //debug(f);
                }
                //debug(f);
                llong ans = 0;
                for(auto [key,value] : f){
                    maximize(ans,1LL * key - 1LL * value);
                }
                cout<<ans<<'\n';
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

