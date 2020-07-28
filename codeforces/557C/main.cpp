#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

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
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x + k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x - k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int maxLen = 1e5;
    vector <int> len[maxLen + 2];
    int n,sum = 0;
    int l[maxLen + 2],d[maxLen + 2];
    int cnt[maxLen / 490];

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>l[i];
        }
        for(int i = 1;i <= n;++i){
            cin>>d[i];
            sum+=d[i];
        }
        for(int i = 1;i <= n;++i){
            len[l[i]].emplace_back(d[i]);
        }
        for(int i = 1;i <= maxLen;++i){
            if(!len[i].empty()){
                sort(all(len[i]));
            }
        }
        int ans = numeric_limits <int> :: max();
        for(int i = 1;i <= maxLen;++i){
            if(!len[i].empty()){
                for(int j = 0;j < sz(len[i]);++j){
                    ++cnt[len[i][j]];
                }
                int tmp = 0;
                for(int j = sz(len[i]) - 1;~j;--j){
                    tmp += len[i][j];
                    int used = sz(len[i]) - j - 1;
                    int t = tmp;
                    --cnt[len[i][j]];
                    for(int pw = 200;~pw and used > 0;--pw){
                        if(used >= cnt[pw]){
                            used -= cnt[pw];
                            t += pw * cnt[pw];
                        } else {
                            t += pw * used;
                            break;
                        }
                    }
                    minimize(ans,sum - t);
                }
                for(int j = 0;j < sz(len[i]);++j){
                    ++cnt[len[i][j]];
                }
            }
        }
        cout<<ans;
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