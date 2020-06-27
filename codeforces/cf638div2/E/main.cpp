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

    const int N = 505;
    bool f[N][N];
    int a[N],b[N];
    int n,k;
    llong tot = 0;

    void solve(){
        cin>>n>>k;
        for(int i = 1;i <= n;++i){
            cin>>a[i]>>b[i];
            tot += a[i];
            tot += b[i];
        }
        f[0][0] = true;
        for(int i = 1;i <= n;++i){
            for(int j = 0;j < k;++j){
                f[i][j] = f[i - 1][(j - a[i] % k + k) % k];
                for(int l = 0;l <= min(a[i],k - 1);++l){
                    if((a[i] - l) % k + b[i] >= k) {
                        f[i][j] |= f[i - 1][(j - l + k) % k];
                    }
                }
            }
        }
        llong ans = 0;
        for(int i = 0;i < k;++i){
            if(f[n][i]){
                maximize(ans,(tot - 1LL * i) / (1LL * k));
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
