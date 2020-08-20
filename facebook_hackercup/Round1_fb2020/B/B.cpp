#include <bits/stdc++.h>

using namespace std;

template <class T,class U>
void maximize(T &lhs,U rhs){
    if(lhs < rhs)lhs = rhs;
}
template <class T,class U>
void minimize(T &lhs,U rhs){
    if(lhs > rhs)lhs = rhs;
}
template < class T,class U >
void maximize(T &lhs,const initializer_list < U > &rhs){
    U max_rhs = max(rhs);
    if(lhs < max_rhs){
        lhs = max_rhs;
    }
}
template < class T,class U >
void minimize(T &lhs,const initializer_list < U > &rhs){
    U min_rhs = min(rhs);
    if(lhs > min_rhs){
        lhs = min_rhs;
    }
}
template <class T>
T tabs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define fn "test"    /// FILE NAME HERE!!!

/* ================================= END OF TEMPLATE ================================= */

/* ================================= DEBUG ================================= */

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

/* ================================= DEBUG ================================= */
namespace Task{

    const llong inf = 1e18;
    class Solver{
        public:
            vector < llong > p,q;
            int n,m,k,s;
            llong maxTime = 0;
          
        public:
            ~Solver(){
                p.clear();
                q.clear();
            }
            
        public:
            llong mulmod(llong u,llong v,llong mod){
                return ((u % mod) * (v % mod)) % mod;
            }
            
            void calc(vector < llong > &vec,int maxr){
                llong A,B,C,D;
                cin>>A>>B>>C>>D;
                for(int i = k + 1;i <= maxr;++i){
                    vec[i] = ((mulmod(A,vec[i - 2],D) + mulmod(B,vec[i - 1],D) + C % D) % D) + 1;
                }
                sort(vec.begin() + 1,vec.begin() + 1 + maxr);
                maxTime += D;
            }
            
            void solve(){
                cin>>n>>m>>k>>s;
                p.resize(n + 2,0);
                q.resize(m + 2,0);
                for(int i = 1;i <= k;++i){
                    cin>>p[i];
                }
                calc(p,n);
                for(int i = 1;i <= k;++i){
                    cin>>q[i];
                }
                calc(q,m);
                
                function < llong(int,int,int) > cost = [&](int i,int l,int r) -> llong {
                    return q[r] - q[l] + min(tabs(p[i] - q[l]),tabs(p[i] - q[r]));
                };
                
                function < bool(llong) > can = [&](llong lim) -> bool{
                    int cur = 0;
                    for(int i = 1;i <= n;++i){
                        int j = cur + 1;
                        while(j <= m and cost(i,cur + 1,j) <= lim){
                            ++j;
                        }
                        cur = --j;
                    }
                    return cur >= m;
                };
                
                llong ans = -1;
                for(llong l = 0,r = maxTime,mid = (l + r) / 2LL;l <= r;mid = (l + r) / 2LL){
                    if(can(mid)){
                        ans = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                cout<<ans<<'\n';
            }
    };
    
    void solve(){
        int T;
        cin>>T;
        for(int test = 1;test <= T;++test){
            cout<<"Case #"<<test<<": ";
            (new Solver) -> solve();
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".input","r",stdin);
    freopen(fn".txt","w",stdout);	
    #endif // ONLINE_JUDGE
    Task::solve();
}

