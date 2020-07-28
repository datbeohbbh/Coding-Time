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

    const int N = 2e3 + 3;
    bitset <N> a[N];
    int n;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            string s;
            cin>>s;
            for(int j = 0;j < len(s);++j){
                if(s[j] == '1'){
                    a[i].set(j + 1);
                }
            }
        }
        int ans = 0;
        for(int u = 1;u <= n;++u){
            for(int v = 1;v <= n;++v){
                if(u != v and a[u].test(v) == 0 and a[v].test(u) == 0) {
                    bitset<N> mask = a[u] & a[v];
                    if (mask . count() > 0) {
                        ++ans;
                    }
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
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
