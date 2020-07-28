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

    string compute(){
        int u;
        cin>>u;
        vector < vector < vector <int> > > cnt(26,vector <vector <int> > (10,vector <int> (u + 1,0)));
        for(int i = 1;i <= 10000;++i){
            int m;
            string r;
            cin>>m>>r;
            for(int j = 1;j <= m;++j){
                string d = to_string(j);
                if(len(d) == len(r)){
                    for(int k = 0;k < len(r);++k){
                        ++cnt[r[k] - 'A'][d[k] - '0'][k];
                    }
                }
            }
        }
        string ans = "";
        vector <bool> vis(26,false);
        for(int i = 9;i >= 0;--i){
            int c = 0;
            int maxx = 0;
            for(int k = u;k >= 0;--k){
                for(int j = 0;j < 26;++j){
                    if(cnt[j][i][k] > 0 and cnt[j][i][k] > maxx and !vis[j]){
                        c = j;
                        maxx = cnt[j][i][k];
                    }
                }
            }
            ans += (char)(c + 'A');
            vis[c] = true;
        }
        return ans;
    }

    void solve(){
        int T;
        cin>>T;
        for(int t = 1;t <= T;++t){
            cout<<"Case #"<<t<<": "<<compute()<<'\n';
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
