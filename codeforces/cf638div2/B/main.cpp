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
        int n,k;
        cin>>n>>k;
        set <int> heap;
        for(int i = 1;i <= n;++i){
            int val;
            cin>>val;
            heap.insert(val);
        }
        if(len(heap) > k){
            cout<<-1<<'\n';
            return;
        }
        cout<<n * k<<'\n';
        for(int i = 1;i <= n;++i){
            for(int val : heap){
                cout<<val<<' ';
            }
            for(int j = 1;j <= k - len(heap);++j){
                cout<<1<<' ';
            }
        }
        cout<<'\n';
    }

    void solve(){
        int t;
        cin>>t;
        while(t--){
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
