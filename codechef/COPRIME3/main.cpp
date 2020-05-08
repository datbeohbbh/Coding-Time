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
    const int maxVal = 1e6;
    llong cnt[maxVal + 2];
    int n;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            int val;
            cin>>val;
            ++cnt[val];
        }
        auto coef = [](const int &x){
            if(x < 3){
                return 0LL;
            }
            return 1LL * x * 1LL *  (x - 1) * 1LL * (x - 2) / 6LL;
        };
        llong ans = coef(n);
        for(int i = 2;i <= maxVal;++i){
            for(int j = (i << 1);j <= maxVal;j += i){
                cnt[i] += cnt[j];
            }
        }
        for(int i = maxVal;i >= 2;--i){
            cnt[i] = coef(cnt[i]);
            for(int j = (i << 1);j <= maxVal;j += i){
                cnt[i] -= cnt[j];
            }
        }
        for(int i = 2;i <= maxVal;++i){
            ans -= cnt[i];
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
