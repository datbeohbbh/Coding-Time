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

    void solve(){
        int T;
        cin>>T;
        while(T--){
            int x,n,m;
            cin>>x>>n>>m;
            while(x > 0 and n > 0 and m > 0){
                if((x >> 1) + 10 < x - 10){
                    x >>= 1;
                    x += 10;
                    --n;
                } else {
                    x -= 10;
                    --m;
                }
            }
            while(x > 0 and m > 0){
                x -= 10;
                --m;
            }
            while(x > 0 and n > 0){
                x >>= 1;
                x += 10;
                --n;
            }
            cout<<(x <= 0 ? "YES\n" : "NO\n");
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
