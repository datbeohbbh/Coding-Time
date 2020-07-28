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
            int n;
            cin>>n;
            int sum = 0;
            int m = 0;
            for(int i = 1;i <= n;++i){
                int val;
                cin>>val;
                m += val > 0;
                sum += val;
            }
            if(sum < 100){
                cout<<"NO\n";
            } else {
                if(sum - m >= 100){
                    cout<<"NO\n";
                } else if(sum - m < 100){
                    if(100 - sum + m > n){
                        cout<<"NO\n";
                    } else {
                        cout<<"YES\n";
                    }
                } else {
                    cout<<"YES\n";
                }
            }
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
