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
            int a,b;
            cin>>a>>b;
            int t = 1;
            while(true){
                if(t * t < 2 * a * b){
                    ++t;
                } else {
                    if(t >= 2*a and t >= b){
                        break;
                    }
                    if(t >= a + b and t >= max(a,b)){
                        break;
                    }
                    if(t >= a and t >= 2*b){
                        break;
                    }
                    if(t >= max(a,b) and t >= a + b){
                        break;
                    }
                    ++t;
                }
            }
            cout<<t*t<<'\n';
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
