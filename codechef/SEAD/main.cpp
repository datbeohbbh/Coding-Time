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

    const int N = 1e5 + 5;
    const int maxD = 1e6;
    const int lg = 18;
    int n,m;
    int b[N],a[N];
    int pos[maxD + 2];
    int rmq[lg + 2][N];

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        a[n + 1] = maxD << 2;
        for(int i = 1;i < n;++i){
            b[i] = a[i + 1] - a[i];
            rmq[0][i] = b[i];
        }
        for(int i = 1;i < n;++i){
            for(int j = a[i];j < a[i + 1];++j){
                pos[j] = i;
            }
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 1;i + MASK(j) - 1 < n;++i){
                rmq[j][i] = max(rmq[j - 1][i],rmq[j - 1][i + MASK(j - 1)]);
            }
        }
        auto getMax = [&](const int &l,const int &r){
            int x = (int)log2(r - l + 1);
            return max(rmq[x][l],rmq[x][r - MASK(x) + 1]);
        };
        cin>>m;
        while(m--){
            int t,d;
            cin>>t>>d;
            int k = (pos[t] ? pos[t] : n) - 1 ;
            int l = 1,r = k;
            int f = -1;
            for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                if(getMax(mid,k) <= d){
                    r = mid - 1;
                    f = mid;
                } else {
                    l = mid + 1;
                }
            }
            cout<<(~f ? f : k + 1)<<'\n';
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
