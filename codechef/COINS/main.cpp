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

    map <llong,llong> vis;

    llong compute(llong n){
        if(vis[n] != 0){
            return vis[n];
        }
        if(n <= 4){
            return n;
        }
        llong x = max(n / 2,compute(n / 2));
        llong y = max(n / 3,compute(n / 3));
        llong z = max(n / 4,compute(n / 4));
        llong ret = max(n,x + y + z);
        vis[n] = ret;
        return ret;
    }

    void solve(){
        llong n;
        while(cin>>n){
            cout<<compute(n)<<'\n';
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
