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

    const int N = 1505;
    int a[N];
    int sum[N];
    int n;
    map <int,vector <pii>> seg;

    class FenwickTree{
    public :
        vector <pii> tree;
    public:
        void clr(int _size){
            tree.clear();
            tree.resize(_size + 2,make_pair(0,-1));
        }

        void update(int node,pii val){
            for(;node <= n;node |= (node + 1)){
                maximize(tree[node],val);
            }
        }

        pii rmq(int node){
            pii ret = make_pair(0,-1);
            for(;node > 0;node = (node & (node + 1)) - 1){
                maximize(ret,tree[node]);
            }
            return ret;
        }
    };
    FenwickTree *fenw = new FenwickTree;

    int k = 0;
    vector <pii> block;

    void calc(const vector <pii> &vec){
        int len = vec.size();
        fenw -> clr(n);
        vector <pii> dp(len + 2,make_pair(0,0));
        pii res(0,0);
        for(int i = 0;i < vec.size();++i){
            int l = vec[i].first;
            int r = vec[i].second;
            pii cur = fenw -> rmq(l - 1);
            maximize(dp[i],make_pair(cur.first + 1,cur.second));
            fenw -> update(r,make_pair(dp[i].first,i));
            if(dp[i].first > res.first){
                res = make_pair(dp[i].first,i);
            }
        }
        if(res.first > k){
            k = res.first;
            int j = res.second;
            block.clear();
            while(~j){
                block.emplace_back(vec[j]);
                j = dp[j].second;
            }
        }
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for(int i = 1;i <= n;++i){
            for(int j = i;j <= n;++j){
                seg[sum[j] - sum[i - 1]].emplace_back(make_pair(i,j));
            }
        }
        for(map <int,vector <pii>> :: iterator it = seg.begin();it != seg.end();++it){
            vector <pii> &vec = it -> second;
            sort(all(vec));
            calc(vec);
        }
        cout<<k<<'\n';
        for(pii p : block){
            cout<<p.first<<' '<<p.second<<'\n';
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
