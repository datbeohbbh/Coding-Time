#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
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
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    int calc(){
        int r,c,chk = 0;
        cin>>r>>c;
        vector <char> *a = new vector <char> [r + 1];
        for(int i = 1;i <= r;++i){
            (a + i) -> resize(c + 1);
        }
        for(int i = 1;i <= r;++i){
            for(int j = 1;j <= c;++j){
                cin>>(*(a + i))[j];
                chk += (*(a + i))[j] == 'A';
            }
        }
        if(!chk){
            return -1;
        }else if(chk == r * c){
            return 0;
        }
        vector <int> *dp_row = new vector <int> [r + 1];
        vector <int> *dp_col = new vector <int> [r + 1];
        vector <int> *maxPref_row = new vector <int> [r + 1];
        vector <int> *maxSuff_row = new vector <int> [r + 1];
        vector <int> *maxPref_col = new vector <int> [r + 1];
        vector <int> *maxSuff_col = new vector <int> [r + 1];
        for(int i = 1;i <= r;++i){
            (dp_row + i) -> resize(c + 1);
            (dp_col + i) -> resize(c + 1);
            (maxPref_row + i) -> resize(c + 1);
            (maxPref_col + i) -> resize(c + 1);
            (maxSuff_row + i) -> resize(c + 1);
            (maxSuff_col + i) -> resize(c + 1);
        }
        for(int i = 1;i <= r;++i){
            for(int j = 1;j <= c;++j){
                if(a[i][j] == 'A'){
                    dp_row[i][j] = dp_row[i][j - 1] + 1;
                }
            }
            for(int j = 1;j <= c;++j){
                maxPref_row[i][j] = max(maxPref_row[i][j - 1],dp_row[i][j]);
            }
            maxSuff_row[i][c] = dp_row[i][c];
            for(int j = c - 1;j > 0;--j){
                maxSuff_row[i][j] = max(maxSuff_row[i][j + 1],dp_row[i][j]);
            }
        }
        for(int j = 1;j <= c;++j){
            for(int i = 1;i <= r;++i){
                if(a[i][j] == 'A'){
                    dp_col[i][j] = dp_col[i - 1][j] + 1;
                }
            }
            for(int i = 1;i <= r;++i){
                maxPref_col[i][j] = max(maxPref_col[i - 1][j],dp_col[i][j]);
            }
            maxSuff_col[r][j] = dp_col[r][j];
            for(int i = r - 1;i > 0;--i){
                maxSuff_col[i][j] = max(maxSuff_col[i + 1][j],dp_col[i][j]);
            }
        }
        int ret = 4;
        for(int i = 1;i <= r;++i){
            if(maxPref_row[i][c] == r){
                return 1;
            }
            for(int j = 1;j <= c;++j){
                if(a[i][j] == 'A'){
                    int t = j;
                    while(t <= c and a[i][t] == 'A'){
                        if(maxPref_row[i][t - 1] + t - j + 1 + (t + 1 <= c ? maxSuff_row[i][t + 1] : 0) >= r){
                            minimize(ret,2);
                        } else if(i == 1 or i == r){
                            minimize(ret,3);
                        }
                        ++t;
                    }
                    j = t;
                }
            }
        }
    }

    void solve(){
        int t;
        cin>>t;
        while(t--){
            int ans = calc();
            if(ans == -1){
                cout<<"MORTAL\n";
            } else {
                cout<<ans<<'\n';
            }
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