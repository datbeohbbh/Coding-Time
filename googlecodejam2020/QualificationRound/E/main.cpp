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

    const int inf = 1e9;

    class HopcroftKarp{
    public:
        vector <int> pairU;
        vector <int> pairV;
        vector <int> dist;
        vector < vector <int> > adj;
        int n;
        int cntMatching;
    public:
        HopcroftKarp(int n){
            pairU.resize((n << 2) + 2,0);
            pairV.resize((n << 2) + 2,0);
            dist.resize((n << 2) + 2,0);
            adj.resize((n << 2) + 2,vector <int> ());
            this -> cntMatching = 0;
            this -> n = n;
        }
        ~HopcroftKarp(){
            pairU.clear();
            pairV.clear();
            dist.clear();
            adj.clear();
            this -> n = 0;
            this -> cntMatching = 0;
        }

        void addEdges(int u,int v){
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        bool bfs(){
            queue <int> q;
            for(int u = 1;u <= n;++u){
                if(!pairU[u]){
                    dist[u] = 0;
                    q.push(u);
                } else {
                    dist[u] = inf;
                }
            }
            dist[0] = inf;
            for(;len(q);q.pop()){
                int u = q.front();
                if(dist[u] >= dist[0])continue;
                for(int i = 0;i < len(adj[u]);++i){
                    int v = adj[u][i];
                    if(dist[pairV[v]] == inf){
                        dist[pairV[v]] = dist[u] + 1;
                        q.push(pairV[v]);
                    }
                }
            }
            return (dist[0] != inf);
        }

        bool dfs(int u){
            if(u){
                for(int i = 0;i < len(adj[u]);++i){
                    int v = adj[u][i];
                    if(dist[pairV[v]] == dist[u] + 1){
                        if(dfs(pairV[v])){
                            pairV[v] = u;
                            pairU[u] = v;
                            return true;
                        }
                    }
                }
                dist[u] = inf;
                return false;
            }
            return true;
        }

        void computeMatching(){
            while(bfs()){
                for(int u = 1;u <= n;++u){
                    if(!pairU[u] and dfs(u)){
                        ++cntMatching;
                    }
                }
            }
        }
    };

    int n,sum;

    vector < vector <int> > calcMatrix(int a,int b,int c){
        vector < vector <int> > ret(n + 2,vector <int> (n + 2,0));
        for(int i = 1;i < n - 1;++i){
            ret[i][i] = a;
        }
        ret[n - 1][n - 1] = b;
        ret[n][n] = c;
        vector <int> freq(n + 2,0);
        for(int i = 1;i <= n;++i){
            ++freq[ret[i][i]];
        }
        for(int f = n;f >= 0;--f){
            for(int val = 1;val <= n;++val){
                if(freq[val] == f){
                    HopcroftKarp *g = new HopcroftKarp(n);
                    for(int i = 1;i <= n;++i){
                        if(ret[i][i] == val){
                            g -> addEdges(i,i + n);
                        }
                    }
                    for(int i = 1;i <= n;++i){
                        for(int j = 1;j <= n;++j){
                            if(!ret[i][j] and ret[i][i] != val and ret[j][j] != val){
                                g -> addEdges(i,j + n);
                            }
                        }
                    }
                    g -> computeMatching();
                    if(g -> cntMatching != n){
                        return vector < vector <int> > ();
                    }
                    for(int i = 1;i <= n;++i){
                        ret[i][(g -> pairU[i]) - n] = val;
                    }
                }
            }
        }
        return ret;
    }

    void compute(int test){
        cin>>n>>sum;
        vector < vector <int> > ans(n + 2,vector <int> (n + 2));
        bool ok = false;
        for(int a = 1;a <= n and !ok;++a){
            for(int b = 1;b <= n and !ok;++b){
                for(int c = 1;c <= n and !ok;++c){
                    if((n - 2) * a + b + c == sum){
                        ans = calcMatrix(a,b,c);
                        if(!ans.empty()){
                            ok = true;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<test<<": ";
        if(ok){
            cout<<"POSSIBLE\n";
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= n;++j){
                    cout<<ans[i][j]<<' ';
                }
                cout<<'\n';
            }
        } else {
            cout<<"IMPOSSIBLE\n";
        }
    }

    void solve(){
        int numTest;
        cin>>numTest;
        for(int test = 1;test <= numTest;++test){
            compute(test);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
