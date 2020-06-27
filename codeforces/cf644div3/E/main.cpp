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
            int cnt = 0;
            vector < vector <int> > a(n + 2,vector <int> (n + 2,0));
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= n;++j){
                    char c;
                    cin>>c;
                    a[i][j] = c - '0';
                    cnt += c - '0';
                }
            }
            bool has = true;
            for(int i = n - 1;i >= 1;--i){
                for(int k = 1;k <= i;++k){
                    if(a[k][i] == 1){
                        int f = 0;
                        if(k + 1 <= n) {
                            f |= (a[k + 1][i] == 1);
                        }
                        if(i + 1 <= n){
                            f |= (a[k][i + 1] == 1);
                        }
                        if(!f){
                            has = false;
                        }
                    }
                    if(a[i][k] == 1){
                        int f = 0;
                        if(i + 1 <= n){
                            f |= (a[i + 1][k] == 1);
                        }
                        if(k + 1 <= n){
                            f |= (a[i][k + 1] == 1);
                        }
                        if(!f){
                            has = false;
                        }
                    }
                }
            }
            if(!cnt){
                has = true;
            }
            cout<<(has ? "YES\n" : "NO\n");
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
