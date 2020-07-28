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
#define MASK(i) ((1) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    void calc(){
        int n,m;
        cin>>n>>m;
        vector <string> a(n,"");
        for(int i = 0;i < n;++i){
            cin>>a[i];
        }
        vector < vector < bool > > f[26];
        vector < int > g[26];
        vector < vector < pair <int,int> > > tr[26];
        for(int i = 0;i < 26;++i){
            f[i].resize(m,vector <bool> (MASK(n),false));
            g[i].resize(m ,0);
            tr[i].resize(m,vector <pair <int,int> >(MASK(n),make_pair(0,0)));
        }
        for(int i = 0;i < m;++i){
            for(int c = 0;c < 26;++c){
                for(int j = 0;j < n;++j){
                    if(a[j][i] - 'a' != c){
                        g[c][i] |= MASK(j);
                    }
                }
            }
        }
        for(int c = 0;c < 26;++c){
            f[c][0][g[c][0]] = true;
        }
        for(int mask = 0;mask < MASK(n);++mask){
            for(int i = 0;i < m - 1;++i){
                for(int c = 0;c < 26;++c){
                    for(int d = 0;d < 26;++d){
                        if(!(mask & g[d][i + 1])){
                            if(f[c][i][mask]) {
                                f[d][i + 1][mask | g[d][i + 1]] = f[d][i + 1][mask | g[d][i + 1]] | f[c][i][mask];
                                tr[d][i + 1][mask | g[d][i + 1]] = make_pair(c, mask);
                            }
                        }
                    }
                }
            }
        }
        int chk = -1;
        int mm = 0;
        for(int c = 0;c < 26;++c){
            /*for(int i = -1;i < n;++i){
                if(f[c][m - 1][(MASK(n) - 1) ^ (~i ? MASK(i) : 0)]){
                    chk = c;
                    mm = (MASK(n) - 1) ^ (~i ? MASK(i) : 0);
                    break;
                }
            }*/
            for(int mask = 0;mask < MASK(n);++mask){
                if(f[c][m - 1][mask]){
                    chk = c;
                    mm = mask;
                    break;
                }
            }
        }
        if(chk == -1){
            cout<<-1<<'\n';
        } else {
            string ans = "";
            for(int i = m - 1;i >= 0;--i){
                ans += (char)(chk + 'a');
                pair <int,int> mem = tr[chk][i][mm];
                chk = mem.first;
                mm = mem.second;
            }
            reverse(all(ans));
            cout<<ans<<'\n';
        }
    }

    void solve(){
        int T;
        cin>>T;
        while(T--){
            calc();
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
