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

    const int lg = 31;

    class Solver{
    public:
        int n;
        vector <int> a;
        vector < vector <int> > f;
    public:
        ~Solver(){
            a.clear();
            f.clear();
        }
        void solve(){
            cin>>n;
            a.resize(n + 2,0);
            f.resize(lg + 1,vector <int> (n + 2,0));
            for(int i = 1;i <= n;++i){
                cin>>a[i];
                for(int j = 0;j <= lg;++j){
                    f[j][i] = ((a[i] >> j) & 1);
                }
            }
            for(int j = 0;j <= lg;++j){
                for(int i = 1 ;i <= n;++i){
                    f[j][i] += f[j][i - 1];
                    f[j][i] %= 2;
                }
            }
            llong ans = 0;
            for(int j = 0;j <= lg;++j){
                int cnt[] = {1,0};
                for(int i = 1;i <= n;++i){
                    ans += (1LL << j) * 1LL * cnt[f[j][i] ^ 1];
                    ++cnt[f[j][i]];
                }
            }
            cout<<ans<<'\n';
        }
    };

    void solve(){
        int T;
        cin>>T;
        while(T--){
            (new Solver) -> solve();
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
