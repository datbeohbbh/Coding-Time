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

    string s,t;
    int n,m;
    vector < vector <int> > f;

    class PrefixFunction{
    public:
        string t;
        int len;
        vector < vector <int> > aut;
        vector <int> lps;
        PrefixFunction(string t){
            this -> t = t;
            this -> len = t.size();
        }
        void buildKmp(){
            lps.resize(len + 1,0);
            for(int i = 1;i < len;++i){
                int j = lps[i - 1];
                while(j and t[j] != t[i]){
                    j = lps[j - 1];
                }
                lps[i] = j + (t[j] == t[i]);
            }
        }
        void buildAutomaton(){
            aut.resize(len + 1,vector <int> (27,0));
            for(int i = 0;i < len;++i){
                for(int c = 0;c < 26;++c){
                    if(i and (char)(c + 'a') != t[i]){
                        aut[i][c] = aut[lps[i - 1]][c];
                    } else {
                        aut[i][c] = i + (t[i] == (char)(c + 'a'));
                    }
                }
            }
        }
    };
    PrefixFunction *kmp;

    int compute(int cur,int l){
        if(cur == n){
            return 0;
        }
        if(~f[cur][l]){
            return f[cur][l];
        }
        int &ret = f[cur][l];
        int c_l = s[cur] == '?' ? 0 : s[cur] - 'a';
        int c_r = s[cur] == '?' ? 25 : s[cur] - 'a';
        for(int c = c_l;c <= c_r;++c){
            if(kmp -> aut[l][c] == m){
                maximize(ret,1 + compute(cur + 1,kmp -> lps[l]));
            } else {
                maximize(ret,compute(cur + 1,kmp -> aut[l][c]));
            }
        }
        return ret;
    }

    void solve(){
        cin>>s>>t;
        n = s.size(),m = t.size();
        kmp = new PrefixFunction(t);
        kmp -> buildKmp();
        kmp -> buildAutomaton();
        f.resize(n + 2,vector <int> (m + 2,-1));
        cout<<compute(0,0);
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
