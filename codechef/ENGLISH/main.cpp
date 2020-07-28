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

    const int K = 26;
    int idx[K][K];

    struct Node{
    public:
        Node *child[K * K];
        int cnt;
        Node(){
            for(int c = 0;c < K * K;++c){
                child[c] = nullptr;
            }
            cnt = 0;
        }
    };

    class Trie{
    public:
        Node *root = nullptr;
    public:
        Trie(){
            root = new Node();
        }
        ~Trie(){
            root = nullptr;
        }
        void add(const string &s){
            Node* cur = root;
            for(int i = 0;i < len(s);++i){
                int a = s[i] - 'a';
                int b = s[len(s) - i - 1] - 'a';
                if(!cur -> child[idx[a][b]]){
                    cur -> child[idx[a][b]] = new Node();
                }
                cur = cur -> child[idx[a][b]];
                ++(cur -> cnt);
            }
        }
    };

    class Solver{
    public:
        llong dfs(Node *t,int h = 0){
            if(!t){
                return 0;
            }
            llong ans = (t -> cnt >> 1) * (1LL * h * 1LL * h - 1LL * (h - 1) * 1LL * (h - 1));
            for(int c = 0;c < K * K;++c){
                ans += dfs(t -> child[c],h + 1);
            }
            return ans;
        }

        void solve(){
            int n;
            cin>>n;
            Trie *t = new Trie();
            for(int i = 0;i < n;++i){
                string s;
                cin>>s;
                t -> add(s);
            }
            cout<<dfs(t -> root)<<'\n';
        }
    };

    void solve(){
        int nTest;
        cin>>nTest;
        int cnt = 0;
        for(int i = 0;i < K;++i){
            for(int j = 0;j < K;++j){
                idx[i][j] = cnt++;
            }
        }
        while(nTest--){
            (new Solver) -> solve();
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
