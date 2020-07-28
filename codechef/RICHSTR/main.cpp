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

    const int lg = 17;

    class Solve{
    public:
        string s;
        int n,q;
        vector <int> cnt[26];
        vector <int> g[26];
        vector <int> f[26];
        vector < vector < int>  > rmq[26];
    public:
        ~Solve(){
            s.clear();
            for(int c = 0;c < 26;++c){
                cnt[c].clear();
                g[c].clear();
                f[c].clear();
                rmq[c].clear();
            }
        }
    public:

        void computeRange(int c){
            vector < vector < int > > sp;
            sp.resize(lg + 1,vector < int > (n + 2,0));
            for(int i = 0;i <= n;++i){
                sp[0][i] = g[c][i];
            }
            for(int j = 1;j <= lg;++j){
                for(int i = 0;i + MASK(j) - 1 <= n;++i){
                    sp[j][i] = min(sp[j - 1][i],sp[j - 1][i + MASK(j - 1)]);
                }
            }
            auto getMin = [&](int l,int r){
                int x = (int)log2(r - l + 1);
                return min(sp[x][l],sp[x][r - MASK(x) + 1]);
            };
            for(int r = 0;r <= n;++r){
                f[c][r] = -1;
                for(int lo = 0,hi = r - 3,mid = (lo + hi) >> 1;lo <= hi;mid = (lo + hi) >> 1){
                    if(g[c][r] > getMin(mid,r - 3)){
                        lo = mid + 1;
                        f[c][r] = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                if(~f[c][r]){
                    if((cnt[c][r] - cnt[c][f[c][r] - 1]) << 1 <= (r - f[c][r] + 1)){
                        f[c][r] = -1;
                    }
                }
            }
        }

        void solve(){
            cin>>n>>q>>s;
            s = " " + s;
            for(int c = 0;c < 26;++c){
                cnt[c].resize(n + 2,0);
                g[c].resize(n + 2,0);
                f[c].resize(n + 2,0);
            }
            for(int c = 0;c < 26;++c){
                for(int i = 1;i <= n;++i){
                    cnt[c][i] = cnt[c][i - 1] + (s[i] - 'a' == c);
                }
                for(int i = 1;i <= n;++i){
                    g[c][i] = (cnt[c][i] << 1) - i;
                }
            }
            for(int c = 0;c < 26;++c){
                computeRange(c);
                rmq[c].resize(lg + 1,vector <int> (n + 2,0));
                for(int i = 1;i <= n;++i){
                    rmq[c][0][i] = f[c][i];
                }
                for(int j = 1;j <= lg;++j){
                    for(int i = 1;i + MASK(j) - 1 <= n;++i){
                        rmq[c][j][i] = max(rmq[c][j - 1][i],rmq[c][j - 1][i + MASK(j - 1)]);
                    }
                }
            }

            auto getMax = [&](int c,int l,int r){
                int x = (int)log2(r - l + 1);
                return max(rmq[c][x][l],rmq[c][x][r - MASK(x) + 1]);
            };

            while(q--){
                int l,r;
                cin>>l>>r;
                bool ok = false;
                for(int c = 0;c < 26 and !ok;++c){
                    ok |= getMax(c,l,r) >= l;
                }
                cout<<(ok ? "YES\n" : "NO\n");
            }
        }
    };

    void solve(){
        int Test;
        cin>>Test;
        while(Test--){
            (new Solve) -> solve();
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
