#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

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

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

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

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 2505;
    string s[N];
    bool ok[N];
    int n,k;

    void solve(){
        cin>>k>>n;
        for(int i = 1;i <= k;++i){
            cin>>s[i];
            vector <int> vec(27,0);
            for(int j = 0;j < n;++j){
                ++vec[s[i][j] - 'a'];
            }
            for(int c = 0;c < 26;++c){
                ok[i] |= vec[c] > 1;
            }
        }
        for(int i = 2;i <= k;++i){
            vector <int> c1(27,0);
            vector <int> c2(27,0);
            for(char c : s[i]){
                ++c2[c - 'a'];
            }
            for(char c : s[1]){
                ++c1[c - 'a'];
            }
            for(int c = 0;c < 26;++c){
                if(c1[c] != c2[c]){
                    cout<<-1;
                    return;
                }
            }
        }
        bool ff = false;
        for(int i = 1;i <= k;++i){
            for(int j = i + 1;j <= k;++j){
                int cnt = 0;
                for(int c = 0;c < n;++c){
                    cnt += s[i][c] != s[j][c];
                }
                if(cnt > 4){
                    cout<<-1;
                    return;
                } else if(cnt > 0){
                    ff = true;
                }
            }
        }
        if(k == 1 or !ff){
            swap(s[1][0],s[1][1]);
            cout<<s[1];
            return ;
        }
        vector <int> diff;
        for(int i = 0;i < n;++i){
            if(diff.size() == 2){
                break;
            }
            for(int j = i + 1;j < n;++j){
                if(s[1][i] == s[1][j]){
                    diff.emplace_back(i);
                    diff.emplace_back(j);
                    break;
                }
            }
        }
        int p = 1;
        while(p <= k and s[1] == s[p]){
            ++p;
        }
        for(int i = 0;i < n;++i){
            if(s[1][i] != s[p][i]){
                diff.emplace_back(i);
            }
        }
        for(int i = 0;i < diff.size();++i){
            for(int j = i + 1;j < diff.size();++j){
                swap(s[1][diff[i]],s[1][diff[j]]);
                bool f = true;
                for(int t = 2;t <= k;++t){
                    int cnt = 0;
                    for(int c = 0;c < n;++c){
                        cnt += s[1][c] != s[t][c];
                    }
                    if(cnt == 1 or cnt > 2){
                        f = false;
                    } else if(!cnt){
                        if(!ok[t]){
                            f = false;
                        }
                    }
                }
                if(f){
                    cout<<s[1];
                    return;
                }
                swap(s[1][diff[i]],s[1][diff[j]]);
            }
        }
        cout<<-1;
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
