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
            vector <int> a(n + 2,0);
            int odd = 0,even = 0;
            for(int i = 1;i <= n;++i){
                cin>>a[i];
                if(a[i] & 1)++odd;
                else{
                    ++even;
                }
            }
            if(!((odd & 1) | (even & 1))){
                cout<<"YES\n";
            } else {
                bool ok = false;
                for(int i = 1;i <= n;++i){
                    for(int j = 1;j <= n;++j){
                        if(i != j){
                            if(Abs(a[i] - a[j]) == 1){
                                ok = true;
                                break;
                            }
                        }
                    }
                }
                cout<<(ok ? "YES\n" : "NO\n");
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
