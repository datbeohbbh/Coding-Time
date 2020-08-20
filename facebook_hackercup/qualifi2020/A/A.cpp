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
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    class Solver{
        public:
            string in,out;
            int n;
            vector < vector < int > > adj;
            vector < vector < int > > ans;
        public:
            
            void addEdges(int u,int v){
                if(1 <= u and u <= n and 1 <= v and v <= n){
                    if(out[u] == 'Y' and in[v] == 'Y'){
                        adj[u].emplace_back(v);
                    }
                }
            }
           
            void dfs(int src,int u){
                ans[src][u] = 1;
                for(int v : adj[u]){
                    if(!ans[src][v]){
                        dfs(src,v);
                    }
                }
            }
            
            void solve(){
                cin>>n>>in>>out;
                adj.resize(n + 2,vector < int > ());
                in = " " + in;
                out = " " + out;
                for(int i = 1;i <= n;++i){
                    addEdges(i,i - 1);
                    addEdges(i,i + 1);
                }
                ans.resize(n + 2,vector < int > (n + 2,0));
                for(int u = 1;u <= n;++u){
                    dfs(u,u);
                }
                for(int u = 1;u <= n;++u){
                    for(int v = 1;v <= n;++v){
                        cout<<(ans[u][v] ? 'Y' : 'N');
                    }
                    cout<<'\n';
                }
            }
    };
    
    void solve(){
        int T;
        cin>>T;
        for(int tests = 1;tests <= T;++tests){
            cout<<"Case #"<<tests<<":\n";
            (new Solver) -> solve();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".txt","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}

