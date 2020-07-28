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

#define ll long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    void solve(){
        int n;
        cin>>n;
        vector <int> r(n + 2,0);
        vector <int> b(n + 2,0);
        for(int i = 1;i <= n;++i){
            cin>>r[i];
        }
        for(int i = 1;i <= n;++i){
            cin>>b[i];
        }
        for(int p = 1;p <= 10000;++p){
            int sum_r = 0;
            int sum_b = 0;
            for(int i = 1;i <= n;++i){
                if(r[i]){
                    if(!b[i]){
                        sum_r += p;
                    } else {
                        ++sum_r;
                        ++sum_b;
                    }
                } else {
                    if(b[i]){
                        ++sum_b;
                    }
                }
            }
            if(sum_r > sum_b){
                cout<<p;
                exit(0);
            }
        }
        cout<<-1;
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
