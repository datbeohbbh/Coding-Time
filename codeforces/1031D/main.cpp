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

    const int N = 2e3 + 3;
    const int tx[] = {1,0};
    const int ty[] = {0,1};
    const int inf = 1e9;
    vector < vector <int> > dist;
    char a[N][N];
    int n,k;

    bool insize(int u,int v){
        return 1 <= u and u <= n and 1 <= v and v <= n;
    }

    void dijkstra(){
        set <pair <int,pii> > heap;
        dist.resize(n + 2,vector <int> (n + 2,inf));
        dist[1][1] = a[1][1] != 'a';
        heap.insert(make_pair(dist[1][1],make_pair(1,1)));
        while(!heap.empty()){
            pair <int,pii> top = *heap.begin();
            heap.erase(heap.begin());
            int u = top.second.first;
            int v = top.second.second;
            for(int i = 0;i < 2;++i){
                int nxt_u = u + tx[i];
                int nxt_v = v + ty[i];
                if(!insize(nxt_u,nxt_v))continue;
                int w = a[nxt_u][nxt_v] != 'a';
                if(dist[nxt_u][nxt_v] > dist[u][v] + w){
                    if(dist[nxt_u][nxt_v] != inf){
                        heap.erase(heap.find(make_pair(dist[nxt_u][nxt_v],make_pair(nxt_u,nxt_v))));
                    }
                    dist[nxt_u][nxt_v] = dist[u][v] + w;
                    heap.insert(make_pair(dist[nxt_u][nxt_v],make_pair(nxt_u,nxt_v)));
                }
            }
        }
    }

    void solve(){
        cin>>n>>k;
        minimize(k,(n << 1) - 1);
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j) {
                cin >> a[i][j];
            }
        }
        dijkstra();
        vector <pii>  src;
        vector <vector <bool> > vis(n + 2,vector <bool> (n + 2,false));
        int maxLen = -1,t = -1;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                if(dist[i][j] <= k){
                    maximize(maxLen,dist[i][j]);
                    maximize(t,i + j - 2);
                }
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                if(dist[i][j] == maxLen and i + j - 2 == t){
                    src.emplace_back(make_pair(i,j));
                    vis[i][j] = true;
                }
            }
        }
        vector <char> ans;
        if(maxLen == -1){
            src.emplace_back(make_pair(1,1));
            ans.emplace_back(a[1][1]);
        }
        int cnt = src.size();
        while(!src.empty() and cnt < n * n){
            vector <pii> tmp;
            char minC = 'z';
            for(pii p : src) {
                for(int i = 0;i < 2;++i) {
                    int u = p . first + tx[i];
                    int v = p . second + ty[i];
                    if(!insize(u,v))continue;
                    if (!vis[u][v]) {
                        minimize(minC, a[u][v]);
                    }
                }
            }
            for(pii p : src) {
                for(int i = 0;i < 2;++i) {
                    int u = p . first + tx[i];
                    int v = p . second + ty[i];
                    if(!insize(u,v))continue;
                    if(!vis[u][v] and a[u][v] == minC){
                        tmp.emplace_back(make_pair(u,v));
                    }
                    vis[u][v] = true;
                }
            }
            src.clear();
            for(;tmp.size();tmp.pop_back()){
                src.emplace_back(tmp.back());
            }
            if(!src.empty()){
                ans.emplace_back(minC);
            }
            cnt += src.size();
        }
        reverse(all(ans));
        while(ans.size() < (n << 1) - 1){
            ans.emplace_back('a');
        }
        reverse(all(ans));
        for(char c : ans){
            cout<<c;
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