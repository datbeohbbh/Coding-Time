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

    const int N = 2e5 + 5;
    int n;
    int a[N];

    void solve(){
        int t;
        cin>>t;
        while(t--){
            cin>>n;
            for(int i = 1;i <= n;++i){
                cin>>a[i];
            }
            vector <bool> ok(n + 2,false);
            set <int> heap;
            for(int i = 1;i <= n;++i){
                if(heap.empty() or heap.find(a[i]) == heap.end()){
                    heap.insert(a[i]);
                    if(*heap.begin() == 1 and *heap.rbegin() == i){
                        ok[i] = true;
                    }
                } else {
                    break;
                }
            }
            heap.clear();
            vector <pair <int,int> > ans;
            for(int i = n;i > 1;--i){
                if(heap.empty() or heap.find(a[i]) == heap.end()){
                    heap.insert(a[i]);
                    if(*heap.begin() == 1 and *heap.rbegin() == n - i + 1 and ok[i - 1]){
                        ans.emplace_back(make_pair(i - 1,n - i + 1));
                    }
                } else {
                    break;
                }
            }
            cout<<len(ans)<<'\n';
            for(auto p : ans){
                cout<<p.first<<' '<<p.second<<'\n';
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
