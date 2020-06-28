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

    const int N = 1e5 + 5;
    vector <int> adj[N];
    vector <int> ans;
    int d[N],a[N],ord[N];
    int n,m;

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= m;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            ord[i] = i;
            d[i] = -a[i];
        }
        sort(ord + 1,ord + 1 + n,[&](const int &u,const int &v) -> bool{
            return d[u] < d[v];
        });
        set < pair <int,int> > heap;
        for(int u = 1;u <= n;++u){
            if(!d[u]) {
                heap.insert(make_pair(d[u], u));
            }
        }
        while(!heap.empty()){
            while(!heap.empty() and heap.begin() -> first != 0){
                heap.erase(heap.begin());
            }
            if(!heap.empty()){
                pair <int,int> top = *heap.begin();
                heap.erase(heap.begin());
                int u = top.second;
                ans.emplace_back(u);
                for(int v : adj[u]){
                    if(heap.find(make_pair(d[v],v)) != heap.end()){
                        heap.erase(heap.find(make_pair(d[v],v)));
                    }
                    ++d[v];
                    if(d[v] == 0){
                        heap.insert(make_pair(d[v],v));
                    }
                }
            }
        }
        auto cnt = [&]() -> int{
            int cc = 0;
            for(int u = 1;u <= n;++u){
                cc += d[u] == 0;
            }
            return cc == n;
        };
        if(cnt()){
            cout<<-1;
            exit(0);
        }
        cout<<len(ans)<<'\n';
        for(int val : ans){
            cout<<val<<' ';
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
