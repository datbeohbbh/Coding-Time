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
            int n,k;
            cin>>n>>k;
            vector < int > a(n + 2,0);
            vector < int > w(k + 2,0);
            vector < int > maxValue(k + 2,numeric_limits < int > :: min());
            vector < int > minValue(k + 2,numeric_limits < int > :: max());
            for(int i = 1;i <= n;++i){
                cin>>a[i];
            }
            for(int i = 1;i <= k;++i){
                cin>>w[i];
            }
            sort(a.begin() + 1,a.begin() + 1 + n);
            sort(w.begin() + 1,w.begin() + 1 + k);
            set < pair < int,int > > heap;
            for(int i = n - k + 1;i <= n;++i){
                --w[n - i + 1];
                maximize(maxValue[n - i + 1],a[i]);
                minimize(minValue[n - i + 1],a[i]);
                if(w[n - i + 1]){
                    heap.insert({w[n - i + 1],n - i + 1});
                }
            }
            for(int i = n - k;i >= 1;--i){
                pair < int,int > top = *heap.begin();
                heap.erase(heap.begin());
                minimize(minValue[top.second],a[i]);
                --w[top.second];
                if(w[top.second]){
                    heap.insert({w[top.second],top.second});
                }
            }
            llong ans = 0;
            for(int i = 1;i <= k;++i){
                ans += 1LL * maxValue[i] + 1LL * minValue[i];
            }
            cout<<ans<<'\n';
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
