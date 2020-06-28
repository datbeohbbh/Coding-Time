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

    const int b = 30;

    void compute(){
        int n;
        cin>>n;
        if(n <= b){
            for(int i = 1;i <= n;++i){
                cout<<i<<' '<<1<<'\n';
            }
            return;
        }
        n -= b;
        int k = b;
        int f = 0,i = 0;
        for(i = 0;i <= b;++i){
            if(BIT(n,i)){
                if(!f){
                    for(int j = 0;j <= i;++j){
                        cout<<i + 1<<' '<<j + 1<<'\n';
                    }
                } else {
                    for(int j = i;j >= 0;--j){
                        cout<<i + 1<<' '<<j + 1<<'\n';
                    }
                }
                f ^= 1;
            } else {
                --k;
                cout<<i + 1<<' '<<(!f ? 1 : i + 1)<<'\n';
            }
        }
        for(;k > 0;--k,++i){
            cout<<i + 1<<' '<<(!f ? 1 : i + 1)<<'\n';
        }
    }

    void solve(){
        int T;
        cin>>T;
        for(int test = 1;test <= T;++test){
            cout<<"Case #"<<test<<":\n";
            compute();
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
