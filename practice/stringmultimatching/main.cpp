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
    class Solver{
    public:
        vector < char > alphabet;
        vector < string > pattern;
        string text;
        int n;

        ~Solver(){
            alphabet.clear();
            pattern.clear();
            text.clear();
        }

        struct Node{
        public:
            Node *next;
            int data;
            Node(){};
            Node(int _data,Node *_next):data(_data),next(_next){};
        };

        class LinkedList{
        public:
            Node *first,*last;
            LinkedList(){
                first = last = nullptr;
            }
            void add(int val){
                Node *new_node = new Node(val,nullptr);
                if(first == nullptr){
                    first = last = new_node;
                } else {
                    last -> next = new_node;
                    last = new_node;
                }
            }
            void addAll(LinkedList *cur) {
                if(first == nullptr){
                    first = last = cur -> first;
                } else {
                    last -> next = cur -> first;
                    last = cur -> last;
                }
            }
            bool empty() const {
                return (first == nullptr and last == nullptr);
            }
            void clearList(){
                first = last = nullptr;
            }
        };

        class AhoCorasick{
        public:
            map < char,int > to[N];
            int sz = 1;
            vector < int > suffixLink;
            LinkedList* list[N];
            vector < int > res[N];
        public:
            AhoCorasick(const vector < string > &pattern){
                for(int i = 0;i <= N - 5;++i){
                    list[i] = new LinkedList();
                }
                for(int i = 0;i < len(pattern);++i){
                    const string &s = pattern[i];
                    int cur = 0;
                    for(char c : s){
                        if(!to[cur][c]){
                            to[cur][c] = sz++;
                        }
                        cur = to[cur][c];
                    }
                    list[cur] -> add(i);
                }
                suffixLink.resize(sz + 2,0);
            }
            ~AhoCorasick(){
                suffixLink.clear();
                sz = 1;
                for(int i = 0;i < sz;++i){
                    to[i].clear();
                    list[i] -> clearList();
                    res[i].clear();
                }
            }
            void pushLinks(const vector < char > &alphabet){
                vector < int > que(N << 1,0);
                int st = 0,en = 0;
                que[en++] = 0;
                while(st < en){
                    int v = que[st++];
                    int u = suffixLink[v];
                    for(const char &c : alphabet){
                        if(to[v].find(c) != to[v].end()){
                            que[en++] = to[v][c];
                            suffixLink[to[v][c]] = v ? to[u][c] : 0;
                            if(!list[suffixLink[to[v][c]]] -> empty()) {
                                list[to[v][c]] -> addAll(list[suffixLink[to[v][c]]]);
                            }
                        } else if(to[u].find(c) != to[u].end()){
                            to[v][c] = to[u][c];
                        }
                    }
                }
            }
            void search(const string &text,const vector < string > &pattern){
                int cur = 0;
                for(int i = 0;i < len(text);++i){
                    char c = text[i];
                    if(to[cur].find(c) != to[cur].end()){
                        cur = to[cur][c];
                    } else {
                        cur = 0;
                    }
                    if(cur){
                        Node *iter = list[cur] -> first;
                        while(iter != nullptr){
                            res[iter -> data].emplace_back(i - len(pattern[iter -> data]) + 1);
                            iter = iter -> next;
                        }
                    }
                }
                for(int i = 0;i < len(pattern);++i){
                    for(int pos : res[i]){
                        cout<<pos<<' ';
                    }
                    cout<<'\n';
                }
            }
        };

        void solve(int _n){
            this -> n = _n;
            cin.ignore();
            for(int i = 1;i <= n;++i){
                string s;
                getline(cin,s);
                pattern.emplace_back(s);
                for(char c : s){
                    alphabet.emplace_back(c);
                }
            }
            getline(cin,text);
            sort(all(alphabet));
            alphabet.erase(unique(all(alphabet)),alphabet.end());
            AhoCorasick *ac = new AhoCorasick(pattern);
            ac -> pushLinks(alphabet);
            ac -> search(text,pattern);
        }
    };

    void solve(){
        for(int n;cin>>n;){
            (new Solver) -> solve(n);
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
