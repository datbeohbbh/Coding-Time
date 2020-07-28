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
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    const int N = 2e5 + 5;
    vector <int> adj[N];
    int a[N],b[N],c[N];
    int n;
    llong ans = 0;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int u,v,i = 1;i < n;++i){
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        function < pair <int,int> (int,int,int) >  dfs = [&](int u,int par,int minValue){
            pair <int,int> f;
            if(b[u] ^ c[u]){
                f.first += (b[u] ^ 1);
                f.second += b[u];
            }
            for(int v : adj[u]){
                if(v ^ par){
                    pair <int,int> ret = dfs(v,u,min(a[u],minValue));
                    f.first += ret.first;
                    f.second += ret.second;
                }
            }
            if(a[u] < minValue){
                ans += 1LL * a[u] * 2LL * min(f.first,f.second) ;
                int subs = min(f.first,f.second);
                f.first -= subs;
                f.second -= subs;
            }
            return f;
        };
        pair <int,int> f = dfs(1,1,numeric_limits <int> :: max());
        cout<<(f.first + f.second ? -1 : ans);
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
