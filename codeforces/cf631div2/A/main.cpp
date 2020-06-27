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
            int n,x;
            cin>>n>>x;
            vector <int> a(505,1);
            for(int i = 1;i <= n;++i){
                int u;
                cin>>u;
                a[u] = 0;
            }
            for(int i = 2;i <= 500;++i){
                a[i] += a[i - 1];
            }
            for(int v = 500;v >= 1;--v){
                if(a[v] <= x){
                    cout<<v<<'\n';
                    break;
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
