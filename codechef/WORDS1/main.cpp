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

    class Solver{
    public:
        vector < vector < int > > adj;
        vector < int > p;
        vector < int> par;
        vector < int > cnt;
        int n;
    public:
        ~Solver(){
            adj.clear();
            p.clear();
            par.clear();
            cnt.clear();
        }

        int findp(int u){
            return u == par[u] ? u : par[u] = findp(par[u]);
        }

        void join(int u,int v){
            u = findp(u),v = findp(v);
            if(u == v){
                return;
            }
            cnt[u] += cnt[v];
            par[v] = u;
        }

        void work(){
            cin>>n;
            adj.resize(26,vector <int> ());
            par.resize(n + 2,0);
            cnt.resize(n + 2,0);
            for(int i = 1;i <= n;++i){
                par[i] = i;
                cnt[i] = 1;
            }
            for(int i = 1;i <= n;++i){
                string s;
                cin>>s;
                p.emplace_back(s.back() - 'a');
                adj[s[0] - 'a'].emplace_back(i);
            }
            for(int i = 0;i < n;++i){
                for(int v : adj[p[i]]){
                    join(i + 1,v);
                }
            }
            int chk = 0;
            for(int u = 1;u <= n;++u){
                if(u == findp(u)){
                    maximize(chk,cnt[u]);
                }
            }
            if(chk == n){
                cout<<"Ordering is possible.\n";
            } else {
                cout<<"The door cannot be opened.\n";
            }
        }
    };

    void solve(){
        int T;
        cin>>T;
        while(T--){
            Solver *ans = new Solver;
            ans -> work();
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
