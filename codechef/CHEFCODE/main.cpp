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
        int n;
        llong k;
        cin>>n>>k;
        vector < llong > a(n,0);
        for(int i = 0;i < n;++i){
            cin>>a[i];
        }
        vector < llong > left;
        vector < llong > right;
        for_each(a.begin(),a.begin() + (n >> 1),[&](const llong &val){
            left.emplace_back(val);
        });
        for_each(a.begin() + (n >> 1),a.end(),[&](const llong &val){
            right.emplace_back(val);
        });
        function < vector < llong > (const vector < llong >) > calc = [&](const vector < llong > &vec){
            vector < llong > ret;
            for(int mask = 1;mask < MASK(len(vec));++mask){
                llong mul = 1LL;
                bool ok = true;
                for(int i = 0;i < len(vec);++i){
                    if(BIT(mask,i)){
                        if(vec[i] <= k / mul){
                            mul *= vec[i];
                        } else {
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok){
                    ret.emplace_back(mul);
                }
            }
            return ret;
        };
        left = calc(left);
        right = calc(right);
        sort(all(right));
        llong ans = len(left) + len(right);
        for(llong ll : left){
            llong rr = k / ll;
            int lo = 0,hi = len(right) - 1;
            int p = -1;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(right[mid] <= rr){
                    lo = mid + 1;
                    p = mid;
                } else {
                    hi = mid - 1;
                }
            }
            ans += ++p;
        }
        cout<<ans;
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
