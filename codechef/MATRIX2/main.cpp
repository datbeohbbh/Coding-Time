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
    int a[N][N];
    llong ans = 0;
    int n,m;

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                char c;
                cin>>c;
                a[i][j] = c - '0';
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if(a[i][j]) {
                    a[i][j] = min(a[i - 1][j - 1], a[i - 1][j]) + 1;
                    ans += 1LL * a[i][j];
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
