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

    void compute(){
        int n;
        cin>>n;
        vector <string> p(n + 2);
        int mxs = 0;
        for(int i = 1;i <= n;++i){
            cin>>p[i];
            if(len(p[i]) > len(p[mxs])){
                mxs = i;
            }
        }
        bool ok = true;
        for(int i = 1;i <= n;++i){
            int j = len(p[i]) - 1;
            int k = len(p[mxs]) - 1;
            for(;j >= 1 and k >= 1;--j,--k){
                if(p[i][j] != p[mxs][k]){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                cout<<"*\n";
                return;
            }
        }
        p[mxs].erase(0,1);
        cout<<p[mxs]<<'\n';
    }

    void solve(){
        int T;
        cin>>T;
        for(int test = 1;test <= T;++test){
            cout<<"Case #"<<test<<": ";
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
