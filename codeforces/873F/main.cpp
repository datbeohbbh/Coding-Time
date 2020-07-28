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

    const int N = 2e5 + 5;
    const int lg = 20;
    int n;
    int sum[N];
    string s,t;

    class SuffixArray {
    public:
        pair <pii,int> cur_rank[N];
        int rank[N];
        int p[N][lg + 1];
        int lcp[N];
        string str;
        int len;
    public:
        SuffixArray(string str){
            this -> str = str;
            this -> len = str.size();
        }
        void buildSuffixArray(){
            for(int i = 0;i < len;++i){
                p[i][0] = str[i] - 'a';
            }
            for(int j = 1;j <= lg;++j){
                for(int i = 0;i < len;++i){
                    cur_rank[i] = make_pair(make_pair(p[i][j - 1],(i + MASK(j - 1) < len ? p[i + MASK(j - 1)][j - 1] : -1)),i);
                }
                sort(cur_rank,cur_rank + len);
                for(int i = 0;i < len;++i){
                    p[cur_rank[i].second][j] = (i and cur_rank[i].first == cur_rank[i - 1].first ? p[cur_rank[i - 1].second][j] : i);
                }
            }
            for(int i = 0;i < len;++i){
                rank[i] = cur_rank[i].second;
            }
        }
        int buildLcp(int i,int j){
            int ret = 0;
            for(int k = lg;~k;--k){
                if(i + MASK(k) <= len and j + MASK(k) <= len) {
                    if (p[i][k] == p[j][k]) {
                        ret += MASK(k);
                        i += MASK(k);
                        j += MASK(k);
                    }
                }
            }
            return ret;
        }
    };
    SuffixArray *sa;

    int get_sum(int l,int r){
        return sum[r] - (!l ? 0 : sum[l - 1]);
    }

    void solve(){
        cin>>n>>s>>t;
        reverse(all(s));
        reverse(all(t));
        sa = new SuffixArray(s);
        sa -> buildSuffixArray();
        ll ans = 0;
        for(int i = 0;i < n;++i){
            sum[i] = t[sa -> rank[i]] - '0';
            if(t[i] == '0'){
                maximize(ans,n - i);
            }
        }
        for(int i = 1;i < n;++i){
            sum[i] += sum[i - 1];
        }
        for(int i = 1;i < n;++i){
            sa -> lcp[i] = sa -> buildLcp(sa -> rank[i],sa -> rank[i - 1]);
        }
        stack <int> stk;
        vector <int> left(n,0);
        for(int i = 1;i < n;++i){
            while(!stk.empty() and sa -> lcp[stk.top()] > sa -> lcp[i]){
                stk.pop();
            }
            left[i] = (!stk.empty() ? stk.top() : 0);
            stk.emplace(i);
        }
        while(!stk.empty()){
            stk.pop();
        }
        for(int i = n - 1;i >= 1;--i){
            while(!stk.empty() and sa -> lcp[stk.top()] > sa -> lcp[i]){
                stk.pop();
            }
            int r = (!stk.empty() ? stk.top() : n) - 1;
            stk.push(i);
            maximize(ans,1LL * sa -> lcp[i] * 1LL * (r - left[i] + 1 - get_sum(left[i],r)));
        }
        cout<<ans;
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
