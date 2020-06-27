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

    const int maxlg = 30;
    vector < int > a;
    vector < int > pref;
    vector < int > suff;
    vector < int > maxpref;
    vector < int > maxsuff;
    int n;

    struct Node{
    public:
        Node *child[2];
        Node(){
            child[0] = child[1] = nullptr;
        }
    };

    class Trie{
    public:
        Node *root = nullptr;
    public:
        Trie(){
            root = new Node();
        }
        void add(int val){
            Node *cur = root;
            for(int j = maxlg;~j;--j){
                if(!cur -> child[BIT(val,j)]){
                    cur -> child[BIT(val,j)] = new Node();
                }
                cur = cur -> child[BIT(val,j)];
            }
        }
        int rmq(int val){
            int ret = 0;
            Node* cur = root;
            for(int j = maxlg;~j and cur;--j){
                if(cur -> child[BIT(val,j) ^ 1]){
                    ret |= MASK(j);
                    cur = cur -> child[BIT(val,j) ^ 1];
                } else {
                    cur = cur -> child[BIT(val,j)];
                }
            }
            return ret;
        }
    };

    void solve(){
        cin>>n;
        a.resize(n + 2,0);
        pref.resize(n + 2,0);
        suff.resize(n + 2,0);
        maxpref.resize(n + 2,0);
        maxsuff.resize(n + 2,0);
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int i = 1;i <= n;++i){
            pref[i] = pref[i - 1] ^ a[i];
        }
        for(int i = n;i >= 1;--i){
            suff[i] = suff[i + 1] ^ a[i];
        }
        Trie *tpref = new Trie();
        Trie *tsuff = new Trie();
        tpref -> add(0);
        tsuff -> add(0);
        for(int i = 1;i <= n;++i){
            maxpref[i] = max(a[i],tpref -> rmq(pref[i]));
            tpref -> add(pref[i]);
        }
        for(int i = n;i >= 1;--i){
            maxsuff[i] = max(a[i],tsuff -> rmq(suff[i]));
            tsuff -> add(suff[i]);
        }
        for(int i = 1;i <= n;++i){
            maximize(maxpref[i],maxpref[i - 1]);
        }
        for(int i = n;i >= 1;--i){
            maximize(maxsuff[i],maxsuff[i + 1]);
        }
        llong ans = 0;
        for(int i = 1;i <= n;++i){
            maximize(ans,maxpref[i] + maxsuff[i + 1]);
        }
        cout<<ans;
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
