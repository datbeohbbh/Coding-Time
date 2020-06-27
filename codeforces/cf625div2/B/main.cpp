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

    const int N = 2e5 + 5;
    int a[N],b[N];
    ll f[N];
    int n;
    map <int,set <ll> > heap;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>b[i];
            a[i] = i - b[i];
        }
        heap[a[1]].insert(b[1]);
        f[1] = b[1];
        for(int i = 2;i <= n;++i){
            if(!heap[a[i]].empty()){
                maximize(f[i],1LL * b[i] + *heap[a[i]].rbegin());
            } else {
                f[i] = b[i];
            }
            heap[a[i]].insert(f[i]);
        }
        cout<<*max_element(f + 1,f + 1 + n);
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
