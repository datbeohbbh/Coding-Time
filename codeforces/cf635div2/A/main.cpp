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

    bool ok(llong x,llong y,llong z){
        return (x + y) > z and (x + z > y) and (y + z > x);
    }

    void solve(){
        int T;
        cin>>T;
        while(T--){
            llong a[4];
            for(int i = 0;i < 4;++i){
                cin>>a[i];
            }
            bool f = false;
            for(int i = 0;i <= 1 and !f;++i){
                for(int j = 1;j <= 2 and !f;++j){
                    for(int k = 2;k <= 3 and !f;++k){
                        if(ok(a[i],a[j],a[k])){
                            cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<'\n';
                            f = true;
                            break;
                        }
                    }
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
