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
        int n;
        cin>>n;
        vector <int> a;
        for(int i = 1;i <= n;++i){
            int val;
            cin>>val;
            a.emplace_back(val);
        }
        llong ans = 0;
        for(int bit = 30;bit >= 0;--bit){
            vector <int> b;
            for(int i = 0;i < len(a);++i){
                if((a[i] >> bit) & 1){
                    b.emplace_back(a[i]);
                }
            }
            if(len(b) >= 2){
                ans += (1LL << bit);
                swap(a,b);
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
