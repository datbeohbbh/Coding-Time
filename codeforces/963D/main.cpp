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
    const int K = 26;
    string s;
    int n;

    struct Node{
        Node *next;
        int value;
        Node(){}
        Node(int val,Node *nxt):value(val),next(nxt){}
    };

    class LinkedList{
    public:
        Node *first = nullptr;
        Node *last = nullptr;
        ~LinkedList(){
            first = last = nullptr;
        }
        bool isEmpty() const{
            return (first == nullptr and last == nullptr);
        }
        void add(int val){
            Node *newNode = new Node(val,nullptr);
            if(first == nullptr){
                first = last = newNode;
            } else {
                last -> next = newNode;
                last = newNode;
            }
        }
        void addAll(LinkedList *lval){
            if(first == nullptr){
                first = last = lval -> first;
            } else {
                last -> next = lval -> first;
                last = lval -> last;
            }
        }
    };

    class AhoCorasick{
    public:
        vector < int > suffLink;
        vector < vector < int > > to;
        vector < vector < int > > occ;
        vector < string > pattern;
        LinkedList* *list;
        int sz = 1;
    public:
        AhoCorasick(const vector < string > &t_pattern){
            int maxLen = 0;
            pattern = t_pattern;
            for_each(all(pattern),[&](const string &str){
                maxLen += len(str);
            });
            list = new LinkedList*[maxLen + 2];
            for(int i = 0;i <= maxLen;++i){
                list[i] = new LinkedList;
            }
            suffLink.resize(maxLen + 2,0);
            occ.resize(len(pattern) + 2,vector < int > ());
            to.resize(maxLen + 2,vector < int > (K,0));
            for(int i = 0;i < len(pattern);++i){
                int cur = 0;
                for(char c : pattern[i]){
                    if(!to[cur][c - 'a']){
                        to[cur][c - 'a'] = sz++;
                    }
                    cur = to[cur][c - 'a'];
                }
                list[cur] -> add(i);
            }
        }
        void pushLinks(){
            vector < int > que(N << 1,0);
            int st = 0,en = 0;
            que[en++] = 0;
            while(st < en){
                int v = que[st++];
                int u = suffLink[v];
                for(int c = 0;c < K;++c){
                    if(to[v][c]){
                        que[en++] = to[v][c];
                        suffLink[to[v][c]] = v ? to[u][c] : 0;
                        if(!list[suffLink[to[v][c]]] -> isEmpty()){
                            list[to[v][c]] -> addAll(list[suffLink[to[v][c]]]);
                        }
                    } else {
                        to[v][c] = to[u][c];
                    }
                }
            }
        }
        void search(const string &text){
            int cur = 0;
            for(int i = 0;i < len(text);++i){
                int c = text[i] - 'a';
                if(to[cur][c]){
                    cur = to[cur][c];
                } else {
                    cur = 0;
                }
                if(cur){
                    Node *iter = list[cur] -> first;
                    while(iter != nullptr){
                        occ[iter -> value].emplace_back(i - len(pattern[iter -> value]) + 1);
                        iter = iter -> next;
                    }
                }
            }
        }
        void compute(const vector < pair < int,string > > &queries){
            for(int i = 0;i < len(queries);++i){
                int k = queries[i].first;
                string m = queries[i].second;
                if(len(occ[i]) < k){
                    cout<<-1<<'\n';
                } else {
                    int ans = numeric_limits < int > :: max();
                    for(int j = 0;j < len(occ[i]);++j){
                        if(j - k + 1 >= 0){
                            minimize(ans,occ[i][j] - occ[i][j - k + 1] + len(m));
                        }
                    }
                    cout<<ans<<'\n';
                }
            }
        }
    };

    void solve(){
        cin>>s>>n;
        vector < pair < int,string > > queries;
        for(int i = 1;i <= n;++i){
            int k;
            string m;
            cin>>k>>m;
            queries.emplace_back(make_pair(k,m));
        }
        vector < string > pattern;
        for_each(all(queries),[&](const pair < int,string > &p){
            pattern.emplace_back(p.second);
        });
        AhoCorasick *ac = new AhoCorasick(pattern);
        ac -> pushLinks();
        ac -> search(s);
        ac -> compute(queries);
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
