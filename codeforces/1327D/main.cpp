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
        int tests;
        cin>>tests;
        const int lim = 1000;
        while(tests--){
            int n;
            cin>>n;
            vector < vector <int> > p(3,vector <int> (n + 2,0));
            vector <int> c(n + 2,0);
            vector <bool> vis(n + 2,false);
            for(int i = 1;i <= n;++i){
                cin>>p[2][i];
                p[1][i] = p[0][i] = p[2][i];
            }
            for(int i = 1;i <= n;++i){
                cin>>c[i];
            }

            int f = 0,ans = 0;
            for(int k = 1;k <= lim and !ans;++k,f ^= 1){
                for(int i = 1;i <= n;++i){
                    if(!vis[i]){
                        int j = i;
                        bool col = true;
                        while(!vis[j] and col){
                            if(c[j] != c[p[f][j]]){
                                col = false;
                            }
                            vis[j] = true;
                            j = p[f][j];
                        }
                        if(col){
                            ans = k;
                            break;
                        }
                    }
                }
                for(int i = 1;i <= n;++i){
                    p[f ^ 1][i] = p[2][p[f][i]];
                    vis[i] = false;
                }
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
