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
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            vector <llong> a(n + 2,0);
            for(int i = 1;i <= n;++i){
                cin>>a[i];
            }
            for(int i = 1;i <= n;++i){
                a[i] += a[i - 1];
                a[i] %= 1LL * n;
            }
            vector <int> pos(n + 2,0);
            pos[0] = 1;
            for(int i = 1;i <= n;++i){
                if(pos[a[i]]){
                    cout<<i - pos[a[i]] + 1<<'\n';
                    for(int j = pos[a[i]];j <= i;++j){
                        cout<<j<<' ';
                    }
                    break;
                }
                pos[a[i]] = i + 1;
            }
            cout<<'\n';
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
