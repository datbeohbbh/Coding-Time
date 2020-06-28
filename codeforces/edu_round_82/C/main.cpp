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

    const int N = 27;
    int deg[N],adj[N][N];

    void dfs(int u,int par,int deep,pii &res){
        maximize(res,make_pair(deep,u));
        for(int i = 0;i < 26;++i){
            if(adj[u][i]){
                if(i != par){
                    dfs(i,u,deep + 1,res);
                }
            }
        }
    }

    void dfs_(int u,int par){
        cout<<(char)(u + 'a');
        for(int i = 0;i < 26;++i){
            if(adj[u][i]){
                if(i != par){
                    dfs_(i,u);
                }
            }
        }
    }

    void calc(){
        string s;
        cin>>s;
        int cnt = 0;
        if(s.size() == 1){
            cout<<"YES\n";
            for(int i = 0;i < 26;++i){
                cout<<(char)(i + 'a');
            }
            cout<<'\n';
            return ;
        }
        vector <bool> vis(30,false);
        for(int i = 0;i < 26;++i){
            deg[i] = 0;
            for(int j = 0;j < 26;++j){
                adj[i][j] = false;
            }
        }
        for(int i = 0;i < s.size() - 1;++i){
            int a = s[i] - 'a';
            int b = s[i + 1] - 'a';
            adj[a][b] = true;
            adj[b][a] = true;
        }
        int diff = 0;
        for(int i = 0;i < 26;++i){
            for(int j = 0;j < 26;++j){
                deg[i] += adj[i][j];
            }
        }
        int f = -1;
        for(int i = 0;i < 26;++i){
            if(deg[i] > 2){
                cout<<"NO\n";
                return;
            }
            cnt += deg[i];
            diff += (deg[i] != 0);
            if(deg[i] != 0){
                vis[i] = true;
                f = i;
            }
        }
        cnt >>= 1;
        if(cnt != diff - 1){
            cout<<"NO\n";
            return ;
        }
        pii res(-1,-1);
        dfs(f,f,0,res);
        int u = res.second;
        res = make_pair(-1,-1);
        dfs(u,u,0,res);
        if(res.first != diff - 1){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
        dfs_(res.second,res.second);
        for(int i = 0;i < 26;++i){
            if(!vis[i]){
                cout<<(char)(i + 'a');
            }
        }
        cout<<'\n';
    }

    void solve(){
        int t;
        cin>>t;
        while(t--){
            calc();
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
