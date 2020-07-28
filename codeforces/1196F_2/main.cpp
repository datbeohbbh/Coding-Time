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
    const llong inf = 1e18;
    int n,m,k;
    vector < pair < int,int > > adj[N];

    set < tuple < llong,int,int > > heap;
    set < tuple < llong,int,int >  > ans;
    vector < llong> dist;
    void dijkstra(){
        dist.resize(n + 2,inf);
        for(int u = 1;u <= n;++u){
            heap.insert(make_tuple(0,u,u));
        }
        function < bool(llong,int,int) > chk = [&](llong d,int u,int v){
            if(u > v){
                swap(u,v);
            }
            return (ans.find(make_tuple(d,u,v)) == ans.end());
        };
        while(!heap.empty()){
            llong cur;
            int u,pref;
            tie(cur,u,pref) = *heap.begin();
            heap.erase(heap.begin());
            if(len(ans) == k){
                if(get < 0 > (*ans.rbegin()) <= cur){
                    break;
                }
            }
            for(pair < int,int > p : adj[u]){
                int v = p.first;
                int w = p.second;
                if(v == pref)continue;
                if(dist[v] > cur + 1LL * w){
                    dist[v] = cur + 1LL * w;
                    heap.insert(make_tuple(dist[v],v,u));
                }
                if(len(ans) < k){
                    if(chk(dist[v],u,v)){
                        ans.insert(make_tuple(dist[v],min(u,v),max(u,v)));
                    }
                } else if(len(ans) == k and get < 0 > (*ans.rbegin()) > dist[v]){
                    if(chk(dist[v],u,v)){
                        ans.erase(ans.find(*ans.rbegin()));
                        ans.insert(make_tuple(dist[v],min(u,v),max(u,v)));
                    }
                }
            }
        }
    }

    void solve(){
        cin>>n>>m>>k;
        for(int i = 1;i <= m;++i){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].emplace_back(make_pair(v,w));
            adj[v].emplace_back(make_pair(u,w));
        }
        dijkstra();
        cout<<get < 0 > (*ans.rbegin());
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
