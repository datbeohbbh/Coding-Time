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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
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
    int n,m;
    int pref[N];
    string a;

    void clean(){
        for(int i = 0;i <= n;++i){
            pref[i] = 0;
        }
        a.clear();
    }

    class Node{
    public:
        int cnt[3];
    public:
        Node(){
            cnt[0] = cnt[1] = cnt[2] = 0;
        };
        Node(int* t){
            for(int i = 0;i < 3;++i){
                cnt[i] = *(t + i);
            }
        }
    };

    class SegmentTree{
    public:
        vector <Node> tree;
        vector <int> lz;
    public:
        SegmentTree(int num_node){
            tree.resize((num_node << 2) + 2,Node());
            lz.resize((num_node << 2) + 2,0);
        }
        void pushdown(int l,int r,int node){
            if(lz[node]) {
                int *t = new int[3];
                t[0] = t[1] = t[2] = 0;
                for (int i = 0; i < 3; ++i) {
                    t[(i + lz[node]) % 3] += tree[node] . cnt[i];
                }
                tree[node] = Node(t);
                if (l ^ r) {
                    lz[node << 1] += lz[node];
                    lz[node << 1 | 1] += lz[node];
                    lz[node << 1] %= 3, lz[node << 1 | 1] %= 3;
                }
                lz[node] = 0;
            }
        }
        void build(int l,int r,int node = 1){
            if(l > r){
                return;
            }
            if(l == r){
                int *t = new int[3];
                t[0] = t[1] = t[2] = 0;
                ++t[pref[l]];
                return (void)(tree[node] = Node(t));
            }
            int mid = (l + r) >> 1;
            build(l,mid,node << 1);
            build(mid + 1,r,node << 1 | 1);
            for(int i = 0;i < 3;++i){
                tree[node].cnt[i] = tree[node << 1].cnt[i] + tree[node << 1 | 1].cnt[i];
            }
        }
        void update(int tl,int tr,int l,int r,int adds,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return;
            }
            if(tl <= l and r <= tr){
                int *t = new int[3];
                t[0] = t[1] = t[2] = 0;
                for(int i = 0;i < 3;++i){
                    t[(i + adds) % 3] += tree[node].cnt[i];
                }
                tree[node] = Node(t);
                if(l ^ r){
                    lz[node << 1] += adds;
                    lz[node << 1 | 1] += adds;
                    lz[node << 1] %= 3,lz[node << 1 | 1] %= 3;
                }
                return;
            }
            int mid = (l + r) >> 1;
            update(tl,tr,l,mid,adds,node << 1);
            update(tl,tr,mid + 1,r,adds,node << 1 | 1);
            for(int i = 0;i < 3;++i){
                tree[node].cnt[i] = tree[node << 1].cnt[i] + tree[node << 1 | 1].cnt[i];
            }
        }
        Node query(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return Node();
            }
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            Node cl = query(tl,tr,l,mid,node << 1);
            Node cr = query(tl,tr,mid + 1,r,node << 1 | 1);
            Node ret = Node();
            for(int i = 0;i < 3;++i){
                ret.cnt[i] = cl.cnt[i] + cr.cnt[i];
            }
            return ret;
        }
    };

    void solve(){
        ifstream cin("test.inp");
        ofstream cout("test.out");
        cin>>n>>m>>a;
        for(int i = 0;i < len(a);++i){
            pref[i + 1] = a[i] - '0';
        }
        for(int i = 1;i <= n;++i){
            pref[i] += pref[i - 1];
            pref[i] %= 3;
        }
        SegmentTree *seg = new SegmentTree(n);
        seg -> build(0,n);
        auto coef = [&](const int &x){
            return (x <= 1 ? 0LL : 1LL * x * 1LL * (x - 1) / 2LL);
        };
        while(m--){
            int type,l,r;
            cin>>type>>l>>r;
            if(type == 1){
                int adds = (r % 3 - (a[l - 1] - '0') % 3 + 3) % 3;
                seg -> update(l,n,0,n,adds);
                a[l - 1] = (char)(r + '0');
            } else {
                Node cur = seg -> query(l - 1,r,0,n);
                cout<<coef(cur.cnt[0]) + coef(cur.cnt[1]) + coef(cur.cnt[2])<<'\n';
            }
        }
        cin.close();
        cout.close();
        clean();
    }
}

// remember clean function.
// creat 3 file test.inp test.out gtest.out
namespace TestGenerator {

    #define RED     "\033[31m"
    #define RESET   "\033[0m"
    #define GREEN   "\033[32m"

    int n,m;
    string a;

    void clean(){
        a.clear();
    }

    void solve() {
        ifstream cin("test.inp");
        ofstream cout("gtest.out");
        cin>>n>>m>>a;
        a = " " + a;
        while(m--){
            int type,l,r;
            cin>>type>>l>>r;
            if(type == 1){

            } else {
                int ans = 0;
                for(int i = l;i <= r;++i){
                    int s = 0;
                    for(int j = i;j <= r;++j){
                        s = (s + (a[j] - '0') % 3) % 3;
                        ans += (s == 0);
                    }
                }
                cout<<ans<<'\n';
            }
        }
        cin.close();
        cout.close();
        clean();
    }

    string getInformation(ifstream &file) {
        char c;
        string ret = "";
        while (file . get(c)) {
            ret += c;
        }
        file . close();
        while (ret . back() == '\n') {
            ret . pop_back();
        }
        return ret;
    }

    bool check(string out_a,string out_b){
        // checker
        return true;
    }

    bool compareFile() {
        ifstream a("test.out");
        ifstream b("gtest.out");
        string out_a = getInformation(a);
        string out_b = getInformation(b);
        return (out_a == out_b);
    }

    void testing(const int NUM_TEST) {
        for (int test_id = 1; test_id <= NUM_TEST; ++test_id) {
            ofstream gentest("test.inp");
            // ------- test area --------//
            cout << "running on test :" << ' ' << test_id << '\n';
            cout <<"input of test " << test_id << ' ' << ":" << '\n';

            int n = 1 + rand(20);
            int m = 1 + rand(50);
            gentest<<n<<' '<<m<<'\n';
            cout<<n<<' '<<m<<'\n';
            for(int i = 1;i <= n;++i){
                int val = rand(10);
                gentest<<val;
                cout<<val;
            }
            gentest<<'\n';
            cout<<'\n';
            for(int i = 1;i <= m;++i){
                int l = 1 + rand(n);
                int r = l + rand(n - l + 1);
                gentest<<2<<' '<<l<<' '<<r<<'\n';
                cout<<2<<' '<<l<<' '<<r<<'\n';
            }
            gentest . close();

            // ------- test area --------//

            task::solve();
            TestGenerator::solve();
            bool flag = TestGenerator::compareFile();
            cout<<"test "<<test_id<<" : ";
            if (!flag) {
                cout<<RED<<"failed"<<RESET<<'\n'<<'\n';
                cout<<RED<<"status : failed"<<RESET;
                exit(0);
            } else {
                cout<<GREEN<<"passed"<<RESET<<'\n';
            }
            cout << '\n';
        }
        cout<<GREEN<<"status : accepted"<<RESET;
    }
}

//TestGenerator::testing(5);

int main(void){
/*
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
*/
    TestGenerator::testing(200);
   // task::solve();
}
