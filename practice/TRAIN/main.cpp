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
#define fn "TRAIN"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    const int N = 1e3 + 3;
    const int inf = 2e9;
    vector < pair < int,int >  > adj[N];
    set < pair < int,int > > heap;
    int dist[N];
    int n;

    void solve(){
        cin>>n;
        for(int i = 0;i < n;++i){
            for(int c,j = i;j < n;++j){
                cin>>c;
                adj[i].emplace_back(make_pair(j,c));
            }
        }
        fill(dist,dist + n,inf);
        dist[0] = 0;
        heap.insert(make_pair(0,0));
        while(!heap.empty()){
            pair < int,int > top = *heap.begin();
            heap.erase(heap.begin());
            int u = top.second;
            for(pair < int,int > p : adj[u]){
                int v = p.first;
                int c = p.second;
                if(dist[v] > dist[u] + c){
                    if(dist[v] != inf){
                        heap.erase(heap.find(make_pair(dist[v],v)));
                    }
                    dist[v] = dist[u] + c;
                    heap.insert(make_pair(dist[v],v));
                }
            }
        }
        cout<<dist[n - 1];
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".INP","r",stdin);
    freopen(fn".OUT","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
