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

    const llong base = 1000000007;
    class Solver{
        public:
            llong mulmod(llong a,llong b,llong mod){
                return ((a % mod) * (b % mod)) % mod;
            }

            void solve(){
                int n,k,w;
                cin>>n>>k>>w;
                vector < llong > l(n + 2,0);
                vector < llong > h(n + 2,0);
                for(int i = 1;i <= k;++i){
                    cin>>l[i];
                }
                llong al,bl,cl,dl;
                cin>>al>>bl>>cl>>dl;
                for(int i = k + 1;i <= n;++i){
                    l[i] = ((mulmod(al,l[i - 2],dl) + mulmod(bl,l[i - 1],dl) + cl) % dl) + 1;
                }
                for(int i = 1;i <= k;++i){
                    cin>>h[i];
                }
                llong ah,bh,ch,dh;
                cin>>ah>>bh>>ch>>dh;
                for(int i = k + 1;i <= n;++i){
                    h[i] = ((mulmod(ah,h[i - 2],dh) + mulmod(bh,h[i - 1],dh) + ch) % dh) + 1;
                }
                llong cur_sum = 0;
                llong ans = 1;
                vector < llong > ver(n + 2,0);
                for(int i = 1;i <= n;++i){
                    llong curl = l[i];
                    int j = i + 1;
                    while(j <= n and curl + w >= l[j]){
                        curl = l[j++];
                    }
                    ver[i] = h[i];
                    ans = mulmod(ans,cur_sum + 2LL * (h[i] + w),base);
                    llong cur_p = 2LL * (h[i] + w);
                    for(int t = i + 1;t < j;++t){
                        int f = t - 1;
                        llong maxh = h[f];
                        int g = f;
                        while(f >= i and l[f] + w >= l[t]){
                            if(maxh <= h[f]){
                                maxh = h[f];
                                g = f;
                            }
                            --f;
                        }
                        ver[t] = ver[g] + tabs(h[g] - h[t]);
                        cur_p = 2LL * (l[t] + w - l[i]) + ver[t] + h[t];
                        ans = mulmod(ans,cur_sum + cur_p,base);
                    }
                    //debug(cur_sum,cur_p,j);
                    //debug(cur_p,j - 1);
                    if(j <= n){
                        cur_sum += cur_p;
                    }
                    i = --j;
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
    freopen(fn".inp","r",stdin);
    //freopen(fn".txt","w",stdout);	
    #endif // ONLINE_JUDGE
    /*ofstream cout("test.inp");
    cout<<1<<'\n';
    cout<<1000000<<' '<<1000000<<' '<<20<<'\n';
    for(int i = 1;i <= 1000000;++i){
        cout<<i<<' ';
    }
    cout<<'\n';
    cout<<"0 0 0 0\n";
    for(int i = 1;i <= 1000000;++i){
        cout<<i<<' ';
    }
    cout<<'\n';
    cout<<"0 0 0 0\n";*/
    Task::solve();
}

